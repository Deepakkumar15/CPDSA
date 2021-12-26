// SEGMENT TREE IMPLEMENTATION 
// EFFICIENT WAY (ITERATIVE METHOD)
// 0-BASED INDEXING ARRAY

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 1e5+7 ;
ll n, q;
ll t[2*N] ;

void build(){ // FOR BUILDING THE SEGMENT TREE ARRAY
    for(ll i=n-1; i>0; i--)
        t[i] = min(t[i<<1], t[i<<1|1]) ; // SUM OF LEFT CHILD + RIGHT CHILD
}

void modify(ll p, ll val){ // UPDATE ANY VALUE AT CERTAIN INDEX OF ARRAY 
    for(t[p+=n]=val; p>1; p >>= 1)
        t[p>>1] = min(t[p], t[p^1]) ; // DOING CHANGES IN THE VALUE OF PARENT AS WELL EXCEPT ROOT
}

void add(ll p, ll val){ // ADD ANY VALUE AT CERTAIN INDEX OF ARRAY 
    for(t[p+=n]+=val; p>1; p >>= 1)
        t[p>>1] = min(t[p], t[p^1]) ; // DOING CHANGES IN THE VALUE OF PARENT AS WELL EXCEPT ROOT
}

ll query(ll l, ll r){ // FIND SUM IN A GIVEN RANGE
    ll ans=INF ;
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
        if(l&1) // IF L -> RIGHT CHILD
            ans = min(ans, t[l++]) ;
        if(!(r&1)) // IF R -> LEFT CHILD
            ans = min(ans, t[r--]) ;
    }
    
    return ans ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n >> q ;
    for(ll i=n; i<2*n; i++)
        cin >> t[i] ;
    build() ;
    
    while(q--){
		char ch ;
		cin >> ch ;

		if(ch == 'u'){
			ll l, val ;
			cin >> l >> val ;
			modify(l-1, val) ;
		}
		else{
			ll l, r ;
			cin >> l >> r ;
			cout << query(l-1, r-1) << "\n" ;
		}
	}
    return 0 ;
}