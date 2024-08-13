class Solution {
public:
    int calculateScore(string& s) {
        int score = 0;
        for (size_t i = 1; i < s.length(); ++i) {
            score += abs(static_cast<int>(s[i]) - static_cast<int>(s[i - 1]));
        }
        return score;
    }

    int scoreOfString(string& s) {
        return calculateScore(s); 
    }
};