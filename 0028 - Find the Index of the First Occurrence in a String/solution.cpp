class Solution {
public:
    int strStr(string haystack, string needle) {
        int foundIndex = haystack.find(needle);

    if (foundIndex != string::npos) {
        // cout << "Substring found at index: " << foundIndex << endl;
        return foundIndex;
    } else {
        // cout << "Substring not found" << endl;
        return -1;
    }
    }
};
