//DUTCH NATIONAL FLAG ALGORITHM
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
	int n ;
	cin >> n ;
	int arr[n] ;
	for(int i=0; i<n ;i++)
		cin >> arr[i] ;

	int low=0, mid=0;
	int high = n-1 ;

	while(mid <= high)
		switch(arr[mid])
		{
			case 0:
				swap(arr[low++], arr[mid++]) ;
				break;
			case 1:
				mid++ ;
				break ;
			case 2:
				swap(arr[mid], arr[high--]) ;
				break ;		
		}

	cout << "THE SORTED ARRAY IS :" ;
	for(auto it : arr)
		cout << it << " " ;	

	return 0 ;
}