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

ll power(ll x, ll y, ll p){
    ll res=1 ;
    x%=p ;
    while(y){
        if(y&1)
            res = ((res%p) * (x%p))%p;
        x = (x*x)%p ;
        y>>=1 ;
    }
    
    return res ;
}

void solve(){
    ll x, y, p ;
    cin >> x >> y >> p ;
    
    cout << power(x, y, p) << "\n" ;
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




// MULTIPLICATION OF TWO BIG INTERGERS UNDER MOD

ll multiply(ll x, ll y){
    ll res = 0 ;
    x%=mod ;
    while(y){
        if(y&1)
            res = (res%mod + x%mod) % mod ;
        x = (2 * (x%mod)) % mod ;
        y >>= 1 ;
    }
    
    return res % mod ;
}