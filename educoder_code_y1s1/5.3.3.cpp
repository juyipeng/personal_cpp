// 任务描述
// 本关任务：输入一个字符串（少于80个字符），统计并输出其中元音字母（AEIOUaeiou）的个数（不区分大小写）。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入一个字符串（少于80个字符），统计并输出其中元音字母（AEIOUaeiou）的个数

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：I have an apple
// 预期输出：
// 6

#include <iostream>

using namespace std;

int main()
{
    char origin[80];
    cin.getline(origin,80);
    char *charTread;
    charTread = origin;
    int result = 0;
    while(*charTread != '\0')
    {
        if (*charTread == 'a' 
        || *charTread == 'e'
        || *charTread == 'i'
        || *charTread =='o'
        || *charTread =='u'
        || *charTread =='A'
        || *charTread =='E'
        || *charTread =='I'
        || *charTread =='O'
        || *charTread =='U'
        )
        {result++;}
        charTread++;
    }
    cout<< result;
}