// VERY NICE GCD IMPLEMENTATION QUESTION 
// ADA AND GCD SPOJ SOLUTION
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
ll mp[10000005]={0}, dp[10000005], cnt[10000005]={0}, lp[10000005] ;

ll power(ll x, ll y){
    ll res=1 ;
    x%=mod ;
    while(y){
        if(y&1)
            res = ((res % mod) * (x % mod)) % mod;
        x = (x*x) % mod ;
        y>>=1 ;
    }
    
    return res ;
}

// void prime_power(ll n){
//     while(n%2==0){
//         mp[2]++ ;
//         n>>=1 ;
//     }
    
//     for(ll i=3; i*i<=n; i+=2)
//         while(n%i==0){
//             mp[i]++ ;
//             n/=i ;
//         }
        
//     if(n>2)
//         mp[n]++ ;
//     return ;
// }

void solve(){
    ll n, m ;
    cin >> n ;
    ll res = n ;
    
    for(ll i=2; i<10000005; i++)
        if(!lp[i])
            for(ll j = i; j<10000005; j+=i)
                lp[j] = i;

    for(ll i=0; i<10000005; i++)
        dp[i] = INT_MAX ;
        
    while(n--){
        cin >> m ;
        set<ll> s ;
        while(m--){
            ll x ;
            cin >> x ;
            while(x>1){
                ll f = lp[x] ;
                if(s.find(f) == s.end())
                    s.insert(f) ;
                while(x%f==0){
                    mp[f]++ ;
                    x/=f;
                }
            }
            
        }
        
        for(auto it:s){
            dp[it] = min(dp[it], mp[it]) ;
            cnt[it]++ ;
            mp[it]=0 ;
        }
    }
    
    ll gcd=1 ;
    for(ll i=2; i<10000005; i++)
        if(cnt[i]==res)
            gcd = ((gcd % mod) * (power(i, dp[i]) % mod) ) % mod ;
        
    cout << gcd << "\n" ;    
    
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    // cin >> t ;
    while(t--)
        solve() ;
    
    return 0 ;
}