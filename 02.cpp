#include "Vectory.hpp"
#include <iostream>
using namespace std; 
void print(int len ,Vectory<int> & arr)
{
    for(int i=len;i>=0;i--)
    {
        cout<<"Arr["<<i<<"] is : "<<arr[i]<< " the len is :"<<arr.getLen()<<"the capacity is "<< arr.getCapacity()<<endl;
        arr.popBack();
        if(arr.isEmpty())
        {
            cout<<"Arr is empty"<<endl;
        }
    }
}
int main()
{
    Vectory<int> arr;
    for(int i=1;i<=10;i++)
    {
        arr.pushBack(short(i+'A'-1));
        cout<<"len is : " << arr.getLen() << " capacity is : "<< arr.getCapacity() << endl;
    }
    Vectory<int> arr1(arr);
    //print(arr.getLen(),arr);
    for(int i=9;i>=0;i--)
    {
        cout<<"Arr["<<i<<"] is : "<<arr[i]<< " the len is :"<<arr.getLen()<<"the capacity is "<< arr.getCapacity()<<endl;
        arr.popBack();
        if(arr.isEmpty())
        {
            cout<<"Arr is empty"<<endl;
        }
    }
    for(int i=9;i>=0;i--)
    {
        cout<<"Arr["<<i<<"] is : "<<arr1[i]<< " the len is :"<<arr1.getLen()<<"the capacity is "<< arr1.getCapacity()<<endl;
        arr1.popBack();
        if(arr1.isEmpty())
        {
            cout<<"Arr is empty"<<endl;
        }
    }
}