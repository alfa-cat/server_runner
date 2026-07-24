#pragma once // чтобы не включилось два раза
#include <string> // зависимость
#include <vector> // зависимость

class FileManager { // создаем класс
public:
    std::string readFile(const std::string& filePath); // тута мы читаем файл, очевидно к нему должен быть путь, отсюда и параметр filePath
    bool writeFile(const std::string& filePath, const std::string& content); // тута у нас запись текста, путь куда записать, и контент
    std::vector<std::string> listFiles(const std::string& dir); // тута мы говорим что будет видеть файлы из директории
};