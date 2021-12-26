// DFS IS A RECURSIVE IMPLEMENTATION
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std ;

template<typename T>
class Graph{

	map<T, list<T>> l;
public:
	void addEdge(T x, T y){
		l[x].push_back(y) ;
		l[y].push_back(x) ;
	}	

	void dfs_help(T src, map<T, bool> &visited){
		// Recursive function that will traverse the graph
		cout << src << " " ;
		visited[src] = true ;
		
		for(auto nbr:l[src])
			if(!visited[nbr])
				dfs_help(nbr, visited) ;
	}

	void dfs(T src){
		map<T, bool> visited ;
		for(auto it:l){
			T node = it.first ;
			visited[node] = false ;
		}
		// CALLING THE DFS_HELP FUNCTION
		dfs_help(src, visited) ;
	}

};

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	Graph<int> g;
	g.addEdge(0,1) ;
	g.addEdge(1,2) ;
	g.addEdge(2,3) ;
	g.addEdge(3,4) ;
	g.addEdge(4,5) ;

	g.dfs(0) ;
	return 0; 
}