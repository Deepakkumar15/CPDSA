#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> l, int key, int len)
{
	int s=0;
	int e=len-1;
	while(s<=e)
	{
		int mid = (s+e)/2 ;
		if(l[mid] == key)
		{	
			return mid ;
			break ;
		}
		else if(l[mid] > key)
			e = mid-1 ;
		else
			s = mid+1 ;
	}

	return -1; 
}

int main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cout << "ENTER THE KEY VALUE THAT YOU WANT TO SEARCH :" << endl  ;
    int key ;
	cin >> key; 	
   
	cout << "ENTER THE SORTED ARRAY :" << endl ;
	vector<int> l ;
	int n ;
	while(cin >> n)
		l.push_back(n) ;
	int len = l.size(); 
	
	cout << "THE INDEX OF KEY VALUE IS : " << binarySearch(l, key, len) << endl ;
	return 0 ;
}