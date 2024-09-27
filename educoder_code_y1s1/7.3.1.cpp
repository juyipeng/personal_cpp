// 任务描述
// 本关任务：设计一个程序，让用户输入一行句子，数出句子中有多少个单词并输出，再让用户输入一串数字表示单词重新排序的顺序，最后按用户设定的顺序来输出一行新的句子。要求所有数组都只能用new来定义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户输入的句子里只包含字母和空格（句子末尾没有空格），以回车完成输入，该句子最多100个字符，句子里最多10个单词。用户输入的一串数字是正常表示单词顺序的，不用考虑异常情况。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
/*
This is a good day to work
6543210
*/
// 预期输出：
// 7
// work to day good a is This
#include <iostream>
using namespace std;

int main()
{    
    char **cSpace = new char*[10];
    char *buffer = new char[100];
    cin.getline(buffer,100);
    int nLetterQuantity = 0, nSequence = 0;
    while(*(buffer+nSequence)!=0){
        *(cSpace+nLetterQuantity)=new char[100];
        int i = 0;
        while(*(buffer+nSequence)!=' '&&*(buffer+nSequence)!=0){
            *(*(cSpace+nLetterQuantity)+i) = *(buffer+nSequence);
            ++nSequence;
            ++i;
        }
        *(*(cSpace+nLetterQuantity)+i) = 0;
        if(*(buffer+nSequence)==' '){
            nSequence++;
        }else{}
        ++nLetterQuantity;
    }
    int *nOrder = new int[nLetterQuantity];
    for(int i = 0; i < nLetterQuantity; i++){
        *(nOrder+i)=cin.get()-'0';
    }
    cout<< nLetterQuantity << '\n';
    for(int i = 0; i < nLetterQuantity-1; i++){
        cout<< *(cSpace+*(nOrder+i)) << ' ';
    }
    cout<< *(cSpace+*(nOrder+nLetterQuantity-1));

    delete[]buffer;
    for(int i = nLetterQuantity; i>0; i--){
        delete [] *(cSpace+i-1);
    }
    delete[] nOrder;
    delete[]cSpace;
    return 0;
}