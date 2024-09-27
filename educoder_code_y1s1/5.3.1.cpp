// 任务描述
// 本关任务：在矩阵中，一个元素在所在行中是最大值，在所在列中是最小值，则被称为鞍点（Saddle point）。求所给矩阵的鞍点

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入两个正整数 m 和 n（m，n≤10），然后输入该 m 行 n 列矩阵 mat 中的元素，如果找到 mat 的鞍点，就输出它的下标；
// 如果找到多个鞍点，则分行输出它们的下标（行下标小的鞍点优先输出）；否则，输出“Not Found”。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：3 3 5 1 2 1 1 1 2 1 5
// 预期输出：
// mat[1][0]=1
// mat[1][1]=1
// mat[1][2]=1

#include <iostream>

using namespace std;

int main()
{
    int matrix[10][10] = {0};
    int m = 0, n = 0;
    cin>> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>> matrix[i-1][j-1];
        }
    }
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bool test = true;
            for (int s = 1; s <= m; s++)
            {
                if (matrix[s-1][j-1]<matrix[i-1][j-1])
                {test = false;}
            }
            for (int s = 1; s <= n; s++)
            {
                if (matrix[i-1][s-1]>matrix[i-1][j-1])
                {test = false;}
            }
            if (test)
            {
                cout<<"mat["<<i-1<<"]["<<j-1<<"]="<<matrix[i-1][j-1]<<endl;
                count++;
            }
        }
    }
    if (count == 0)
    {cout<<"Not Found";}
}