#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int depth = 0, tmp = 0;
    char buffer[4096];
    cin.getline(buffer, 4096);
    int nb[11][1024]={0};
    //record
    for(int i = 0;buffer[i]!=0; i++){
        if(buffer[i]=='0'){
            nb[depth][tmp]=-1;
            tmp++;
        }
        if(buffer[i]=='1'){
            nb[depth][tmp]=1;
            tmp++;
        }
        if(buffer[i]=='n'){
            nb[depth][tmp]=0;
            tmp++;
        }
        if(tmp==pow(2,depth)){
            tmp=0;
            depth++;
        }                                                                                                                                                                                                            
    }
    //process
    for(int i = depth; i >=0; i--){
        for(int j = 0; j < pow(2,i); j++){
            if(nb[i][j]==-1&&nb[i+1][2*j]==0&&nb[i+1][2*j+1]==0){
                nb[i][j] = 0;
            }
        }
    }
    depth=0;tmp=0;bool flag = true;
    while(flag){
        flag=false;
        for(int j = 0; j < pow(2,depth); j++){
            if(nb[depth][j]!=0){
                depth++;
                flag = true;
            }
        }
    }
    depth--;
    //output
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < pow(2,i); j++){
            if(nb[i][j]==1){
                cout<< 1;
            }
            else if(nb[i][j]==-1){
                cout<< 0;
            }
            else{
                cout<<"null";
            }
            cout<<' ';
        }
    }
    tmp = 0;
    for(int i = 0; i<pow(2,depth); i++){
        if(nb[depth][i]!=0){
            tmp = i;
        }
    }
    int j = 0;
    while(j<=tmp){
        if(nb[depth][j]==1){
            cout<< 1;
        }
        else if(nb[depth][j]==-1){
            cout<< 0;
        }
        else{
            cout<<"null";
        }
        if(j!=tmp){
            cout<<' ';
        }
        j++;
    }
}