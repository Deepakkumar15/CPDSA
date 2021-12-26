// codechef feb challenge 2021
// ANOTHER TREE WITH NUMBER THEORY

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int 
vector<ll> *l ;
ll n ;

ll bfs(ll v, ll w){
    ll ans=0 ;
    ll len = l[v].size() ;
    if(len==0)
        return 0 ;
    if(w%len != 0)
        return w ;
    for(auto it:l[v])
        ans += bfs(it, w/len) ;
        
    return ans ;    
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n ;
    l = new vector<ll> [n+1] ;
    for(ll i=2; i<=n; i++){
        ll p ;
        cin >> p ;
        l[p].push_back(i) ;
    }
    
    ll q ;
    cin >> q ;
    while( q--){
        ll v, w ;
        cin >> v >> w ;
        ll ans = bfs(v, w) ;
        cout << ans << "\n" ;
    }    
    
    return 0 ;
}