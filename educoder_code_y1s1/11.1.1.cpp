#include<iostream>
#include"date.h"
using namespace std;

int main()
{
     int day,month,year;
     cin>>year>>month>>day;
     Date d1; // 默认值为1900年1月1日
     Date d2(year,month,day); 
     cin>>year>>month>>day;
     Date d3(year,month,day); 

     cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3<<endl;
     cout << "d2+=7 is " << ( d2 += 7 )<<endl;

     d3.setDate( d3.getyear(),d3.getmonth(), d3.getday()+5);//重新设置日期，如果新日期非法，则保持原日期不变
     cout << "d3 is " << d3<<endl; //
     cout << "++d3 is " << ++d3 <<endl;

     Date d4( 2002,6,20 );

     cout << "d4 is " << d4 << endl;                        
     cout << "d4++ is " << d4++ << endl;                    
     cout << "d4 is " << d4 << endl;     
     cout << "d3<d4 is "<<((d3<d4)?"true":"false")<<endl;       
     return 0;
}