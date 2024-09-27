#include "queue.h"
#include <iostream>
#include <cstring>

int main(){
    char a[64];
    int value;
    NewQueue que;
    while(std::cin >> a){
        std::cin >> value;
        if(strcmp(a,"EnFront")==0){
            que.enFront(value);
        }
        else if(strcmp(a,"EnMiddle")==0){
            que.enMiddle(value);
        }
        else if(strcmp(a,"EnRear")==0){
            que.enRear(value);
        }
        else if(strcmp(a,"DeFront")==0){
            que.deFront();
        }
        else if(strcmp(a,"DeMiddle")==0){
            que.deMiddle();
        }
        else if(strcmp(a,"DeRear")==0){
            que.deRear();
        }
    }
    if(que.isEmpty()) std::cout << "null";
    else std::cout << que.read(0);
    for(int i = 1; i < que.getScale(); i++){
        std::cout << ' ' << que.read(i);
    }
    return 0;
}