#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int depth = 0, res = 1, tmp = 0;
    char buffer[4096];
    cin.getline(buffer, 4096);
    int nb[11][1024]={0};
    for(int i = 0;buffer[i]!=0; i++){
        if(buffer[i]==' '){
            nb[depth][tmp]=(buffer[i-1]=='l'?0:1);
            tmp++;
        }
        if(tmp==pow(2,depth)){
            tmp=0;
            depth++;
        }
    }
    nb[depth][tmp] = 1;
    if(tmp=pow(2,depth)){
        tmp=0;
        depth++;
    }
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < pow(2,i); j++){
            if(nb[i][j]==1&&nb[i+1][2*j]==1&&nb[i+1][2*j+1]==1){
                res++;
            }
        }
    }
    cout<<res;
}