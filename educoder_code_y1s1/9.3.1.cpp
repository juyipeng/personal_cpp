/*
@pengjuyi 
@2023_12_9 
@version_1_0
*/
#include <iostream>
#include <cstring>

using namespace std;

void showOption(){
    cout<<"欢迎来到Logo绘制系统："<<endl;
    cout<<"1--笔向上"<<endl;
    cout<<"2--笔向下"<<endl;
    cout<<"3--左转"<<endl;
    cout<<"4--右转"<<endl;
    cout<<"5 n--前进n格（n为正整数）"<<endl;
    cout<<"6--打印20*20数组"<<endl;
    cout<<"9--数据结束（标记）"<<endl;
}

// Your code here
void printTotal(bool bSpace[][20]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j <20; j++){
            if(bSpace[i][j]){
                cout << '*';
            }
            else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main()
{
    // enum Direction{RIGHT, UP, LEFT, DOWN};
    // Your code here
    bool bTrace = false, bSpace[20][20] = {0};//VerticalSite:i_HorizentalSite:j_[i][j]
    int nCntrloprtr = 0, nX = 0, nY = 0, nDirection = 0, lenth = 0;
    showOption();
    while(nCntrloprtr!=9){
        cin>>nCntrloprtr;
        switch(nCntrloprtr){
            case 1:
            bTrace = false;
            nDirection = 1;
            break;
            case 2:
            bTrace = true;
            nDirection = 3;
            // bSpace[nY][nX] = true;
            break;
            case 3:
            nDirection = (nDirection+1)%4;
            break;
            case 4:
            nDirection = (nDirection+3)%4;
            break;
            case 5:
            cin >> lenth;
            switch(nDirection){
                case 0:
                for(int i = 0; i < lenth; i++){
                    nX++;
                    if(bTrace){bSpace[nY][nX] = true;}
                }
                break;
                case 1:
                for(int i = 0; i < lenth; i++){
                    nY--;
                    if(bTrace){bSpace[nY][nX] = true;}
                }
                break;
                case 2:
                for(int i = 0; i < lenth; i++){
                    nX--;
                    if(bTrace){bSpace[nY][nX] = true;}
                }
                break;
                case 3:
                for(int i = 0; i < lenth; i++){
                    nY++;
                    if(bTrace){bSpace[nY][nX] = true;}
                }
                break;                
            }
            break;
            case 6:
            printTotal(bSpace);
            break;
            defaut:
            break;
        }
    }


    return 0;
}
