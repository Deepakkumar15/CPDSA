// UNDIRECTED GRAPH
#include <bits/stdc++.h>
#include <iostream>

using namespace std ;
const int N = 3e3 + 10 ;
int p[N][N] ;
vector<int> l[N] ;

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    int n, m, k ;
    cin >> n >> m >> k ;
    int a, b ;
    
    for(int i=0; i<m; i++){
        cin >> a >> b ;
        l[a].push_back(b) ;
        l[b].push_back(a) ;
    }

    map<pair<pair<int, int>, int>, bool> umap ;
    while(k--){
        int p, q, r ;
        cin >> p >> q >> r ;
        umap[{{p,q},r}]=true ;    
    }
    queue<pair<int, int>> q; 
    q.push({-1, 1}) ;
    int sol = -1 ;
    while(!q.empty()){
        auto x = q.front() ;
        q.pop() ;
        if(x.second == n){
            sol = x.first ;
            break ;
        }
        for(auto it: l[x.second]){
            if(p[x.second][it] || umap[{x, it}])
                continue ;
            p[x.second][it] = x.first ;
            q.push({x.second, it}) ;
        }
    }

    if(sol == -1)
        cout << "-1" << endl  ;
    else{
        int x = n ;
        vector<int> v ;
        v.push_back(n) ;
        v.push_back(sol) ;
        while(p[sol][x]!=-1){
            v.push_back(p[sol][x]) ;
            int temp = p[sol][x] ;
            x = sol ;
            sol = temp ;
        }
        reverse(v.begin(), v.end()) ;
        cout << v.size()-1 << endl ;
        for (auto it:v)
            cout << it << " " ;
    }

    return 0 ;
}