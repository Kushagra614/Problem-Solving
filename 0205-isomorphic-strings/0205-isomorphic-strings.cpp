class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, char> mapping;
        string transformed = s;
        
        // Try to build mapping from s to t
        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];
            
            if (mapping.find(char_s) != mapping.end()) {
                // Check if existing mapping conflicts
                if (mapping[char_s] != char_t) {
                    return false;
                }
            } else {
                // Check if char_t is already mapped to another character
                for (auto& pair : mapping) {
                    if (pair.second == char_t) {
                        return false;
                    }
                }
                mapping[char_s] = char_t;
            }
        }
        
        // Replace characters in s using the mapping
        for (int i = 0; i < transformed.length(); i++) {
            transformed[i] = mapping[transformed[i]];
        }
        
        // Check if transformed string equals t
        return transformed == t;
    }
};