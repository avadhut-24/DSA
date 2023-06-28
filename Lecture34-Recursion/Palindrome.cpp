#include <bits/stdc++.h>
using namespace std;

string palindrome(string str, int n, int i)
{
   if(i >= n/2)
   return "is";
   
   if(str[i] != str[n-1-i])
   {
      return "is not";
   }
   i++;
   return palindrome(str, n, i);
}

int main()
{
    string str = "racecar";
    int n = str.length();
    int i = 0;
    cout << str << " " << palindrome(str, n, i) << " a palindrome "<<endl;
    return 0;
}