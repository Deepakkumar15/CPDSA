//SECRET PASSWORD CODEFORCES
// DSU BASED QUESTION

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
#define vi vector<ll> 
#define vs vector<string>


ll find(vi &parent, ll a){
    return parent[a] = (parent[a] == a ? a : find(parent, parent[a])) ;    
}

void Union(vi &parent, ll a, ll b){
    ll pa = find(parent, a) ;
    ll pb = find(parent, b) ;
    
    if(pa == pb)
        return ;
    parent[pa] = pb ;    
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll n ;
    cin >> n ;
    
    vi parent(27) ;
    for(ll i=0; i<=26; i++)
        parent[i] = i ;
        
    bool total[26] = {false} ;    
    bool visited[26] = {false} ;
    while(n--){
        string s ;
        cin >> s ;
        
        memset(visited, false, sizeof(visited)) ;
        for(auto ch:s)
            visited[ch-'a']=true ;
            
        for(ll i=0; i<26; i++)
            if(visited[i]){
                total[i]=true ;
                Union(parent, s[0]-'a', i) ;
            }
        
    }
    
    ll count=0 ;
    for(ll i=0; i<26; i++){
        if(total[i] && find(parent, i)==i)
            count++ ;
    }
    
    cout << count << endl ;
    return 0 ;
}