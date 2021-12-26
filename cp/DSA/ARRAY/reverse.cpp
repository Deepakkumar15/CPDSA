// PROGRAM TO REVERSE THE ARRAY OR STRING
// ITERATIVE VERSION
#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++)
        cin >> a[i] ;
    int s=0, e=n-1 ;
    while(s < e){
        swap(a[s], a[e]) ;
        s++ ;
        e-- ;
    }    
    
    for(auto it:a)
        cout << it << " " ;
        
    return 0 ;
}