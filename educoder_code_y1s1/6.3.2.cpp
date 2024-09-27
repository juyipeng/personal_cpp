// 任务描述
// 本关任务：完全数（perfect number），又称为完美数或完备数，是一些特殊的自然数。它所有的真因子（即除了自身以外的约数）的和，恰好等于它本身。例如：28是一个完全数，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加：1+2+4+7+14=28。编写程序，输入两个正整数m和n(1≤m≤n≤10000)，输出m ~ n之间（包含m和n）的所有完全数。如果m ~ n之间没有完全数，则输出-1

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入两个正整数m和n(1≤m≤n≤10000)，输出m ~ n之间（包含m和n）的所有完全数。如果m ~ n之间没有完全数，则输出-1。要求定义并调用函数 perfectNumber(n) 判断 n 是否是完全数。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：1 30
// 预期输出：
// 6 28
#include <iostream>

using namespace std;

bool isPerfect(int num);

int main(){
    int nFirst = 0, nLast = 0, nCount = 0;
    cin>> nFirst >> nLast;
    for(int i = nFirst; i <= nLast; i++){
        if(isPerfect(i)){
            nCount++;
            cout<< i << ' ';
        }
    }
    if(nCount==0){
        cout<< -1;
    }
    return 0;
}

bool isPerfect(int num){
    int sum = 0;
    for(int i = 1; i < num; i++){
        if(num%i==0){
            sum += i;
        }
    }
    if(sum == num){
        return true;
    }
    else{
        return false;
    }
}