// 任务描述
// 本关任务：输入一个字符串（少于80个字符），去掉重复的字符后，按照字符的ASCII码值从大到小输出。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入一个字符串（少于80个字符），去掉重复的字符后，按照字符的ASCII码值从大到小输出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：ya7bb2tizx4m55n9q2
// 预期输出：
// zyxtqnmiba97542

#include <iostream>

int main()
{
    char origin[80];
    std::cin.getline(origin,80);
    int lenthOfString = 0;
    while (origin[lenthOfString] != '\0')
    {lenthOfString++;}
    char presentLargestChar = 127;
    bool test = true;
    while(test)
    {
        char presentchar = 0;
        int count = 0;
        for (int i = 1; i <= lenthOfString; i++)
        {
            if (origin[i - 1] < presentLargestChar && origin[i-1] > presentchar)
            {
                presentchar = origin[i - 1];
                count++;
            }
        }
        if (count == 0)
        {test = false;}
        else
        {
            std::cout<< presentchar;
            presentLargestChar = presentchar;
        }
    }
        
}