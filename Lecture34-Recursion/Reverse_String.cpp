
/*
#include <bits/stdc++.h>
using namespace std;

void reverse(int *arr, int n)
{
  int i=0;
  int j=n-1;
  while(i < j)
  {
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
}

int main()
{ 
    int arr[10];

    //taking input
    cout <<"Taking input elements of array"<<endl;
    for(int i=0; i<10; i++)
    {
       cin >> arr[i];
    }
    
    reverse(arr, 10);

    //printing array
    for(int i=0; i<10; i++)
    {
      cout << arr[i]<<endl;
    }
    return 0;
}

********************************************************************************************************/
/*
//Now I am solving using only one variable i
#include <bits/stdc++.h>
using namespace std;

void swap(string &str){
  int n = str.length();
  for(int i=0; i<n/2; i++)
  {
     char temp = str[i];
     str[i] = str[n-1-i];
     str[n-1-i] = temp; 
  }

}


int main()
{
  string str = "avadhut";
  swap(str);
  cout << str<<endl;
  return 0;
}
*****************************************************************************************************************/


//This solution is using recursion
#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i, int j)
{  
  if(i>j)          //base case
  { 
    return ;
  }

   swap(str[i], str[j]);     //Processing
   i++;
   j--;
   return reverse(str, i, j);    // Recursive call

}

int main()
{
  string str = "avadhut";
  int i = 0;
  int j = str.length() - 1;
   reverse(str, i, j);
  cout << str<<endl;
  return 0;
}