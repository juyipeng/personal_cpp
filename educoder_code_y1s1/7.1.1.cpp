// 任务描述
// 本关任务：Julian历法是用年以及这一年中的第几天来表示日期。设计一个函数，将Julian历法表示的日期转换成月和日，
// 如Mar 8（注意闰年的问题）。函数返回一个字符串，即转换后的月和日。
// 如果参数有错，如天数为第370天，返回NULL指针，此时屏幕无打印输出。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入年份和天数，输出转换后的月和日。
// 如果参数有错，如天数为第370天，返回NULL指针，此时屏幕无打印输出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// 1998
// 33
// 预期输出：
// Feb 2

#include <iostream>
#include <cstring>
using namespace std;

char* julian(int year,int day){
    if(day <= 0){
        return NULL;
    }
    int nRun = (year%4==0)-(year%100==0)+(year%400==0);
    int nMonth = 1;
    int nDays[12] = {31,28+nRun,31,30,31,30,31,31,30,31,30,31};
    while(day > nDays[nMonth-1]){
        day -= nDays[nMonth-1];
        ++nMonth;
        if(nMonth>12){
            return NULL;
        }
    }
    char* result = new char[1];
    *result = '\0';
    switch (nMonth)
    {
    case 1:strcat(result,"Jan ");break;
    case 2:strcat(result,"Feb ");break;
    case 3:strcat(result,"Mar ");break;
    case 4:strcat(result,"Apr ");break;
    case 5:strcat(result,"May ");break;
    case 6:strcat(result,"Jun ");break;
    case 7:strcat(result,"Jul ");break;
    case 8:strcat(result,"Aug ");break;
    case 9:strcat(result,"Sept ");break;
    case 10:strcat(result,"Oct ");break;
    case 11:strcat(result,"Nov ");break;
    case 12:strcat(result,"Dec ");break;
    default:
        break;
    }
    char temp[3];
    temp[0] = '0'+day/10;
    temp[1] = '0'+day%10,'\0';
    strcat(result,temp);
    return result;
}

int main()
{
    int year,day;
    char* res;
    cin>>year>>day;
    res=julian(year,day);
    cout<<res<<endl;
    delete []res;
    return 0;
}