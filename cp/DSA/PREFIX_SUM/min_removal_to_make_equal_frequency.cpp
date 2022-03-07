// CF 702-DIV3 F SOL
// Minimum removals required to make frequency of all remaining array elements equal

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



void solve(){
    ll n ;
    cin >> n ;
    map<ll, ll> mp ;
    for(ll i=0; i<n; i++){
        ll x ;
        cin >> x ;
        mp[x]++ ;
    }
    
    vi v ;
    for(auto it:mp)
        v.pb(it.ss) ;
    sort(v.begin(), v.end()) ;
    ll sz = v.size() ;
    vi prefix_sum(sz+1, 0) ;
    for(ll i=0; i<sz; i++)
        prefix_sum[i+1] = prefix_sum[i] + v[i] ;
    
    ll min_op = prefix_sum[sz];
    for(ll i=1; i<=sz; i++){
        ll res = prefix_sum[i-1] + (prefix_sum[sz]-prefix_sum[i-1] - (v[i-1]*(sz-i+1))) ;
        min_op = min(min_op, res) ;
    }
    
    cout << min_op << "\n" ;    
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








// WITHOUT PREFIX SUM:

void solve(){
    ll n ;
    cin >> n ;
    map<ll, ll> freq;
 
    // Traverse the array
    for (int i = 0; i < n; i++) {
        ll x ;
        cin >> x ;
        freq[x]++;
    }
 
    // Stores all the frequencies
    vector<int> v;
 
    // Traverse the map
    for (auto z : freq) {
        v.push_back(z.second);
    }
 
    // Sort the frequencies
    sort(v.begin(), v.end());
 
    // Count of frequencies
    int size = v.size();
 
    // Stores the final count
    ll ans = n - (v[0] * size);
 
    // Traverse the vector
    for (int i = 1; i < v.size(); i++) {
 
        // Count the number of removals
        // for each frequency and update
        // the minimum removals required
        if (v[i] != v[i - 1]) {
            ll safe = v[i] * (size - i);
            ans = min(ans, n-safe);
            // SAFE IS SUBTRACTED FROM N BECAUSE SUM OF ALL THE FREQ. -> N (TOTAL NO. OF ELEMENTS.)
        }
    }
 
    // Print the final count
    cout << ans << "\n" ;
    return ;
}
