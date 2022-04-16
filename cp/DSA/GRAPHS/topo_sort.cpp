// TOPOLOGICAL SORTING AND CYCLE DETECTION USING TOPOLOGICAL SORT:


vi *adj ;
vi vis(1e5+7, 0), ans ;


void dfs(ll src){
    vis[src] = 1 ;
    for(auto it:adj[src])
        if(!vis[it])
            dfs(it) ;
    ans.pb(src) ;
}

bool topo_sort(){
    for(ll i=1; i<=n; i++)
        if(!vis[i])
            dfs(i) ;
            
    reverse(ans.begin(), ans.end()) ;
    map<ll, ll> mp ;
    for(ll i=0; i<ans.size(); i++)
        mp[ans[i]] = i ;
        
    for(ll i=1; i<=n; i++)
        for(auto it:adj[i])
            if(mp[i] > mp[it])
                return false ;
                
    return true ;
}