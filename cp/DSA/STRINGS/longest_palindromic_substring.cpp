// LONGEST PALINDROMIC SUBSTRING

#define ll long long int

bool is_palindrome(string s1){
    string s2 = s1 ;
    reverse(s2.begin(), s2.end()) ;
    
    return s1 == s2 ;
}

class Solution {
public:
    string longestPalindrome(string s) {
        ll n = s.size() ;
        
        string longest_palindrome = "";
        longest_palindrome += s[0] ;
        for(ll i=0; i<n-1; i++){
            for(ll j=i; j<n; j++){
                if(is_palindrome(s.substr(i, j-i+1)) && longest_palindrome.length() < j-i+1)
                    longest_palindrome = s.substr(i, j-i+1) ;
            }
        }
        
        return longest_palindrome ;
    }
};




// DP SOLUTION:


#define ll long long int

class Solution {
public:
    string longestPalindrome(string s) {
        ll n = s.size() ;
        ll dp[n+1][n+1] ;
        
        for(ll i=0; i<=n; i++)
            for(ll j=0; j<=n; j++)
                dp[i][j] = 0 ;
        
        for(ll i=0; i<n; i++)
            dp[i][i] = 1 ; // 1 length string
        
        for(ll i=0; i<n-1; i++)
            if(s[i] == s[i+1]) // 2 length string
                dp[i][i+1] = 1 ;
        
        
        for(ll i=3; i<=n; i++){
            for(ll j=0; j<=n-i; j++){
                ll end = i+j-1 ;
                if(s[j] == s[end] && dp[j+1][end-1])
                    dp[j][end] = 1 ;
                else
                    dp[j][end] = 0 ;
            }
        }
        
        ll x=0, y=0 ;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(dp[i][j] && y-x+1 < j-i+1){
                    x = i; y = j ;
                }
            }
        }
        
        string longest_palindrome = "" ;
        for(ll i=x; i<=y; i++)
            longest_palindrome += s[i] ;
        
        return longest_palindrome ;
    }
};




// FINDING THE CENTER OF THE PALINDROME.

#define ll long long int

class Solution {
public:
    string longestPalindrome(string s) {
        ll n = s.size() ;
        ll st = 0, end=0 ;
        
        // odd length palindrome -> mid -> center of the palindrome
        for(ll mid=0; mid<n; mid++){
            ll x = 1 ;
            while(mid-x >=0 && mid+x < n && s[mid+x] == s[mid-x]){
                if(2*x > end-st){
                    st = mid-x ;
                    end = mid+x ;
                }
                x++ ;
            }
            
        }
        
        // even length palindrome -> mid mid+1 -> center lies between mid and mid+1 in this type of palindrome.
        for(ll mid=0; mid<n; mid++){
            ll x = 0 ;
            while(mid-x >=0 && mid+x+1 < n && s[mid+x+1] == s[mid-x]){
                if(2*x+1 > end-st){
                    st = mid-x ;
                    end = mid+x+1 ;
                }
                x++ ;
            }
            
        }
        
        string longest_palindrome = "" ;
        for(ll i=st; i<=end; i++)
            longest_palindrome += s[i] ;
        
        return longest_palindrome ;
    }
};