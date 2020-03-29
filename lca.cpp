#include<bits/stdc++.h>
using namespace std;
struct lca{
    int n, l,root;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    void _init(int num,int num1){
    n=num;root=num1;}
    void add_edge(int a,int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
            }
            tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int solve(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
                if (!is_ancestor(up[u][i], v))
                u = up[u][i];
            }
        return up[u][0];
    }
    void preprocess() {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        adj.resize(n);
        dfs(root,root);
    }
    //lca.init(n,root)
    //lca.preprocess()
    //lca.add_edge(u,v)
    //lcd.solve(u,v);
};
