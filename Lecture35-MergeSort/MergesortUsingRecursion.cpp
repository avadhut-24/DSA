/*#include <bits/stdc++.h>
using namespace std;

void merge( int *arr, int *first, int *second, int len1, int len2)
{
    int index1 = 0;
    int index2 = 0;
    int i = 0;

   while (index1 < len1 && index2 < len2)
   {
     if(first[index1] < second[index2])
         arr[i++] = first[index1++];

     else 
         arr[i++] = second[index2++];
   }

   while(index1 < len1)
   {
     arr[i] = first[index1];
   }

    while(index2 < len2)
   {
    arr[i] = second[index2];
   }
    
}

void mergeSort(int *arr, int s, int e)
{
   if(s>=e)
   return;

   int mid= (s+e)/2;

   int len1 = s + mid + 1;
   int len2 = e - mid;

   int first[len1];
   for(int i=0; i<len1; i++)
   {
    first[i] = arr[i];
   }
   
   int second[len2];
   for(int i=0; i<len2; i++)
   {
    second[i] = arr[mid+1+i];
   }
   
    //sorting left part
   mergeSort(first, 0, mid);

   //sorting right part
   mergeSort(second, 0, len2-1);

   //merge two sorted parts
   merge(arr, first, second, len1, len2);
}

 int main()
 {
    int arr[5]= {2,1,3,5,4};
    mergeSort(arr, 0, 4);
    //printing sorted array
    for(int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
 }  */

 /*second attempt
#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
} */

//In place mergeSort
#include<bits/stdc++.h>
using namespace std;


void merge(int *arr, int s, int e, int mid)
{
    int start1 = s;
    int start2 = mid+1;
    
    //if the direct merge is already sorted
    if(arr[mid] <= arr[mid+1])
    return;

    //now we have two sorted parts, and we have to merge them 
    //for that compare elements of two parts and update the array accordingly
    while(start2 <= e && start1 < start2)
    {
    if(arr[start1] <= arr[start2])
    {
        start1++;
    }
    else
    {
      int value = arr[start2];
      int index = start2;

      while(index != start1)
      {
        arr[index] = arr[index-1];
        index--;
      }
      arr[start1] = value;

      start1++;
      start2++;
    }
 
}
}

void mergeSort(int *arr, int s, int e)
{
    if(s>=e)
    return;

    int mid = s + (e-s)/2;
   
    //sort left part
    mergeSort(arr, 0, mid);

    //sort right part
    mergeSort(arr, mid+1, e);

    //merge two sorted parts
    merge(arr, s, e,  mid);

}

int main()
{
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}