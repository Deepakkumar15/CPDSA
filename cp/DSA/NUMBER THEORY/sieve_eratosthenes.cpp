// SIEVE OF ERATOSTHENES
// FOR FINDING ALL THE PRIME NUMBERS IN A SPECIFIC RANGE FROM [1, n]
#include <bits/stdc++.h>
#include <iostream>

using namespace std ;
#define MAX 1000005
#define ll long long

void prime(int *a, int n){
	for(int i=3; i<n; i+=2)
		a[i]=1 ;
	for(int i=3; i<n; i+=2)
		if(a[i]==1)
			for(ll j=i*i; j<=n; j+=i)
				a[j]=0 ;
    a[2]=1 ;				
// 	a[0]=a[1]=0 ;		
}

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