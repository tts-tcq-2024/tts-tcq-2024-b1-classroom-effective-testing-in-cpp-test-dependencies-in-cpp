#include <iostream>
#include <assert.h>
#include <sstream>

std::string getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::ostringstream oss;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            oss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return oss.str();
}

int main() {
    std::string colorMap = getColorMap();
    // Check if the map contains misaligned entries
    assert(colorMap.find("0 | White | Blue") != std::string::npos);
    assert(colorMap.find("1 | White | Orange") != std::string::npos);
    assert(colorMap.find("2 | White | Green") != std::string::npos);
    assert(colorMap.find("3 | White | Brown") != std::string::npos);
    assert(colorMap.find("4 | White | Slate") != std::string::npos);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
