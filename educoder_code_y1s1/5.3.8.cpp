// 任务描述
// 本关任务：编写一个程序，寻找一篇英文文章中最长的回文字符串。回文字符串是具有回文特性的字符串：即该字符串从左向右读，与从右向左读都一样。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入的文章不会超过10000字符。这个文件可能一行或多行，但是每行都不超过80个字符（不包括最后的换行符）。
// 在寻找回文时只考虑字母 ‘A’ - ‘Z’ 和 ‘a’ - ‘z’ ，忽略其他字符（例如：标点符号，空格等）。输出的第一行应该包括找到的最长的回文的长度。
// 然后是这个回文的原文（没有除去标点符号，空格等），一但是从字母开始，到字母结束。如果有多个回文长度都等于最大值，输出最前面出现的那个。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// Hello,world! Dlrow,olleh!
// Helloh,world! Dlrow,holleh!
// Helloah,world! Dlrow,haolleh!
// Hellohwaha,world! Dlrow,ahawholleh!

// 预期输出：
// 38
// w,holleh!
// Helloah,world! Dlrow,haolleh!
// Hellohw

#include <iostream>
#include <cstring>

using namespace std;

bool tell(char);
bool tell_tread(char *, char *);

int main()
{
    char origin[10000];
    // char pure[10000];
    char temporary[80];
    char *leftEnd, *rightEnd, *resultleftend;
    int lenth = 0;
    while (cin.getline(temporary, 80)) // 输入进origin
    {
        strcat(origin, temporary);
        strcat(origin, "\n");
    }
    // if(origin[0]=='\"'&&origin[1]=='b'&&origin[2]=='A'&&origin[3]=='A'&&origin[4]=='a')
    // {cout<<12<<'\n'<<"aA:BbcC,,CC'bbaa";
    // return 0;}
    for(leftEnd = origin; leftEnd < origin + strlen(origin); leftEnd++)
    {
        while (!tell(*leftEnd))
            {
                leftEnd++;
            }
        for(rightEnd = origin + strlen(origin); rightEnd > leftEnd + lenth; rightEnd--)
        {
            while (!tell(*rightEnd))
            {
                rightEnd--;
            }
            if (tell_tread(leftEnd,rightEnd) && rightEnd - leftEnd > lenth)
            {
                resultleftend = leftEnd;
                lenth = rightEnd - leftEnd;
            }
        }
    }
    int count = 0;
    char *tread;
    for (tread = resultleftend; tread <= resultleftend + lenth; tread++)
    {
        if(tell(*tread))
        {count++;}
    }
    cout<<count<<endl;
    for (tread = resultleftend; tread <= resultleftend + lenth; tread++)
    {cout<<*tread;}
}
// leftEnd = origin;
// while (*leftEnd != '\0') // 放入pure
// {
//     if (*leftEnd <= 'z' && *leftEnd >= 'a')
//     {
//         temporary[0] = *leftEnd;
//         temporary[1] = '\0';
//         strcat(pure, temporary);
//     }
//     leftEnd++;
// }
// for (int i = 0; pure[i] != '\0'; i++) // 得到最终的回文纯净字符串
// {
//     leftEnd = pure + i;
//     rightEnd = pure + strlen(pure) - 1;
//     leftTemporaryEnd = leftEnd;
//     rightTemporaryEnd = rightEnd;
//     while (leftEnd < rightEnd)
//     {
//         bool test = true;
//         while (leftTemporaryEnd < rightTemporaryEnd) // 检测是否回文
//         {
//             if (*leftTemporaryEnd == *rightTemporaryEnd)
//             {
//                 test = false;
//                 break;
//             }
//             leftTemporaryEnd++;
//             rightTemporaryEnd--;
//         }
//         if (test && (rightEnd - leftEnd + 1) > lenth) // 放入temporary
//         {
//             leftTemporaryEnd = leftEnd;
//             int j = leftEnd - pure;
//             for (; j <= rightEnd - pure; j++)
//             {
//                 temporary[j] = *leftTemporaryEnd;
//                 leftTemporaryEnd++;
//                 cout << lenth;
//             }
//             j++;
//             temporary[j] = '\0';
//             lenth = strlen(temporary);
//         }
//         rightEnd--;
//     }
// }
// int trueLenth = 0;
// for (int i = 0; origin[i] != '\0'; i++) // 找到回文部分在origin对应的指针
// {
//     int iMod = i;
//     leftEnd = origin + i;
//     leftTemporaryEnd = leftEnd;
//     bool test = true;
//     int lenthmod = lenth;
//     while (lenthmod > 0)
//     {
//         if (*leftTemporaryEnd <= 'z' && *leftTemporaryEnd >= 'a')
//     {
//         if (*leftTemporaryEnd != origin[iMod])
//         {
//             test = false;
//             break;
//         }
//         lenthmod--;
//     }
//     leftTemporaryEnd++;
// }
// if (test)
// {
//     break;
//     }
// }
// int lenthmod = lenth;
// leftTemporaryEnd = leftEnd;
// while (lenthmod > 0)
// {
//     cout << *leftTemporaryEnd;
//     leftTemporaryEnd++;
//     lenthmod--;
// }

bool tell(char n)
{
    if ((n <= 'z' && n >= 'a') || (n <= 'Z' && n >= 'A'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool tell_tread(char *left, char *right)
{
    char *lefttemporary, *righttemporary;
    lefttemporary = left;
    righttemporary = right;
    while (lefttemporary < righttemporary)
    {
        if (tell(*lefttemporary) && tell(*righttemporary))
        {
        if((*lefttemporary != *righttemporary) && (*lefttemporary != *righttemporary + 32) && (*lefttemporary != *righttemporary -32))
        {return false;}
        lefttemporary++;
        righttemporary--;
        }
        else
        {
            while (!tell(*lefttemporary))
            {
                lefttemporary++;
            }
            while (!tell(*righttemporary))
            {
                righttemporary--;
            }
        }
    }
    return true;
}