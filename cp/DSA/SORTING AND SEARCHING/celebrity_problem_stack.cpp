//CELEBRITY PROBLEM TYPE QUESTION

#include <bits/stdc++.h>
 
using namespace std ;
 
// template for ordered_set 
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
 
const ll mod = 1e9+7 ;
const ll N = 2e5+7 ;
#define INF 1e9+7

bool cmp(vi &a, vi &b){
    ll cnt=0 ;
    for(ll i=0; i<5; i++)
        if(a[i] < b[i])
            cnt++ ;
    
    return cnt>=3 ;
}

void solve(){
    ll n ;
    cin >> n ;
    
    vvi a ;
    for(ll i=0; i<n; i++){
        vi tmp ;
        for(ll j=0; j<5; j++){
            ll x ;
            cin >> x ;
            tmp.push_back(x) ;
        }
        a.push_back(tmp) ;
    }
     
    if(n==1){
        cout << 1 << "\n" ;
        return ;
    } 

    stack<ll> s ;
    for(ll i=0; i<n; i++)
        s.push(i) ;
    
    while(s.size() > 1){
        ll i1 = s.top() ;
        s.pop() ;
        ll i2 = s.top() ;
        s.pop() ;
        
        // if i1 is superior to i2 -> push i1 push
        cmp(a[i1], a[i2]) ? s.push(i1) : s.push(i2) ;
    }
    
    // s.top() is the potential winner
    // check if it is winner or not, if not return -1
    vi res = a[s.top()] ;
    
    for(ll i=0; i<n; i++)
        if(res != a[i])
            if(!cmp(res, a[i])){
                cout << -1 << endl ;
                return ;
            }
        
    cout << s.top()+1 << endl ;
    return ;    
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    cin >> t ;
    
    while(t--)
        solve() ;
        
    return 0 ;
}