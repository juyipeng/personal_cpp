#include <iostream>
#include <string>
#include "line.h"

int main(){
    double a,b,c,d;
    std::cin >> a >> b >> c >> d;
    line l1(a,b,c,d);
    std::cin >> a >> b >> c >> d;
    line l2(a,b,c,d);
    std::string s;
    std::cin >> s;
    std::cout << l1.length() << ' ' << l2.length() <<std::endl; 
    bool tell;
    if(s==">"){
        tell = l1>l2;
    }
    else if(s=="<"){
        tell = l1<l2;
    }
    else if(s=="=="){
        tell = l1==l2;
    }
    else{}
    if(tell){
        std::cout << "Yes!";
    }
    else{
        std::cout << "No!";
    }
    return 0;
}