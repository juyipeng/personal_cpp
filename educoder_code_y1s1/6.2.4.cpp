#include <iostream>
using namespace std;

int mystrstr(char[],char[]);

int main() 
{
   char a[81], b[81];
   cin>>a;
   cin>>b;
   cout << mystrstr(a, b);
   return 0;
}

int mystrstr(char cTotal[], char cToFind[]){
    for(int i = 0; cTotal[i] != '\0'; i++){
        bool b_m_Test = true;
        for(int j = 0; cToFind[j] != '\0'; j++){
            if(cTotal[i+j] != cToFind[j]){
                b_m_Test = false;
                break;
            }
        }
        if(b_m_Test){
            return i;
        }
    }
    return -1;
}