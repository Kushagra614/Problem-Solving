class Solution {
public:
    int lengthOfLastWord(std::string &s) {
        int n = s.length();
        int i = n - 1;
        
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Mark the end of the last word
        int end = i;
        
        // Find the start of the last word
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        
        // Length of the last word
        int result = end - i;
        return result;
    }
};
