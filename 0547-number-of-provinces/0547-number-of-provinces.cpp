class Solution {
public:

    void dfs(int start,vector<vector<int>>& isConnected, vector<int>&vis)
    {
        vis[start] = 1;

        for(int i = 0; i< isConnected.size(); i++)
        {
            if(isConnected[start][i] == 1 && !vis[i])
            {
                dfs(i, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int count = 0;

        for(int i = 0; i< n; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i, isConnected, vis);
            }
        }

        return count;
    }
};