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









// N^3 SOLUTION:

// dp[j] -> LCIS value if the LCIS end at b[j] (jth element of second array)

void solve(){
    ll n, m;
    cin >> n ;
    vi a(n) ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    cin >> m ;
    vi b(m) ;
    for(ll i=0; i<m; i++)
        cin >> b[i] ;
        
    vi dp(m, 0) ;
    
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(a[i] == b[j]){
                ll prev_max_lcis = 0 ;
                for(ll k=j; k>=0; k--)
                    if(b[k] < b[j])
                        prev_max_lcis = max(prev_max_lcis, dp[k]) ;
                
                dp[j] = max(prev_max_lcis+1, dp[j]) ;
                
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) ;
    
    return ;
}




// PRINTING OF LCIS: -> KEEP TRACK OF PREV ELEMENT AS WELL IN FROM OF PREV_IDX
                        // I.E INDEX OF PREVIOUS ELEMENT IN LCIS

void solve(){
    ll n, m;
    cin >> n ;
    vi a(n) ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    cin >> m ;
    vi b(m), dp(m, 0), prev_idx(m, -1);
    for(ll i=0; i<m; i++){
        cin >> b[i] ;
        prev_idx[i] = i ;
    }
        
    
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(a[i] == b[j]){
                ll prev_max_lcis = 0, idx = j;
                for(ll k=j; k>=0; k--)
                    if(b[k] < b[j] && prev_max_lcis < dp[k]){
                        prev_max_lcis = dp[k] ;
                        idx = k ;
                    }
                
                if(prev_max_lcis+1 > dp[j]){
                    dp[j] = prev_max_lcis+1;
                    prev_idx[j] = idx ;
                }
                
            }
        }
    }
    
    ll mx_idx = 0 ;
    for(ll i=0; i<m; i++)
        if(dp[i] > dp[mx_idx])
            mx_idx = i ;
    
    cout << dp[mx_idx] << endl ;
    
    if(!dp[mx_idx])
        return ;
    
    vi lcis ;
    while(mx_idx != prev_idx[mx_idx]){
        lcis.pb(b[mx_idx]);
        mx_idx = prev_idx[mx_idx] ;
    }
    lcis.pb(b[mx_idx]) ;
    
    reverse(lcis.begin(), lcis.end()) ;
    for(auto it:lcis)
        cout << it << " " ;
        
    return ;
}






// N^2 SOLUTION: 


void solve(){
    ll n, m;
    cin >> n ;
    vi a(n) ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    cin >> m ;
    vi b(m), dp(m, 0), prev_idx(m, -1);
    for(ll i=0; i<m; i++){
        cin >> b[i] ;
        prev_idx[i] = i ;
    }
        
    
    for(ll i=0; i<n; i++){
        ll prev_max_lcis = 0, idx=-1;
        for(ll j=0; j<m; j++){
            if(a[i] == b[j] && prev_max_lcis + 1 > dp[j]){
                dp[j] = prev_max_lcis + 1;
                prev_idx[j] = idx ;
            }
            
            if(b[j] < a[i] && prev_max_lcis < dp[j]){
                prev_max_lcis = dp[j] ;
                idx = j ;
            }
        }
    }
    
    ll mx_idx = 0 ;
    for(ll i=0; i<m; i++)
        if(dp[i] > dp[mx_idx])
            mx_idx = i ;
    
    cout << dp[mx_idx] << endl ;
    
    if(!dp[mx_idx])
        return ;
    
    vi lcis ;
    while(mx_idx != -1){
        lcis.pb(b[mx_idx]);
        mx_idx = prev_idx[mx_idx] ;
    }
    // lcis.pb(b[mx_idx]) ;
    
    reverse(lcis.begin(), lcis.end()) ;
    for(auto it:lcis)
        cout << it << " " ;
        
    return ;
}
