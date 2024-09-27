#include <iostream>

using namespace std;



int solve(int ileft, int spaceleft);

int value[150] = {0}, volume[150] = {0};
int result[150][1001];

int main(){
    for(int i = 0; i < 150; i++){
        for(int j = 0; j < 1001; j++){
            result[i][j] = -1;
        }
    }
    int nquantity = 0, nspace = 0;
    cin>> nspace >> nquantity;
    for(int i = 0; i < nquantity; i++){
        cin>> volume[i] >> value[i];
    }
    cout<< solve(nquantity - 1,nspace);
    return 0;
}

int solve(int ileft, int spaceleft){
    if(result[ileft][spaceleft]>=0){
        return result[ileft][spaceleft];
    }
    else if(ileft < 0||spaceleft==0){
        result[ileft][spaceleft] = 0;
        return 0;
    }
    else if(ileft >= 0 && volume[ileft] > spaceleft){
        result[ileft][spaceleft] = solve(ileft-1, spaceleft);
        return result[ileft][spaceleft];
    }
    else{
        result[ileft][spaceleft] = max(solve(ileft - 1, spaceleft),(solve(ileft - 1, spaceleft - volume[ileft])+value[ileft]));
        return result[ileft][spaceleft];
    }
}