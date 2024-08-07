#include <iostream>
#include <assert.h>
#include <functional>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Simulate failure for temperatures above a certain threshold for testing
    if (celcius > 200) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit, std::function<int(float)> networkAlert) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

void testAlerter() {
    alertFailureCount = 0;

    // Test with a temperature that should trigger a failure
    alertInCelcius(400.5, networkAlertStub); // Should fail (celcius > 200)
    assert(alertFailureCount == 1);

    // Test with a temperature that should not trigger a failure
    alertInCelcius(303.6, networkAlertStub); // Should pass (celcius <= 200)
    assert(alertFailureCount == 1); // Should still be 1

    // Test with another temperature that should trigger a failure
    alertInCelcius(500.0, networkAlertStub); // Should fail (celcius > 200)
    assert(alertFailureCount == 2);
}

int main() {
    testAlerter();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
