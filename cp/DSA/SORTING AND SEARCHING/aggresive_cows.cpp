// AGGRESIVE COWS PROBLEM SPOJ
// BINARY SEARCH ON THE ANSWER CONCEPT
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;
#define ll long long 
ll n, c;
// ll arr[n] ;

bool check(ll mid, ll *arr){
    ll count = 1 ;
    ll temp = arr[0] ;
    
    for(int i=0; i<n; i++){
        if(arr[i]-temp >= mid){
            count++ ;
            temp = arr[i] ;
        }
    }
    
    return (count>=c) ? true : false ;
    
}

ll binary_search_arr(ll l, ll r, ll *arr){
    ll mid=0, res=0; 
    
    while(l<=r){
        mid = (l+r)/2 ;
        if(check(mid, arr)){
            l = mid+1 ;
            res = mid ;
        }
        else
            r = mid-1 ;
    }
    
    return res ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t ;
    cin >> t ;
    // ll n, c ;
    while(t--){
        cin >> n >> c; 
        ll arr[n] ;
        for(ll i=0; i<n; i++)
            cin >> arr[i] ;
        
        sort(arr, arr+n) ;
        ll len = arr[n-1]-arr[0] ;
        ll res = binary_search_arr(1, len, arr) ;
        
        cout << res << endl ;
    }
    return 0 ;
}