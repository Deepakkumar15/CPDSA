// TYPE-2 OF EULER TOUR OF A TREE OR TREE FLATTENING 
// EULER TOUR OF TYPE-2 (USED FOR MOST OF TIME)
// POWERFUL CONCEPT (EULER TOUR + RANGE QUERIES)

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 2e5+7 ;
vi adj[N] ; // FOR MAKING TREE
vi te(2*N+1) ; // FOR EULER TOUR OF TREE
vi st(N+1), ed(N+1) ; // FOR STORING STARTING AND ENDING TIME OF A NODE
vi t(4*N+2) ; // FOR BUILDING SEGMENT TREE
bool visited[N] = {false} ;

ll n, q, tim=1;

// FOR MAKING START AND END ARRAY FOR EULER TOUR OF TYPE-2
// WE CAN ALSO STORE REQUIRED DATA ACC. TO QUESTION DEMAND
void dfs(ll src){
    visited[src]=true ;
    st[src] = tim++ ; 
    for(auto it : adj[src])
        if(!visited[it])   
            dfs(it) ;
    
    ed[src] = tim++ ;
    return ;
}

void build(){ // FOR BUILDING THE SEGMENT TREE ARRAY
    for(ll i=2*n-1; i>0; i--)
        t[i] = t[i<<1] + t[i<<1|1] ; // SUM OF LEFT CHILD + RIGHT CHILD
}

void modify(ll p, ll val){ // UPDATE ANY VALUE AT CERTAIN INDEX OF ARRAY 
    for(t[p+=2*n]=val; p>1; p >>= 1)
        t[p>>1] = t[p] + t[p^1] ; // DOING CHANGES IN THE VALUE OF PARENT AS WELL EXCEPT ROOT
}

ll sum_query(ll l, ll r){ // FIND SUM IN A GIVEN RANGE
    ll sum=0 ;
    for(l+=2*n, r+=2*n; l<=r; l>>=1, r>>=1){
        if(l&1) // IF L -> RIGHT CHILD
            sum += t[l++] ;
        if(!(r&1)) // IF R -> LEFT CHILD
            sum += t[r--] ;
    }
    
    return sum ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n >> q ;
    ll m = n-1 ;
    ll a[n+1] ;
    for(ll i=1; i<=n; i++)
        cin >> a[i] ;
        
    while(m--){
        ll x, y ;
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    
    dfs(1) ;
    // MAKING EULER TOUR ARRAY FROM STARTING AND ENDING ARRAY
    for(ll i=1; i<=n; i++){
        te[st[i]]=a[i] ;
        te[ed[i]]=a[i] ;
    }
    
    for(ll i=2*n; i<4*n; i++)
        t[i] = te[i-(2*n)+1] ;
        
    build();
  
    while(q--){
        ll x ;
        cin >> x ;
        if(x==1){
            ll val, s ;
            cin >> s >> val ;
            modify(st[s]-1, val) ;
            modify(ed[s]-1, val) ;
        }
        else{
            ll s ;
            cin >> s ;
            cout << sum_query(st[s]-1, ed[s]-1)/2 << "\n" ;
        }
    }
    
    return 0 ;
}