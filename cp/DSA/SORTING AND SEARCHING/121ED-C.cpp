// EDUCATIONAL 121 DIV-2 C

#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  long long int
#define ld  long double
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff  first
#define ss  second
#define pb  push_back
#define debug(x) cout << (#x) << " -> " << (x) << endl

// Direction arrays
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7

// Modular Exponentiation
ll power(ll x, ll y, ll p){
    ll res=1 ; x%=p ;
    while(y){ if(y&1) res = ((res%p) * (x%p))%p; x = (x*x)%p ; y>>=1 ;}
    return res ;
}

// Modular Multiplication
ll multiply(ll x, ll y, ll p=mod){
    ll res = 0 ; x%=p ;
    while(y){ if(y&1) res = (res%p + x%p) % p ; x = (2 * (x%p)) % p ; y >>= 1 ;}
    return res % p ;
}

// Modular Division
ll divide(ll a, ll b, ll p=mod) {
  if (b % p == 0)return -1;
  return multiply(a % p, power(b, p - 2, p), p);
}



void solve(){
    ll n ;
    cin >> n ;
    vi k(n), h(n) ;
    for(ll i=0; i<n; i++)
        cin >> k[i] ;
    for(ll i=0; i<n; i++)
        cin >> h[i] ;
    
    vpi intervals ;
    for(ll i=0; i<n; i++){
        intervals.pb({k[i]-h[i]+1, k[i]}) ;
    }
    
    ll index = 0 ;
    
    sort(intervals.begin(), intervals.end()) ;
    for(ll i=1; i<n; i++){
        if(intervals[index].ss < intervals[i].ff){ // no merging occurs 
            index++ ;
            intervals[index] = intervals[i] ;
        }
        
        else // merging occurs here
            intervals[index].ss = max(intervals[index].ss, intervals[i].ss) ;
        
    }
    
    intervals.resize(index+1) ;
    ll sz = intervals.size() ;
    
    ll ans=0 ;
    for(ll i=0; i<sz; i++){
        ll t = intervals[i].ss - intervals[i].ff + 1;
        ans += (t*(t+1))/2 ;
    }
    
    cout << ans << "\n" ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    ll t=1;
    cin >> t ;

    while(t--)
        solve() ;

    return 0 ;
}