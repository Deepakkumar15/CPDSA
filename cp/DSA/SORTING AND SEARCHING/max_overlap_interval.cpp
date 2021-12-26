#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vb  vector<bool>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7

ll overlap(vpi &v){
    vector<pair<ll, char>> data ;
    
    for(auto it:v){
        data.push_back({it.first, 'x'}) ;
        data.push_back({it.second, 'y'}) ;
    }
    
    sort(data.begin(), data.end()) ;
    
    ll count=0, ans=0 ;
    for(auto it:data){
        if(it.second=='x')
            count++ ;
        else 
            count-- ;
        ans = max(ans, count) ;
    }
    
    return ans ;
}

signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
    
    ll n ;
    cin >> n ;
    vpi v(n) ;
    for(ll i=0; i<n; i++)
        cin >> v[i].first >> v[i].second ;
    
    cout << overlap(v) << "\n";
	return 0 ;
}