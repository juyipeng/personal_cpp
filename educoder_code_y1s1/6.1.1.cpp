// 任务描述
// 本关任务：编写一个求n!的函数，并用于求从n个数中取m个数的组合数（m<=n<=14）。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入n和m，输出组合数。不用考虑溢出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：4 1
// 预期输出：
// 4

#include <iostream>

using namespace std;

int Factorial(int nNum);

int main(){
    int nN = 0, nM = 0;
    cin>> nN >> nM;
    int nResult;
    nResult = Factorial(nN)/Factorial(nM)/Factorial(nN - nM);
    cout<< nResult;
}

int Factorial(int nNum){
    int nFactorial = 1;
    for (int i = 1; i <= nNum; i++){
        nFactorial *= i;
    }
    return nFactorial;
}