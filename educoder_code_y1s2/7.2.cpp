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
        cin >> present;
        minHeap.push(present);
    }
    for(int i = 0; i < n; i++){
        present = minHeap.top();
        minHeap.pop();
        res[i] = present;
    }
    int tar;
    bool tell = false;
    cin >> tar;
    int rl,rh;
    for(int i = 0; (i < n-1)&&!tell; i++){
        int low = i+1, high = n-1,p;
        while(low<=high){
            p = (low+high)/2;
            if(res[p]+res[i]==tar){
                tell = true;
                rl = p;
                rh = i;
                break;
            }
            else if(res[p]+res[i]>tar){
                high = p-1;
            }
            else{
                low = p+1;
            }
        }
    }
    if(tell){
        cout << res[rl] << ' ' << res[rh];
    }
    else{
        cout << "null";
    }



    delete[]res;
}