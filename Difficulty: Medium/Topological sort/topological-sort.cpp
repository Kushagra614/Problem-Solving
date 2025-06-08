class Solution {
  public:
  
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st)
    {
        vis[node] = 1;
        for(auto i : adj[node])
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        
        st.push(node); 
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>vis(V, 0);
        stack<int>st;
        vector<vector<int>>adj(V);
        vector<int>ans;
        
        //changing edges into adj
        for( auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        for(int j = 0; j < V; j++)
        {
            if(!vis[j])
            {
                dfs(j, vis, adj, st);
            }
            
        }
        
        
        while(!st.empty())
        {
            int s = st.top();
            st.pop();
            ans.push_back(s);
        }
        
        return ans;
        
        
        
        
    }
};