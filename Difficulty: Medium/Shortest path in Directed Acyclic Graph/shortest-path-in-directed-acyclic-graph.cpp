// User function Template for C++
class Solution {
  public:
  
    void dfs(int node, vector<int>&vis, stack<int>&st, unordered_map<int, list<pair<int, int>>>adj)
    {
        vis[node] = 1;
        
        for(auto i : adj[node])
        {
            if(!vis[i.first])
            {
                dfs(i.first, vis, st, adj);
            }
        }
        st.push(node);
    }
    
    void solveEnd(int src, vector<int>&dis, unordered_map<int, list<pair<int, int>>>adj, stack<int>st)
    {
        dis[src] = 0;
         while(!st.empty())
        {
            int src = st.top();
            st.pop();
            
              if(dis[src] != INT_MAX) 
              {  // Only if current node is reachable
                
                for(auto k : adj[src]) 
                {
                    if(dis[src] + k.second < dis[k.first]) 
                    {
                     dis[k.first] = dis[src] + k.second;
                    }
                
                }
               }
        }
    }
            
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<int>vis(V, 0);
        unordered_map<int, list<pair<int, int>>>adj;
        
        
        // edges into ajlist
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v,w});
        }
        
        //perform topo sort
        stack<int>st;
        
        for(int i = 0; i< V; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }
        
        
        //now we will update the dist arr
        vector<int>dis(V, INT_MAX);
        
        solveEnd(0, dis, adj, st);
      
        // At the end, before returning
        for(int i = 0; i < V; i++) 
        {
            if(dis[i] == INT_MAX) 
            {
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};
