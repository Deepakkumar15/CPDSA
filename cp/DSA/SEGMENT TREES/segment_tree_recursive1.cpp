#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vb  vector<bool>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e+9+7
ll n, q;

class node{
public:
    ll v=0 ;
    
    node(){}
    node(ll val){
        v = val ;
    }
    
    void merge(node &l, node &r){
        v = l.v + r.v ;
    }
};

class update{
public:
    ll v=0 ;
    
    update(){}
    update(ll val){
        v = val ;
    }
    
    void combine(update &upd, ll tl, ll tr){
        v += upd.v ;
    }
    
    void apply(node &x, ll tl, ll tr){
        x.v += (tr-tl+1) * v ;
    }
};

class segtree{
public:
    ll len ;
    vector<node> t ;
    vb lazy ;
    vector<update> u;
    // node identity_element ;
    // update identity_transform ;
    
    segtree(ll l){
        len = l ;
        t.resize(4*len) ;
        u.resize(4*len) ;
        lazy.resize(4*len) ;
        // identity_transform = update() ;
        // identity_element = node() ;
    }
    
    void apply(ll v, ll tl, ll tr, update &upd){
        if(tl != tr){
            lazy[v]=1 ;
            u[v].combine(upd, tl, tr) ;
        }
        upd.apply(t[v], tl, tr) ;
    }
    
    void pushdown(ll v, ll tl, ll tr){
        if(!lazy[v])
            return ;
        ll tm = (tl+tr)>>1 ;
        
        apply(v<<1, tl, tm, u[v]) ;
        apply(v<<1|1, tm+1, tr, u[v]) ;
        
        u[v] = 0 ;
        lazy[v]=0 ;
    }
    
    void build_(vi &arr, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = arr[tr] ;
            return ;
        }
        
        ll tm = (tl+tr) >> 1 ;
        build_(arr, v<<1, tl, tm) ;
        build_(arr, v<<1|1, tm+1, tr) ;
        
        t[v].merge(t[v<<1], t[v<<1|1]) ;
    }
    
    node query_(ll v, ll tl, ll tr, ll l, ll r){
        if(l > tr || r < tl)
            return 0;
        if(tl >= l && tr <= r)
            return t[v] ;
        
        pushdown(v, tl, tr) ;
        ll tm = (tl+tr) >> 1 ;
        node res1 = query_(v<<1, tl, tm, l, r) ;
        node res2 = query_(v<<1|1, tm+1, tr, l, r) ;
        node ans ;
        ans.merge(res1, res2) ;
        return ans ;
    }
    
    void modify_(ll v, ll tl, ll tr, ll l, ll r, update &upd){
        if(l > tr || r < tl)
            return ;
        if(tl >= l && tr <= r){
            apply(v, tl, tr, upd) ;
            return ;
        }
        
        pushdown(v, tl, tr) ;
        ll tm = (tl+tr) >> 1 ;
        modify_(v<<1, tl, tm, l, r, upd) ;
        modify_(v<<1|1, tm+1, tr, l, r, upd) ;
        t[v].merge(t[v<<1], t[v<<1|1]) ;
    }
    
    void update_(ll v, ll tl, ll tr, ll l, ll r, update &upd){
        if(l > tr || r < tl)
            return ;
        if(tl >= l && tr <= r){
            apply(v, tl, tr, upd) ;
            return ;
        }
        
        pushdown(v, tl, tr) ;
        ll tm = (tl+tr) >> 1 ;
        update_(v<<1, tl, tm, l, r, upd) ;
        update_(v<<1|1, tm+1, tr, l, r, upd) ;
        t[v].merge(t[v<<1], t[v<<1|1]) ;
    }
    
    
    
public:  
    void build(vi &arr){
        build_(arr, 1ll, 0ll, len-1) ;
    }
    
    ll query(ll l, ll r){
        return query_(1ll, 0ll, len-1, l, r).v ;    
    }
    
    void modify1(ll l, ll r, ll val){
        update upd = val ;
        modify_(1ll, 0ll, len-1, l, r, upd) ;
    }
    
    void modify2(ll l, ll r, ll val){
        update upd = val ;
        return update_(1ll, 0ll, len-1, l, r, upd) ;
    }
};

signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
    
    cin >> n ;
    vi arr(n) ;
    for(ll i=0; i<n; i++)
        cin >> arr[i] ;
    segtree s(n) ;
    s.build(arr) ;
    
    s.modify1(0, 7, 5) ;
    s.modify1(1, 3, 2) ;
    for(ll i=0; i<n; i++)
        cout << s.query(i, i) << " " ;
        
    cout << endl ;    
	return 0 ;
}