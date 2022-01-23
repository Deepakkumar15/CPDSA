#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  long long int
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


bool check(vi &h, ll mid){
    ll n = h.size() ;
    vi add(n, 0) ;
    vi final_val(n, 0) ;
    for(ll i=n-1; i>1; i--){
        if(h[i] + add[i] >= mid){
            ll d = min(h[i]/3, (h[i]+add[i]-mid)/3) ;
            final_val[i] = h[i] - (3*d) + add[i] ;
            add[i-1] += d ;
            add[i-2] += 2*d ;
        }
        
        else
            return false ;
    }
    
    final_val[1] = h[1]+add[1] ;
    final_val[0] = h[0]+add[0] ;
    
    for(ll i=0; i<n; i++)
        if(final_val[i] < mid)
            return false ;
    return true ;
}

void solve(){
    ll n ;
    cin >> n ;
    vi h(n) ;
    ll sum=0 ;
    for(ll i=0; i<n; i++){
        cin >> h[i] ;
        sum+=h[i] ;
    }
    
    if(h[n-1] == 1){
        cout << 1 << "\n" ;
        return ;
    }
    
    ll l = *min_element(h.begin(), h.end()) ;
    // binary search on answer
    ll r = sum;
    ll res=0 ;
    while(l<=r){
        ll mid = (l+r) >> 1 ;
        if(check(h, mid)){
            l = mid+1 ;
            res = mid ;
        }
        else
            r = mid-1 ;
    }
    
    cout << res << "\n" ;
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