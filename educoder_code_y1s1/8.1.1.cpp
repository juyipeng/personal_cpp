// 任务描述
// 本关任务：编写程序模拟一个用于时间的电子时钟。该时钟以时、分和秒的形式记录时间。定义相应的结构体并编写3个函数：

// setTime 函数用于设置时钟的时间，
// increase 函数模拟时间过去了1秒，
// showTime 显示当前时间，显示格式为HH:MM:SS。
// 注意时钟为24小时制。
// 头歌平台上请不要将time等用于结构体的类型名

// 编程要求
// 根据提示，在右侧编辑器补充代码。用户会输入六个整型数，分别代表第一次输入的时、分、秒和第二次输入的时、分、秒。
// 输出每次输入的时间以及增加一秒后的时间

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：12 48 56 13 2 16
// 预期输出：
// 12:48:56
// 12:48:57
// 13:02:16
// 13:02:17

#include <iostream>

using namespace std;

struct Clocks{
    char m_inf[9] = "00:00:00";
    void setTime(int,int,int);
    void increase();
    void showTime();
};

void Clocks::setTime(int sec, int min, int hour){
    m_inf[0]=hour/10+'0';
    m_inf[1]=hour%10+'0';
    m_inf[3]= min/10+'0';
    m_inf[4] = min%10+'0';
    m_inf[6] = sec/10+'0';
    m_inf[7] = sec%10+'0';
}

void Clocks::increase(){
    ++m_inf[7];
    if(m_inf[7] > '9'){
        m_inf[7]-=10;
        ++m_inf[6];
    }
    if(m_inf[6] > '5'){
        m_inf[6]-=6;
        ++m_inf[4];
    }
    if(m_inf[4] > '9'){
        m_inf[4]-=10;
        ++m_inf[3];
    }
    if(m_inf[3] > '5'){
        m_inf[3]-=6;
        ++m_inf[1];
    }
    if(m_inf[1] > '9'){
        m_inf[1]-=10;
        ++m_inf[0];
    }
    if(m_inf[0]=='2'&&m_inf[1]=='4'){
        m_inf[0]=m_inf[1]='0';
    }
}

void Clocks::showTime(){
    cout<<m_inf<<endl;
}

int main(){
    Clocks **pclocks = new Clocks*[2];
    for(int i = 0; i < 2; i++){
        *(pclocks+i) = new Clocks;
        int sec, min, hour;
        cin>>hour>>min>>sec;
        (**(pclocks+i)).setTime(sec,min,hour);
        (**(pclocks+i)).showTime();
        (**(pclocks+i)).increase();
        (**(pclocks+i)).showTime();
        delete *(pclocks+i);
    }
    delete [] pclocks;
}