class Solution {
public:
    // bool isAnagram(string& s, string& t) {
    //     if (s.size() != t.size()) return false;
    //         
    //     unordered_map<char, int> st1;
    //     unordered_map<char, int> st2;

    //     for (auto i : s) st1[i]++;
    //     for (auto i : t) st2[i]++;

    //     if (st1 == st2) return true;
    //     else return false;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {

    //     vector<bool> vis(strs.size(), false);
    //     vector<vector<string>> res;

    //     for (int i = 0; i < strs.size(); i++) {
    //         if (!vis[i]) {
    //             vector<string>ans;
    //             ans.push_back(strs[i]);
    //             vis[i] = true;

    //             for (int j = i+1; j < strs.size(); j++) {
    //                 if (!vis[j] && isAnagram(strs[i], strs[j])) {
    //                     ans.push_back(strs[j]);
    //                     vis[j] = true;
    //                 }
    //             }

    //             res.push_back(ans);
    //         }
    //     }
    //     return res;
    // }

    // ----X-----------X---------X---------X---------X---------X---------X------------X

    // OPTIMAL APPROACH

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>> res;

        for(auto s : strs)
        {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            mp[sorted_s].push_back(s);
        }

        for(auto pair : mp)
        {
            res.push_back(pair.second);
        }
        return res;
    }

};