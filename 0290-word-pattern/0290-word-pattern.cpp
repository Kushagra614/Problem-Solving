class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        vector<string>words;
        stringstream ss(s);

        while(ss >> word)
        {
            words.push_back(word);
        }

        if(pattern.size() != words.size()) return false;

        unordered_map<char, string>cts;
        unordered_map<string, char>stc;

        for(int i = 0; i<pattern.size(); i++)
        {
            char c = pattern[i];
            string w = words[i];


            if(cts.count(c) && cts[c] != w) return false;
            if(stc.count(w) && stc[w] != c) return false;

            cts[c] = w;
            stc[w] = c;
        }
        return true;

    }
};