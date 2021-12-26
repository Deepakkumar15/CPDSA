#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

class Graph{
	map<int, list<int>> l;
public:
	void addEdge(int &a, int &b){
		l[a].push_back(b) ;
		l[b].push_back(a) ;
	}
public:
	bool check(int &x, int &y){
		for(auto it:l[x])
			if(it==y)
				return true ;
		return false ;		
	}

};

 int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	Graph g ;
	int n, m ;
	cin >> n >> m ;
	int a, b ;
	for(int i=0; i<m; i++){
		cin >> a >> b ;
		g.addEdge(a, b) ;
	}
	int q, x, y ;
	cin >> q ;
	while(q--){
		cin >> x >> y ;
		(g.check(x, y)) ? cout << "YES" << endl : cout << "NO" << endl ;
	}

	return 0 ;
	
 }	