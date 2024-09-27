// 任务描述
// 本关任务：通信录包含

// “姓名”（最多20个字符）、
// “生日”（包括“年”、“月”、“日”）、
// “电话号码”、
// “家庭地址”（最多50个字符）。
// 定义一个嵌套的结构类型，输入n(n<10)个学生信息，再按照他们的年龄从小到大的顺序输出。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户先输入正整数n表示学生人数，然后输入这些学生的信息，再按照他们的年龄从小到大的顺序输出。

// 测试说明
// 平台会对你编写的代码进行测试：
// 测试输入：
/*
2
Wangwu 1990 12 11 13901232222 No.800DongchuanRoad
Zhangsan 1993 1 23 1891233799 No.238HuashanRoad
预期输出：
Zhangsan 1993 1 23 18912337789 No.238 HuasanRoad
Wangwu 1990 12 11 13901232222 No. 800 DongchuanRoad
*/

#include <iostream>
#include <cstring>

using namespace std;

class inf{
    public:
    void set();
    void println();
    int date();
    private:
    string m_sName, m_sPhone, m_sSite;
    int m_nYear, m_nMonth, m_nDay, m_nSequence;
};

void inf::set(){
    cin>> m_sName >> m_nYear >> m_nMonth >> m_nDay >> m_sPhone;
    while(cin.get()!='.'){}
    cin>> m_nSequence >> m_sSite;
    cin.get();
    return ;
}

void inf::println(){
    cout<< m_sName << ' ' << m_nYear << ' ' << m_nMonth << ' ' << m_nDay
        << ' ' << m_sPhone << " No." << m_nSequence << m_sSite << endl;
    return;
}

int inf::date(){
    return m_nYear*10000 + m_nMonth* 100 + m_nDay;
}

int main(){
    int nQuantity;
    cin>> nQuantity;
    inf **pi = new inf*[nQuantity];
    for(int i = 0;i < nQuantity; i++){
        *(pi+i) = new inf;
        (*(pi+i))->set();
    }
    for(int i = nQuantity - 1; i > 0; i--){
        bool test = true;
        for(int j = 0; j < i; j++){
            if(((*(pi+j))->date())>((*(pi+j+1))->date())){
                auto tmp = *(pi+j);
                *(pi+j) = *(pi+j+1);
                *(pi+j+1) = tmp;
                test = false;
            }
        }
        if(test){
            break;
        }
    }
    for(int i = nQuantity-1; i>=0; i--){
        (*(pi+i))->println();
    }

    for(int i = 0;i < nQuantity; i++){
        delete *(pi + i);
    }
    delete [] pi;
    return 0;
}