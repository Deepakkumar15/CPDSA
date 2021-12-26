// cycle detection in a directed graph using dfs algorithm
// vertices from 1 to n
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;


class Graph{
	int v;
	list<int> *l ;
    bool isCyclic_help(int node, bool *visited, int parent) ;
public:
	Graph(int v){
		this->v = v ;
		l = new list<int> [v] ;
	};

	void addEdge(int a, int b){
		l[a].push_back(b) ;
		l[b].push_back(a) ;
	}
	
	void print(){
	   for(int i=0; i<v; i++){
	       list<int> nbr = l[i] ;
	       cout << i << "->" ;
	       for(auto it:nbr)
	          cout << it << " " ;
	       cout << endl ;   
	   }
	}
	
	bool isCyclic() ;
};

bool Graph::isCyclic_help(int node, bool *visited, int parent){
	visited[node]=true ;
	list<int> :: iterator it;
	for(it=l[node].begin(); it!=l[node].end(); ++it){
	    if(!visited[*it]){
		    if(isCyclic_help(*it, visited, node))
			    return true ;
		}	    
		else if(*it!=parent)
			return true; 
	}
	return false ;
}

bool Graph::isCyclic(){
	bool *visited = new bool [v] ;

    for(int i=0; i<v; i++)
		visited[i]=false ;
        
    for(int i=0; i<v; i++)
        if(!visited[i])
            if(isCyclic_help(i, visited, -1))
                return true ;
	return false ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    // g.addEdge(3, 1); 
    g.print() ;
    (g.isCyclic()) ? cout << "GRPAH CONTAINS CYCLE." : cout << "GRPAH DOESN'T CONTAIN CYCLE." ;
    
	return 0 ;
}