// 任务描述
// 本关任务：把右侧代码中的两个函数main和func填补完整，使得该程序能判断用户输入的一个正整数是否为回文数（即顺读和倒读相同的数）。

// 编程要求
// 根据提示，在右侧编辑器补充代码，判断用户输入的一个正整数是否为回文数。注意以下要求：
// 1：只能在“此处填补几行代码”的位置添加代码。
// 2：不可定义新的变量、数组或其它对象。不可使用循环。
// 3：func函数的定义中不可调用库函数。
// 4：用户的输入必定为一串数字（少于20个字符），以回车完成输入。
// 5：填补部分的代码总共不超过10行（分号和逗号合计不超过10个）。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：338909833
// 预期输出：
// Yes

// 测试输入：378909833
// 预期输出：
// No
#include <iostream>
#include <cstring>
using namespace std;

bool func(char array[ ], int len) {
	//此处填补几行代码
    for(int i = 0; i <= (len-1)/2; i++){
        if(array[i]!=array[len-1-i]){
            return false;
        }
    }
    return true;
}


int main() {
    char ch[20];
    bool result;

    cin >> ch;

	//此处填补几行代码
    int i;
    while(ch[i]!=0){i++;}
    if(func(ch,i)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}