#include<iostream>
#include<conio.h>

using namespace std;


void mergesort(int arr[],int si, int ei){

  
  int mid = (si+ei)/2;
  mergesort(arr,si,mid);
  mergesort(arr,mid+1,ei);
}


int main(){

  int arr[6] = {6,3,9,5,2,8};
  int n = 6;

  getch();
  return 0;
}
