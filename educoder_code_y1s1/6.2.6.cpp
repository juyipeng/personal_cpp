#include<iostream>
using namespace std;

void merge(int* low, int* mid, int* high){
    int buffer[100] = {0};
    bool btest1 = true, btest2 = true;
    int i = 0, j = 0, t = 0;
    while(i<=mid-low || j<=high-mid-1){
        if((j>high-mid-1)||((i<=mid-low && j<=high-mid-1)&&(*(low+i)<*(mid+1+j)))){
            buffer[t] = *(low+i);
            i++; 
        }
        else{
            buffer[t] = *(mid+1+j);
            j++;
        }
        t++; 
    }
    for(i = 0; i+low<=high; i++){
        *(low+i) = buffer[i];
    }
}

void merge_Sort(int* low, int* high){
    if (low>=high){
        return;
    }
    else{
        int* mid = low+(high-low)/2;
        merge_Sort(low,mid);
        merge_Sort(mid+1,high);
        merge(low,mid,high);
        return;
    }
}

int main(){
    int n, num[100];
    cin>>n;
    for(int i = 0; i<n;i++){
        cin>>num[i];
    }
    merge_Sort(num,num+n-1);
    for(int i = 0; i<n;i++){
        cout<<num[i]<<' ';
    }
    return 0;
}