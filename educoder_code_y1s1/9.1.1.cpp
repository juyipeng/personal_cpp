/*
pengjuyi 2023.12.8 version1.0
*/
#include <iostream>
#include <cstdio>

using namespace std;

void showOption(){
    cout<<"欢迎使用股票分析系统："<<endl;
    cout<<"1--输入股票价格序列"<<endl;
    cout<<"2--查询股票价格"<<endl;
    cout<<"3--输出升序的股票价格序列"<<endl;
    cout<<"4--输出最大值和最小值的日期"<<endl;
    cout<<"5--一笔交易的最大利润"<<endl;
    cout<<"6--多笔交易的最大利润"<<endl;
    cout<<"7--退出"<<endl;
}

// Your code here
int input(int space[]){
    int nQuantity = 0, price = 0;
    while(price != -1){
        cin >> price;
        if(price != -1){
            space[nQuantity] = price;
            nQuantity++;
        }
    }
    return nQuantity;
}

void printall(int space[], int nQuantity){
    for(int i = 0; i < nQuantity; i++){
        cout << space[i] << ' ';
    }
    cout<<endl;
}

void printsorted(int space[], int nQuantity){
    bool bTest = true;
    int nLastPrice = -1, nTmp = 0;
    while(bTest){
        bTest = false;
        nTmp = 999;
        for(int i = 0; i < nQuantity; i++){
            if((space[i]>nLastPrice)&&(space[i]<nTmp)){
                nTmp = space[i];
            }
        }
        nLastPrice = nTmp;
        for(int i = 0; i < nQuantity; i++){
            if(space[i]==nTmp){
                cout << space[i] << ' ';
                bTest = true;
            }
        }
    }
    cout<<endl;
}

void printends(int space[], int nQuantity){
    int largest = 0; int smallest = 1024;
    for(int i = 0; i < nQuantity; i++){
        if(space[i]<smallest){smallest = space[i];}
        if(space[i]>largest){largest = space[i];}
    }
    for(int i = 0; i < nQuantity; i++){
        if(space[i]==smallest){
            cout << i << ' ';
            break;
        }
    }
    for(int i = 0; i < nQuantity; i++){
        if(space[i]==largest){
            cout << i;
            break;
        }
    }
    cout << endl;
}

void printonce(int space[], int nQuantity){
    int res = 0;
    for(int i = 0; i < nQuantity-1; i++){
        for(int j = i+1; j < nQuantity; j++){
            if(space[j]-space[i]>res){
                res = space[j]-space[i];
            }
        }
    }
    // int nRes = -1024, nTmpRes = -1024;
    // for(int i = 0;i < nQuantity-1; i++){
    //     if(space[i]>space[i+1]){
    //         nTmpRes = -1024;
    //     }
    //     else{
    //         if(nTmpRes!=-1024){
    //             nTmpRes += space[i+1]-space[i];
    //         }
    //         else{
    //             nTmpRes = space[i+1]-space[i];
    //         }
    //     }
    //     if(nTmpRes>nRes){
    //         nRes = nTmpRes;
    //     }
    // }

    // if(res>0){
        cout<<res<<endl;
    //     }
    // else{
    //     cout<<"NO interests!";
    // }
}

void printtotal(int space[], int nQuantity){
    int res = 0;
    for(int i = 0; i < nQuantity-1; i++){
        if(space[i+1]>space[i]){
            res += space[i+1] - space[i];
        }
    }
    cout << res << endl;;
}

int main()
{
    int space[1024] = {0}, nCntrloprtr = 0, nQuantity = 0;
    bool bTest = true;
    showOption();
    // Your code here
    while(bTest){
        cin >> nCntrloprtr;
        switch(nCntrloprtr){
            case 1:
            nQuantity = input(space);
            break;
            case 2:
            printall(space, nQuantity);
            break;
            case 3:
            printsorted(space, nQuantity);
            break;
            case 4:
            printends(space, nQuantity);
            break;
            case 5:
            printonce(space, nQuantity);
            break;
            case 6:
            printtotal(space, nQuantity);
            break;

            case 7:
            bTest = false;
        }
    }

    return 0;
}