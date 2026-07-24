#include "../src/data/file_manager.h"
#include <iostream>

int main() {
    FileManager fm;
    //Тест 1. Чтение файла
    std::string content = fm.readFile("text.txt");
    std::cout << "Read content: " << content << std::endl;
}