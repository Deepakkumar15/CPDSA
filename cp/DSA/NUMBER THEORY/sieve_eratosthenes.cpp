// SIEVE OF ERATOSTHENES
// FOR FINDING ALL THE PRIME NUMBERS IN A SPECIFIC RANGE FROM [1, n]
#include <bits/stdc++.h>
#include <iostream>

using namespace std ;
#define MAX 1000005
#define ll long long

int prime [n+1];
for(int i=2;i<=n;i++)
	if(prime[i] == 0)
		for(int j=2*i;j<=n;j+=i)
			prime[j] = i;


// prime[i] = 0 => i is prime

int main(){
	int n ;
	cin >> n ;
	int a[MAX]={0} ;
	prime(a, n) ;
	for(int i=0; i<n; i++)
	    if(a[i]==1)
	        cout << i << " " ;
	cout << endl ;        
 	return 0 ;
 }	