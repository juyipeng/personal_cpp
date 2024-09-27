// 任务描述
// 本关任务：写出所给代码中的两个函数funA和funB的声明与定义，使得funA(p)=a能实现通过指针p访问用户输入的字符串a，funB能将该字符串中的小写字母全部变成大写，并返回这个大写的字符串。

// 编程要求
// 根据提示，在右侧编辑器补充代码，除了实现funA和funB外，不能修改包括main函数在内的其他代码，不能在全局定义新的变量、指针、数组和函数等，不能调用其他的库。
// funA和funB内不能调用任何输入输出函数（包含但不限于cin,cout,scanf,prinf,getchar,putchar等等）。
// 不允许存在内存泄漏，由于EC不能检测内存泄漏(同学们可以自行了解内存泄漏检测工具valgrind)，助教将进行手动评测（以最后一次提交为准）。
// 每个测试用例有三行，每行对应一个字符串，长度不超过98，而且只含有小写和大写字母。
// 输出有三行，将输入转化为大写后，按顺序输出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
/*
ieee
tryAtry
acisOK
*/
// 预期输出：
// IEEE
// TRYATRY
// ACISOK
#include <iostream>
#include <cstring>
using namespace std;

char*&funA(char**&);
char*funB(char*,char**);

int main() 
{
    char a[100], b[100];
    for(int i = 0; i < 3; ++i) 
    {
        char **p;
        cin >> a;
        funA(p) = a;
        cout << funB(b, p) << endl;
    }
    return 0;
}

// 写出两个函数的定义
char* &funA(char **&p){
    p = new char*;
    return *p;
}

char* funB(char*b,char**p){
    char temp = 0;
    int i;
    for(i = 0; *(*p+i)!=0; i++){
        if(*(*p+i)>='a'&&*(*p+i)<='z'){
            temp = *(*p+i)-32;
        }
        else{
            temp = *(*p+i);
        }
        b[i] = temp;
    }
    b[i] = 0;
    
    delete p;


    return b;
} 