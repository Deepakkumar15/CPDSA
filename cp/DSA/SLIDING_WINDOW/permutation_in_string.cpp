// Permutation in String

#define ll long long int

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ll n1 = s1.length() ;
        ll n2 = s2.length() ;
        
        if(n1 > n2){
            return false ;
        }
        
        unordered_map<char, ll> mp, temp ;
        for(ll i=0; i<n1; i++){
            mp[s1[i]]++ ;
            temp[s2[i]]++ ;
        }
        
        bool flag = false ;
        
        for(ll i=0; i<=n2-n1; i++){
            if(mp == temp){
                flag = true ;
                break ;
            }
            temp[s2[i+n1]]++ ;
            temp[s2[i]]-- ;
            if(temp[s2[i]] <= 0)
                temp.erase(s2[i]) ;
        }
        
        if(flag)
            return true ;
        
        return false ;
        
    }
};