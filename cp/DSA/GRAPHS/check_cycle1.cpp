// cycle detection in a directed graph using dfs algorithm
// vertices from 1 to n
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;


class Graph{
	int v;
	list<int> *l ;
	bool isCyclic_help(int v, bool *visited, bool *rec) ;
   
public:
	Graph(int v){
		this->v = v ;
		l = new list<int> [v] ;
	};

	void addEdge(int a, int b){
		l[a].push_back(b) ;
	}
	bool isCyclic() ;	

};

bool Graph::isCyclic_help(int v, bool *visited, bool *rec){
	if(!visited[v]){
		visited[v]=true ;
		rec[v]=true ;

		for(auto nbr:l[v]){
			if(!visited[nbr] && isCyclic_help(nbr, visited, rec))
				return true ;
			else if(rec[nbr])
				return true; 
		}
	}
	rec[v]=false ;
	return false ;
}

bool Graph::isCyclic(){
	bool *visited = new bool [v] ;
	bool *rec = new bool [v] ;

	for(int i=0; i<v; i++){
		visited[i]=false ;
		rec[i]=false ;
	}
	
	for(int i=0; i<v; i++)
		if(isCyclic_help(i, visited, rec))
			return true ;
	return false ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    
    Graph g(6);
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 
    g.addEdge(5, 4);
    
    (g.isCyclic()) ? cout << "GRPAH CONTAINS CYCLE." : cout << "GRPAH DOESN'T CONTAIN CYCLE." ;
    
	return 0 ;
}
