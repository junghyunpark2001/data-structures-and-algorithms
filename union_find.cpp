#include <iostream>
#include <vector>

using namespace std;
class union_find{
public:
    union_find(int n) : parent(n), rank(n, 0){
        for(int i=0;i<n;++i){
            parent[i] = i; // 모든 원소가 자신을 부모로 가리킴
        }
    }

    int find(int u){
        if(u!=parent[u]){
            parent[u] = find(parent[u]);
        }
    }

    void union_sets(int u,int v){
        int root_u = find(u);
        int root_v = find(v);
        if(rank[root_u]>= rank[root_v]){
            parent[root_v] = root_u;
            rank[root_v]++;
        }
        else{
            parent[root_u] = root_v;
            rank[root_u]++;            
        }

    }
private:
    vector<int> parent;
    vector<int> rank;
};