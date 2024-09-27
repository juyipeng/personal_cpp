// 任务描述
// 本关任务：输入若干个正整数（输入-1作为输入结束标志），要求按照输入顺序的逆序建立一个单链表，并输出。

// 编程要求
// 根据提示，在右侧编辑器修改代码，用户输入若干个正整数（输入-1作为输入结束标志），要求按照输入顺序的逆序建立一个单链表，并输出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：1 4 89 56 -1
// 预期输出：
// 56 89 4 1
#include <iostream>
using namespace std;

struct List
{
    int num;
    List *next = NULL;
};

int main()
{
    List *head,*p,*q;
    int num;

    head = q = NULL;
    //cout << "请输入若干个正整数（-1结束）\n";
    cin >> num;
    while(num != -1)
    {
        p = new List;
        p->num = num;
        q = head;
        head = p;
        p = NULL;
        head->next = q;
        cin >> num;
    }

    //cout << "按照输入顺序逆序输出\n";
    for(p = head; p != NULL; p = p->next)
    {
        cout << p->num << " ";
    };
    cout << endl;

    for(p = head; p != NULL; p = q)
    {
        q = p->next;
      delete [] p;
    }

    return 0;
}