// 任务描述
// 本关任务：输入两个十进制正整数 n 和 base(2≤base≤16)，将 n 转换为 base 进制后输出。

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入两个十进制正整数 n 和 base(2≤base≤16)，将 n 转换为 base 进制后输出。大于十进制的 base 进制常用的是十六进制，在十六进制中，除了十进制中用到的 0-9 这十个数字外，还引入了A、B、C、D、E、F 来分别表示十进制的10、11、12、13、14、15。要求定义并调用函数 printInt(n,base)，它的功能是屏幕输出 n 的 base 进制表示

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：255 16
// 预期输出：
// FF

#include <iostream>

using namespace std;

void printInt(int num, int base);

int main(){
    int num = 0, base = 1;
    cin>> num >> base;
    printInt(num, base);
    return 0;
}

void printInt(int num, int base){
    int sequence = -1, buffer[1024] = {0};
    while(num != 0){
        sequence++;
        buffer[sequence] = num%base;
        num /= base;
    }
    for(int i = sequence; i >= 0; i--){
        if(buffer[i] < 10){
            cout<<buffer[i];
        }
        else{
            switch(buffer[i]){
                case 10:cout<<'A';break;
                case 11:cout<<'B';break;
                case 12:cout<<'C';break;
                case 13:cout<<'D';break;
                case 14:cout<<'E';break;
                case 15:cout<<'F';break;
            }
        }
    }
    return;
}