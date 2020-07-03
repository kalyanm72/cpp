struct bridges{
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer;
int n;
    bridges(int num){n=num;}
void add_edge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
void init(){
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, inf);
}
void find_bridges() {
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}};
