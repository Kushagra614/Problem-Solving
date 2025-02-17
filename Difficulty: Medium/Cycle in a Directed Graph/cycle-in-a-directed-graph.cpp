//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<vector<int>>&adj, vector<int>&dfsTrack, vector<int>&vis)
    {
        //inistialisation
        vis[src] = 1;
        dfsTrack[src] = 1;
        
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                if(dfs(i,adj,dfsTrack, vis))
                {
                    return true;
                }
                
            }
            else if(vis[i] == true && dfsTrack[i] == true) return true;
        }
        
        dfsTrack[src] = 0;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        
         int n = adj.size();
         vector<int>dfsTrack(n,0);
         vector<int>vis(n,0);
         
         for(int i = 0; i<n ; i++)
         {
             if(!vis[i])
             { 
                 if(dfs(i, adj ,dfsTrack, vis)) return true;
             }
         }
         return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends