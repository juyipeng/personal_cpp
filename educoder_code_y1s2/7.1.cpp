#include <iostream>  
#include <queue>  
#include <functional>
#include <string>

using namespace std;

int main(){
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int n;
    cin >> n;
    int *res = new int[n];
    int t = 0;
    int present;
    cin >> present;
    minHeap.push(present);
    for(int i = 1; i < n; i++){
        cin.get();
        cin >> present;
        minHeap.push(present);
    }
    for(int i = 0; i < n; i++){
        present = minHeap.top();
        minHeap.pop();
        res[i] = present;
    }

    if(n%2){
        cout << res[n/2];
    }
    else{
        cout << (res[n/2]+res[n/2-1])/2;
    }

    delete[]res;
}