/*
任务描述
本关任务：根据如下插入排序基本思想编程，对整数数组排序：

一个数显然是有序的，因此规模为1的排序问题能够求解；
如果能够为n-1个数排序，那么当有n个数时，只需先将前n-1个数排好序，再将最后一个数插入前面这n-1个有序数列中的合适位置即可
这样我们就得到了插入排序算法。

例如要对3，6，2，4从小到大排序

考虑规模为1的问题，即数字3，一个数显然是有序的
规模为1的问题求解完毕后，加入新的数字6，将其放在3后面，得到序列3，6，从而解决了规模为2的问题
规模为2的问题求解完毕后，加入新的数字2，将其放在3前面，得到序列2，3，6，从而解决了规模为3的问题
规模为3的问题求解完毕后，加入新的数字4，将其放在2和3中间，得到序列2，3，4，6，从而解决了规模为4的问题，排序过程结束。

编程要求
根据提示，在右侧编辑器补充代码，输入包含一个表示元素数量的正整数n（0<n<=100)和n个整数（int取值范围内），输出排序后的元素，数字之间用空格分隔

测试说明
平台会对你编写的代码进行测试：

测试输入：3 3 2 -1
预期输出：
-1 2 3
*/

#include <iostream>

using namespace std;

int PutOff(int *, int *, int);

int main()
{
    int nScale = 0, nSpace[100] = {0}, nPresent = 0;
    cin >> nScale;
    for (int i = 0; i < nScale; i++)
    {
        cin >> nPresent;
        int *pnTmp = nSpace;
        while (*pnTmp < nPresent && pnTmp < nSpace + i)
        {
            pnTmp++;
        }
        PutOff(nSpace, pnTmp, i);
        *pnTmp = nPresent;
    }
    for(int i = 0; i < nScale; i++)
    {
        cout<< nSpace[i]<< ' ';
    }
}

int PutOff(int *pnStart, int *pnPresent, int nLenth)
{
    for (int *tmp = pnStart + nLenth; tmp > pnPresent; tmp--)
    {
        *tmp = *(tmp - 1);
    }
    return 0;
}