#include <bits/stdc++.h>
using namespace std;

int main() {
	string str = "I, Deepak, kumar, IIITS, INDMONEY." ;
	stringstream ss(str) ;
	string word ;
	
	while(getline(ss, word, ',')){
	    cout << word << endl ;
	}
	return 0;
}