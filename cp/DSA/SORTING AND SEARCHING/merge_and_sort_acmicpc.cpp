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
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7

void solve(){
    ll t ;
    cin >> t ;
    vi v ;
    ll cost=0 ;
    
    while(t--){
        ll n ;
        cin >> n ;
        vi a(n), res;
        ll len=0 ;
        
        for(ll i=0; i<n; i++){
            cin >> a[i] ;
            // len++ ;
            if(i!=0 && a[i] < a[i-1]){
                v.push_back(len) ;
                res.push_back(len) ;
                len=0 ;
            }
            len++ ;
        }
        
        if(len > 0){
            v.push_back(len) ;
            res.push_back(len) ;
        }
        
        ll l=0, r=res.size()-1 ;
        
        while(l<r){
            if(res[l] <= res[r])
                cost += res[l++] ;
            
            else
                cost += res[r--] ;
        }
    }

    
    
    // merge part
    priority_queue<ll, vector<ll>, greater<ll>> pq(v.begin(), v.end()) ;
    
    // ll cost=0 ;
    while(pq.size() > 1){
        ll p1 = pq.top() ;
        pq.pop() ;
        
        ll p2 = pq.top() ;
        pq.pop() ;
        
        cost += p1+p2 ;
        pq.push(p1+p2) ;
    }
    
    
    cout << cost << endl ;
    
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