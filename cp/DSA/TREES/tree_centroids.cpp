// FIND CENTROIDS OF THE TREE
// PROBLEM LINK: https://leetcode.com/problems/minimum-height-trees/submissions/

#define ll int

class Solution {
public:
    vector<ll> *adj ;
    
    vector<ll> find_centroids_of_tree(vector<ll> &degree, ll n){
        queue<ll> q ;
        for(ll i=0; i<n; i++)
            if(degree[i] == 1){
                degree[i]-- ;
                q.push(i) ;
            }
        
        // do multisource bfs from every leaf node & reduce their degree
        vector<ll> centroids ;
        while(!q.empty()){
            ll sz = q.size() ;
            centroids.clear() ;
            
            while(sz--){
                ll par = q.front() ;
                q.pop() ;
                centroids.push_back(par) ;
                
                for(auto it : adj[par]){
                    if(--degree[it] == 1){ // it will be new leaf now
                        q.push(it) ;
                    }
                }
            }
        }
        
        return centroids ;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj = new vector<ll> [n+1] ;
        vector<ll> degree(n+1) ; 
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        if(n==1){
            return {0} ;    
        }
        
        vector<ll> centroids = find_centroids_of_tree(degree, n) ;
        
        return centroids;
    }
};