#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


struct student
{
    char name[100];
    long long int number;
    int score;
};

void getinfo(std::vector<student*>&, char*);
