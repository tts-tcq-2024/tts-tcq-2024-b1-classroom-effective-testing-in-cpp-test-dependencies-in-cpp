#include <iostream>
#include <sstream>
#include <vector>
#include <assert.h>

std::vector<std::pair<std::string, std::string>> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::pair<std::string, std::string>> colorMap;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMap.push_back({majorColor[i], minorColor[j]});
        }
    }
    return colorMap;
}

std::string formatColorMap(const std::vector<std::pair<std::string, std::string>>& colorMap) {
    std::ostringstream oss;
    for(size_t i = 0; i < colorMap.size(); i++) {
        oss << i << " | " << colorMap[i].first << " | " << colorMap[i].second << "\n";
    }
    return oss.str();
}


void printColorMap(const std::string& formattedColorMap) {
    std::cout << formattedColorMap;
}

void testColorMapFormat() {
    auto colorMap = generateColorMap();
    std::string formattedColorMap = formatColorMap(colorMap);

    // Check for alignment issues
    assert(formattedColorMap.find("0 | White | Blue") != std::string::npos);
    assert(formattedColorMap.find("1 | White | Orange") != std::string::npos);
    assert(formattedColorMap.find("2 | White | Green") != std::string::npos);
    assert(formattedColorMap.find("3 | White | Brown") != std::string::npos);
    assert(formattedColorMap.find("4 | White | Slate") != std::string::npos);
}

int main() {
    auto colorMap = generateColorMap();
    std::string formattedColorMap = formatColorMap(colorMap);
    printColorMap(formattedColorMap);

    // Run the test
    testColorMapFormat();

    std::cout << "All is well (maybe!)\n";
    return 0;
}
