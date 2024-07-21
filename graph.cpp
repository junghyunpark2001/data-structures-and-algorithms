#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
private:
    int v;
    vector<vector<int>> adj;
public:
    Graph(int v){
        this->v = v;
        adj.resize(v);
    }
    
    void add_edge(int u,int v){
        adj[u].push_back(v);
    }

    void BFS(int start){
        vector<bool> visited(v,false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<" ";

            for(int neighbor:adj[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);

                }
            }
        }
        cout<<'\n';

    }
    void dfs_util(int node, vector<bool>& visited){
        visited[node] = true;
        cout<<node<<" ";

        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                dfs_util(neighbor, visited);
            }
        }
    }

    void dfs(int start){
        vector<bool> visited(v,false);
        dfs_util(start,visited);
        cout<<'\n';
    }
};