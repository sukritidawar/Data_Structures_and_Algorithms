#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[s] = true;
    // cout << s << " ";
    for(int i = 0; i < graph[s].size(); i++){
        // cout << endl << v << " " << visited[v];
        if(visited[graph[s][i]] == false){
            dfs(graph[s][i], graph, visited);
        }
    }
}

void printgraph(vector<vector<int>> graph){
    for(int i = 0; i < graph.size(); i++) {
        cout << i << " --> ";
        for(int v : graph[i]){
            cout << v << " ,";
        }
        cout << endl;
    }
}

int connected_components(vector<vector<int>> &graph, vector<bool> vis) {
    int count = 0;
    for(int i = 1; i < graph.size(); i++){
        if(vis[i] == false){
            dfs(i, graph, vis);
            count++;
        }
    }
    return count;
}

void bfs(vector<vector<int>> graph, int s, vector<bool> &visited){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int v : graph[x]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


bool dfsDetect(vector<vector<int>> &graph, int s, vector<bool> &vis){
    if(vis[s] == true){
        return true;
    }
    vis[s] = true;
    bool ans = false;
    for(int v : graph[s]){
        ans = dfsDetect(graph, v, vis);
        vis[v] = false;
    }
    return ans;
}

bool dfsRec(vector<int> adj[], int s, vector<bool> &vis, vector<bool> &recSt) {
        vis[s] = true;
        recSt[s] = true;
        for(int v : adj[s]) {
            if(vis[v] == false && dfsRec(adj, v, vis, recSt) == true) {
                return true;
            }
            else if(recSt[v] == true){
                return true;
            }
        }
        recSt[s] = false;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	   	vector<bool> vis(V, false);
	   	vector<bool> recSt(V, false);
	   	for(int i = 0; i < V; i++) {
	   	    if(vis[i] == false && dfsRec(adj, i, vis, recSt) == true){
	   	        return true;
	   	    }
	   	}
	   	return false;
	}


int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    while(e--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    vector<bool> vis(v, false);
    // dfs(1, graph, vis);
    // printgraph(graph);
    // cout << connected_components(graph, vis);
    // bfs(graph, 1, vis);
    cout << detectCycle_directedGraph(graph, vis);
}
