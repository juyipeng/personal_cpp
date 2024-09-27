// 任务描述
// 本关任务：输入只包含小写字母的非空字符串，求最长无重复字母的字符串的长度

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入只包含小写字母的非空字符串，长度小于100，寻找没有重复字母的子串，求这一类子串的最大长度并输出

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：abcabcbb
// 预期输出：
// 3
// 输出说明：子串abc长度为3

#include <iostream>

using namespace std; 

int main()
{
    char cSpace[100] = {0};
    cin.get(cSpace, 100);
    int nLength = 0;
    for (int nLeft = 0; cSpace[nLeft] != '\0'; nLeft++)
    {
        bool bTest = true;
        int nRight = nLeft;
        for(; cSpace[nRight] != '\0' && bTest; nRight++)
        {
            for(int i = nLeft; i < nRight; i++)
            {
                if(cSpace[i]==cSpace[nRight])
                {
                    bTest = false;
                    break;
                }
            }
        }
        if(nRight - nLeft -1 > nLength)
        {
            nLength = nRight - nLeft - 1;
        }
    }
    cout<< nLength;
}