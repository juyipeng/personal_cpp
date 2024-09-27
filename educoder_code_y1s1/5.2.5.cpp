// 任务描述
// 本关任务：对于一个给定的有序数组，求出目标值x在该数组中第一次和最后一次出现的位置

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户先输入n，然后输入一个规模为n的有序数组，再输入目标值下，求出目标值x在该数组中第一次和最后一次出现的位置，如果x未出现在数组中，输出两个-1。请尽量提高计算效率。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：6 5 7 7 8 8 10 8
// 预期输出：
// 3 4
// 输出说明：数组为{5,7,7,8,8,10}

/*
@brief 求数组中目标值首次和最后一次出现的位置
*/
#include <iostream>

using namespace std;

int main()
{
    int nScale = 0, nSpace[1024] = {0}, nLeft = 0, nRight = 0, nPresent = 0;
    cin>> nScale;
    for (int i = 0; i < nScale; i++)
    {
        cin>> nSpace[i];
    }
    cin>>nPresent;
    while(nSpace[nLeft]!=nPresent && nLeft<nScale)
    {nLeft++;}
    nRight = nScale - 1;
    while(nSpace[nRight]!=nPresent && nRight > -1)
    {nRight--;}
    if (nRight == -1)
    {
        nLeft = -1;
    }
    
    cout<<nLeft<<' '<<nRight;
}