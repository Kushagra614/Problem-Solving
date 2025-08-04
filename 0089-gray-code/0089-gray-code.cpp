class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) {
            return {0};
        }
        vector<int> ans;
        vector<int> prev = grayCode(n - 1);
        ans = prev;
        int add = 1 << (n - 1);
        for (int i = prev.size() - 1; i >= 0; i--) {
            ans.push_back(prev[i] + add);
        }
        return ans;
    }
};