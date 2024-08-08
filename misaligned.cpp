#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <assert.h>


struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};


std::vector<ColorPair> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<ColorPair> colorMap;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ColorPair pair;
            pair.majorColor = majorColor[i];
            pair.minorColor = minorColor[j];
            colorMap.push_back(pair);
        }
    }
    return colorMap;
}


void printColorMap(const std::vector<ColorPair>& colorMap) {
    for (size_t i = 0; i < colorMap.size(); i++) {
        
        std::cout << std::setw(2) << i << " | " 
                  << std::setw(6) << colorMap[i].majorColor << " | " 
                  << std::setw(6) << colorMap[i].minorColor << "\n";
    }
}

int main() {
    std::vector<ColorPair> colorMap = generateColorMap();


    assert(colorMap.size() == 25); 
    assert(colorMap[0].majorColor == "White" && colorMap[0].minorColor == "Blue");   
    assert(colorMap[24].majorColor == "Violet" && colorMap[24].minorColor == "Slate"); 
    assert(colorMap[6].majorColor == "Red" && colorMap[6].minorColor == "Green");  


    printColorMap(colorMap);

    std::cout << "All is well (maybe!)\n";
    return 0;
}
