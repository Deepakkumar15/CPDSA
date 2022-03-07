#include <bits/stdc++.h>
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  int
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


ll n, m, q ;
vector<set<ll>> lockdes(5e5+7) ;
class node{
public:
    ll descnt=0, user_id = -1 ;
    ll parent = -1 ;
    bool locked = false ;
};

vector<node> info(5e5+7) ;
vi *adj ;
ll cnt=0 ;
bool check_and_update_ancestors(ll node){
    for(ll ancestor = info[node].parent; ancestor != -1; ancestor = info[ancestor].parent)
        if(info[ancestor].locked)
            return false ;
    
    for(ll ancestor = info[node].parent; ancestor != -1; ancestor = info[ancestor].parent){
        info[ancestor].descnt += 1 ;
        lockdes[ancestor].insert(node) ;
    }
    return true ;
} 


bool lock_node(ll node, ll user_id){
    if(info[node].locked || info[node].descnt)
        return false ;
    
    bool update_resp = check_and_update_ancestors(node) ;
    if(update_resp){
        info[node].locked = true;
        info[node].user_id = user_id ;
    }
    
    return update_resp ;
}


bool unlock_node(ll node, ll user_id){
    if(info[node].user_id != user_id)
        return false ;
    
    for(ll ancestor = info[node].parent; ancestor != -1; ancestor = info[ancestor].parent){
        info[ancestor].descnt-- ;
        if(lockdes[ancestor].find(node) != lockdes[ancestor].end())
            lockdes[ancestor].erase(node) ;
    }
    
    info[node].locked = false ;
    info[node].user_id = -1 ;
    
    return true ;
}


bool upgrade_node(ll node, ll user_id){
    cout << "started processing " << node << " " << user_id << "\n" ;
    if(!info[node].descnt || info[node].locked){
        return false ;
    }
    
    for(auto it : lockdes[node]){
        if(user_id != info[it].user_id)
            return false ;
    }
    
    for(auto it : lockdes[node]){
        if(it <= 0 || it >= n){
            cnt++ ;
            cout << it << "----------\n" ;
            continue ;
        }
        cout << it << "----------\n" ;
        unlock_node(it, info[it].user_id) ;
    }
    
    for(ll i=0; i<7; i++)   
        cout << info[i].locked << " " ;
    cout << endl ;
    
    lock_node(node, user_id) ;
    return true ;
}
void solve(){
    unordered_map<string, ll> mp ;
    cin >> n >> m >> q ;
    adj = new vi [n+1] ;
    for(ll i=0; i<n; i++)
        lockdes[i].clear() ;
        
    for(ll i=0; i<n; i++){
        string str;
        cin >> ws ;
        getline(cin, str) ;
        mp[str] = i ;
        for(ll j=1; j<=m; j++){
            if(m*i+j >= n)
                break ;
            adj[i].pb(m*i+j) ;
            adj[m*i+j].pb(i) ;
            info[m*i+j].parent = i ;
        }
        
    }
    // cin >> ws ;
    for(auto it:mp)
        cout << it.ff << "-" << it.ss << endl ;
    for(ll i=0; i<q; i++){
        vs v ;
        ll op, user_id ;
        string str, temp;
        string country = "", s1 = "", s2 = "" ;
        getline(cin, str) ;
        stringstream ss(str) ;
        while(getline(ss, temp, ' ')){
            v.pb(temp) ;
        }
        ll sz = v.size() ;
        s1 += v[0] ;
        s2 += v[sz-1] ;
        op = stoi(s1) ;
        user_id = stoi(s2) ;
        for(ll i=1; i<sz-1; i++){
            country += v[i] ;
            if(i != sz-2)
                country += " " ;
        }
           
        cout << op << "-" << country << "-" << user_id << endl ; 
        if(op == 1){
            lock_node(mp[country], user_id) ? cout << "true\n" : cout << "false\n" ;
        }
        else if(op == 2){
            unlock_node(mp[country], user_id) ? cout << "true\n" : cout << "false\n" ;
        }
        else if(op == 3){
            cout << "opopop\n" ;
            upgrade_node(0LL, 5) ? cout << "true\n" : cout << "false\n" ;
        }
        
    }
    
    for(ll i=0; i<7; i++)   
        cout << info[i].locked << " " ;
    cout << endl ;
    return ;
}


signed main(){
    // ios_base::sync_with_stdio(false) ;
    // cin.tie(0) ;
    // cout.tie(0) ;

    ll t=1;
    // cin >> t ;

    while(t--)
        solve() ;

    return 0 ;
}
