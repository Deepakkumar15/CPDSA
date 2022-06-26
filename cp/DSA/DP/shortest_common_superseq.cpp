// shortest common supersequence



#define ll long long int

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ll n = str1.size() ;
        ll m = str2.size() ;
        
        ll dp[n+1][m+1] ;
        for(ll i=0; i<=n; i++)
            for(ll j=0; j<=m; j++)
                dp[i][j] = 0 ;
        
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1 ;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
            }
        }
        
        string shortest_common_superseq = "" ;
        ll i=n, j=m ;
        while(i && j){
            if(str1[i-1] == str2[j-1]){
                i-- ; j-- ;
                shortest_common_superseq += str1[i] ;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i-- ;
                shortest_common_superseq += str1[i] ;
            }
            else{
                j-- ;
                shortest_common_superseq += str2[j] ;
            }
            
        }
        
        while(i){
            i-- ;
            shortest_common_superseq += str1[i] ;
        }
        while(j){
            j-- ;
            shortest_common_superseq += str2[j] ;
        }
        
        reverse(shortest_common_superseq.begin(), shortest_common_superseq.end()) ;
        return shortest_common_superseq ;
        
    }
};





// use index array to store the indices of LCS


#define ll long long int

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ll n = str1.size() ;
        ll m = str2.size() ;
        
        ll dp[n+1][m+1] ;
        for(ll i=0; i<=n; i++)
            for(ll j=0; j<=m; j++)
                dp[i][j] = 0 ;
        
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1 ;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
            }
        }
        
        vector<pair<int, int>> index ;
        
        ll i=n, j=m ;
        while(i && j){
            if(str1[i-1] == str2[j-1]){
                i-- ; j-- ;
                index.push_back({i, j}) ;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i-- ;
            }
            else
                j-- ;
            
        }
        
        index.push_back({-1, -1}) ;
        reverse(index.begin(), index.end()) ;
        
        string shortest_common_superseq = "" ;
        
        for(ll idx=1; idx<index.size(); idx++){
            ll first_str_limit = index[idx].first, sec_str_limit = index[idx].second ;
            ll ff = index[idx-1].first+1 ;
            ll ss = index[idx-1].second+1 ;
            while(ff<first_str_limit)
                shortest_common_superseq += str1[ff++] ;
            while(ss<sec_str_limit)
                shortest_common_superseq += str2[ss++] ;
            
            shortest_common_superseq += str1[first_str_limit] ;
        }
        
        i = index[index.size()-1].first+1 ;
        j = index[index.size()-1].second+1 ;
        while(i<n)
            shortest_common_superseq += str1[i++] ;
        while(j<m)
            shortest_common_superseq += str2[j++] ;
        
        return shortest_common_superseq ;
        
    }
};