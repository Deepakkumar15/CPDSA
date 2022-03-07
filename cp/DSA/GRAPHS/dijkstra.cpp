// DIJKSTRA ALGORITHM FOR SHORTEST PATH
// SINGLE-SOURCE SHORTEST PATH ALGORITHM(SSSP)
// FOR NON-NEGATIVE WEIGHTED GRAPHS (DIRECTED AND NON-DIRECTED)
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std ;
#define ll long long int
#define vi vector<ll>
#define pi pair<ll, ll>
vi dist(1e5+7, INT_MAX) ;

template<typename T>
class Graph{
	unordered_map<T, list<pair<T, int>>> adj; 

public:
	void addEdge(T a, T b, int dist, bool dir=true){
		adj[a].push_back({b, dist}) ;
		if(dir)
			adj[b].push_back({a, dist}) ;
	}

	void print_adj(){
		for(auto it:adj){
			cout << it.first << "->"  ;
			for(auto itr:it.second)
				cout << "(" << itr.first << " " << itr.second << ")" ;
			cout << endl ;
		}
	}

	void dijkstra(ll src){
		set<pi> s ;
		dist[src]=0 ;
		s.insert({0, src}) ;

		while(!s.empty()){
			auto it = *(s.begin()) ;
			s.erase(s.begin()) ;
			
			ll par = it.second ;
			ll par_dist = it.first ;
			
			for(auto it : adj[par]){
			    ll child = it.first ;
			    ll child_dist = par_dist + it.second ;
				if(child_dist < dist[child]){
					// In set updation is not possible
					// we have to remove the old pair and 
					// insert a new pair instead
					if(s.find({dist[child], child})!=s.end())
						s.erase({dist[child], child}) ;
					
					dist[child] = child_dist;
					s.insert({dist[child], child}) ;
					parent[child] = par
				}
			}
		}

		for(ll i=1; i<=n; i++)
			cout << dist[i] << endl ;
		return ;
    }	
};

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	Graph<int> g;
	g.addEdge(1, 2, 1) ;
	g.addEdge(1, 3, 4) ;
	g.addEdge(2, 3, 1) ;
	g.addEdge(3, 4, 2) ;
	g.addEdge(1, 4, 7) ;

	g.print_adj() ;
	g.dijkstra(1) ;

	return 0 ;
}
