#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

int main(){
    stack<double> n_space;
    char buf[256] = {};
    cin.getline(buf,256);
    double temp;
    for(int i = 0; buf[i]!=0; i++){
        if(buf[i]>='0' && buf[i]<='9'){
            n_space.push(buf[i]-'0');
        }
        else if(buf[i]==' '){}
        else if(n_space.size()<2){
            cout << "Error";
            return 0;
        }
        else{
            switch(buf[i]){
                case '+':
                temp = n_space.top();
                n_space.pop();
                temp += n_space.top();
                n_space.pop();
                n_space.push(temp);
                break;
                case '-':
                temp = n_space.top();
                n_space.pop();
                temp = n_space.top()-temp;
                n_space.pop();
                n_space.push(temp);
                break;
                case '*':
                temp = n_space.top();
                n_space.pop();
                temp *= n_space.top();
                n_space.pop();
                n_space.push(temp);
                break;
                case '/':
                temp = n_space.top();
                n_space.pop();
                temp = n_space.top()/temp;
                n_space.pop();
                n_space.push(temp);
                break;
            }
        }
        // std::cout << (n_space.empty()?0:n_space.top())  <<  ' ' << n_space.size() << endl;
    }
    if(n_space.size()!=1){
        cout << "Error";
        return 0;
    }
    else{
        cout << fixed << setprecision(1) << n_space.top();
    }
}