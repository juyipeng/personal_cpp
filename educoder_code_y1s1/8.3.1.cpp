#include <iostream>

using namespace std;

struct matrix{
    long long a = 1, b = 0, c = 0, d = 1;
    void set();
};

matrix mult(const matrix &a,const matrix &b){
    matrix r;
    long long tmp = 1000000007;
    r.a=(tmp+a.a*b.a+a.b*b.c)%tmp;
    r.b=(tmp+a.a*b.b+a.b*b.d)%tmp;
    r.c=(tmp+a.c*b.a+a.d*b.c)%tmp;
    r.d=(tmp+a.c*b.b+a.d*b.d)%tmp;
    return r;
}

matrix fpower(matrix m, long long n){
    matrix res;
    // res.a = res.d =1;
    // res.b = res.c =0;
    while(n){
        if(n % 2){
            res = mult(res,m);
        }
        n/=2;
        // matrix tmp = m;
        // m.a = tmp.a*tmp.a+tmp.b*tmp.c;
        // m.b = tmp.a*tmp.b+tmp.b*tmp.d;
        // m.c = tmp.c*tmp.a+tmp.d*tmp.c;
        // m.d = tmp.c*tmp.b+tmp.d*tmp.d;
        // m.a%=1000000007;
        // m.b%=1000000007;
        // m.c%=1000000007;
        // m.d%=1000000007;
        m = mult(m,m);
    }
    return res;
}

void matrix::set(){
    cin>> a >> b;
    cin.get();
    cin>> c >> d;
    cin.get();
    return;
}

int main(){
    long long n;
    cin>>n;
    matrix m;
    m.set();
    m = fpower(m,n);
    cout<< m.a << ' ' << m.b << '\n' << m.c <<' '<<m.d;
    return 0;
}