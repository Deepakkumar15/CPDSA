// COIN CHANGE PROBLEM
// RECURSION + MEMOIZATION SOLUTION
class Solution{
    public:
        long long int dp[1005][1005] ;
        Solution(){
            memset(dp, -1, sizeof(dp)) ;
        }
                
        long long int count( int S[], int m, int n ){
            if(n==0) 
                return 1 ;
            if(m==0)
                return 0 ;
            
            if(dp[m][n] != -1)
                return dp[m][n] ;
                
            if(S[m-1]<=n)
                return dp[m][n] = count(S, m-1, n) + count(S, m, n-S[m-1]) ;
            else
                return dp[m][n] = count(S, m-1, n) ;
            
        }
};



// ITERATIVE DP VERSION
class Solution{
    public:
                
        long long int count( int S[], int m, int n ){
            long long int dp[m+1][n+1] ;
            for(int i=0; i<=m; i++)
                dp[i][0]=1 ;
            for(int j=1; j<=n; j++)
                dp[0][j]=0 ;
                
            for(int i=1; i<=m; i++){
                for(int j=1; j<=n; j++){
                    if(S[i-1]<=j)
                        dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]] ;
                    else
                        dp[i][j] = dp[i-1][j] ;
                }
            }    
            
            return dp[m][n] ;
            
        }

};


// min number of coins required to make change
// 0(n*m) solution (not memory efficient)
#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
ll n, sum ;

void min_coins(vi &coins){
    ll dp[n][sum+1] ;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<=sum; j++)
            dp[i][j] = INT_MAX ;
    
    // initialize the first row and first column
    // if the sum == 0, then we require 0 number of coins
    for(ll i=0; i<n; i++)
        dp[i][0] = 0 ;

    // if the sum is the multiple of first coin, then only we can make the required sum
    for(ll j=1; j<=sum; j++)
        if(j%coins[0]==0)
            dp[0][j] = j/coins[0] ;
            
    for(ll i=1; i<n; i++)
        for(ll j=1; j<=sum; j++)
            j-coins[i]>=0 ? dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1) : dp[i][j] = dp[i-1][j] ;
        
            
    dp[n-1][sum]==INT_MAX ? cout << -1 : cout << dp[n-1][sum] ;
    return ;
}

void solve(){
    cin >> n >> sum ;
    vi coins(n) ;
    for(ll i=0; i<n; i++)
        cin >> coins[i] ;
    sort(coins.begin(), coins.end()) ;
    
    min_coins(coins) ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    // cin >> t ;
    while(t--)
        solve() ;
    
    return 0 ;
}               



// min number of coins required to make the change of sum
// 0(n) solution
#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
ll n, sum ;

void min_coins(vi &coins){
    ll n = coins.size() ;
    ll dp[sum+1] ;
    for(ll i=0; i<=sum; i++)
        dp[i] = INT_MAX ;
        
    // dp[i] -> states that min number of coins required to make the change i 
    dp[0]=0 ;
    for(ll i=1; i<=sum; i++)
        for(ll j=0; j<n; j++)
            if(i-coins[j]>=0)
                dp[i] = min(dp[i], dp[i-coins[j]]+1) ;
                
    dp[sum]==INT_MAX ? cout << -1 : cout << dp[sum] ;            
    return ;
}

void solve(){
    cin >> n >> sum ;
    vi coins(n) ;
    for(ll i=0; i<n; i++)
        cin >> coins[i] ;
    sort(coins.begin(), coins.end()) ;
    
    min_coins(coins) ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    // cin >> t ;
    while(t--)
        solve() ;
    
    return 0 ;
}               




// total number of ways to make required change
#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
ll n, sum ;

void min_coins(vi &coins){
    ll n = coins.size() ;
    ll dp[sum+1] = {0} ;
    
    // dp[i] -> states that total number of ways to make the required change i 
    dp[0]=1 ;
    for(ll i=1; i<=sum; i++)
        for(ll j=0; j<n; j++)
            if(i-coins[j]>=0)
                dp[i] = (dp[i]%mod + dp[i-coins[j]]%mod) % mod ;
                
    cout << dp[sum] ;          
    return ;
}

void solve(){
    cin >> n >> sum ;
    vi coins(n) ;
    for(ll i=0; i<n; i++)
        cin >> coins[i] ;
    sort(coins.begin(), coins.end()) ;
    
    min_coins(coins) ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1 ;
    // cin >> t ;
    while(t--)
        solve() ;
    
    return 0 ;
}               