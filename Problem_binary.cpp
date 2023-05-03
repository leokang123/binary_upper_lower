#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr1[500005],arr2[500005];
int binarySearch1(int tg,int start,int end)
{
  if(start>end){return -1;}
  int mid = (start+end)/2;
  if(tg == arr1[mid]) {
    while(arr1[mid] == arr1[mid-1]) mid-=1;
   // cout<<mid<<' ';
    return mid;
    }

  else if(tg<arr1[mid]) return binarySearch1(tg,start,mid-1);
  else return binarySearch1(tg,mid+1,end);
}
int binarySearch2(int tg,int start,int end)
{
  if(start>end){return -1;}
  int mid = (start+end)/2;
  if(tg == arr1[mid]) {
    while(arr1[mid] == arr1[mid+1]) mid+=1;
    //cout<<mid<<' ';
    return mid;
  }
  else if(tg<arr1[mid]) return binarySearch2(tg,start,mid-1);
  else return binarySearch2(tg,mid+1,end);
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int num1,num2;
  cin>>num1;
  for(int i=0;i<num1;i++)
  {
    cin>>arr1[i];
  }
  cin>>num2;
  for(int i=0;i<num2;i++)
  {
    cin>>arr2[i];
  }
  sort(arr1,arr1+num1);
  
  for(int i = 0;i<num2;i++)
  {
    int snum = 0;
    int end = num1;
    int idx1 = binarySearch1(arr2[i],0,end);
    int idx2 = binarySearch2(arr2[i],0,end);
    if(idx1 != -1) snum = idx2-idx1 + 1;
    arr2[i] = snum;
  }
  for(int i =0;i<num2;i++)
  {
    cout<<arr2[i]<<' ';
  }
  cout<<'\n';
  return 0;
}
