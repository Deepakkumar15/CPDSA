//Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
// RECURSIVE SOLUTION

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll count(ll n){
    if(n<0)
        return 0 ;
    if(n==0)
        return 1 ;
    return count(n-1) + count(n-2) + count(n-3) ;    
}    

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    
    ll n ;
    cin >> n ;
    cout << count(n) << endl; 
    
    return 0 ;
}

//Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
// DP VERSION

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll count(ll n){
    if(n<0)
        return 0 ;
    ll cnt[n+1] ;
    cnt[0]=1 ;
    cnt[1]=1 ;
    cnt[2]=2 ;
    
    for(ll i=3; i<=n; i++)
        cnt[i] = cnt[i-1] + cnt[i-2] + cnt[i-3] ;
        
    return cnt[n] ;    
}    

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    
    ll n ;
    cin >> n ;
    cout << count(n) << endl; 
    
    return 0 ;
}