#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
   char arr[10000];
   while(cin>>arr)
   {
       int len=strlen(arr)-1;
       int arr2[10000];
       for(int i=0;i<=len;i++)
       {
           arr2[i]=(int)arr[i];
       }
       sort(arr2,arr2+len+1);
       for(int i=0;i<=len;i++)
       {
           cout<<(char)arr2[i];
           if(i!=len){
               cout<<' ';
           }
       }
       cout<<endl;
   }
//ifstream fin("");
//ofstream fout;
//fout.open("");
//fin.close();
//fout.close();
   return 0;
}
