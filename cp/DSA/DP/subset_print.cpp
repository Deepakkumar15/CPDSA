// SUBSET PROBLEM 
// TOP DOWN RECURSION CALLING ALL THE CHILD
// PRINTING ALL THE SUBSET OF AN ARRAY

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
const ll MAX=100 ;
ll n ;
ll a[MAX] ;
set<ll> res ;

void fn(set<ll> s, ll i){
    if(i==n){
        ll temp=0 ;
        for(auto it:s){
            temp+=it ;
            cout << it << " " ;
        }    
        cout << endl ;
        res.insert(temp) ;
        return ;
    }
    fn(s, i+1) ;
    s.insert(a[i]) ;
    fn(s, i+1) ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
        
    ll sum ;
    cin >> sum ;
    
    set<ll> s ;
    fn(s, 0) ;
    if(res.find(sum)!=res.end())
        cout << "SUM FOUND" ;
    else
        cout << "SUM NOT FOUND" ;
    return 0 ;
}