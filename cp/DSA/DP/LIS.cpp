// O(N^2) SOLUTION FOR LIS 
// DP ONLY

#define ll long long int
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        ll dp[n+1] ;
        for(ll i=0; i<=n; i++)
            dp[i]=1 ;  
        // dp[i] -> states that subsequence of max length we can make with i elements
        
        dp[0]=0 ;
        
        for(ll i=2; i<=n; i++)
            for(ll j=1; j<i; j++)
                if(a[i-1] > a[j-1])
                    dp[i] = max(dp[i], dp[j]+1) ;
        
        
        return *max_element(dp, dp+n+1) ;            
    }
};


// O(NLOGN) SOLUTION FOR LIS
// DP + BINARY SEARCH

#define ll long long int
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<ll> ans ;
        ans.push_back(a[0]) ;
        
        for(ll i=1; i<n; i++){
            if(ans.back() < a[i])
                ans.push_back(a[i]) ;
            else{
                auto it = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin() ;
                ans[it] = a[i] ;
            }
        }
        
        return ans.size() ;
    }
};