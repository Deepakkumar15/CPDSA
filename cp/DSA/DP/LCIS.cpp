// LCIS -> LONGEST COMMON INCREASING SUBSEQUENCE

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
#define debug(x) cout << (#x) << " -> " << (x) << endl

// Direction arrays
ll dx[4] = {1, 0, 0, -1}; // DLRU
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
vi a(505, 0) ; 
vi b(505, 0) ;
vi dp(505, 0); 
vi idx(505, 0) ;

void fn(ll id){
    if(id==0)
        return ;
    fn(idx[id]) ;
    cout << b[id] << " " ;
}

void solve(){
    ll n, m;
    cin >> n ;
    for(ll i=1; i<=n; i++)
        cin >> a[i] ;
        
    cin >> m ;
    for(ll i=1; i<=m; i++)
        cin >> b[i] ;
    
            
    for(ll i=1; i<=n; i++){
        ll id=0;
        for(ll j=1; j<=m; j++){
            if(a[i] == b[j]){
                dp[j] = dp[id]+1 ;
                idx[j] = id ;
            }
            
            else if(a[i] > b[j] && dp[id] < dp[j])
                id = j ;
               
        }
        
    }        

    ll id=0 ;
    for(ll j=1; j<=m; j++)
        if(dp[j] > dp[id])
            id = j ;
            
    cout << dp[id] << "\n" ;
    fn(id) ;
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