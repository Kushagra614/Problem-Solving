class Solution {
  public:
  
    // void dfs(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st)
    // {
    //     vis[node] = 1;
    //     for(auto i : adj[node])
    //     {
    //         if(!vis[i])
    //         {
    //             dfs(i, vis, adj, st);
    //         }
    //     }
        
    //     st.push(node); 
        
    // }
    // vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //     vector<int>vis(V, 0);
    //     stack<int>st;
    //     vector<vector<int>>adj(V);
    //     vector<int>ans;
        
    //     //changing edges into adj
    //     for( auto e : edges)
    //     {
    //         int u = e[0];
    //         int v = e[1];
    //         adj[u].push_back(v);
    //     }
        
    //     for(int j = 0; j < V; j++)
    //     {
    //         if(!vis[j])
    //         {
    //             dfs(j, vis, adj, st);
    //         }
            
    //     }
        
        
    //     while(!st.empty())
    //     {
    //         int s = st.top();
    //         st.pop();
    //         ans.push_back(s);
    //     }
        
    //     return ans;
        
        // -X-X-X-X-X-X--X-X-X-X-X-X-X-X-X--XX--X-X-X-X-X-X-X-X-X-X-X-X-X-X-X
        //  NOW USING BFS ( KAHNS ALGO)

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
    
    vector<vector<int>>adj(V);
    vector<int>indeg(V);
    queue<int>q;
    
        //edges to adj
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            
        }
        
        // find all the indegree
        for(int i = 0; i< V; i++)
        {
            for(auto j : adj[i])
            {
                indeg[j]++;
            }
        }
        
        
        // 0 indeg to queue
        for(int i = 0; i< V; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }
        
        
        //now do bfs
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto nbr : adj[node])
            {
                indeg[nbr]--;
                if(indeg[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        
        return ans;
        
        
        
    
        
        
    }
};