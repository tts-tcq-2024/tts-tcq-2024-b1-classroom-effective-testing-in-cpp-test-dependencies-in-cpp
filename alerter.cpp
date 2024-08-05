#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // Modify to return 500 when temperature is above a threshold
    return (celcius > 200) ? 500 : 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Correctly increment failure count
        alertFailureCount += 1;
    }
}

int main() {
    // Add test cases that should fail
    alertInCelcius(400.5);  // Should fail
    alertInCelcius(303.6);  // Should fail
    alertInCelcius(50.0);   // Should pass
    assert(alertFailureCount == 2);  // Test should fail because the count should be 2
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
