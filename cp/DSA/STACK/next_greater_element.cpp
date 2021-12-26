// NEXT GREATER ELEMENT USING STACK

#define ll long long int
vector<ll> nextLargerElement(vector<ll> a, ll n){
    vector<ll> nge(n, -1) ;
    stack<ll> st ;
    
    // process from back
    for(ll i=n-1; i>=0; i--){
        // pop condition
        while(!st.empty() && st.top() <= a[i])
            st.pop() ;
            
        if(!st.empty())
            nge[i] = st.top() ;
            
        // else there will be always -1
        st.push(a[i]) ;
    }
    
    return nge ;
}





// NEXT GREATER ELEMENT IN CIRCULAR FASHION (SLIGHT MODIFICATION)
#define ll long long int
vector<ll> nextLargerElement(vector<ll> a, ll n){
    vector<ll> nge(n, -1) ;
    stack<ll> st ;
    
    // process from back
    for(ll i=2*n-1; i>=0; i--){
        // pop condition
        while(!st.empty() && st.top() <= a[i%n])
            st.pop() ;
            
        if(!st.empty() && i<n)
            nge[i] = st.top() ;
            
        // else there will be always -1
        st.push(a[i]%n) ;
    }
    
    return nge ;
}