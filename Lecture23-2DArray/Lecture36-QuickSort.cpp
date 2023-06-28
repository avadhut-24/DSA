#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivotIndex = 0;
    int cnt = 0;
    for(int i = s+1; i <= e; i++)
    {
        if(arr[i]<arr[s])
        cnt++;
    }
    pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);
    
    int i = s;
    int j = e;
 
    //Now making sure that left and part are respectivley 
    //less than and greater than that of pivotIndex element
    while(i < pivotIndex && j > pivotIndex)
    {
      while(arr[i]<arr[pivotIndex])
      {
        i++;
      }

      while(arr[j]>arr[pivotIndex])
      {
        j--;
      }

      swap(arr[i++], arr[j--]);

    }
   
   return pivotIndex;

}


void quickSort(int *arr, int s, int e)
{
    //base case
    if(s>=e)
    return;

    //Do the partition
   int p = partition(arr, s, e);

    //sort left part
    quickSort(arr, 0, p-1);

    //sort right part
    quickSort(arr, p+1, e);
}

int main()
{
     int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}