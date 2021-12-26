// PROGRAMME TO FIND OUT NUMBER OF 1'S IN BIT REPRESENTATION OF A DECIMAL NUMBER
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
   int num = 7 ;
   int cnt = __builtin_popcount(num) ;

   // FOR A LONG LONG NUMBER WE USE:
   // __builtin_popcountll() ;
   
   cout << cnt ;
    
    
    return 0 ;
}