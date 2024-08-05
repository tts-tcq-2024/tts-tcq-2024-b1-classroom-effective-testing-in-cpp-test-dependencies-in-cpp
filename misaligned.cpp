#include <iostream>
#include <assert.h>
#include <vector>
#include <utility>

std::vector<std::pair<int, std::string>> getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::pair<int, std::string>> colorMap;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMap.push_back({i * 5 + j, std::string(majorColor[i]) + " | " + minorColor[j]});
        }
    }
    return colorMap;
}

int printColorMap() {
    auto colorMap = getColorMap();
    for(const auto& entry : colorMap) {
        std::cout << entry.first << " | " << entry.second << "\n";
    }
    return colorMap.size();
}

void testColorMap() {
    auto colorMap = getColorMap();
    assert(colorMap.size() == 25);
    assert(colorMap[0].first == 0 && colorMap[0].second == "White | Blue");
    assert(colorMap[24].first == 24 && colorMap[24].second == "Violet | Slate");
    // Add more assertions if needed
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
