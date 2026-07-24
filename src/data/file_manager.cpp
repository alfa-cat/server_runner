#include "file_manager.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

std::string FileManager::readFile(const std::string& filePath) {
    std::cerr << "Trying to open: " << filePath << std::endl;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "FAILED to open file" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
