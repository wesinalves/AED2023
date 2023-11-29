#include <bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> edgeList;
    int V, E;
    int* dist;
    public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        dist = new int[V];
    }
    void initializeSingleSource(int src){
        for(int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[src] = 0;    
    }
    void addEdge(int w, int u, int v){
        edgeList.push_back({w, u, v});
    }
    void displayDistances(){
        cout << "Vertex" << "\t" << "distance from source" << endl;
        for(int i = 0; i < V; i++)
            cout << i << "\t" << dist[i] << endl;
    }
    void relax(int u, int v, int w){
        if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            dist[v] = dist[u] + w;
    }
    bool bellmanFord(int src){
        initializeSingleSource(src);

        // process vertices
        for(int i = 0; i <= V-1; i++){
            for(auto edge: edgeList){
                int w = edge[0];
                int u = edge[1];
                int v = edge[2];
                relax(u, v, w);
            }
        }
        // check negative cicle
        for(auto edge: edgeList){
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                cout << "Aborting. Graph contains negative weight cycle";
                return false;
            }
        }

        return true;
    
    }
};

int main(){
    int V = 5;
    int E = 10;
    Graph g = Graph(V,E);
    g.addEdge(6,0,1);
    g.addEdge(7,0,2);
    g.addEdge(5,1,3);
    g.addEdge(8,1,2);
    g.addEdge(-4,1,4);
    g.addEdge(-2,3,1);
    g.addEdge(-3,2,3);
    g.addEdge(9,2,4);
    g.addEdge(2,4,0);
    g.addEdge(7,4,3);

    g.bellmanFord(0);

    g.displayDistances();

    return 0;
}