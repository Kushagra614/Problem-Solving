class Solution {
  public:
  
  void dfsSolve(int node, vector<vector<int>>& adj, vector<int>&vis ,vector<int>&ans)
  {
      vis[node] = 1;
      ans.push_back(node);
      
      for(auto i : adj[node])
      {
          if(!vis[i])
          {
              dfsSolve(i, adj, vis, ans);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int>vis(adj.size(), 0);
        vector<int>ans;
        dfsSolve(0, adj, vis, ans);
        return ans;
    }
};