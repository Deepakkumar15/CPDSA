// SUBSET PROBLEM 
// TOP DOWN RECURSION CALLING ALL THE CHILD

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

const ll MAX=100 ;
ll a[MAX] ;
ll cnt=0, sum1, n ;
 
void fn(ll sum, ll i){
    if(i==n){
        cout << sum << endl ;
        if(sum==sum1)
            cnt++ ;
        return ;
    }
    fn(sum, i+1) ;
    
    fn(sum + a[i], i+1) ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
        
    cin >> sum1 ;
    
    fn(0, 0) ;
    if(cnt)
        cout << "SUM FOUND" ;
    else
        cout << "SUM NOT FOUND" ;
    return 0 ;
}



// SUBSET PROBLEM 
// BOTTOM UP RECURSION CALLING ALL THE CHILD

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

const ll MAX=100 ;
ll a[MAX] ;
ll n ;
 
bool fn(ll sum, ll i){
    if(sum==0)
        return true ;
    if(sum<0 || i==n)
        return false ;
        
    bool flag1 = fn(sum, i+1) ;
    
    bool flag2 = fn(sum - a[i], i+1) ;
    
    if(flag1 || flag2)
        return true ;
    return false ;    
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
    
    if(fn(sum, 0))
        cout << "SUM FOUND" ;
    else
        cout << "SUM NOT FOUND" ;
    return 0 ;
}

