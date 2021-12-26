#include <bits/stdc++.h>
#include <iostream>

using namespace std ;
#define MAX 10000
#define ll long long
int primes[MAX] ;
int a[MAX]={0} ;

int prime(int *a, int n){
    int j=0 ;
    for(int i=3; i<n; i+=2)
        a[i]=1 ;
    for(int i=3; i<n; i+=2)
        if(a[i]==1)
            for(ll j=i*i; j<=n; j+=i)
                a[j]=0 ;
    a[2]=1 ;
    for(int i=1000; i<MAX; i++)
        if(a[i]==1)
            primes[j++]=i ;
    
    return j ;        
}

bool is_connected(int a, int b){
    string x = to_string(a) ;
    string y = to_string(b) ;
    
    return ((x[0]==y[0] && x[1]==y[1] && x[2]==y[2] && x[3]!=y[3]) || (x[0]==y[0] && x[1]==y[1] && x[2]!=y[2] && x[3]==y[3]) || (x[0]==y[0] && x[1]!=y[1] && x[2]==y[2] && x[3]==y[3]) || (x[0]!=y[0] && x[1]==y[1] && x[2]==y[2] && x[3]==y[3])) ;
}

class Graph{
    int level[MAX] ;
    int n = prime(a, MAX) ;
    map<int, list<int>> l ;
    map<int, list<int>> :: iterator it ;
    
public:
    void build_graph(){
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(is_connected(primes[i], primes[j])){
                    l[primes[i]].push_back(primes[j]) ;
                    l[primes[j]].push_back(primes[i]) ;
                }
        // for(it=l.begin(); it!=l.end(); ++it){
        //     cout << it->first << "-> " ;
        //     list<int> v = it->second ;
        //     for(auto itr:v)
        //         cout << itr << " " ;
        //     cout << endl ;    
        // }    
    }
public:            
    int bfs(int a, int b){
        map<int, bool> visited ;
        queue<int> q ;
        q.push(a) ;
        visited[a]=true ;
        level[a]=0 ;
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            
            for(auto nbr:l[node])
                if(!visited[nbr]){
                    q.push(nbr) ;
                    visited[nbr]=true ;
                    level[nbr] = level[node]+1 ;
                }
            if(node==b)
                return level[b] ;    
        }
        
        return 0 ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int t ;
    cin >> t ;
    int a, b ;
    
    Graph g ;
    g.build_graph() ;
    
    while(t--){
        cin >> a >> b ;
        if(a==b)
            cout << "0" << endl ;
        else{
            int ans = g.bfs(a,b) ;
            
            (ans) ? cout << ans << endl : cout << "Impossible" << endl ; 
        }    
    }
    
    return 0 ;
 }  