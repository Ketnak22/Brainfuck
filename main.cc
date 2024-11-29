// Brainfuck 

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

#include "brainfuck.cc"

std::string readFile(const char* fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
    }

    std::string line;
    std::string result;

    while (std::getline(file, line)) {
        result += line;
    }

    return result;
}

std::string filterString(const std::string& input, const std::unordered_set<char>& allowedChars) {
    std::string result;
    for (char c : input) {
        if (allowedChars.find(c) != allowedChars.end()) {
            result += c;
        }
    }
    return result;    
}

const std::unordered_set<char> allowedChars = {'>', '<', '+', '-', '.', ',', '[', ']'};

int main() {
    std::string fileContent = readFile("example.bf");
    run(filterString(fileContent, allowedChars).c_str());

    return 0;
}