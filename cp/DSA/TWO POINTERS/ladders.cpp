// CF 171 DIV2 - C

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

void solve(){
    ll n, m;
    cin >> n >> m ;
    vi a(n) ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    vpi b(m) ;
    for(ll i=0; i<m; i++)
        cin >> b[i].ff >> b[i].ss ;
    
    if(n<=2){
        for(ll i=0; i<m; i++)
            cout << "Yes\n" ;
        return ;
    }
    vi l, r ;
    ll i=0;
    // find all the v of u size buckets
    // size of v type bucket -> 3 and u size -> variable
    while(i<n-2){
        if(a[i] > a[i+1] && a[i+1] <= a[i+2]){
            if(a[i+1] < a[i+2]){ // v type bucket
                l.pb(i) ;
                r.pb(i+2) ;
                i+=2 ;
            }
            else{ // u type bucket
                ll x=i;
                i++ ;
                while(i<n-1 && a[i] == a[i+1])
                    i++ ;
                if(i != n-1 && a[i] < a[i+1]){
                    l.pb(x) ;
                    r.pb(i+1) ;
                }
            }
        }
        
        else
            i++ ;
    }
    
    if(l.size()==0){ // no bucket is present
        for(ll i=0; i<m; i++)
            cout << "Yes\n" ;
        return ;
    }
    
    ll len = l.size() ;
    for(ll i=0; i<m; i++){
        ll x = b[i].ff-1 ;
        ll y = b[i].ss-1 ;
        auto idx1 = lower_bound(l.begin(), l.end(), x)-l.begin() ;
        auto idx2 = lower_bound(r.begin(), r.end(), y)-r.begin() ;
        if(idx1 != len){
            ll left = l[idx1], right = r[idx1] ;
            if(left >=x && right <= y){
                cout << "No\n" ;
                continue ;
            }
        }
        
        if(idx2 != len){
            ll left = l[idx2], right = r[idx2] ;
            if(left >=x && right <= y){
                cout << "No\n" ;
                continue ;
            }
        }
        
        cout << "Yes\n" ;
    }
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    ll t=1;
    // cin >> t ;

    while(t--)
        solve() ;

    return 0 ;
}