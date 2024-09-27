// 任务描述
// 本关任务：修改ppt中分治法求最大最小数的程序，使之能够求最大和第二大数，同时还要求尽量节约空间

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户先输入元素个数n(n>2)，然后依次输入这n个整数，输出其中最大和第二大数

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：5 4 -3 2 5 1
// 预期输出：
// 5 4

// 测试输入：5 5 -3 2 5 1
// 预期输出：
// 5 5

#include <iostream>

using namespace std;

int main(){
    int nQuantity = 0,nTemp, nLargest = -2147483647, nSecondLargest = -2147483647;
    cin>> nQuantity;
    for(int i = 0; i < nQuantity; i++){
        cin >>nTemp;
        if(nTemp > nLargest){
            nSecondLargest = nLargest;
            nLargest = nTemp;
        }
        else if(nTemp > nSecondLargest && nTemp <= nLargest){
            nSecondLargest = nTemp;
        }
        else{}
    }
    cout << nLargest << ' ' << nSecondLargest;
}