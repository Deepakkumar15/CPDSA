// CF LINK: https://codeforces.com/contest/1675/problem/D


#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<ll> s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
// s.order_of_key(k) -> return no. of element strictly less than k
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

#define min_pair_heap  priority_queue<pi, vpi, greater<pi> >
#define min_heap       priority_queue<ll, vi, greater<ll> >
#define debug(x) cout << (#x) << " -> " << (x) << endl

// Direction arrays
ll dx[4] = {1, 0, 0, -1}; // DLRU
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

vi *adj ;
vi siz(2e5+5, 1), heavy(2e5+5, 0) ;
map<ll, vi> mp ;

void dfsH(ll src, ll chain, ll par){
    if(mp.find(chain) != mp.end())
        mp[chain].push_back(src) ;
    else{
        vi temp ;
        temp.pb(src) ;
        mp[chain] = temp ;
    }
    
    if(heavy[src] != 0)
        dfsH(heavy[src], chain, src) ;
    
    for(auto it : adj[src]){
        if(it != heavy[src] && it != par)
            dfsH(it, it, src) ;
    }
}

void dfs(ll src, ll par){
    for(auto it: adj[src]){
        if(it != par){
            dfs(it, src) ;
            siz[src] += siz[it] ;
            if(siz[it] >= siz[heavy[src]])
                heavy[src] = it ;
        }
    }    
}

void solve(){
    ll n ;
    cin >> n ;
    
    adj = new vi [n+2] ;
    for(ll i=0; i<=n; i++){
        siz[i] = 1 ;
        heavy[i] = 0 ;
    }
    
    ll root = 0 ;
    for(ll i=1; i<=n; i++){
        ll x ;
        cin >> x ;
        if(x == i){
            root = x ;
            continue ;
        }
        adj[i].pb(x) ;
        adj[x].pb(i) ;
        
    }
    
    dfs(root, -1) ;
    dfsH(root, root, -1) ;
    
    cout << mp.size() << "\n" ;
    for(auto it:mp){
        cout << it.ss.size() << "\n" ;
        for(auto itr: it.ss)
            cout << itr << " "  ;
        cout << "\n" ;
    }
     
    cout << endl ;
    
    siz.clear() ; heavy.clear() ; mp.clear() ;
    
    for(ll i=0; i<=n; i++)
        adj[i].clear() ;
        
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