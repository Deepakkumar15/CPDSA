// HAMBURGERS CODEFORCES
// BINARY SEARCH ON ANSWER

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
ll MAX = 1e12+1000;

ll cnt1=0, cnt2=0, cnt3=0 ;
ll r, nb, ns, nc, pb, ps, pc ;

bool check(ll x){
     ll b = max(0LL, cnt1*x - nb) ;
     ll s = max(0LL, cnt2*x - ns) ;
     ll c = max(0LL, cnt3*x - nc) ;
     
     ll cost = b*pb + s*ps + c*pc ;
     
     if(cost<=r)
          return true ;
     return false ;   
     
}

ll binary_fn(ll l, ll r){
     ll mid=0, res=0; 

     while(l<=r){
          mid = (l+r)/2 ;
          if(check(mid)){
               l = mid+1 ;
               res = mid ;
          }
          else
                r = mid-1 ;
     }
    
     return res ;
     
}

signed main(){
     ios_base::sync_with_stdio(false) ;
     cin.tie(0) ;
     cout.tie(0) ;
     
     string s ;
     cin >> s ;
     for(ll i=0; i<s.length(); i++){
          if(s[i]=='B')
               cnt1++ ;
          else if(s[i]=='S')
               cnt2++ ;
          else
               cnt3++ ;
     }
     cin >> nb >> ns >> nc ;
     cin >> pb >> ps >> pc ;
     cin >> r ;
     
     ll ans = binary_fn(0, MAX) ;
     
     cout << ans << endl ;
     
     return 0 ;
}