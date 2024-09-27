// 任务描述
// 本关任务：编写一个带有两个double参数的函数，计算这两个参数的谐均值。
// 两数值的谐均值可以这样计算：首先对两数值的倒数取平均值，最后再取倒数。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数calculate，main函数已隐藏，其功能是先输入测试样例数t，
// 然后输入t组输入，程序依次输出t个谐均值。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：2 3 4 6.5 3.8
// 预期输出：
// 3.429
// 4.796

#include <iostream>

using namespace std;

double calculate(double x,double y)
{
    double dResult = 2/((1/x)+(1/y));
    return dResult;

}
