//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(int src, unordered_map<int,bool>&vis,vector<vector<int>>& adj)
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
    bool isCycle(vector<vector<int>>& adj) {
        
        //vis arr
        int V = adj.size();
        unordered_map<int,bool>vis;
        
        for(int i = 0; i< V; i++)
        {
            if(!vis[i]){
            if(solve(i,vis,adj))
            {
                return true;
            }
        }
        }
        return false;
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