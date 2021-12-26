// ITERATIVE FUNCTIOIN 
// BINARY EXPONENTIATION IN LOG(N) 
#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7

ll power(ll x, ll y){
    ll res=1 ;
    while(y){
        if(y&1)
            res = res*x;
        x*=x ;
        y>>=1 ;
    }
    
    return res ;
}

void solve(){
    ll x, y ;
    cin >> x >> y ;
    
    cout << power(x, y) << "\n" ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    cin >> t ;
    while(t--)
        solve() ;
    
    return 0 ;
}