#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; //vertices
    list<int> *adjList; //Array of LL of size v
    
    public:
    Graph(int v){
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << i << "->";
            for(int node : adjList[i]){
                cout << node << ", "; 
            }
            cout << endl;
        }
    }
};

//Graph implementation with hashmaps
//template for generic graph
template<typename T>
class Graph_{
    map<T, list<T> >adjList;
    public:
    Graph_(){

    }
    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto everyrow : adjList){
            cout << everyrow.first << " -> ";
            for(T x : everyrow.second){
                cout << x << " , ";
            }
            cout << endl;
        }
    }
};

void dfs(int s, vector<int> g[], bool vis[]){
    vis[s] = true;
    cout << s << " ";
    for(int i = 0; i < g[s].size(); i++){
        if(vis[g[s][i]] == false){
            dfs(g[s][i], g, vis);
        }
    }
}

int number_connectedComponents(vector<int> g[], int n, bool vis[]){
    int cc_count = 0;
    for(int i = 0; i <= n; i++){
        if(vis[i] == 0){
            dfs(i, g, vis);
            cc_count++;
        }
    }
    return cc_count;
}

int main(){
    // Graph g(4);
    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(0,3);
    // g.addEdge(1,3);
    // g.addEdge(3,2);
    // g.printGraph();
    // Graph_<string> g;
    // g.addEdge("A", "D");
    // g.addEdge("A", "J");
    // g.addEdge("D", "S");
    // g.printGraph();
    int N, E;
    cin >> N; 
    vector<int> g[N]; //graph adj List
    bool vis[N];
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < N; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, g, vis);
    return 0;
}