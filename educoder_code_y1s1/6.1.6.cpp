// 任务描述
// 本关任务：陶陶家的院子里有一棵苹果树，每到秋天树上就会结出 n （1≤n≤100） 个苹果。苹果成熟的时候，陶陶就会跑去摘苹果。陶陶有个 30cm 高的板凳，当他不能直接用手摘到苹果的时候，就会踩到板凳上再试试。

// 现在已知每个苹果到地面的高度 a[i] cm（1≤i≤n，100≤a[i]≤200），以及陶陶把手伸直时能达到的最大高度 height cm （100≤height≤120），请你编写程序帮助陶陶计算一下他能摘到的苹果数目。

// 假设只要他能够伸手碰到苹果，苹果就会掉下来。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数 int GetApple(int a[], int height, int n)来计算淘淘能摘到的苹果数目。
// 函数参数：数组 a 保存苹果到地面的高度，height 代表陶陶把手伸直时能达到的最大高度，n为树上总的苹果数。
// 函数返回值：淘淘能摘到的苹果数目

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：10 100 200 150 140 129 134 167 198 200 111 110
// 输入说明：第一个输入的数据是苹果数目n；接着输入的数据是这n个苹果，每个苹果到地面的高度；最后输入的数据是陶陶把手伸直时能达到的最大高度。
// 预期输出：
// 5
#include<iostream>
using namespace std;

int GetApple(int a[], int height, int n)
{
    static int nCount = 0;
    for (int i = 0; i < n; i++){
        if(a[i] <= height + 30){
            nCount++;
        }
        else{}
    }
    return nCount;
}

int main()
{
	int n,a[100],height;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
	cin>>height;

    cout<< GetApple(a, height, n);
    
	return 0;
}
