#include <bits/stdc++.h>
#include <iostream>

using namespace std ;
#define MAX 32001
#define ll long long

vector<int>* sieve(){
    bool primes[MAX] ;
    for(int i=0; i<MAX; i++)
        primes[i]=true ;
    for(int i=2; i*i<MAX; i++)
        if(primes[i]==true)
            for(ll j=i*i; j<MAX; j+=i)
                primes[j]=false; 
    
    vector<int> *a = new vector<int> () ;
    a->push_back(2) ;
    for(int i=3; i<MAX; i++)
        if(primes[i]==true)
            a->push_back(i) ;
            
    return a;        
}

void print_primes(int m, int n, vector<int>* &primes){
    bool is_prime[n-m+1] ;
    for(int i=0; i<=n-m; i++)
        is_prime[i]=true ;
    
    for(int i=0; primes->at(i)*(ll)primes->at(i)<=n; i++){
        int curr_prime=primes->at(i) ;
        ll base = (m/(curr_prime))*(curr_prime) ;
        if(base<m)
            base+=curr_prime ;
        for(ll j=base; j<=n; j+=curr_prime)
            is_prime[j-m]=false ;
        if(base==curr_prime)
            is_prime[base-m]=true ;
    }
    if(m==1)
        is_prime[0]=false ;
    for(int i=0; i<=n-m; i++)
        if(is_prime[i]==true)
            cout << i+m << endl ;
    cout << endl ;        
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int t ;
    cin >> t ;
    vector<int> *primes = sieve() ;
    // for(int i=0; i<primes->size(); i++)
    //     cout << primes->at(i) << " " ;

    int m, n ;
    while(t--){
        cin >> m >> n ;
        print_primes(m, n, primes) ;
    }
    return 0 ;
}
