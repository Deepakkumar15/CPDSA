// Longest Substring without repeating characters

#define ll int

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ll n = s.length() ;
        if(n==0){
            return 0 ;
        }
        if(n==1){
            return 1 ;
        }
        
        unordered_map<char, ll> mp ;
        
        ll l=0, r=0 ;
        ll ans = 1, len = 1 ;
        while(l<=r && r<n && l<n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]] + 1);
            }
                
            mp[s[r]] = r ;
            len = r-l+1 ;
            r++ ;
            
            
            ans = max(ans, len) ;
        }
        
        return ans ;
        
        
    }
};