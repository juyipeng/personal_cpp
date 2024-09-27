// 任务描述
// 本关任务：编写函数模板maxmin，可以输出数组中最大数和最小数

// 编程要求
// 根据提示，在右侧编辑器补充代码，输出数组中最大数和最小数。不要修改main函数。输出格式为:
// 整型数组最大值 最小值
// 浮点数组最大值 最小值

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// 4
// 1 2 3 4
// 5
// 5.1 4.2 3.3 2.4 1.5
// 输入说明：第一行为整型数组规模，第二行为整型数组内容，第三行为浮点型数组规模，第四行为浮点型数组内容
// 预期输出：
// 4 1
// 5.1 1.5

#include <iostream>
using namespace std;

//你的代码

template <class T>
void maxmin(T* tArray, int quantity){
    T max = *(tArray), min = *(tArray);
    for (int i = 1; i < quantity; i++){
        if(*(tArray+i) < min){
            min = *(tArray+i);
        }
        if(*(tArray+i) > max){
            max = *(tArray+i);
        }
    }
    cout<< max << ' ' << min <<endl;
    return;
}


int main()
{
    int m, n;
    int arr_int[10000];
    double arr_double[10000];
    
    // 输入m和整型数组
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> arr_int[i];
    
    // 输入n和浮点型 数组
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr_double[i];
    // 输出结果
    maxmin(arr_int, m);
    maxmin(arr_double, n);
    return 0;
}
