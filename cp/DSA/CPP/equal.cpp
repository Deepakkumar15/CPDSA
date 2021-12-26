// CODEFORCES ROUND DIV.3
// HOW TO EQUAL n ELEMENTS BY PASSING VALUES TO EACH OTHER
// BY RUNNING THE LOOP 2*n TIMES

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t ;
    cin >> t;
    while(t--){
        ll n ;
        cin >> n ;
        ll arr[3] = {0};
        
        for(ll i=0; i<n; i++){
            ll x ;
            cin >> x ;
            arr[x%3]++;
        }    
        
        
        ll ans = 0, cnt = n/3, prev=0;
        for(int i=0;i<=6;i++){
            arr[i%3] += prev;
            prev = max(0ll, arr[i%3]-cnt);
            arr[i%3] -= prev;
            ans += prev;
        }
        
        cout << ans << endl ;
    }
    return 0 ;
    
}