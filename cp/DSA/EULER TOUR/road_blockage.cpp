// PROBLEM LINK : https://practice.geeksforgeeks.org/contest/
//job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/

#include <bits/stdc++.h>

#define ll int
class Solution {
  public:
    ll t[400007] ;
    vector<ll> *adj ;
    vector<ll> depth, parent;
    vector<ll> st, ed ;
    ll time_cnt=0 ;
    
    void dfs(ll src, ll par){
        st[src] = time_cnt++ ;
        for(auto it : adj[src])
            if(it != par){
                depth[it] = depth[src] + 1 ;
                parent[it] = src ;
                dfs(it, src) ;
            }
        
        ed[src] = time_cnt++ ;
    }
    
    void build(ll n){ // FOR BUILDING THE SEGMENT TREE ARRAY
        for(ll i=2*n-1; i>0; i--)
            t[i] = max(t[i<<1], t[i<<1|1]) ; // SUM OF LEFT CHILD + RIGHT CHILD
    }
    
    
    ll mx_query(ll l, ll r, ll n){ // FIND SUM IN A GIVEN RANGE
        ll ans=INT_MIN ;
        for(l+=2*n, r+=2*n; l<=r; l>>=1, r>>=1){
            if(l&1) // IF L -> RIGHT CHILD
                ans = max(ans, t[l++]) ;
            if(!(r&1)) // IF R -> LEFT CHILD
                ans = max(ans, t[r--]) ;
        }
        
        return ans ;
    }
    
    vector<int> solve(int n, int q, vector<vector<int> > &edge,
                      vector<vector<int> > &query) {
        adj = new vector<ll> [n+1] ;
        
        for(auto it : edge){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        
        for(ll i=0; i<=n; i++){
            depth.push_back(0) ;
            st.push_back(0) ;
            ed.push_back(0) ;
            parent.push_back(-1) ;
        }
            
        dfs(0, -1) ;
        
        for(ll i=0; i<n; i++){
            t[st[i] + 2*n] = depth[i] ;
            t[ed[i] + 2*n] = depth[i] ;
        }
        build(n) ;
        
        vector<ll> ans ;
        for(ll i=0; i<q; i++){
            ll res = 0 ;
            ll x = query[i][0] ;
            ll y = query[i][1] ;
            
            if(x != parent[y])
                swap(x, y) ;
            
            ll mx1 = mx_query(0, st[y]-1, n) ;
            ll mx2 = mx_query(ed[y]+1, 2*n-1, n) ;
                
            res = max(mx1, mx2) ;    
            ans.push_back(res) ;
        }
        
        return ans ;
    }
};