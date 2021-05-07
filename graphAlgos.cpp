#include<bits/stdc++.h>
using namespace std;

vector<int> calc_Indegree(vector<vector<int> > &graph, int V) {
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++) {
        for(int v : graph[i]) {
            indegree[v]++;
        }
    }
    return indegree;
}

void topologicalSort_bfs(vector<vector<int> > &graph, int V) { // Kahn's Algo, time: O(V + E), space: O(V)
    vector<int> indegree = calc_Indegree(graph, V);
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(int v : graph[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

void dfs(int s, stack<int> &st, vector<vector<int> > &graph, vector<bool> &vis) {
    vis[s] = true;
    for(int u : graph[s]) {
        if(vis[u] == false) {
            dfs(u, st, graph, vis);
        }
    }
    st.push(s);
}

void topologicalSort_dfs(vector<vector<int> > &graph, int V) {
    vector<bool> vis(V, false);
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(vis[i] == false) {
            dfs(i, st, graph, vis);
        }
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        cout << x << " ";
    }
}

bool cycleDetection(int V, vector<vector<int> > graph) { // directed graph
    vector<int> indegree = calc_Indegree(graph, V);
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
                count++;
            }
        } 
    }
    return count != V;
}

int main(){
    int V = 5, E = 5;
    vector<vector<int> > graph(V);
    while(E--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    // topologicalSort_bfs(graph, V);
    // topologicalSort_dfs(graph, V);
    cout << cycleDetection(V, graph);
    return 0;
}