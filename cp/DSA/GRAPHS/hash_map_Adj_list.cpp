// IMPLEMENTATION OF A WEIGHTED UNIDIRECTIONAL GRAPH
// USING HASH MAP METHOD
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <cstring> 

using namespace std ;

class Graph{
	//Adj list
	unordered_map<string, list<pair<string, int>>> l ;
public:
	void addEdge(string x, string y, bool dir, int wt){
		l[x].push_back(make_pair(y, wt)) ;
		// l[x].push_back({y, wt}) ; 
		// WE CAN CODE THIS AS WELL
		if(dir)
			l[y].push_back(make_pair(x, wt)) ;
	}

	void printAdjList(){
		for(auto p: l){
			string city = p.first ;
			list<pair<string, int>> nbrs = p.second ;
			cout << city << "->" ;
			for(auto nbr : nbrs)
				cout << nbr.first << nbr.second << "," ;

			cout << endl ;
		}
	}

};

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	Graph g; 
	g.addEdge("A", "B", true, 20) ;
	g.addEdge("A", "C", true, 10) ;
	g.addEdge("C", "D", true, 30) ;
	g.addEdge("B", "D", true, 40) ;
	g.addEdge("A", "D", false, 50) ;

	g.printAdjList() ;


	return 0 ;
}