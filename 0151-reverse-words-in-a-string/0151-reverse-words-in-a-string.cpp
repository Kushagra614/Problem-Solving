class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = n - 1;

        // Traverse from the end to the beginning
        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            // Find the start of the word
            int j = i;
            while (j >= 0 && s[j] != ' ') j--;

            // Extract the word and push it into the vector
            words.push_back(s.substr(j + 1, i - j));

            // Move i to the start of the next word
            i = j;
        }

        // Join the words to form the final result
        string result;
        for (int k = 0; k < words.size(); k++) {
            if (k > 0) result += " ";  // Add space between words
            result += words[k];
        }

        return result;
    }
};
