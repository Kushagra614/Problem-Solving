class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto i: intervals)
        {
            if(i[1] < newInterval[0])
            {
                ans.push_back(i);            
            }
            else if(i[0] > newInterval[1])
            {
                ans.push_back(newInterval);
                newInterval = i;
            }
            else
            {
                newInterval[0] = min(i[0], newInterval[0]);
                newInterval[1] = max(i[1], newInterval[1]);

            }

            
        }
        ans.push_back(newInterval);
        return ans;
    }
};