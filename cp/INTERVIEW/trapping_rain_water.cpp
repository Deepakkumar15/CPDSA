#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

int solve(int *a, int *l, int *r, int n){
    int sum=0 ;
    for(int i=0; i<n; i++)
        sum+=(min(l[i], r[i])-a[i]) ;
    return sum ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int t, n ;
    cin >> t ;
    int *a ;
    while(t--){
        cin >> n ;
        a = new int [n] ;
        for(int i=0; i<n; i++)
            cin >> a[i] ;
            
        int l[n], r[n] ;
        l[0]=a[0] ;
        int res=a[0] ;
        for(int i=1; i<n; i++)
            (a[i]>res) ? l[i]=res=a[i] : l[i]=res ;
                
        r[n-1] = a[n-1] ;
        res = a[n-1] ;
        for(int i=n-2; i>=0; i--)
            (a[i]>res) ? r[i]=res=a[i] : r[i]=res ;
        
        cout << solve(a, l, r, n) << endl ;
    }
    
    return 0 ;
}