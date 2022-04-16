// CF LINK: https://codeforces.com/problemset/problem/1252/C

#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<ll> s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
// s.order_of_key(k) -> return no. of element strictly less than k
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
ll dx[4] = {1, 0, 0, -1}; // DLRU
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


// path compression 
ll find(vi &parent, ll a){
    return parent[a] = (parent[a]==a ? a : find(parent, parent[a])) ;
}

// by size
void Union(vi &parent, vi &size, ll a, ll b){
    ll pa = find(parent, a) ;
    ll pb = find(parent, b) ;
    
    if(pa != pb){
        if(size[pa] < size[pb])
            swap(pa, pb) ;
        parent[pb] = pa ;
        size[pa]+=size[pb] ;
    }
    
    return ;
}


void solve(){
    ll n, q;
    cin >> n >> q ;
    vi r(n), c(n), parentr(n+1), parentc(n+1), sizer(n+1, 1), sizec(n+1, 1);
    for(ll i=0; i<=n; i++){
        parentr[i] = i ;
        parentc[i] = i ;
    }
    cin >> r[0] ;
    for(ll i=1; i<n; i++){
        cin >> r[i] ;
        if((r[i-1]%2==0 && r[i]%2==0) || (r[i-1]%2==1 && r[i]%2==1))
            Union(parentr, sizer, i-1, i) ;
    }
    cin >> c[0] ;
    for(ll i=1; i<n; i++){
        cin >> c[i] ;
        if((c[i-1]%2==0 && c[i]%2==0) || (c[i-1]%2==1 && c[i]%2==1))
            Union(parentc, sizec, i-1, i) ;
    }
    
    while(q--){
        ll r1, c1, r2, c2 ;
        cin >> r1 >> c1 >> r2 >> c2 ;
        if(find(parentr, r1-1) == find(parentr, r2-1) && find(parentc, c1-1) == find(parentc, c2-1))
            cout << "YES\n" ;
        else
            cout << "NO\n" ;
    }    
    
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











// BRUTE FORCE SOLUTION I.E DSU ON A GRID

#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<ll> s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
// s.order_of_key(k) -> return no. of element strictly less than k
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
ll dx[4] = {1, 0, 0, -1}; // DLRU
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


ll find(vi &parent, ll a){
    return parent[a] = (parent[a] == a ? a : find(parent, parent[a])) ;
}

void Union(vi &parent, vi &size, ll a, ll b){
    ll pa = find(parent, a) ;
    ll pb = find(parent, b) ;
    
    if(pa != pb){
        if(size[pa] < size[pb])
            swap(pa, pb) ;
        
        size[pa] += size[pb] ;
        parent[pb] = pa ;
    }
}

void solve(){
    ll n, q ;
    cin >> n >> q ;
    vi a(n), b(n) ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    for(ll i=0; i<n; i++)
        cin >> b[i] ;
    vi parent(n*n+1), size(n*n+1, 1) ;
    for(ll i=0; i<=n*n; i++)
        parent[i] = i ;
       
    vvi v(n, vi (n));
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
           v[i][j] = a[i] + b[j] ;
    
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(j<n-1 && v[i][j]%2==0 && v[i][j+1]%2==0)
                Union(parent, size, i*n+j+1, i*n+j+2) ;
            if(i<n-1 && v[i][j]%2==0 && v[i+1][j]%2==0)
                Union(parent, size, i*n+j+1, i*n+j+n+1) ;
        }
    }
    
    while(q--){
        ll r1, c1, r2, c2 ;
        cin >> r1 >> c1 >> r2 >> c2 ;
        r1--, r2-- ;
        ll x1 = r1*n+c1, x2 = r2*n+c2 ;
        if(find(parent, x1) == find(parent, x2))
            cout << "YES\n" ;
        else
            cout << "NO\n" ;
    }
    return ;
}


int main() {

    ll t=1 ;
//  cin >> t ;
    while(t--){
        solve() ;
    }   
    return 0;
}