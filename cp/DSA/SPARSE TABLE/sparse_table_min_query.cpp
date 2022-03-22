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
const ll N = 2e5+7 ;
const ll K = 30 ; // for total bits as length of interval can be 2^16 for 1e5 value
ll n, q;
ll a[N] ;
ll t[N][K] ;

void build(){ // for min_range _query (can be changed as per the query requirement)
    for(ll j=1; j<K; j++)
        for(ll i=0; i+(1<<j)<=n; i++)
            t[i][j] = min(t[i][j-1], t[i+(1<<(j-1))][j-1]) ;
}

ll query(ll l, ll r){ // FOR IDEMPOTENT FUNCTION QUERIES ONLY
    ll len = r-l+1 ;
    ll j = log2(len) ;
    return min(t[l][j], t[r-(1<<j)+1][j]) ; // ANSWERING IN O(1) TIME
    // APPLICABLE ONLY FOR IDEMPOTENT FUNCTION
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n >> q ;
    for(ll i=0; i<n; i++){
        cin >> a[i] ;
        t[i][0] = a[i] ; // for interval length 1 i.e the element itself
    }
    
    build() ;
    
    while(q--){
        ll l, r ;
        cin >> l >> r ;
        cout << query(l-1, r-1) << "\n" ;
    }
    return 0 ;
}
