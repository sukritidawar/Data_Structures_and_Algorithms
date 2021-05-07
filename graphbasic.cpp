#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v){
    for(int i = 0; i < v; i++){
        for(int x : adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

//Breadth First Search- BFS

//for connected graphs and a given source
void BFS(vector<int> adj[], int v, int s){
    bool visited[v + 1];
    for(int i = 0; i < v; i++){
        visited[i] = false;      //to check whether this node is already checked before or not
    }
    queue<int> q;
    q.push(s);  //Add source to the queue
    visited[s] = true;  //Since we have added it to queue, we'll be checking it.
    while(q.empty() == false){ //Check all elementd until queue becomes empty
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(visited[v] == false){ //check whether which of the adjacents are not visited yet
                visited[v] = true;
                q.push(v);
            }
        }
    } 
}

//for disconnected graphs and no source given
void BFSd(vector<int> adj[], int s, bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void BFSDis(vector<int> adj[], int v){ //O(v + e) time
    bool visited[v + 1];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(visited[i] == false){
            BFSd(adj, i, visited);
        }
    }
}
 
//Counting connected componenets in a graph
void BFSdc(vector<int> adj[], int s, bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int BFSDisCount(vector<int> adj[], int v){
    bool visited[v + 1];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i = 0; i < v; i++){
        if(visited[i] == false){
            BFSdc(adj, i, visited);
            count++;
        }
    }
    return count;
} 

//Depth First Search - DFS
//First version- undirected and connected graph, source is given
void DFSRec(vector<int> adj[], int s, bool visited[]){
    visited[s] = true;
    cout << s << " ";
    for(int u : adj[s]){
        if(visited[u] == false){
            DFSRec(adj, u, visited);
        }
    }
}

void DFS(vector<int> adj[], int v, int s){
    bool visited[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    DFSRec(adj, s, visited);
}

//Detect cyle in undirected graph..
bool dfsrec(bool visited[], vector<int> adj[], int s, int parent){
    visited[s] = true;
    for(int u : adj[s]){
        if(visited[u] == false){
            if(dfsrec(visited, adj, u, s) == true){
                return true;
            }
        }
        else if(u != parent){
            return true;
        }
    }
    return false;
}
bool cycle_undirectedGraph(vector<int> adj[], int v){
    bool visited[v];
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < v; i++){
        if(visited[i] == false){
            if(dfsrec(visited, adj, i, -1) == true){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv){
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    // printGraph(adj, v);
    BFSDis(adj, v);
    return 0;
}