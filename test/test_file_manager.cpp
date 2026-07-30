#include "../src/data/file_manager.h"
#include <iostream>

int main() {
    FileManager fm;

    // 1. writeFile test
    bool written = fm.writeFile("test_write.txt", "Hello from writeFile!");
    std::cout << "writeFile: " << (written ? "OK" : "FAIL") << std::endl;

    // 2. readFile test
    std::string content = fm.readFile("text.txt");
    std::cout << "readFile: " << content << std::endl;

    // 3. listFiles test
    std::cout << "Files in current dir:" << std::endl;
    for (const auto& f : fm.listFiles(".")) {
        std::cout << " - " << f << std::endl;
    }

    return 0;
}