// O(N*K) solution using nge array

#include <bits/stdc++.h>
#define ll int
#define vi vector<ll>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        ll n = a.size();
        vi nge(n, n) ; // it stores the index only
        stack<pair<ll, ll>> st ; // stack will store the index also along with the element
        
        for(ll i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first <= a[i])
                st.pop() ;
            if(!st.empty())
                nge[i] = st.top().second ;
            
            st.push({a[i], i}) ;
        }
        
        vi ans ;
        ll j=0 ;
        for(ll i=0; i+k-1 < n; i++){
            j=i ;
            while(nge[j] <= i+k-1)
                j = nge[j] ;
            
            ans.push_back(a[j]) ;
        }
        
        return ans; 
    }
};