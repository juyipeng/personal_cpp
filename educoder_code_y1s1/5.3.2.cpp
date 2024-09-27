// 任务描述
// 本关任务：输入一个字符串（少于80个字符），把字符串中所有的数字字符转换为整数，去掉其他字符。

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入一个字符串（少于80个字符），输出转换后的整数值的2倍（不考虑负值，不会超过int的范围）

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：pro56gr am93 m4in g
// 预期输出：
// 113868
// 输出说明：56934*2=113868
#include <iostream>

int main()
{
    char origin[80];
    std::cin.getline(origin,80);
    int number = 0;
    char presentChar = 'c';
    int i = 1;
    while (presentChar != '\0')
    {
        presentChar = origin[i-1];
        if(presentChar >= '0' && presentChar <= '9')
        {
            number *= 10;
            number += static_cast<int>(presentChar) - '0';
        }
        i++;    
    }
    std::cout<< number*2;
}