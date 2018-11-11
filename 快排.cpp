#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000
int qsort(int* begin,int* end)
{
    if((begin+1)>=end) return 0;
    int key=*begin;
    int* left=begin;
    int* right=end-1;
    while(left < right)
    {
        while(left<right&&((key<*right)))
        {
            right--;
        }
        *left=*right;
        while(left<right&&((key>=*left)))
        {
            left++;
        }
        *right=*left;
    }
    *right=key;
    qsort(begin,right);
    qsort(right+1,end);
    return 0;
}
int main(){
   int arr[N];
   for(int i=0;i<N;i++)
   {
       arr[i]=rand()%N;
   }
   qsort(arr,arr+N);
   for(int i=0;i<N;i++)
   {
       cout<<arr[i]<<" ";
       if(i%20==0) cout<<endl;
   }
   return 0;
}
