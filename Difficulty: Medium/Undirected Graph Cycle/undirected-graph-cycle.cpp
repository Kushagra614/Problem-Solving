//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solveBFS(int src, unordered_map<int,bool>&vis,vector<vector<int>>& adj)
    {
        queue<int>q;
        unordered_map<int,int>parent;
        
        
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        
        while(!q.empty())
        {
             int front = q.front();
            q.pop();
        
        for(auto nbr : adj[front])
        {
           
            
            if(!vis[nbr])
            {
              vis[nbr] = true;
              q.push(nbr);
              parent[nbr] = front;
            }
            else if(vis[nbr] == true && nbr != parent[front])
            {
                return true;
            }
            
        }
        }
        return false;
        
    }
    
    bool solveDFS(int src, unordered_map<int, bool>& vis, vector<vector<int>>& adj, int parent)
{
    vis[src] = true;

    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            if (solveDFS(nbr, vis, adj, src))  
            {
                return true;  
            }
        }
        else if (nbr != parent)  
        {
            return true;  
        }
    }
    return false;  // No cycle detected
}

bool isCycle(vector<vector<int>>& adj)
{
    int V = adj.size();
    unordered_map<int, bool> vis;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (solveDFS(i, vis, adj, -1))  // Start DFS with parent = -1
            {
                return true;  // Cycle found
            }
        }
    }
    return false;  // No cycle found in any component
}

    
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends