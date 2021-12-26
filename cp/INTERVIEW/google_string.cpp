#include <bits/stdc++.h>
#include <iostream>
#include <istream>
#include <cstring>
#include <cctype>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;

	string str ;
	cin >> str ;
	int n = str.length() ;
    int m = n/2 ;
    
	string s1, s2 ;
	s1.insert(0, str, 0, m) ;
	s2.insert(0, str, m, m) ;

	sort(s1.begin(), s1.end()) ;
	sort(s2.begin(), s2.end()) ;
    
    int greater_count = 0 ;
    for(int i=0; i<m; i++)
		if(s2[m-1] >= s1[i])
			greater_count++ ;
			
    int smaller_count = 0 ;
    for(int i=0; i<m; i++)
		if(s1[m-1] >= s2[i])
			smaller_count++ ;
    
    int equal_count ;
    int arr[26] = {0} ;
	for(int i=0; i<n ; i++)
		arr[str[i] - 'a']++ ;
    equal_count = n - (*max_element(arr, arr+n)) ;

	int result = min(greater_count, smaller_count) ;

	cout << min(result, equal_count) << endl ;

	return 0 ;
}