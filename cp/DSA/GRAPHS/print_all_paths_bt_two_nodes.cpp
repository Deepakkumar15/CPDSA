

// PRINT ALL PATHS BETWEEN TWO NODES:

// USING DFS:

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

vi vis(10, 0) ;
vi *adj ;
void dfs(vi &src, ll par, ll dest){
    ll curr = src.back() ;
    // print the path
    if(curr == dest){
        for(auto it:src)
            cout << it << " " ;
        cout << endl ;
    }
    
    for(auto it:adj[curr]){
        if(!vis[it] && it != par){
            vi new_src(src) ;
            new_src.pb(it) ;
            dfs(new_src, curr, dest) ;
        }
    }
    
    return ;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    adj = new vi [n+1] ;
    while(m--){
        ll x, y ;
        cin >> x >> y ;
        adj[x].pb(y) ;
    }
    
    ll start, dest ;
    cin >> start >> dest ;
    vi src;
    src.pb(start) ;
    dfs(src, -1, dest) ;
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







// USING BFS:

vi vis(10, 0) ;
vi *adj ;
bool isVisited(vi &path, ll node){
    // fn to check if we already visited the vertex or not
    for(auto it : path)
        if(it == node)
            return true ;
    return false ;
}

void bfs(vi &src, ll dest){
    queue<vi> q ;
    q.push(src) ;
    
    while(!q.empty()){
        vi temp = q.front() ;
        q.pop() ;
        ll par = temp.back() ;
        if(par == dest){
            for(auto it:temp)
                cout << it << " " ;
            cout << endl ;
        }
        
        for(auto it: adj[par]){
            if(!isVisited(temp, it)){
                vi new_src(temp) ;
                new_src.pb(it) ;
                q.push(new_src) ;
            }
        }
        
    }
    
    return ;
}
