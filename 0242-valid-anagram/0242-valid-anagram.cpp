class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int>st1;
        unordered_map<char, int>st2;

        for(auto i : s)
        {
            st1[i]++;
        }

        for(auto i : t)
        {
            st2[i]++;
        }

        if(st1 == st2) return true;
        else
        {
            return false;
        }
    }
};