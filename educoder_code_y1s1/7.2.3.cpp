// 任务描述
// 本关任务：设计一个程序用于向后推算指定日期经过n天后的具体日期。

// 编程要求
// 根据提示，在右侧编辑器补充代码，输入为长度为8的字符串str和一个正整数n，str前四位表示年份，后四位表示月和日。当推算出的年份大于4位数时，输出“out of limit!”，否则输出8位的具体日期。

// 测试说明
// 平台会对你编写的代码进行测试：

// 测试输入：
// 00250709 60000
// 预期输出：
// 01891017
#include <iostream>
using namespace std;

int main()
{    
    int nDayinMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31}, nTime,year,month,day;
    char cDate[9];
    cin>>cDate;
    cin>> nTime;
    year = 1000*(cDate[0]-'0')+100*(cDate[1]-'0')+10*(cDate[2]-'0')+(cDate[3]-'0');
    month = 10*(cDate[4]-'0')+(cDate[5]-'0');
    day = 10*(cDate[6]-'0')+(cDate[7]-'0');
    while(nTime>0){
        int tmp = nDayinMonths[month-1] - day;
        if(month==2){
            tmp += (year%4==0)-(year%100==0)+(year%400==0);
        }
        if (nTime<=tmp){
            day += nTime;
            break;
        }
        else{
            day = 0;
            nTime -= tmp;
            month++;
            if(month>12){
                month-=12;
                year+=1;
                if(year>=10000){
                    cout<<"out of limit!";
                    return 0;
                }
            }
        }
    }
    cDate[0]='0'+year/1000;
    cDate[1]='0'+year/100%10;
    cDate[2]='0'+year/10%10;
    cDate[3]='0'+year%10;
    cDate[4]='0'+month/10;
    cDate[5]='0'+month%10;
    cDate[6]='0'+day/10;
    cDate[7]='0'+day%10;
    cout<<cDate;
    return 0;
}