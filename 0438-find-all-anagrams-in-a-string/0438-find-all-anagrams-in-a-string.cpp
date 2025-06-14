class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pMap;
        vector<int> ans;

        // p into mp
        for (auto i : p) {
            pMap[i]++;
        }

        int w = p.size();
        unordered_map<char, int> sMap;

        // for the 1st window
        for (int i = 0; i < w; i++) {
            sMap[s[i]]++;
        }

        if (pMap == sMap) {
            ans.push_back(0);
        }

        // sliding window
        for (int i = w; i < s.size(); i++) {
            // add new element
            sMap[s[i]]++;

            // remove old element
            auto old = s[i - w];
            sMap[old]--;
            if (sMap[old] == 0) {
                sMap.erase(old);
            }

            if (pMap == sMap) {
                ans.push_back(i - w + 1);
            }
        }
        return ans;
    }
};