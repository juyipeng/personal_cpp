#include <iostream>
// #include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    // vector<int> nspace;
    int scale = 0,n,tmp, res = 0;
    cin >> n;
    while(cin >> tmp){
        minHeap.push(tmp);
    }
    if(n!=minHeap.size()){
        cout << "error";
        return 0;
    }
    while(minHeap.size()>1){
        int tmp = 0;
        tmp += minHeap.top();
        minHeap.pop();
        tmp += minHeap.top();
        minHeap.pop();
        minHeap.push(tmp);
        res+=tmp;
    }
    cout<< res;

}