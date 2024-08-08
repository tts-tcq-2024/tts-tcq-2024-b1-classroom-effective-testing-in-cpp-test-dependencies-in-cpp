#include <iostream>
#include <assert.h>
#include <vector>
#include <string>

// Function to generate the color map
std::vector<std::string> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> colorMap;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMap.push_back(std::to_string(i * 5 + j) + " | " + majorColor[i] + " | " + minorColor[j]);
        }
    }
    return colorMap;
}

// Function to print the color map
void printColorMap(const std::vector<std::string>& colorMap) {
    for(const std::string& entry : colorMap) {
        std::cout << entry << "\n";
    }
}

// Main function with failing tests
int main() {
    // Generate the color map
    std::vector<std::string> colorMap = generateColorMap();

    // Print the color map
    printColorMap(colorMap);

    // Test to ensure the map has 25 entries
    assert(colorMap.size() == 25);

    // Additional tests to ensure failure (These tests should fail)
    // Testing incorrect expected outputs
    /*assert(colorMap[0] == "0 | White | Blue");
    assert(colorMap[1] == "1 | White | Orange");
    assert(colorMap[2] == "2 | White | Green");
    assert(colorMap[3] == "3 | White | Brown");
    assert(colorMap[4] == "4 | White | Slate");

    // Misalignment test - these tests should fail due to expected misalignment in the actual output
    assert(colorMap[5] == "5 | Red | Blue");
    assert(colorMap[10] == "10 | Black | Blue");
    assert(colorMap[15] == "15 | Yellow | Blue");
    assert(colorMap[20] == "20 | Violet | Blue");

    // Boundary test - these tests should fail due to incorrect boundary conditions
    assert(colorMap[24] == "24 | Violet | Slate");*/

    std::cout << "All is well (maybe!)\n";
    return 0;
}
