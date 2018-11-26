#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;
#define EPS 1e-9
#define N 100000 + 5
#define M 10000 + 5
#define MM(X) memset(X , 0 , sizeof(X))
#define MZ(X) memset(X , 0xff , sizeof(X))
#define MI(X) memset(X , 0x3f , sizeof(X))
class Date{
private:
    int year,month,day;
    const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
public:
    Date(int _year=1980,int _month=1,int _day=1):year(_year),month(_month),day(_day)
    {
        if(_year<0) year=1980;
        if(_month<0) month=1;
        if(_day<0) day=1;
    }
    ~Date(){;}
    const bool inPeriod(Date & d1,Date & d2) const
    {
        if((*this >= d1 && *this <=d2)||(*this >= d2 && *this <=d1))
        {
            return true;
        }
        return false;
    }
    const bool isLeap() const
    {
        if(year%400==0||(year%4==0&&year%100!=0))
        {
            return true;
        }
        return false;
    }
    friend ostream & operator << (ostream & out,const Date & d1)
    {
        cout<<d1.year<<"/"<<d1.month<<"/"<<d1.day;
        //printf("%4d/%2d/%2d",els.year,els.month,els.day);
    }
    friend istream & operator >> (istream & in , Date & els)
    {
        return in >> els.year >> els.month >> els.day;
    }
    Date operator + (int _day) 
    {

        Date td(year,month,day);
        while(_day)
        {
            //cout<<td.year<<'/'<<td.month<<'/'<<td.day<<"dd:"<<_day<<endl;
            int px=((td.isLeap()&&td.month==2)?(days[td.month]+1):days[td.month]);
            if((td.day+_day)>px)
            {
                td.month++;
                _day=_day - (px - td.day + 1);
                td.day=1;
            }
            else{
                td.day+=_day;
                _day=0;
            }
            if(td.month>12)
            {
                td.year++;
                td.month=td.month-12;
            }

        }
        return td;
    }
    int operator - (Date & d1)
    {
        Date t1 = (*this>=d1)?*this:d1,
             t2 = (*this<=d1)?*this:d1;
        int i=0;
        while(!(t1==(t2+i)))
        {
            i++;
        }
        return i;
    }
    void operator =(Date & d1)
    {
        year=d1.year;
        month = d1.month;
        day = d1.day;
    }
    bool operator < (const Date & d1) const
    {
        if(year != d1.year)
        {
            return year < d1.year;
        }
        if(month != d1.month)
        {
            return month < d1.month;
        }
        return day< d1.day;
    }
    bool operator >= (const Date & d1) const{
        return !(*this < d1);
    }
    bool operator > (const Date & d1) const
    {
        return d1 < *this;
    }
    bool operator <= (const Date & d1) const
    {
        return !(*this > d1);
    }
    bool operator == (const Date & d1) const
    {
        return (!(*this > d1) )&&( !(*this < d1));
    }
    bool operator != (const Date & d1) const
    {
        return !(*this == d1);
    }
    const int getyear() const
    {
        return year;
    }
    const int getmonth() const
    {
        return month;
    }
    const int getday() const
    {
        return day;
    }
    bool setyear(int _year)
    {
        if(_year>0)
        {
            year=_year;
            return true;
        }
        return false;
    }
    bool setmonth(int _month)
    {
        if(_month>=1&&_month<=12)
        {
            month=_month;
            return true;
        }
        return false;
    }
    bool setday(int _day)
    {
        if(_day<=((this->isLeap()&&month==2)?days[month]+1:days[month])&&_day>=1)
        {
            day=_day;
            return true;
        }
        return false;
    }
};
int main(){
    Date d1(2000,4,22),d2(2018,11,26),d3,d4;
    cin>>d3>>d4;
    cout<<d1<<endl<<d2<<endl<<d3<<endl<<d4<<endl;
    cout<<(d3 + 100)<<endl;
    return 0;
}
