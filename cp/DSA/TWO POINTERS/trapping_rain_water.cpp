// TRAPPING RAIN WATER USING TWO POINTER
// 0(N) TIME COMP. AND 0(1) SPACE COMP.

#define ll long long int
#define vi vector<ll>
int Solution::trap(const vector<int> &a) {
    ll n = a.size() ;
    if(n==1)
        return 0 ;
    ll ans=0 ;
    ll l=0, r=n-1 ;
    ll l_max=a[0], r_max=a[n-1] ;
    
    while(l<=r){
        if(a[l] <= a[r]){
            (a[l] >= l_max) ? l_max = a[l] : ans += l_max-a[l] ;
            l++ ;
        }   
        
        else{
            (a[r] >= r_max) ? r_max = a[r] : ans += r_max-a[r] ;
            r-- ;
        }
    }
    
    return ans ;
}
