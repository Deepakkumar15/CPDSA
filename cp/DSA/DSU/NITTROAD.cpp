// NITT ROAD SPOJ SOLUTION
// OPTIMIZATION THROUGH SIZE ALONG WITH PATH COMPRESSION
// PROCESS FROM BACK OFFLINE QUERIES

#include <bits/stdc++.h>
 
using namespace std ;
#define ll long long int
#define vi vector<long long int>
#define vs vector<string>
 
ll find(vi &parent, ll a){
    return parent[a] = (parent[a]==a ? a : find(parent, parent[a])) ;
}
 
ll Union(vi &parent, vi &size, ll a, ll b){
    ll pa = find(parent, a) ;    
    ll pb = find(parent, b) ;
    ll ans=0 ;
    if(pa != pb){
        if(size[pa] < size[pb])
            swap(pa, pb);
        parent[pb] = pa;
        ans = size[pa]*size[pb] ;
        size[pa] += size[pb];
    }
    
    return ans ;
}
 
signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t ;
    cin >> t ;
    while(t--){
        ll n, q ;
        cin >> n ;
        vi parent(n+1) ;
        vi size(n+1, 1) ;
        vector<pair<pair<ll, ll>, bool>> v(n) ;
        
        for(ll i=0; i<=n; i++)
            parent[i] = i ;
            
        for(ll i=1; i<=n-1; i++){
            ll a, b ;
            cin >> a >> b ;
            v[i] = {{a, b}, false} ;
        }
        
        stack<ll> s ;
        cin >> q ;
        while(q--){
            char ch ;
            cin >> ch ;
            if(ch == 'Q')
                s.push(0) ;
            else{
                ll x; 
                cin >> x ;
                s.push(x) ;
                v[x].second = true ;
            }    
        }
        
        ll count = (n*(n-1)) / 2 ;
        for(ll i=1; i<n; i++){
            if(v[i].second == false){
                ll ans = Union(parent, size, v[i].first.first, v[i].first.second) ;
                count -= ans ;
            }
        }
        
        vi result ;
        while(!s.empty()){
            ll res = s.top() ;
            s.pop() ;
            if(!res)
                result.push_back(count) ;
            else{
                ll temp = Union(parent, size, v[res].first.first, v[res].first.second) ;
                count -= temp ;
            }    
        }
        
        reverse(result.begin(), result.end()) ;
        for(auto it:result)
            cout << it << "\n" ;
            
        cout << "\n" ;
    }
      
    return 0 ;
}