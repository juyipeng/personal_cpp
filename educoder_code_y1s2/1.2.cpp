#include "point.h"
#include <iostream>

int main(){
    double para[6] = {};
    for(int i = 0; i < 6; i++){
        std::cin >> para[i];
    }
    Triangle t1(para);
    std::cout << t1.girth() << ' ' << t1.area() << std::endl;
    for(int i = 0; i < 4; i++){
        std::cin >> para[i];
    }
    Circle c1(para);
    std::cout << c1.girth() << ' ' << c1.area() << std::endl;
    return 0;
}