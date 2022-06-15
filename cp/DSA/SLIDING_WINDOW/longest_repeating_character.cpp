// Longest Repeating Character Replacement

#define ll long long int

class Solution {
public:
    int max(ll a, ll b){
        if(a >= b) return a ;
        return b ;
    }
    
    int characterReplacement(string s, int k) {
        unordered_map<char, vector<ll>> mp ;
        ll n = s.length() ;
        for(ll i=0; i<n; i++)
            mp[s[i]].push_back(i) ;
        
        ll temp_mx = 1;
        for(auto it : mp){
            vector<ll> temp = it.second;
            temp.push_back(n) ;
            ll m = temp.size() ;
            ll limit = k;
            for(ll i=0; i<m; i++){	
                ll idx = temp[i];
                limit = k ;
                for(ll j=i; j<m-1; j++){
                    ll req_swaps = max(0, temp[j+1] - temp[j] - 1);
                    ll possible_swaps = min(limit, req_swaps) ;
                    
                    if(!limit && req_swaps) // if limit exhausted already
                        break ;
                    if(possible_swaps == req_swaps && temp[j+1] == n){ 
                        // if this character is the last character of string.
                            idx = n-1 ;
                            limit = max(0, limit-req_swaps) ;
                            break ;                        
                    }
                    else if(possible_swaps == req_swaps && temp[j+1]!=n){
                        // if limit >= required swaps, then change all the required characters.
                        idx = temp[j+1] ;
                    }
                    else if(possible_swaps != req_swaps){
                        // if possible_swaps < required_swaps -> limit < required swaps.
                        idx = temp[j] + possible_swaps ;
                        limit = max(0, limit-req_swaps) ;
                        break ;
                    }
                        
                    limit = max(0, limit-req_swaps) ;
                }
                
                ll cmp_mx = idx-temp[i]+1 ;
                cmp_mx += min(limit, temp[i]) ;
                temp_mx = max(temp_mx, cmp_mx) ;
            }
        }

        return temp_mx ;
    }
};