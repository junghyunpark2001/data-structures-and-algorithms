#include <iostream>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int MX = 500005;
int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
int val[MX];
int unused = 0;

// rolling hash
int hash_function(string& s){
    int h = 0;
    for(auto x : s) h = (h*a+x)%M;
    return h;
}

int find(string k){
    int h = hash_function(k);
    int idx = head[h];
    while(idx!=-1){
        if(key[idx]==k) return idx;
        idx = nxt[idx];
    }
    return -1;
}

void insert(string k, int v){
    int idx = find(k);
    if(idx!=-1){
        val[idx] = v;
        return;
    }
    int h = hash_function(k);
    key[unused] = k;
    val[unused] = v;
    if(head[h]!=-1){
        nxt[unused] = head[h];
        pre[head[h]] = unused;
    }
    head[h] = unused;
    unused++;
}

void erase(string k){
    int idx = find(k);
    if(idx==-1) return;
    if(pre[idx]!=-1) nxt[pre[idx]] = nxt[idx];
    if(nxt[idx]!=-1) pre[nxt[idx]] = pre[idx];
    int h = hash_function(k);
    if(head[h]==idx) head[h] = nxt[idx];
}