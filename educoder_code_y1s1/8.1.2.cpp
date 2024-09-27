// 任务描述
// 本关任务：用结构体表示一个复数，编写实现复数的加法、乘法、和输出的函数。

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入四个整型数a, b, c, d，分别代表复数x = a + bi 和y = c + di。
// 然后依次计算输出：
// x = ?
// y = ?
// x += y; x = ?
// y *= x; y = ?
// x + y = ?
// y * x = ?
// x = ?
// y = ?
// 其中？为一个复数

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：1 2 3 4
// 输入说明：表示1+2i和3+4i两个复数
// 预期输出：
// x = 1+2i
// y = 3+4i
// x += y; x = 4+6i
// y *= x; y = -12+34i
// x + y = -8+40i
// y * x = -252+64i
// x = 4+6i
// y = -12+34i 
// 注意：不要输出类似3+0i的情况

#include <iostream>

using namespace std;

struct ComplexNumber{
    public:
    ComplexNumber operator+(const ComplexNumber &a);
    ComplexNumber operator*(const ComplexNumber &a);
    void operator+=(const ComplexNumber &a);
    void operator*=(const ComplexNumber &a);
    void printcomplexnumber();
    void set(int l,int r);
    private:
    int m_l,m_r;
};

ComplexNumber ComplexNumber::operator+(const ComplexNumber &a){
    ComplexNumber c;
    c.m_l = (this->m_l) + (a.m_l);
    c.m_r = (this->m_r) + (a.m_r);
    return c;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &a){
    ComplexNumber c;
    c.m_l = (this->m_l) * (a.m_l)-(this->m_r) * (a.m_r);
    c.m_r = (this->m_l)*a.m_r + (this -> m_r)*a.m_l;
    return c;
}

void ComplexNumber::operator+=(const ComplexNumber &a){
    this->m_l = this->m_l + a.m_l;
    this->m_r = this->m_r + a.m_r;
    return; 
}

void ComplexNumber::operator*=(const ComplexNumber &a){
    int tmp = this->m_l;
    this->m_l = (this->m_l) * (a.m_l)-(this->m_r) * (a.m_r);
    this->m_r = tmp*a.m_r + (this -> m_r)*a.m_l;
    return; 
}

void ComplexNumber::printcomplexnumber(){
    if(m_r==0&&m_l==0){
        cout<< 0;
    }
    else if(m_l==0){
        cout<< m_r << 'i';
    }
    else if(m_r==0){
        cout<< m_l;
    }
    else{
        cout<< m_l << (m_r==0?"+":"") << m_r << 'i';
    }
    return;
}

void ComplexNumber::set(int l,int r){
    m_l=l;
    m_r = r;
    return;
}

int main(){
    int l,r;
    ComplexNumber *x = new ComplexNumber,*y = new ComplexNumber;
    cin>>l >> r;
    (*x).set(l,r);
    cin>> l >> r;
    y->set(l,r);
    cout<<"x = ";
    x->printcomplexnumber();
    cout<<"\ny = ";
    y->printcomplexnumber();
    cout<<"\nx += y; x = ";
    (*x)+=(*y);
    x->printcomplexnumber();
    cout<<"\ny *= x; y = ";
    (*y)*=(*x);
    y->printcomplexnumber();
    cout<<"\nx + y = ";
    ComplexNumber *tmp = new ComplexNumber;
    (*tmp) = (*x)+(*y);
    tmp->printcomplexnumber();
    delete [] tmp;
    cout<<"\ny * x = ";
    tmp = new ComplexNumber;
    (*tmp) = (*x)*(*y);
    tmp->printcomplexnumber();
    delete [] tmp;
    cout<<"\nx = ";
    x->printcomplexnumber();
    cout<<"\ny = ";
    y->printcomplexnumber();

    delete[]x;
    delete[]y;
    return 0;
}
