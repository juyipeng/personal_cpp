// 任务描述
// 本关任务：输入两个字符串str1和str2，查找str2在str1里首次出现的位置。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入两个字符串str1和str2，每个字符串是一行，查找str2在str1里首次出现的位置。如果str2在str1中不存在，则输出-1。
// 注意：（1）每一行不超过160个字符，可以包含任意字符；（2）不使用字符串比较的库函数。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// To be, or not to be: that is the question, 
// To
// 预期输出：
// 0
#include <iostream>

using namespace std;

int main ()
{
    char str1[160], str2[160];
    cin.getline(str1,160);
    cin.getline(str2,160);
    int count = 0;
    for (int i = 1; str1[i - 1] != '\0'; i++)
    {
        bool test = false;
        if (str1[i - 1] == str2[0])
        {
            test = true;
            for (int j = 1; str2[j - 1] != '\0'; j++)
            {
                if (str2[j - 1] != str1[i + j - 2])
                {test = false;}
            }
            if (test)
            {
                count++;
                cout<<i - 1;
                break;
            }
        }
    }
    if (count == 0){cout<< -1;}
}