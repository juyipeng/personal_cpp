#include "class.h"

int main(){
    RomanWithInt *tmp = nullptr;
    std::string a = "";
    while(true){
        std::cin >> a;
        if(a == "@"){break;}
        if(a[0]>='1'&&a[0]<='9'){
            tmp = new RomanWithInt(std::stoi(a));
            delete tmp;
        }                                                                       
        else{
            tmp = new RomanWithInt(a);
        }
    }
}