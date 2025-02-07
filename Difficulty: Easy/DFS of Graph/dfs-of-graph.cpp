//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void dfsans(int n, int vis[], vector<int>&dfs , vector<vector<int>>&adj)
    {
        vis[n] = 1;
        dfs.push_back(n);
        
        for(auto i : adj[n])
        {
            if(!vis[i])
            {
                 dfsans(i, vis, dfs, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        
        //create visiting arr
        int vis[adj.size()] = {0};
        
        //create ans vector
        vector<int>dfs;
        
        //starting node
        int start = 0;
        
        dfsans(start, vis, dfs, adj);
        
        return dfs;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends