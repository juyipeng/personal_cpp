#include <iostream>
#include <cstring>
using namespace std;

void revstr(char* c){
    int ifinal;
    for(ifinal = 0; *(c+ifinal)!=0; ifinal++){}
    char *revc = new char[ifinal+1];
    for(int i = 0; i <= ifinal-1 ;i++){
        *(revc+i) = *(c+ifinal-i-1);
    }
    *(revc+ifinal) = 0;
    strcpy(c,revc);
    delete [] revc;
    return;
}

void add_float(char* a, char* b, char* res) {
    char al[126],ar[126],bl[126],br[126],rl[126],rr[126],temp[126];
    int i,j;
    for(i = 0; *(a+i)!='.'&&*(a+i)!=0; i++){
        al[i] = *(a+i);
    }
    for(int imod = i; imod<126;imod++){
        al[imod] = 0;
    }
    if(*(a+i)==0){i--;}
    j = i;
    for(; *(a+j+1)!=0; j++){
        ar[j-i] = *(a+j+1);
    }
    for(;j-i<126;j++){
        ar[j-i] = 0;
    }
    for(i = 0; *(b+i)!='.'&&*(b+i)!=0; i++){
        bl[i] = *(b+i);
    }
    for(int imod = i; imod<126;imod++){
        bl[imod] = 0;
    }
    if(*(b+i)==0){i--;}
    j = i;
    for(; *(b+j+1)!=0; j++){
        br[j-i] = *(b+j+1);
    }
    for(;j-i<126;j++){
        br[j-i] = 0;
    }
    revstr(al);
    revstr(bl);
    for(i = 0; al[i]!=0||bl[i]!=0; i++){
        rl[i] = (al[i]==0?'0':al[i]) + (bl[i]==0?'0':bl[i]) - '0';
    }
    rl[i] = 0;
    for(i = 0; ar[i]!=0||br[i]!=0; i++){
        rr[i] = (ar[i]==0?'0':ar[i]) + (br[i]==0?'0':br[i]) - '0';
    }
    rr[i] = 0;
    for(i = 0; *(rr+i)!=0;i++){}
    for(i = i-1; i>0; i--){
        if(*(rr+i)>'9'){
            *(rr+i)-=10;
            *(rr+i-1)+=1;
        }
    }
    if(*rr>'9'){
        *rr -= 10;
        *rl +=1;
    }
    for(i = 0; *(rl+i+1)!=0;i++){
        if(*(rl+i)>'9'){
            *(rl+i) -=10;
            *(rl+i+1) += 1;
        }
    }
    if(*(rl+i)>'9'){
        *(rl+i+1) = '1';
        *(rl+i+2) = 0;
        *(rl+i)-=10;
    }
    for(i = 0; *(rl+i)!=0; i++){
        if(*(rl+i)=='0'){
            bool test = true;
            for(j = i; *(rl+j)!=0;j++){
                if(*(rl+j)!='0'){
                    test = false;
                }
            }
            if(test){
                for(j=i;*(rl+j)!=0;j++){
                    *(rl+j) = 0;
                }
            }

        }
    }
    for(i = 0; *(rr+i)!=0; i++){
        if(*(rr+i)=='0'){
            bool test = true;
            for(j = i; *(rr+j)!=0;j++){
                if(*(rr+j)!='0'){
                    test = false;
                }
            }
            if(test){
                for(j=i;*(rr+j)!=0;j++){
                    *(rr+j) = 0;
                }
            }
        }
    }
    revstr(rl);
    strcpy(res,rl);
    strcat(res,".");
    strcat(res,rr);
    return;
}


int main()
{
    char num1[128], num2[128], res[128];
    cin >> num1;
    cin >> num2;
    add_float(num1, num2, res);
    cout << res << endl;
    return 0;
}