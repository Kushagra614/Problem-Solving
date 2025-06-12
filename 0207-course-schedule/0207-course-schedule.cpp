class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        queue<int>q;
        vector<int>ans;

         //creating adj list
        for(auto e : prerequisites)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        //finding all the indeg
        for(int i = 0; i<numCourses; i++)
        {
            for(auto j : adj[i])
            {
                indeg[j]++;
            }
        }

        //all the nodes of indeg 0 to be pushed to queue
        for(int i = 0; i<numCourses; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        //now doing bfs
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto i : adj[node])
            {
                indeg[i]--;
                if(indeg[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return (ans.size() == numCourses);


       
    }
};