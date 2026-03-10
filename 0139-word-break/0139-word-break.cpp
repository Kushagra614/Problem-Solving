class Solution {
public:

    bool solveDPmemo(int i, string s, vector<int>& dp, unordered_set<string>& dict)
    {
        //base case
        if(i == s.size()) return true;

        //storing ans
        if(dp[i] != -1)
        {
            return dp[i];
        }

        string curr = "";
        //rec relation
        for(int j = i; j < s.size(); j++)
        {
            curr += s[j];
            if(dict.count(curr))
            {
                if(solveDPmemo(j+1, s, dp, dict))
                {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        vector<int>dp(s.size(), -1);
        bool ans = solveDPmemo(0, s, dp, dict);
        return ans;
    }
};