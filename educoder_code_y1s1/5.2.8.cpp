// 任务描述
// 本关任务：5*5的格子中，每个格子代表一盏灯，点击一次，此格子和上下左右相邻的共5个格子中的灯的状态会发生反转，
// 亮着的会熄灭，熄灭的会点亮。
// 如何用最少的点击次数使所有的灯都点亮？（亮灯用1表示，熄灭状态用0表示）

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入五行，每行五个数值(0或1)，表示当前格子的状态。
// 输出对于输入数据中对应的当前状态最少需要几步才能使25个格子都变亮。
// 如果不能使25个格子都变亮，输出-1。尽量提高计算效率。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：a = 5*i + j
// 00111
// 01011
// 10001
// 11010
// 11100
// 预期输出：
// 3
// 输出说明：点击(0,0)，（2,2）和（4,4）

#include <iostream>

using namespace std;

int click(int*,int);

int main(){
    bool bTest = false;
    int nSpace[25] = {0};
    for(int i = 0; i < 5; i++){//输入状态值
            for(int j = 0; j < 5; j++){
                nSpace[5*i + j] = cin.get() - '0';
            }
            cin.get();
        }
    int nResult = 25;
    for(int a1 = 0; a1 <= 1; a1++){
        for(int a2 = 0; a2 <= 1; a2++){
            for(int a3 = 0; a3 <= 1; a3++){
                for (int a4 = 0; a4 <= 1; a4++){
                    for (int a5 = 0; a5 <= 1; a5++){
                        int nClickCount = 0;
                        int spacemod[25];
                        for (int i = 0; i < 25; i++){//set spacemod
                            spacemod[i] = nSpace[i];
                        }
                        if(a1==1){click(spacemod, 0);nClickCount++;}
                        if(a2==1){click(spacemod, 1);nClickCount++;}
                        if(a3==1){click(spacemod, 2);nClickCount++;}
                        if(a4==1){click(spacemod, 3);nClickCount++;}
                        if(a5==1){click(spacemod, 4);nClickCount++;}
                        for(int i = 1; i < 5; i++){
                            for(int j = 0; j < 5; j++){
                                if(spacemod[5*(i-1)+j]==0){
                                    click(spacemod, 5*i+j);
                                    nClickCount++;
                                }
                            }
                        }
                        if(spacemod[20]+spacemod[21]+spacemod[22]+spacemod[23]+spacemod[24]==5){
                            bTest = true;
                            if(nClickCount < nResult){
                                nResult = nClickCount;
                            }
                        }
                    }
                }
            }
        }
    }
    if(bTest){
        cout<< nResult;
    }
    else{
        cout<< -1;
    }
}

int click(int* array, int sequence){//sequence = 5*j+i
    *(array + sequence) = (*(array + sequence)==0?1:0);
    if(sequence % 5 > 0){
        *(array + sequence - 1) = (*(array + sequence - 1)==0?1:0);
    }
    if(sequence % 5 < 4){
         *(array + sequence + 1) = (*(array + sequence + 1)==0?1:0);
    }
    if(sequence >= 5){
         *(array + sequence - 5) = (*(array + sequence - 5)==0?1:0);
    }
    if(sequence <= 19){
         *(array + sequence + 5) = (*(array + sequence + 5)==0?1:0);
    }
    return 0;
}