#include <iostream>
#include <cmath>

using namespace std;

bool tell(char* head, int index){
    if(index==1){
        if(head[1]=='@'&&head[2]=='@'&&head[0]!='@'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        int t =pow(2,index);
        return (head[0]!='@')&&tell(head+1,index-1)&&tell(head+t,index-1);
    }
}

int main(){
    char*space = new char[4096];
    int ntmp = 0; char ctmp;
    while(cin >> ctmp){
        space[ntmp] = ctmp;
        ntmp++;
    }
    int index = 0;
    for(index=0;space[index]!='@';index++);
    cout << (tell(space,index)?"true":"false");

    delete[]space;
}