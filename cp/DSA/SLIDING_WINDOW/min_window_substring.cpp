#define ll long long int

class Solution {
public:
    bool is_substring_valid(unordered_map<char, ll> &mp1, unordered_map<char, ll> &mp2){
        for(auto it : mp1)
            if(mp2[it.first] < it.second)
                return false ;
        return true ;
    }
    
    string minWindow(string s, string t) {
        ll n = s.length() ;
        unordered_map<char, ll> mp1, mp2 ;
        for(char ch : t)
            mp1[ch]++ ;
        
        s.push_back(s[n-1]) ;
        ll l=0, r=0 ;
        ll i=0, j=0 ;
        ll mn_substring_len = 100007 ;
        while(l<=r && r<=n){
            if(is_substring_valid(mp1, mp2)){
                if(mn_substring_len > r-l+1){
                    mn_substring_len = r-l+1 ;
                    i = l; j = r ;
                }
                mp2[s[l]]-- ;
                l++ ;
            }

            else{
                mp2[s[r]]++ ;
                r++ ;
            }
        }
        
        
        string ans = "" ;
        for(ll x=i; x<j; x++)
            ans += s[x] ;
        
        return ans ;
        
    }
};