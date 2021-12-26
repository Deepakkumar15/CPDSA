// CODEFORCES QUESTION (LONGEST REGULAR BRACKET SEQUENCE)

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 1e5+7 ;

void solve(){
    string s ;
    cin >> s ;
    ll n = s.length() ;
    vi a(n, -1) ;
    
    stack<ll> st ;
    for(ll i=0; i<n; i++){
        if(s[i]==')'){
            if(st.empty())
                a[i] = -1 ;
            else{    
                a[st.top()] = i ;
                a[i]=1 ;
                st.pop() ;
            }
        }
        
        else
            st.push(i) ;
    }
    
    
    unordered_map<ll, ll> mp ;
    a.push_back(-1) ;
    ll cnt=0, res=0;
    for(ll i=0; i<=n; i++){
        if(a[i]==-1){
            res = max(res, cnt) ;
            mp[cnt]++ ;
            cnt=0 ;
        }
        else
            cnt++ ;
    }
    
    res==0 ? cout << "0 1" : cout << res << " " << mp[res] ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    solve() ;
    return 0 ;
}