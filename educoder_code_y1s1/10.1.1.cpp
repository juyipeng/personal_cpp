/*
@file main.cpp
@pengjuyi
@version 1.0
@2023.12.13
*/
#include "clock.h"
using namespace std;
int main(){
    Clock a,b,c;
    a.input();
    b.input();
    if(b.back()>a.back()){c = b-a;}
    else{c = a - b;}
    c.println();
    return 0;
}
