// SEGMENT TREE IMPLEMENTATION 
// LAZY PROPAGATION IMPLEMENTATION
// DOUBLE UPDATE CAN BE DONE WITH THIS CODE

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vb  vector<bool>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
ll n, q;

// NODE CLASS STORES INFORMATION FOR EACH NODE OF SEGMENT TREE

class node{
public:
    ll v=INF ;
    
    node(){}
    node(ll val){
        v = val ;
    }
    
    // MERGING FUNCTION FOR A SPECIFIC node
    // CAN BE CHANGED ACCORDING TO THE QUESTION 
    void merge(node &l, node &r){
        v = min(l.v, r.v) ;
    }
};

// UPDATE CLASS STORES THE RECENT UPDATE FOR EACH NODE WITH LAZY IMPLEMENTATION 
class update{
public:
    ll v=0, idx=0;
    
    // IDX STORES THE INFORMATION THAT WHICH PROCESS TO BE DONE WHILE PUSHDOWN
    // AS 2 UPDATES CAN BE DONE SIMULTANEOUSLY
    
    update(){}
    update(ll val1, ll val2){
        v = val1 ;
        idx = val2 ;
    }
    
    // COMBINING FUNCTION IS USED TO COMBINE OLD AND RECENT UPDATE
    void combine(update &upd, ll tl, ll tr){
        if(upd.idx==2){
           v = upd.v ; // (IDX==2) SET EACH ELEMENT TO GIVEN VALUE IN A GIVEN RANGE
           idx = upd.idx ;
        }
        else{
            v += upd.v ;
            if(idx == 0 || idx == 1) // ONCE IDX==2 IS SET THEN WE CAN'T CHANGE IDX FURTHER 
                idx = upd.idx ;
        }
    }
    
    // APPLY FUNCTION IS USED TO PUSH DOWN THE CHANGES WHILE DOING QUERY ACCORDING TO THE 
    // RECENT IDX VALUE
    void apply(node &x, ll tl, ll tr){
        idx==2 ? x.v = v : x.v += v ;
    }
};

class segtree{
public:
    ll len ;
    vector<node> t ; // NODE ARRAY FOR STORING ALL THE NODES OF SEGMENT TREE
    vb lazy ; // BOOLEAN ARRAY FOR STORING IF A NODE IS LAZY OR NOT
    vector<update> u; // UDPATE ARRAY FOR STORING THE RECENT UPDATE FOR A SPECIFIC NODE
    
    segtree(ll l){
        len = l ;
        t.resize(4*len) ;
        u.resize(4*len) ;
        lazy.resize(4*len) ;
    }
    
    void apply(ll v, ll tl, ll tr, update &upd){
        if(tl != tr){
            lazy[v]=1 ;
            // IF NODE IS LAZY THEN COMBINE THE UPDATES
            u[v].combine(upd, tl, tr) ;
        }
        // NOW APPLY ALL THE CHANGES TO THE GIVEN NODE T[V] 
        upd.apply(t[v], tl, tr) ;
    }
    
    void pushdown(ll v, ll tl, ll tr){
        if(!lazy[v])
            return ;
        ll tm = (tl+tr)>>1 ;
        
        apply(v<<1, tl, tm, u[v]) ;
        apply(v<<1|1, tm+1, tr, u[v]) ;
        
        // SET THE NODE TO NOT LAZY AND ALL UPDATES TO 0
        update upd(0, 0);
        u[v] = upd ;
        lazy[v]=0 ;
    }
    
    void build_(vi &arr, ll v, ll tl, ll tr){
        if(tl == tr){ // LEAF NODES
            t[v] = arr[tr] ;
            return ;
        }
        
        ll tm = (tl+tr) >> 1 ;
        build_(arr, v<<1, tl, tm) ;
        build_(arr, v<<1|1, tm+1, tr) ;
        
        t[v].merge(t[v<<1], t[v<<1|1]) ;
    }
    
    // FOR DOING QUERY IN ANY GIVEN RANGE
    node query_(ll v, ll tl, ll tr, ll l, ll r){
        if(l > tr || r < tl)
            return INF;
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
    
    // BOTH UPDATIONS ON RANGE CAN BE DONE BY THIS MODIFY FUNCTION
    void modify_(ll v, ll tl, ll tr, ll l, ll r, update &upd){
        if(l > tr || r < tl)
            return ;
        if(tl >= l && tr <= r){
            apply(v, tl, tr, upd) ;
            return ;
        }
        
        // PUSHDOWN ALL THE CHANGES FIRST TO IT'S CHILDREN
        pushdown(v, tl, tr) ;
        ll tm = (tl+tr) >> 1 ;
        modify_(v<<1, tl, tm, l, r, upd) ;
        modify_(v<<1|1, tm+1, tr, l, r, upd) ;
        t[v].merge(t[v<<1], t[v<<1|1]) ;
    }
    
    
public:  
    void build(vi &arr){
        build_(arr, 1ll, 0ll, len-1) ;
    }
    
    ll query(ll l, ll r){
        return query_(1ll, 0ll, len-1, l, r).v ;    
    }
    
    void modify(ll l, ll r, ll val, ll idx){
        update upd(val, idx) ;
        modify_(1ll, 0ll, len-1, l, r, upd) ;
    }
    
};

signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
    
    cin >> n >> q ;
    vi arr(n) ;
    for(ll i=0; i<n; i++)
        cin >> arr[i] ;
    segtree s(n) ;
    s.build(arr) ;
    
    while(q--){
		char ch;
		cin >> ch;

		if(ch == 'u'){
			ll l, val ;
			cin >> l >> val ;
			s.modify(l-1, l-1, val, 2) ;
		}
		else{
			ll l, r ;
			cin >> l >> r ;
			cout << s.query(l-1, r-1) << "\n" ;
		}
	}
	return 0 ;
}