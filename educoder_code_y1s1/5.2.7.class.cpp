// 任务描述
// 本关任务：在一个长度为L米的平台上，放着N个质量相同的小球，每个小球的初始速度都为1m/s，
// 小球的运动方向按照摆上去的顺序间隔着向左或者向右，第一个摆上去小球的运动方向向右。
// 我们认为小球的体积很小，碰撞满足动量守恒定律，且发生完全弹性碰撞，碰撞不发生能量损失，碰撞的时间非常短暂可以忽略。
// 问平台上的第一个和最后一个掉落的小球分别是在什么时候掉下去的。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户首先输入2个整数，表示小球的数量N(<10000)和平台的长度L。然后输入N个整数，
// 分别表示小球在平台上的位置，按照小球摆上去的顺序给出，平台的左端点位置为0，右端点位置为L。
// 保证开始的时候没有两个小球在一个位置。输出两个整数，分别表示小球最早掉下去的时间和最晚掉下去的时间，用空格分隔。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：5 10 1 3 5 7 9
// 预期输出：
// 1 9

#include <iostream>

using namespace std;

enum direction
{
    LEFT = -1,
    RIGHT = 1
};

class Ball
{
    public:
    int m_nPosition;
    direction m_direction;
    bool m_bOn;
    int SetPosition(int);
    int SetDirection(direction);
    int Move();
};

int Ball::SetPosition(int nPosition)
{m_nPosition = nPosition;return 0;}

int Ball::SetDirection(direction dDirection)
{m_direction = dDirection;return 0;}

int Ball::Move()
{m_nPosition += m_direction;return 0;}

int main()
{
    int nQuantity = 0, nTime = 0, nLenth = 0;
    Ball ball[10000];
    cin>> nQuantity >> nLenth;
    for (int i = 0; i < nQuantity; i++)
    {
        int nPosition = 0;
        cin>> nPosition;
        ball[i].SetPosition(nPosition);
        ball[i].SetDirection((i%2==0?RIGHT:LEFT));
        ball[i].m_bOn = true;
    }
    bool bTest = true;
    bool bFirst = true;
    while(bTest)
    {   
        nTime++;
        for(int j = 0; j < nQuantity; j++)
        {
            if(ball[j].m_bOn)
            {
                ball[j].Move();
                if(ball[j].m_nPosition >= nLenth || ball[j].m_nPosition <= 0)
                {
                    ball[j].m_bOn = false;
                }
            }
        }
        
        int nCount = 0;
        for (int i = 0; i < nQuantity; i++)
        {
            if(ball[i].m_bOn)
            {nCount++;}
        }
        if (nCount != nQuantity && bFirst)
        {
            cout<< nTime;
            bFirst = false;
        }
        if(nCount == 0)
        {
            cout<< ' ' << nTime;
            break;
        }
    }
}