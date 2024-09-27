#include <iostream>
using namespace std;

int main(){
    int quantity;
    cin >> quantity;
    for(int j = 0; j < quantity; j++)
    {int number, nstack[1000], nqueue[1000], nscale = 0;
    bool isStack = true, isQueue = true;
    cin >> number;
    int oprt, val;
    for(int i = 0; i < number; i++){
        cin >> oprt >> val;
        if(oprt==1){
            nstack[nscale] = val;
            nqueue[nscale] = val;
            nscale++;
        }
        else if(nscale==0){
            isStack = isQueue = false;
            break;
        }
        else{
            if(nstack[nscale-1]!=val){
                isStack=false;
            }
            else{}
            if(nqueue[0] != val){
                isQueue = false;
            }
            for(int k = 0; k < nscale-1; k++){
                nqueue[k] = nqueue[k+1];
            }
            nscale--;
        }}
        if(isQueue&&isStack){
            cout << "Both";
        }
        else if(isQueue){
            cout << "Queue";
        }
        else if(isStack){
            cout << "Stack";
        }
        else{
            cout << "Error";
        }
        cout << endl;
    }
}