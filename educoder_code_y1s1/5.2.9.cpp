#include <iostream>

using namespace std;



int main()
{
    char cSpace[30][30] = {0};
    int nBreadth = 0;
    cin >> nBreadth;
    char cPresent;
    int x = 0, y = 0;
    bool bVertical = true;
    if (nBreadth==1){
        while(cin>> cPresent){
            cout<<cPresent;
        }
        return 0;
    } 
    while(cin>> cPresent)
    {
        cSpace[x][y] = cPresent;
        if(bVertical){
            y++;
            if(y==nBreadth){
                bVertical = false;
                x+=1;
                y-=2;
            }
            else{}
        }
        else{
            y--;
            x++;
            if(y < 0){
                x--;
                y+=2;
                bVertical = true;
            }
            else{}
        }
        // y %= nBreadth;
    }
    for(int i = 0; i < nBreadth; i++)
    {
        for(int j = 0; j < 30 ; j++){
            if(cSpace[j][i]!='\0'){
                cout<< cSpace[j][i] ;//<< j <<' '<< i<<endl;
            }
            else{}
        }
    }
    int c= 1;  
}