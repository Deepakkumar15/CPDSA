// GOOD IMPLEMENTATION OF MEX OF AN ARRAY
// CF 767 DIV2 - C
#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll   long long int
#define ld   long double
#define vi   vector<ll>
#define vs   vector<string>
#define vb   vector<bool>
#define pi   pair<ll, ll>
#define vpi  vector<pi>
#define vvi  vector<vi>
#define ff   first
#define ss   second
#define pb   push_back
#define mpi  map<ll, ll>
#define umpi unordered_map<ll, ll>
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


ll cal_mex(set<ll> mex, ll m){
    while(true){
        if(mex.find(m) != mex.end())
            m++ ;
        else
            return m ;
    }    
}


void solve(){
    ll n ;
    cin >> n ;
    vi a(n), b ;
    set<ll> mex;
    umpi mp ;
    for(ll i=0; i<=n; i++)
        mex.insert(i) ;
    for(ll i=0; i<n; i++){
        cin >> a[i] ;
        if(mex.find(a[i]) != mex.end())
            mex.erase(a[i]) ;
        mp[a[i]]++ ;
    }
      
    ll i=0 ;
    while(i<n){
        ll curr_mex = *(mex.begin()) ;
        // debug(curr_mex) ;
        ll j=i ;
        set<ll> req ;
        while(j<n){
            mp[a[j]]-- ;
            if(mp[a[j]] == 0)
                mex.insert(a[j]) ;
            if(a[j] < curr_mex)
                req.insert(a[j]) ;
            if(req.size() == curr_mex){
                b.pb(curr_mex) ;
                break ;
            }
            j++ ;
        }
        
        // for(auto it:mex)
        //     cout << it << " " ;
        // cout << endl ;
        // debug(j) ;
        i = j ;
        i++ ;
    }
    
    cout << b.size() << "\n" ;
    for(auto it:b)
        cout << it << " " ;
    cout << endl ;
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