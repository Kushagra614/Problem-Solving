class Solution {
  public:
  
 bool bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
    vector<int> parent(vis.size(), -1);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto i : adj[node]) {
            if (!vis[i]) {
                vis[i] = 1;
                parent[i] = node;
                q.push(i);
            }
            else if (i != parent[node]) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int> vis(V, 0);
    vector<vector<int>> adj(V);  // Initialize with size V

    for (auto k : edges) {
        int u = k[0];
        int v = k[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (bfs(i, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}

};