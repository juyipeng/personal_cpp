// 任务描述
// 本关任务：编写一个函数oddstr，将一个字符串奇数位置的字符构成一个字符串

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入一个长度小于200的字符串，main函数通过调用oddstr得到该字符串奇数位置的字符构成的字符串，然后输出新的字符串

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：123456
// 预期输出：
// 246
#include <iostream>
using namespace std;

char* oddstr(char* cstr){
    char *result = new char[110];
    for(int i = 1; (*(cstr+i)!=0)&&(*(cstr+i-1)!=0); i+=2){
        *(result+i/2) = *(cstr+i);
    }
    return result;
}

int main() {
    char str[200];
    cin >> str;
    char *odd = oddstr(str);
    cout << odd << endl;
    delete []odd;
    return 0;
}
