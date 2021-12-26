#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll min_pole(ll n, vector<ll> &power){
    vector<ll> jump(n+1,0);
    
    for(ll i=1; i<=n; i++){
        ll x = max(i-power[i], 1LL);
        ll y = min(i+power[i], n);
        jump[x] = max(jump[x], y); 
    }
    
    for(auto it: jump)
        cout << it << " " ;
    cout << endl ;
    
    ll cnt = 0, back_up=0 , cur = 1;
    for(ll i=1; i<=n; i++){
        if(i>cur)
            return 0;
        back_up = max(back_up, jump[i]);
        if(cur == i && i!=n)
        {
            cnt++;
            cur = back_up;
            back_up=0;
       }
       
    }
    
    cout << cur << " " << back_up << endl ;
    if(cur < n)
        return 0;
    return cnt;
    
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll n ;
    cin >> n ;
    vector<ll> power ;
    power.push_back(0) ;
    for(ll i=1; i<=n; i++){
        ll x ;
        cin >> x;
        power.push_back(x) ;
    }
    
    cout << min_pole(n, power) << endl; 
    return 0 ;
}