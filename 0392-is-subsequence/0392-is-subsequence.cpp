class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        
        if (s.empty()) return true;
        
        if (t.empty()) return false;

        
        while (i < s.size() && j < t.size()) {
            
            if (s[i] == t[j]) {
                i++;
            }
            
            j++;
        }

        
        return i == s.size();
    }
};
