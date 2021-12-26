#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

char decrypt_string(string str, int k){
	string expand, temp ;
	int res=0;

	for(int i=0; i<str.length(); ){
		temp.clear() ;
		res=0 ;

		while(str[i]>='a' && str[i]<='z'){
			temp.push_back(str[i]) ;
			i++ ;
		}

		while(str[i]>='1' && str[i]<='9'){
			res = res*10 + (str[i]-'0') ;
			i++ ;
		}

		for(int j=1; j<=res; j++)
			expand.append(temp) ;

	}
	// THIS CONDITION IS TO HANDLE THE CASE
	// WHEN STRING str IS ENDED WITH ALPHABETS
	// NOT WITH NUMERIC VALUE
	if(res==0)
		expand.append(temp) ;

	return expand[k-1] ;
}

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	string str ;
	cin >> str; 
	int k ;
	cin >> k ;

	cout << decrypt_string(str, k) ;
	return 0 ;
}