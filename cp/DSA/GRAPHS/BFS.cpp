// BFS IS AN ITERATIVE IMPLEMENTATION
// USING BIDIRECTIONAL GRAPH
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std ;

template<typename T>
class Graph{
	map<T, list<T>> l;

public:
	void addEdge(T x, T y){
		l[x].push_back(y) ;
		l[y].push_back(x) ;
	}

	void bfs(T src){
		vi parent(n), dist(n) ;
		vi vis(n, false) ;
		queue<T> q ;
		q.push(src) ;

		visited[src] = true ;

		while(!q.empty()){
			ll par = q.front() ;
			q.pop() ;
			cout << par << " " ;

			for(auto it : adj[par]){
				if(!visited[it]){
					q.push(it) ;
					// mark the neighbour as visited
					visited[it] = true ;
					dist[it] = dist[par]+1;
					parent[it] = par ;
				}
			}
		}
	}

};

// for printing shortest path;
// vi path ;
// for(path.pb(dest); dest != src; path.pb(dest = parent[dest]))
// reverse(path.begin(), path.end()) ;


int main(){
// 	ios_base::sync_with_stdio(false) ;
// 	cin.tie(0) ;
// 	cout.tie(0) ;

	Graph<int> g ;
	g.addEdge(0,1) ;
	g.addEdge(1,2) ;
	g.addEdge(2,3) ;
	g.addEdge(3,4) ;
	g.addEdge(4,5) ;

	g.bfs(0) ;
	return 0 ;
}