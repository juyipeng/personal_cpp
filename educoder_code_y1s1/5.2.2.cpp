// 任务描述
// 本关任务：A是一个n行n列的0-1矩阵(n<20)，每行的1都在0的前面，如何确定哪一行的1最多。

// 编程要求
// 根据提示，在右侧编辑器补充代码，先输入n，然后输入整个矩阵，输出1的个数最多的行的序号。如果有多行1的个数都是最多，输出序号最小的。思考一下如何提高程序执行效率。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// 3
// 1 1 0
// 1 1 1
// 1 0 0
// 预期输出：
// 1
// 输出说明：由于第一行有3个1，在所有的行中最多

#include <iostream>

using namespace std;

int main()
{
    int nScale = 0, nResult = 0, nLargest = 0;
    int nBuffer[20][20] = {0};
    cin>> nScale;
    for (int i = 0; i < nScale; i++)
    {
        for(int j = 0; j < nScale; j++)
        {
            cin>>nBuffer[i][j];
        }
    }
    for (int i = 0; i < nScale; i++)
    {
        int nCount = 0;
        for(int j = 0; j < nScale; j++)
        {
            if (nBuffer[i][j]==1)
            {
                nCount++;
            }
            else{}
        }
        if (nCount > nLargest)
        {
            nResult = i;
            nLargest = nCount;
        }
        else{}
    }
    cout<< nResult;
}