// BASIC DSU IMPLEMENTATION
#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
#define vi vector<int>
#define vs vector<string>

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

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll n ;
    cin >> n ;
    vi parent(n+1) ;
    vi size(n+1, 1) ;
    for(ll i=0; i<=n; i++)
        parent[i]=i ;
        
    return 0 ;
}