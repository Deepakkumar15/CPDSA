#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;
 
int pivot(vector<int> l, int n)
{
	int s=0;
	int e = n-1;

	while(s<=e)
	{
		int mid = s+e/2 ;
		if(mid < e && l[mid] > l[mid+1])
		{
			return mid ;
			break ;
		}

		if(mid > s && l[mid] < l[mid-1])
		{
			return mid-1 ;
			break ;
		}

		if(l[s] >= l[mid])
			e = mid-1;
		else
			s = mid+1 ; 	
	}
	
	return -1 ;
}

int main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	cout << "ENTER THE SORTED AND ROTATED ARRAY :" << endl ;
	vector<int> l ;
	int n ;
	while(cin >> n)
		l.push_back(n) ;
	int len = l.size() ;	

	cout << "THE INDEX OF PIVOT ELEMENT IS : " << pivot(l, len) << endl ;
	return 0 ;
}