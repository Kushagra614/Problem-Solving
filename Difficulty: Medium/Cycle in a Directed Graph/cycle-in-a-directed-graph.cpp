//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solveDFS(int src, unordered_map<int,bool>&vis, unordered_map<int,bool>&track, vector<vector<int>>&adj, int parent)
    {
        
        vis[src] = true;
        track[src] = true;
        
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                if(solveDFS(i,vis,track,adj,src)) return true;
            }
            else if(track[i]){
            return true;
         }
         
        }
        
        track[src] = false;  // Remove from recursion stack
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>>&adj) {
        unordered_map<int, bool>vis;
        unordered_map<int,bool>track;
        //case for disconnected graph
        int v = adj.size();
         for(int i = 0; i < v; i++)
        {
            if(solveDFS(i,vis,track,adj,-1)) return true;
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
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends