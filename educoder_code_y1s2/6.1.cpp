#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <sstream>
#include <string>

using namespace std;

void deleteSelf(int);
void clear();
void process(int);
void trans(int, int);

vector<int>space;
int scale = 0, k = 2;
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

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
    cin >> k;
    process(1);


    if(minHeap.size()==0){
        cout << "none";
    }
    else{
        while(!(minHeap.empty())){
            cout << minHeap.top()<< ' ' ;
            minHeap.pop();
        }
    }

    cout << '\n';

    
        for(int i = 1; i <= scale; i++){
        if(space[i]!=1414134){
            cout << space[i] << ' ';
        }
        else{cout << "null" << ' ';}
        }

    

}

void deleteSelf(int n){
    if(space[n]==1414134){return;}
    else{
        minHeap.push(space[n]);
        space[n] = 1414134;
        if((2*n+1)<=scale){deleteSelf(2*n+1);}
        if((2*n)<=scale){deleteSelf(2*n);}
    }
    clear();
}

void clear(){
    for(int i = scale; space[i]==1414134; i--){
        space.pop_back();
        scale--;
    }
}

void trans(int p, int d){
    if(space[d]!=1414134){minHeap.push(space[d]);}
    space[d] = space[p];
    space[p] = 1414134;
    if(p*2<=scale){trans(p*2,d*2);}
    if(p*2+1<=scale){trans(p*2+1,d*2+1);}
    clear();
}

void process(int n){
    if(space[n]>=k){
        if(n*2<=scale&&n*2!=1414134){
            process(n*2);
        }
    }
    else{
        if(n*2<=scale&&n*2!=1414134){deleteSelf(n*2);}
        if(n*2+1<=scale&&n*2+1!=1414134){
            trans(n*2+1,n);
            process(n);
        }
        else{minHeap.push(space[n]);space[n]=1414134;}
    }
    clear();
}