#include "file_manager.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>

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


bool FileManager::writeFile(const std::string& filePath, const std::string& content) {
        std::ofstream file(filePath, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            return false;
        }

        file << content;
        
        if (!file) {
            return false;
        }

        return true;
}

std::vector<std::string> FileManager::listFiles(const std::string& dirPath) {
    std::vector<std::string> allFiles;

    if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath)) {
        return allFiles;
    }
    for (const auto& entry : std::filesystem::recursive_directory_iterator(dirPath)) {
        if (std::filesystem::is_regular_file(entry.path())) {
            allFiles.push_back(entry.path().string());
        }
    }
    return allFiles;
}