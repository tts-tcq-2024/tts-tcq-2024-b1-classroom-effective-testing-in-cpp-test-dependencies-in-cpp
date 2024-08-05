#include <iostream>
#include <string>
#include <assert.h>

std::string size(int cms) {
    if(cms < 38) {
        return "S";
    } else if(cms >= 38 && cms < 42) {
        return "M";
    } else if(cms >= 42) {
        return "L";
    }
    return "NA";
}

void testSize() {
    assert(size(37) == "S");
    assert(size(38) == "M");
    assert(size(40) == "M");
    assert(size(42) == "L");
    assert(size(43) == "L");
    assert(size(0) == "NA");  // Add test for value outside the range
}

int main() {
    testSize();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
