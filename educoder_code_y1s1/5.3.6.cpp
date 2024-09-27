// 任务描述
// 本关任务：编写一个程序，从键盘上输入一篇英文文章，统计出其中的英文字母（不区分大小写）、数字和其他非空白字符的个数。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户首先输入英文文章的行数n（1≤n≤10），接着依次输入n行内容（每行少于80个字符）。
// 要求统计出其中的英文字母（不区分大小写）、数字和其它非空白字符的个数。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// 6
// We focus on essay generation, which is a challenging 
// task that generates a paragraph-level text 
// with multiple topics. Progress towards understanding 
// different topics and expressing diversity in this 
// task requires more powerful generators and richer 
// training and evaluation resources.

// 预期输出：
// 英文字母：241
// 数字：0
// 其他字符：4

#include <iostream>

using namespace std;

int main()
{
    int lines = 0, letter = 0, number = 0, other = 0;
    cin>> lines;cin.get();
    char text[80];
    for (int i = 1; i <= lines; i++)
    {
        cin.getline(text,80);
        for (int j = 1; text[j - 1] != '\0'; j++)
        {
            int test = 
            ((text[j-1]<='z'&&text[j-1]>='a')||(text[j-1]<='Z'&&text[j-1]>='A'))*2 
            +(text[j-1]<='9'&&text[j-1]>='0')+(text[j-1]==' ')*3;
            switch(test)
            {
                case 1: number++;break;
                case 2: letter++;break;
                case 3: break;
                default: other++;
            }
        }
    }
    cout<<"英文字母："<<letter<<"\n数字："<<number<<"\n其他字符："<<other;
}