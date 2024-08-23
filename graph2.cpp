#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj1[10];
bool vis[10];
void bfs(){
    
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<' ';
        for(auto nxt : adj1[cur]){
            if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
        }
    }
}


void dfs(int cur){
    vis[cur] = true;
    cout<<cur<<' ';
    for(auto nxt : adj1[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    // 1. adjcanent matrix
    // directed graph
    int adj_matrix1[10][10] = {};
    int v1,e1;
    cin>>v1>>e1;
    for(int i=0;i<e1;i++){
        int u,v;
        cin>>u>>v;
        adj_matrix1[u][v] = 1;
    }

    // undirected graph
    int adj_matrix2[10][10] = {};
    int v2,e2;
    cin>>v2>>e2;
    for(int i=0;i<e2;i++){
        int u,v;
        cin>>u>>v;
        adj_matrix2[u][v] = 1;
        adj_matrix2[v][u] = 1;
    }

    // 2. adjacent list
    
    int v3,e3;
    cin>>v3>>e3;
    for(int i=0;i<e3;i++){
        int u,v;
        cin>>u>>v;
        adj1[u].push_back(v);
    }
    vector<int> adj2[10];
    int v4,e4;
    cin>>v4>>e4;
    for(int i=0;i<e4;i++){
        int u,v;
        cin>>u>>v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
}