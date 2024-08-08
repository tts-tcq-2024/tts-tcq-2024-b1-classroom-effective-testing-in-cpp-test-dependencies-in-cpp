#include <iostream>
#include <assert.h>
// bugor error is the value 38 and 42 are not properly categorized in the current implementation.
char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    
    // Additional tests to ensure failure
    assert(size(38) == 'S'); // This will fail since 38 is not handled correctly
    assert(size(42) == 'M'); // This will fail since 42 is not handled correctly
    assert(size(0) == '\0'); // This will fail since 0 should not be categorized
    
    std::cout << "All is well (maybe!)\n";
    return 0;
}
