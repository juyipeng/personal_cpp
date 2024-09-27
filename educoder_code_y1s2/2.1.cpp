#include "link.cpp"
#include <iostream>

int main(){
    char buffer[256] = {};
    std::cin.getline(buffer,256);
    int num = 0;
    int sign = 1;
    Link<int> link(1024);
    for(int i = 0; buffer[i] != 0; i++){
        if(buffer[i] == ' '){
            link.insert(link.showScale(),num*sign);
            num = 0;
            sign = 1;
        }
        if(buffer[i]<='9'&&buffer[i]>='0'){
            num = num*10+buffer[i]-'0';
        }
        if(buffer[i]=='-'){
            sign = -1;
        }
        if(buffer[i+1] == 0){
            // num = num*10+buffer[i]-'0';
            link.insert(link.showScale(),num*sign);
        }
    }
    int a,b;
    std::cin >> a>>b;
    link.insert(a,b);
    int largest,smallest;
    std::cin >> smallest >> largest;
    link.erase(smallest,largest);
    std::cout << link.showScale() << std::endl;
    std::cout << link;
    return 0;
}