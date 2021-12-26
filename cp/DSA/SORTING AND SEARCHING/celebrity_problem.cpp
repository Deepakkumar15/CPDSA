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

    vvi b = a ;
    sort(a.begin(), a.end(), cmp) ;
    
    // potential winner will be a[0], else there is no winner(return -1)
    vi res = a[0] ;
    ll cnt=0 ;
    // check if a[0] is winner or not
    for(ll i=1; i<n; i++){
        cnt=0 ;
        for(ll j=0; j<5; j++)
            if(res[j] < a[i][j])
                cnt++ ;
        if(cnt < 3){
            cout << -1 << endl ;
            return ;
        }
    }
    
    for(ll i=0; i<n; i++)
        if(b[i] == res){
            cout << i+1 << endl ;
            return ;
        }
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