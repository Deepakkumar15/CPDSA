// MULTISOURCE BFS IN A GRID
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

// ll n, m ;
// vi ans ;
vi bfs(ll n, ll m, vvi &vis, vvi &level){
    vi ans ;
    ll r = n/2;
    ll c = m/2 ;
    ll tt = r+c;
    queue<pi> q ;
    
    if(n%2==0 && m%2==0){
        vis[r][c] = 1;
        vis[r-1][c] = 1;
        vis[r][c-1] = 1;
        vis[r-1][c-1] = 1;
        level[r][c] = tt;
        level[r-1][c] = tt;
        level[r][c-1] = tt; 
        level[r-1][c-1] = tt;
        for(ll i=0; i<4; i++)
            ans.pb(level[r][c]) ;
            
        q.push({r,c}) ;
        q.push({r-1,c}) ;
        q.push({r,c-1}) ;
        q.push({r-1,c-1}) ;
    }
    
    else if(n%2==1 && m%2==1){
        vis[r][c] = 1 ;
        level[r][c] = tt;
        ans.pb(level[r][c]) ;
        q.push({r, c}) ;
    }
    
    else{
        vis[r][c] = 1;
        level[r][c] = tt;
        ans.pb(level[r][c]) ;
        ans.pb(level[r][c]) ;
        q.push({r, c}) ;
        if(n%2==0){
            vis[r-1][c] = 1;
            level[r-1][c] = tt;
            q.push({r-1, c}) ;
        }
        else{
            vis[r][c-1] = 1;
            level[r][c-1] = tt;
            q.push({r, c-1}) ;
        }
    }
    
    while(!q.empty()){
        ll k = q.size() ;
        while(k--){
            pi p = q.front();
            q.pop() ;
            for(ll i=0; i<4; i++){
                ll x = p.first + dx[i] ;
                ll y = p.second + dy[i] ;

                if(x >= n || x < 0 || y<0 || y>=m || vis[x][y]==1)
                    continue ;
                vis[x][y] = 1;
                level[x][y] = level[p.ff][p.ss]+1 ;
                ans.pb(level[x][y]) ;
                q.push({x, y}) ; // push in the queue
            }
        }
    }
        
    return ans;
    
}

void solve(){
    ll n, m ;
    cin >> n >> m ;
    vvi vis, level ;    
    for(ll i=0; i<n; i++){
        vi temp ;
        for(ll j=0; j<m; j++){
            temp.pb(0) ;
        }
        vis.pb(temp) ;
        level.pb(temp) ;
    }
    
    vi ans = bfs(n, m , vis, level) ;
    
    for(auto it:ans)
        cout << it << " " ;
    cout << "\n" ;
    
    
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