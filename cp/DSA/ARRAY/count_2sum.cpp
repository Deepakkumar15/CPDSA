// COUNT TOTAL NUMBER OF PAIRS OF 2SUM PROBLEM
// UNORDERED_MAP VERSION
#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll count(ll *a, ll n, ll target){
    ll ans=0; 
    unordered_map<ll, ll> mp ;
    for(ll i=0; i<n; i++)
        mp[a[i]]++ ;
    for(ll i=0; i<n; i++){
        ans+=mp[target-a[i]] ;
        
        if(target-a[i]==a[i])
            ans-- ;
    }
            
    return ans/2 ;        
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll n ;
    cin >> n ;
    ll a[n] ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    ll target ;
    cin >> target ;
    
    cout << count(a, n, target) << endl ; 
    return 0 ;
}