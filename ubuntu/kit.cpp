#include "kit.h"

void getinfo(std::vector<student*> &students, char* filename){
    std::ifstream file(filename); // 替换为您的文件名
    if (file.is_open()) {
        while (file){
            student* ns = new student();
            file >> ns->name;
            file >> ns->number;
            file >> ns->score;
            students.push_back(ns);
        }
        students.pop_back();
        file.close();
    }
}
