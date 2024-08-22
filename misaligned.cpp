#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

int printColorMap(std::ostringstream& buffer) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i, j;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            buffer << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }

    return i * j;
}

int main() {
    std::ostringstream buffer;
    const std::string expected_colors = "1 | White | Orange\n";

    int result = printColorMap(buffer);
    
    assert(result == 25);
    assert(buffer.str().find(expected_colors) != std::string::npos);
    
    std::cout << "All is well (maybe!)\n";
    
    return 0;
}
