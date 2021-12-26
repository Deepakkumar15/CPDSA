// two pointer type implementation 
// max consecutive 1's after atmost k flips

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
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
ll n ;
string s ;

ll fn(char c1, ll k){
    ll l=0, r=0, len=0, ans = INT_MIN ;
    // run as sliding window type 
    while(l<n && r<n){
        if(s[r]==c1){
            r++; // move the right end by 1
            len++ ;
        }
        
        else{ // s[r] == 'c2', we need to change the character 
            if(k){ // we have more k left to make the transition
                k--; // decrease k by 1 and make the transition
                r++;
                len++ ;
            } 
            
            else{ // we have exhausted k
                // there are 2 cases 
                if(s[l]==c1){
                    l++; 
                    len-- ;
                }
                
                else{ // s[l] = 'c2', we made a transition there and while sliding the value of l
                      // we have to increase k by 1
                    l++;
                    len-- ;
                    k++ ;
                }
            }
        }
        
        ans = max(ans, len) ;
    }
    
    ans = max(ans, len) ;
    return ans ;
}

void solve(){
    ll k ;
    cin >> n >> k >> s ;
    
    cout << max(fn('a', k), fn('b', k)) << endl ;
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