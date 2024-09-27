#include <iostream>
#include <string>

using namespace std;



int main(){
    int nQuantity = 1, nPresent = 0, row = 1;
    string sSpace = "";
    cin >> nQuantity >> row;
    for(int i = 0; i < nQuantity; i++){
        sSpace.append(1,(char)(i+1));
    }
    // cout << sSpace << endl;
    while(nQuantity!=1){
        nPresent = (nPresent+row-1)%nQuantity;
        if(nQuantity==2){cout << (int)sSpace[nPresent];}
        else{cout << (int)sSpace[nPresent] << ' ';}
        sSpace.erase(nPresent,1);
        nQuantity--;
    }
    cout << '\n' << (int)sSpace[0] << endl;

    return 0;
}