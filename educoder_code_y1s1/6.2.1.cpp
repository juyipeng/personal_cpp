#include <iostream>

using namespace std;

int main(){
    int a, b, temp;
    cin>> a >> b;
    if(b > a){
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0){
        a%=b;
        temp = a;
        a = b;
        b = temp;
    }
    cout<< a;
}