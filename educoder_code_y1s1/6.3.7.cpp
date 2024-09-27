// 任务描述
// 本关任务：设计函数fib，每调用一次就返回Fibonacci数列的下一个值，
// 即第一次调用返回1，第二次调用返回1，第三次调用返回2，第四次调用返回3……

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成fib函数，main函数已隐藏，不得使用全局变量。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：无
// 预期输出：
// 1
// 1
// 2
// 3
// 5
// 8
// 13
// 21
// 34
// 55

#include<iostream>
using namespace std;

int fib()
{
    static int m = 0,n = 1;
    int temp = n;
    // cout<< n << endl;
    n = m + temp;
    m = temp;
    return temp;
}
