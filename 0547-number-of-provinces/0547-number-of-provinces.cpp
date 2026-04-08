class Solution {
public:

    void dfs(int start, vector<vector<int>>&adj, vector<int>&vis)
    {
        vis[start] = 1;
        for(auto nbr : adj[start])
        {
            if(!vis[nbr])
            {
                dfs(nbr, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // convert the matrix to adj list
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (isConnected[i][j] == 1) 
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
           if(!vis[i])
           {
             dfs(i, adj, vis);
             count++;
           }
        }
        return count;
    }
};