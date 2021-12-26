// REPRESENTATION OF GRAPH 
// USING ADJACENCY LIST
#include <bits/stdc++.h>
#include <iostream>
#include <list>

using namespace std ;

class Graph{
	int v ;
	list<int> *l ;

public:
	Graph(int v){
		this->v = v ;
		l = new list<int> [v] ;
	}	

	void addEdge(int x, int y){
		l[x].push_back(y) ;
		l[y].push_back(x) ;
	}

	void printAdjList(){
		for(int i=0; i<v; i++){
			cout << "vertex is " << i << "->" ;
			for(auto it: l[i])
				cout << it << "," ;
			cout << endl ;
		}

	}

};

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	Graph g(4) ;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);

	g.printAdjList() ;


	return 0 ;
}