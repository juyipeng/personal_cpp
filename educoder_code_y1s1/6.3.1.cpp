// 任务描述
// 本关任务：输入两个正整数m和n（1≤m≤n≤10000），编写一个程序，统计并输出m～n之间（包含m和n）的素数的个数。

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入两个正整数m和n（1≤m≤n≤10000），输出m～n之间（包含m和n）的素数的个数。要求定义并调用函数 isPrime(n) 来判断n是否是素数

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：1 10
// 预期输出：
// 4
#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n==1){
        return false;
    }
    else if(n==2){
        return true;
    }
    else{
        if(n%2==0){
            return false;
        }
        else{
            for(int i = 3; i < n; i+=2){
                if(n%i==0){
                    return false;
                }
            }
            return true;
        }
    }

}

int main()
{
    int ncount = 0, m = 0, n = 0;
    cin>>m>>n;
    for(int i = m; i <= n; i++){
        if(isPrime(i)){
            ncount++;
        }
    }
    cout<< ncount;
	return 0;
}
