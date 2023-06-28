#include<bits/stdc++.h>
#include<array>
using namespace std;



void bubblesort(int *arr, int n)
{   
    if(n == 1)
    {
        return ;
    }
    for(int i=0; i<n-1; i++)
    {
      if(arr[i]>arr[i+1])
      {
        swap(arr[i], arr[i+1]);
      }
    }
    n = n-1;
    bubblesort(arr, n);
}

int main()
{
    int arr[]= {5,12,45,34,89,32};
    int n = 6;
    bubblesort(arr, n);
    for(int i =0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}