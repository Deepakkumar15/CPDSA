#include <bits/stdc++.h>
 
using namespace std ;

// template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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


// Z FUNCTION FOR STRING MATCHING PATTERN
vi z_function(string s) {
    ll n = s.length() ;
    vi z(n) ;
    for(ll i=1, l=0, r=0; i<n; i++) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    
    return z;
}

void solve(){
    string s ;
    cin >> s ;
    
    ll n = s.length() ;
    if(n<3){
        cout << "Just a legend" << endl  ;
        return ;
    }
    vi z = z_function(s) ;
    ll ans=INT_MIN;
    
    // let's try to find out the suffix first and store them in a set
    set<ll> st ;
    for(ll i=1; i<n; i++)
        if(i+z[i]==n)
            st.insert(z[i]) ;
    
    // if no suffix matching is present in the string
    if(!st.size()){
        cout << "Just a legend" << endl ;
        return ;
    }
    
    for(ll i=1; i<n; i++){
        // to find the suitable suffix for this substring matching
        auto it = st.upper_bound(z[i]) ;
        if(it == st.begin())
            continue ; 
        it-- ; 
        // now 2 cases arises
        // 1) if the substring is suffix itself
        if(i+z[i] == n){ 
            if(z[i] == *it){
                if(it == st.begin())
                    continue ;
                it-- ;
            }
            // now checking for largest ans
            ans = max(ans, *it) ;
        }

        // if the middle part is not the suffix
        else if(n > i+z[i])
            ans = max(ans, *it) ;
    }
    
    ans == INT_MIN ? cout << "Just a legend" << endl : cout << s.substr(0, ans) << endl ;
        
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    // cin >> t ;
    while(t--)
        solve() ;
    
    return 0 ;
}               