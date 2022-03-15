//CF -> 408 DIV-2 D

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


vpi *adj ;
ll n, k, d;
set<ll> cut_road ;

void bfs(vi &police){
    queue<ll> q ;
    vi dist(n+1, INT_MAX) ;
    vi parent(n+1, -1) ;
    for(auto source : police){
        q.push(source) ;
        dist[source] = 0 ;
    }
    
    while(!q.empty()){
        ll sz = q.size() ;
        while(sz--){
            ll par = q.front() ;
            q.pop() ;
            for(auto child : adj[par]){
                if(dist[child.ff] == INT_MAX){
                    if(dist[par] + 1 > d)
                        break ;
                    dist[child.ff] = dist[par] + 1 ;
                    parent[child.ff] = par ;
                    q.push(child.ff) ;
                }
                // condition for checking if we are visiting the parent or not
                else if(parent[child.ff] != par && parent[par] != child.ff){
                    cut_road.insert(child.ss) ;
                }
            }
        }
    }
    
    return ;
}


void solve(){
    cin >> n >> k >> d;
    adj = new vpi [n+1] ;
    vi police ;
    for(ll i=0; i<k; i++){
        ll x ;
        cin >> x ;
        police.pb(x) ;
    }
    
    for(ll i=1; i<n; i++){
        ll x, y ;
        cin >> x >> y ;
        adj[x].pb({y, i}) ;
        adj[y].pb({x, i}) ;
    }
    
    bfs(police) ;
    
    cout << cut_road.size() << "\n" ;
    for(auto it:cut_road)
        cout << it << " " ;
    cout << endl ;
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
