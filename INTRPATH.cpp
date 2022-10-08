#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// class Graph {
// 	ll V;
// 	vector<ll> *adjP, *pathNodesP, &pathNodes = *pathNodesP;
// 	vector<bool> *visitedP, *pathP, &visited = *visitedP, &path = *pathP;
// 	vector< vector<ll>> adj;
	
// 	public:
// 		Graph(ll V){
// 			this->V = V;
// 			adj.resize(V+1);
// 		}
		
		
// 		// void DFSUtil(ll u){
// 		// 	visited[u] = true;
// 		// 	for(auto i = adj[u].begin(); i != adj[u].end(); i++)
// 		// 		if(!visited[*i])
// 		// 			DFSUtil(*i);
// 		// }
		
// 		// void DFS(ll u){
// 		// 	visited = new vector<bool>(V+1, false);
// 		// 	DFSUtil(u)
// 		// }
		
		
		
		
// };

bool findPathUtil(ll start, ll end, vector<ll> adj[], vector<bool> visited, vector<bool> path, vector<ll> pathNodes){
	bool flag;

	visited[start] = true;
	if(start == end){
		path[start] = true;
		pathNodes.insert(pathNodes.begin(), start);
		return true;
	}
	for(auto i = adj[start].begin(); i != adj[start].end(); i++){
		if(!visited[*i]){
			cout<<*i<<endl;
			flag = findPathUtil(*i, end, adj, visited, path, pathNodes);
			if(flag){
				path[*i] = true;
				pathNodes.insert(pathNodes.begin(), *i);
				return true;
			}
		}
	}
	return false;
}

void findPath(vector<ll> adj[], ll start, ll end, ll V) {

	vector<bool> path(V+1, false);
	vector<bool> visited(V+1, false);
	vector<ll> pathNodes;
	bool x = findPathUtil(start, end, adj, visited, path, pathNodes);
	for(auto i = pathNodes.begin(); i != pathNodes.end(); i++){
		cout<<*i<<" ";
	}
	cout<<endl;
}

void addEdge(vector<ll> adj[], ll u, ll v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {
	int test;
	ll N, Q, u, v;	
	scanf("%d", &test);
	while(test--){
		scanf("%lld %lld", &N, &Q);
		vector<ll> *adjList = new vector<ll>[N];
		
		for(ll i = 0; i < N-1; i++){
			scanf("%lld %lld", &u, &v);
			addEdge(adjList, u, v);
		}
		while(Q--){
			scanf("%lld %lld", &u, &v);
		
			findPath(adjList, u, v, N);
		}
	}
	return 0;
}