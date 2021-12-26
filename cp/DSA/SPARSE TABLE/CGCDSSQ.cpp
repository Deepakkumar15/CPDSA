/*CODEFORCES QUESTION (SPARSE TABLE + BINARY SEARCH) */


// SPARSE TABLE IMPLEMENTATION
// IDEMPOTENT FUNCTION IMPLEMENTATION ONLY (min, max, gcd, and, or)
// NOT FOR RANGE SUM QUERY

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 1e5+7 ;
const ll K = 30 ; // for total bits as length of interval can be 2^16 for 1e5 value
ll n, q;
ll a[N] ;
ll t[N][K] ;
unordered_map<ll, ll> cnt;

void build(){ // for range_gcd_query (can be changed as per the query requirement)
    for(ll j=1; j<K; j++)
        for(ll i=0; i+(1<<j)<=n; i++)
            t[i][j] = __gcd(t[i][j-1], t[i+(1<<(j-1))][j-1]) ;
}

ll query(ll l, ll r){ // FOR IDEMPOTENT FUNCTION QUERIES ONLY
    ll len = r-l+1 ;
    ll j = log2(len) ;
    return __gcd(t[l][j], t[r-(1<<j)+1][j]) ; // ANSWERING IN O(1) TIME
    // APPLICABLE ONLY FOR IDEMPOTENT FUNCTION
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n ;
    for(ll i=0; i<n; i++){
        cin >> a[i] ;
        t[i][0] = a[i] ; // for interval length 1 i.e the element itself
    }
    
    build() ;
    
    for(ll i=0; i<n; i++){
        ll j=i ;
        while(j<n){
            ll gcd = query(i, j) ;
            ll l=j, r=n-1, ans=i ;
            while(l<=r){
                ll mid = (l+r)>>1 ;
                if(query(i, mid)==gcd){
                    ans = mid ;
                    l = mid+1 ;
                }
                else
                    r = mid-1 ;
            }
            
            cnt[gcd] += ans-j+1 ;
            j = ans+1 ;
        }
    }
    
    cin >> q ;
    while(q--){
        ll x;
        cin >> x ;
        cout << cnt[x] << "\n" ;
    }
    return 0 ;
}