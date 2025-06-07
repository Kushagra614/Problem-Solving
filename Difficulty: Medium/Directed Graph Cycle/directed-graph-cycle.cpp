class Solution {
  public:
  
    bool dfs(int start, vector<int>&vis, vector<int>&track, vector<vector<int>>adj)
    {
        vis[start] = 1;
        track[start] = 1;
        
        for(auto nbr : adj[start])
        {
            if(!vis[nbr])
            {
                if(dfs(nbr, vis, track, adj))
                {
                    return true;
                }
                
            }
            else if(track[nbr])
            {
                return true;
            }
        }
        
        track[start] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>vis(V,0);
        vector<int>track(V,0);
        vector<vector<int>>adj(V);
        
        
        //converting edges to adf list
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        for(int i = 0; i< V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, track, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};