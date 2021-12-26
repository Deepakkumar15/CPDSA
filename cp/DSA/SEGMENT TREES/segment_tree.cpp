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
#define INF 1e+9+7
const ll N = 1e5+7 ;
ll n ;
ll t[2*N] ;

void build(){ // FOR BUILDING THE SEGMENT TREE ARRAY
    for(ll i=n-1; i>0; i--)
        t[i] = t[i<<1] + t[i<<1|1] ; // SUM OF LEFT CHILD + RIGHT CHILD
}

void modify(ll p, ll val){ // UPDATE ANY VALUE AT CERTAIN INDEX OF ARRAY 
    for(t[p+=n]=val; p>1; p >>= 1)
        t[p>>1] = t[p] + t[p^1] ; // DOING CHANGES IN THE VALUE OF PARENT AS WELL EXCEPT ROOT
}

void add(ll p, ll val){ // ADD ANY VALUE AT CERTAIN INDEX OF ARRAY 
    for(t[p+=n]+=val; p>1; p >>= 1)
        t[p>>1] = t[p] + t[p^1] ; // DOING CHANGES IN THE VALUE OF PARENT AS WELL EXCEPT ROOT
}

ll sum_query(ll l, ll r){ // FIND SUM IN A GIVEN RANGE
    ll sum=0 ;
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1){
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
    
    cin >> n ;
    for(ll i=n; i<2*n; i++)
        cin >> t[i] ;
    build() ;
    
    modify(2, 5) ;
    add(0, 3) ;
    for(ll i=1; i<20; i++)
        cout << t[i] << " " ;
    cout << endl ;
    // ARRAY FOLLOWS O-BASED INDEXING 
    cout << sum_query(0, 7) << endl ;
    return 0 ;
}