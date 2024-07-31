#include <iostream>
#include <assert.h>
#include <string>
#include <sstream>

std::string printColorPair(int pairNumber, const char* majorColor, const char* minorColor) {
    std::ostringstream oss;
    oss << pairNumber << " | " << majorColor << " | " << minorColor;
    return oss.str();
}

int main() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::string expectedOutput[] = {
        "0 | White | Blue",
        "1 | White | Orange",
        "2 | White | Green",
        "3 | White | Brown",
        "4 | White | Slate",
        "5 | Red | Blue",
        "6 | Red | Orange",
        "7 | Red | Green",
        "8 | Red | Brown",
        "9 | Red | Slate",
        "10 | Black | Blue",
        "11 | Black | Orange",
        "12 | Black | Green",
        "13 | Black | Brown",
        "14 | Black | Slate",
        "15 | Yellow | Blue",
        "16 | Yellow | Orange",
        "17 | Yellow | Green",
        "18 | Yellow | Brown",
        "19 | Yellow | Slate",
        "20 | Violet | Blue",
        "21 | Violet | Orange",
        "22 | Violet | Green",
        "23 | Violet | Brown",
        "24 | Violet | Slate"
    };

    int index = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::string output = printColorPair(index, majorColor[i], minorColor[j]);
            assert(output == expectedOutput[index]); // This should fail due to the misalignment in the current implementation
            index++;
        }
    }
    
    std::cout << "All is well (maybe!)\n";
    return 0;
}
