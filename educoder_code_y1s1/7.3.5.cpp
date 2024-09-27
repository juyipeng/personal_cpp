// 任务描述
// 本关任务：写一个函数getDate，从键盘读入一个形如dd-mmm-yy的日期。
// 其中dd是一个1位或2位的表示日的整数，mmm是月份的3个字母的缩写，yy是两位数的年份。
// 函数读入这个日期，并将它们以数字形式传给3个参数。

// 编程要求
// 根据提示，在右侧编辑器补充代码，函数读入日期，并将它们以数字形式传给3个参数。假设输入的日期总是合法的

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：5-Mar-18
// 预期输出：
// 5 3 18
#include <iostream>
using namespace std;

void getDate(int&,int&,int&);

int main()
{
    int day, month, year;
    getDate(day, month, year);
    cout << day <<" "<< month<<" " << year << endl;
    return 0;
}

void getDate(int&day,int&month,int&year){
    char *cBuffer = new char[10];
    cin>> cBuffer;
    bool even = false;
    if(*(cBuffer+2)=='-'){
        even = true;
        day = *(cBuffer+1) + *cBuffer*10 - 11*'0';
    }
    else{
        day = *cBuffer - '0';
    }
    switch (*(cBuffer+2+even)+*(cBuffer+3+even)+*(cBuffer+4+even)){
        case 'J'+'a'+'n': month = 1;break;
        case 'F'+'e'+'b': month = 2;break;
        case 'M'+'a'+'r': month = 3;break;
        case 'A'+'p'+'r': month = 4;break;
        case 'M'+'a'+'y': month = 5;break;
        case 'J'+'u'+'n': month = 6;break;
        case 'J'+'u'+'l': month = 7;break;
        case 'A'+'u'+'g': month = 8;break;
        case 'S'+'e'+'p': month = 9;break;
        case 'O'+'c'+'t': month = 10;break;
        case 'N'+'o'+'v': month = 11;break;
        case 'D'+'e'+'c': month = 12;break;
        default:break;
    }
    year = *(cBuffer+6+even)*10+*(cBuffer+7+even) - 11*'0';


    delete [] cBuffer;
}