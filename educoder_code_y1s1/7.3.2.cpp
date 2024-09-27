// 任务描述
// 本关任务：n个人围成一圈，按顺序从1到n编号。从第一个人开始报数1、2、3，报到3的人退出圈子，下一个人从1开始重新报数，报到3的人退出圈子。如此进行下去，直到留下最后一个人。当给定一个正整数n时，请问留下来的人的编号是多少？

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入一个正整数n，输出留下来的人的编号

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：4
// 预期输出：
// 1
#include <iostream>
using namespace std;

int main()
{    
    int nQuantity = 0,nStartPosition = 0,nPresentQuantity =1;
    cin>> nQuantity;
    while(nPresentQuantity < nQuantity){
        nPresentQuantity++;
        for(int i = 0; i < 3; i++){
            nStartPosition++;
            if(nStartPosition >= nPresentQuantity){
                nStartPosition -= nPresentQuantity;
            }
        }
    }
    cout<< nStartPosition + 1;
    return 0;
}