// 任务描述
// 本关任务：实现cstring库的函数strrchr

// 编程要求
// 根据提示，在右侧编辑器补充代码，strrchr第一个参数为输入字符串，第二个参数为要查找的字符。返回一个指针，指向被查找的字符串在字符串中最后出现的位置。如果没有出现，返回空指针。字符串最大长度50。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// asdfgfdsa
// f
// 预期输出：
// fgfdsa

// 测试输入：
// asdgdsa
// f
// 预期输出：
// no

#include <iostream>

using namespace std;

char* fakestrchr(char*,char);

int main(){
    char *cstr = new char[51];
    cin.getline(cstr,51);
    char cToFind = cin.get();
    char *result = fakestrchr(cstr,cToFind);
    if(result){
        cout<< result;
    }
    else{
        cout << "no";
    }

    delete [] cstr;
}

char* fakestrchr(char* cstr, char cToFind){
    char* result = NULL;
    for(int i = 0; *(cstr+i) != 0; i++){
        if(*(cstr+i)==cToFind){
            result = cstr+i;
        }
    }
    return result;
}