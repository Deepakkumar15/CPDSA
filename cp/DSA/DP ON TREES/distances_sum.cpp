// leetcode link: https://leetcode.com/problems/sum-of-distances-in-tree/solution/

// TREE RE-ROOTING TECHNIQUE

#define ll int

class Solution {
public:
    vector<ll> *adj ;
    // dp[i] -> store the distances_sum / final ans for ith node
    vector<ll> subtree_size, dp ;
    ll tree_size = 1 ;
    
    void dfs(ll src, ll par){
        for(auto it : adj[src]){
            if(it != par){
                dfs(it, src) ;
                // calculate the subtree size of the src node
                subtree_size[src] += subtree_size[it] ;
                // calculate ans for the subtree of src only
                // contribution of the edge between parent and it's one of the childs
                // -> distances_sum of child + subtree_size of the child
                dp[src] += (subtree_size[it] + dp[it]) ;
            }
        }
    }
    
    void get_distances_sum(ll src, ll par){
        // already calculated for root -> 0 in dfs fn as we made it the arbitrary node.
        if(src != 0){
            // now re-root the root from parent to it's child(src)
            // child distance_sum = distance_sum(parent) - (remove the edge between parent and this child)
            //                      + (make the child as root i.e change the edge now from child to parent)
            //                      + (distance_sum of child)

            // This is the main equation -> 
            // dp[src] = dp[par] - (subtree_size[src] + dp[src]) + (subtree[par] - subtree[src]) + dp[src] 
            dp[src] = dp[par] + subtree_size[par] - (2*subtree_size[src]) ;

            // change the subtree_size of src -> bcoz it's the root of the tree now.
            subtree_size[src] = tree_size ;
        }
        
        for(auto it : adj[src])
            if(it != par)
                get_distances_sum(it, src) ;
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(ll i=0; i<=n; i++){
            subtree_size.push_back(1) ;
            dp.push_back(0) ;
        }
        
        adj = new vector<ll> [n+1]; 
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        
        dfs(0, -1) ;
        tree_size = n ;
        
        get_distances_sum(0, -1) ;
        
        vector<ll> distances(n) ;
        for(ll i=0; i<n; i++)
            distances[i] = dp[i] ;
        
        return distances ;
    }
};