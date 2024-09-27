// 任务描述
// 本关任务：编写一个程序，能够将所给字符串奇数位置的字符重新构成一个新的字符串并输出。

// 编程要求
// 根据提示，在右侧编辑器补充代码，首先输入一个字符串（少于80个字符），将此字符串奇数位置的字符构成一个新的字符串并输出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：123456
// 预期输出：
// 246

#include <iostream>

using namespace std;

int main()
{
    char cBuffer[80] = {0};
    cin.get(cBuffer,80,'\n');
    for(int i = 1; cBuffer[i]!= '\0' && cBuffer[i-1] != '\0';i+=2)
    {
        cout<<cBuffer[i];
    }
    return 0;
}