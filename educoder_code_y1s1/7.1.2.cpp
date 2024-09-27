// 任务描述
// 本关任务：输入若干个字符串(每个字符串的长度不超过30个字符，字符串总数不超过30)，和一个英文字符ch。 
// 要求删除每个字符串中的字符ch(区分大小写)，得到新的字符串，然后将新的字符串按照字典逆序排序后输出。

// 编程要求
// 根据提示，在右侧编辑器补充代码，用户依次输入字符串数量n，n个字符串和一个英文字符ch。
// 删除每个字符串中的字符ch(区分大小写)，得到新的字符串，然后将新的字符串按照字典逆序排序后输出。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
/*
3
abcddc
sxwcdez
ncvccvd
c
*/

// 预期输出：
// sxwdez
// nvvd
// abdd

// 最大值：91
#include <iostream>

using namespace std;

int thesizeof(char*a){
    int i;
    for(i = 0; *(a+i)!='\0'; i++){
    }
    return i+1;
}

void strbubble(char**a,char**b){
    bool bSorted = true, bLike = true;
    for(int i = 0; (*(*a+i)!='\0')&&(*(*b+i)!='\0'); i++){
        if(*(*a+i)>*(*b+i)){
            bSorted = false;
            bLike = false;
        }
        else if(*(*a+i)<*(*b+i)){
            bLike = false;
            break;
        }
    }
    if(bLike&&(thesizeof(*a)>thesizeof(*b))){
        bSorted = false;
    }
    if(! bSorted){
        auto temp = *a;
        *a = *b;
        *b = temp;
    }
    return;
}

void dltpart(char *a, char c){
    
    for(int i = 0; *(a+i)!='\0'; i++){
        if(*(a+i)==c){
            for(int j = i; *(a+j)!='\0'; j++){
                *(a+j) = *(a+j+1);
            }
        i--;
        }
    }
    return;
}

int main(){
    char **cSpace;
    char todlt;
    cSpace = new char *[30];
    int ifinal = 0;
    int scale;
    cin>> scale;
    cin.get();
    for(int i = 0; i < scale; i++) {
        cSpace[ifinal] = new char[31];
        cin.getline(cSpace[ifinal],31);
        ifinal++;
    }
    ifinal--;
    todlt = cin.get();
    for(int i = ifinal; i>=0; i--){//process
    dltpart(cSpace[i],todlt);
    }
    for(int i = ifinal; i>0; i--){//sort
        for(int j = 0; j < i; j++){
            strbubble(cSpace+j,cSpace+j+1);
        }
    }
    for(int i = ifinal; i>=0; i--){//cout
        cout<< cSpace[i] << endl;
    }
    for(int i = ifinal; i >=0; i--){//delete
        delete [] cSpace[i];
    }
    delete [] cSpace;
}