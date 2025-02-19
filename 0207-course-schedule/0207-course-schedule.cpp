class Solution {
public:
     
    void dfs(unordered_map<int, list<int>>&adj ,vector<int>& ans, int numCourses)
    {
        queue<int>q;
        unordered_map<int,int>indegree;

        //initialise and mark assign all the indegree
        for(auto i : adj)
        {
            for(auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        //pushing all the nodes with 0 indegree into queue
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        //bfs
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for(auto n : adj[frontNode])
            {
                indegree[n] --;

                if(indegree[n] == 0)
                {
                    q.push(n);
                }

            }
        }

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        unordered_map<int, list<int>>adj;
        //creating adj list

        for(vector<int>i : prerequisites)
        {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }


        dfs(adj, ans, numCourses);

        if(ans.size() == numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }
        

    }
};