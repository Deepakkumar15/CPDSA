#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;

int hig_power(string temp)
{
  int n = temp.length() ;
  int ans = 0;
  for(int i=n-1; i>=0; i--)
  {
    if(temp[i] == '0')
      ans++ ;
    else
      break ;
  }  
  
  return ans ;
}

int dec_values(string str, int n)
{
  int count =0 ;
  for(int i=0; i<n; i++)
    if(str[i] == '0')
      count++ ;
  if(count == n)
    return -1 ;
      
  string s ;
  s.insert(0, str, 0, n) ;
  s.insert(n, str, 0, n) ;
  
  string temp ; 
  int cnt[n] ;
  for(int i=0; i<n; i++)
  {
    temp.insert(0, s, i, n) ;
    int x = hig_power(temp) ;
    cnt[i] = x ;
    temp.clear() ;
  }
  
  return *max_element(cnt, cnt+n) ;
  
}

int main()
{
  ios_base :: sync_with_stdio(false) ;
  cin.tie(0) ;
  cout.tie(0) ;
  
  string str ;
  cin >> str ;
  int n = str.length() ;
  cout << dec_values(str, n) ;
  
  return 0;
}