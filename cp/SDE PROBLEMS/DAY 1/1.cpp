#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	int n ;
	cin >> n ;
	bool flag = false ;
	int arr[n]; 
	for(int i=0; i<n ;i++)
		cin >> arr[i] ;

	sort(arr, arr+n) ;
	for(int i=0; i<n-1 ;i++)
		if(arr[i] == arr[i+1])
			flag = true ;

	cout << flag << endl ;	
	return 0 ;
}