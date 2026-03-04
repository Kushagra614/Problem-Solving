class Solution {
public:

    int solve(int i, vector<vector<int>>& jobs, vector<int>& st, vector<int>&dp)
    {
        if(i >= jobs.size()) return 0;

        if(dp[i] != -1) return dp[i];

        //find the next overlapping job
        int next = lower_bound(st.begin(), st.end(), jobs[i][1]) - st.begin();
        int take = jobs[i][2] + solve(next, jobs, st, dp);
        int skip = solve(i+1, jobs, st, dp);

         dp[i] = max(take, skip);
         return dp[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;

        for(int i = 0; i < n; i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
            
        }
        sort(jobs.begin(), jobs.end());

        vector<int>st;
        for(auto &i : jobs)
        {
            st.push_back(i[0]);
        }

        vector<int>dp(n,-1);

        return solve(0, jobs, st, dp);
    }
};