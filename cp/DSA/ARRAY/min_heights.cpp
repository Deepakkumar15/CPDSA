#include <bits/stdc++.h>
 
using namespace std ;
#define ll long long int 

ll min_diff(ll *arr, ll n, ll k){
    if(n==1)
        return 0 ;
        
    ll ans = arr[n-1]-arr[0] ;
    
    ll max = arr[n-1]+k ;
    ll min = arr[0]-k ;
    if(min > max)
        swap(min, max) ;
    
    for(ll i=1; i<n-1; i++){
        ll add = arr[i]+k ;
        ll sub = arr[i]-k ;
        
        if(sub >= min || add <= max)
            continue ;
            
        if(add-min >= max-sub)
            min = sub ;
        else
            max = add ;
    }
    
    return min(ans, max-min) ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    
    ll n ;
    cin >> n ;
    ll arr[n] ;
    for(ll i=0; i<n; i++)
        cin >> arr[i] ;
    ll k ;
    cin >> k ;
    cout << min_diff(arr, n, k) << endl ;
    
    return 0 ;
}