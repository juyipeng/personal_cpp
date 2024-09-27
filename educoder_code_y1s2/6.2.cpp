#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

vector<int>space;
int scale = 0, k = 2;

int main(){
    string b;
    getline(cin,b);
    stringstream sb (b);
    char buffer[100];
    space.push_back(0);
    while(sb >> buffer){
        if(buffer[0]=='n'){scale++; space.push_back(1414134);}
        else{
            int tmp = 0;
            for(int i = 0; buffer[i]!=0; i++){
                tmp = tmp*10+buffer[i]-'0';
            }
            scale++; space.push_back(tmp);
        }
    }

    bool isBST = true;
    for(int i = 1; i <= scale; i++){
        if((i*2<=scale)&&(space[i*2]!=1414134)&&(space[i*2]>=space[i])){
            isBST = false;
        }
        if((i*2+1<=scale)&&(space[i*2+1]!=1414134)&&(space[i*2+1]<=space[i])){
            isBST = false;
        }
    }
    cin >> k;
    if(!isBST){
        cout << "not BST";
    }
    else{
        int *s = new int[space.size()];
        int rs = 0;
        for(int i = 1; i <= scale; i++){
            if(space[i]!=1414134){
                s[rs++] = space[i];
            }
        }
        for(int i = 0; i < rs-1; i++){
            for(int j = rs-1; j >0; j--){
                if(s[j]<s[j-1]){
                    int tmp = s[j];
                    s[j] = s[j-1];
                    s[j-1] = tmp;
                }
            }
        }
        if(k>rs){
            cout << "error";
        }
        else{cout << s[k-1];}
        delete []s;
    }
}