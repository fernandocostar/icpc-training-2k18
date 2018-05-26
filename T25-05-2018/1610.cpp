#include <bits/stdc++.h>
 
using namespace std;
 
class Graph{
    int V;
    list<int> *adj;
    bool dfsUtil(int v, bool visited[], bool *rs);
public:
    Graph(int V);
    bool dfs();
};
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

bool Graph::dfsUtil(int v, bool visited[], bool *visited_this){
    if(visited[v] == false){
        visited[v] = true;
        visited_this[v] = true;
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            if ( !visited[*i] && dfsUtil(*i, visited, visited_this) )
                return true;
            else if (visited_this[*i])
                return true;
        }
    }
    visited_this[v] = false;
    return false;
}

bool Graph::dfs(){
    bool *visited = new bool[V];
    bool *visited_this = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        visited_this[i] = false;
    }

    for(int i = 0; i < V; i++)
        if (dfsUtil(i, visited, visited_this))
            return true;
 
    return false;
}
 
int main(){
	int t, n, m, from, to;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		Graph g(n);
		for(int j = 0; j < m; j++){
			cin >> from >> to;
			g.addEdge(from-1, to-1);
		}
		if(g.dfs()) cout << "SIM" << endl;
		else cout << "NAO" << endl;	
	}
    
    return 0;
}