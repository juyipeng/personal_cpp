#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> students, lunches;
    char a;
    int value = 0;
    while(true){
        cin.get(a);
        if(a == '\n'){
            students.push(value);
            value = 0;
            break;
        }
        else if(a<='9'&&a>='0'){
            value = value*10+a-'0';
        }
        else{
            students.push(value);
            value = 0;
        }
    }
    while(cin.get(a)){
        if(a<='9'&&a>='0'){
            value = value*10+a-'0';
        }
        else{
            lunches.push(value);
            value = 0;
        }
    }
    int rec = 0;
    lunches.push(value);
    while(rec < students.size()){
        if(students.empty()||lunches.empty()){
            break;
        }
        if(students.front() == lunches.front()){
            students.pop();
            lunches.pop();
            rec = 0;
        }
        else{
            int tmp = students.front();
            // cout << students.front();
            students.pop();
            students.push(tmp);
            rec++;
            // cout<<' '<< students.size()<<endl;
        }
    }
    cout << students.size();
}