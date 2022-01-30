// finding mex of an array tricks


//The approach takes O(NlogN) precomputation, but each MEX query takes O(1) time
// and updates the MEX of an array in O(logN) for every point update in the array.
// In C++ :-
// Precomputation:
// - Create a set and a frequency map(or array).
// - Fill the set with all numbers from 0 to n+1.
// - Now, traverse in the array, if the element is within [0, n+1] remove it from the set, 
//   and keep updating the frequency map(or array). It takes at worst O(NlogN) time.
// - Now, for any state, the set.begin() will give the MEX of the current array.

// For updates:
// - If the element to be replaced, is within [0, n+1] then update its frequency in 
//   the frequency map(or array) and if after updating, the frequency of that element 
//   becomes zero, insert it into our set. It takes O(logN) time.
// - Now if the element which is placed in that position is within [0, n+1] then update its 
//   frequency in the frequency map(or array) and remove it from our set(if its present). 
//   It takes O(logN) time.
// - And yet again, after any update, set.begin() will give us the current MEX in O(1).



// FINDING MEX FUNCTION:
ll cal_mex(set<ll> &s, ll m){
    while(true){
        if(s.find(m) != s.end())
            m++ ;
        else
            return m ;
    }
}


// FINDING MEX OF AN ARRAY IN O(1)
set<ll> mex;
umpi mp ;
for(ll i=0; i<=n; i++)
    mex.insert(i) ;
for(ll i=0; i<n; i++){
    cin >> a[i] ;
    if(mex.find(a[i]) != mex.end())
        mex.erase(a[i]) ;
    mp[a[i]]++ ;
}

ll curr_mex = *(mex.begin()) ; // this will give the current mex of the array


// FINDING MEX OF AN ARRAY IF UPDATION OF ELEMENTS IS OCCURRING
ll curr_mex = *(mex.begin()) ;
ll idx = curr_mex ;
mp[a[idx]]-- ;
if(mp[a[idx]] == 0)
    mex.insert(a[idx]) ;
a[idx] = curr_mex ;
b.pb(idx) ;
if(mex.find(curr_mex) != mex.end()){
    mex.erase(curr_mex) ;
    mp[curr_mex]++ ;
}



// CF GLOBAL ROUND 9 - D QUE
// QUESTION ON MEX IF ARRAY ELEMENTS ARE UPDATING
#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll   long long int
#define ld   long double
#define vi   vector<ll>
#define vs   vector<string>
#define vb   vector<bool>
#define pi   pair<ll, ll>
#define vpi  vector<pi>
#define vvi  vector<vi>
#define ff   first
#define ss   second
#define pb   push_back
#define mpi  map<ll, ll>
#define umpi unordered_map<ll, ll>
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

bool is_valid(vi &a){
    ll n = a.size() ;
    for(ll i=0; i<n; i++)
        if(a[i] != i)
            return false ;
    return true ;
}

void solve(){
    ll n ;
    cin >> n ;
    vi a(n) ;
    set<ll> mex;
    umpi mp ;
    for(ll i=0; i<=n; i++)
        mex.insert(i) ;
    for(ll i=0; i<n; i++){
        cin >> a[i] ;
        if(mex.find(a[i]) != mex.end())
            mex.erase(a[i]) ;
        mp[a[i]]++ ;
    }
      
    vi b ;
    while(true){
        if(is_valid(a))
            break ;
        ll curr_mex = *(mex.begin()) ;
        ll idx = curr_mex ;
        // debug(curr_mex) ;
        if(idx == n){
            for(ll i=0; i<n; i++)
                if(a[i]!=i){
                    idx = i;
                    break ;
                }
        }
        if(idx == n)
            break ;
        mp[a[idx]]-- ;
        if(mp[a[idx]] == 0)
            mex.insert(a[idx]) ;
        a[idx] = curr_mex ;
        b.pb(idx+1) ;
        if(mex.find(curr_mex) != mex.end()){
            mex.erase(curr_mex) ;
            mp[curr_mex]++ ;
        }
    }
    
    cout << b.size() << endl ;
    for(auto it:b)
        cout << it << " " ; 
    cout << endl ;
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