class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        /* ----------------------------BRUTE FORCE----------------------------------
        unordered_map<int,int>mp;
        // all ele in map
        for(auto i: nums)
        {
            mp[i]++;
        }

        //mind the max freq k times and store them in an vector
        vector<int>ans;
        for(int i = 0; i <k; i++)
        {
            int maxfreq = 0;
            int maxNum = 0;
            for(auto& j : mp)
            {
                if( j.second > maxfreq)
                {
                    maxfreq = j.second;
                    maxNum = j.first;
                }

            }
        ans.push_back(maxNum);
        mp[maxNum] = 0;

        }
        return ans;*/

        // -------------------OPTIMIZED : USING BUCKET SORT APPROACH-------------------------

        unordered_map<int,int>mp;
        for(auto i : nums)
        {
            mp[i]++;
        }

        vector<vector<int>>buck(nums.size()+1);
        for(auto i : mp)
        {
            buck[i.second].push_back(i.first);
        }

        vector<int>ans;
        for(int i = buck.size()-1; i>= 0 && ans.size()<k; i--)
        {
            for(int num : buck[i])
            {
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;

    }
};
