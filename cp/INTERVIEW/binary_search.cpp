#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;

int solve(int arr[], int n, int x)
{
    int index  = lower_bound(arr, arr+n, x) - arr ;
    if(index >=0 && arr[index] == x)
        return index ;
    else
        return -1 ;
    
}

int main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	int n ;
	cin >> n ;
	int arr[n] ;
	for(int i=0; i<n; i++)
		cin >> arr[i] ;
	
	int q ;
	cin >> q ;
	while(q--)
	{
		int x ;
		cin >> x ;
		if(arr[0] > arr[1])
	    {
	        sort(arr, arr+n) ;
	        int index = solve(arr, n, x) ;
	        cout << n-index << endl ;
	        sort(arr,arr+n, greater<int> ());
	    }
	    else
	        cout << solve(arr,n, x)+1 << endl ;
	}	
	return 0 ;
}