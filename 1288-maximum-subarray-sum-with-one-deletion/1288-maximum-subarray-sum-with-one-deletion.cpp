class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDelete = arr[0];
        int oneDelete = 0;
        int ans = arr[0];

        for(int i = 1; i < n; i++)
        {
            int prevNoDelete = noDelete;
            noDelete = max(noDelete + arr[i], arr[i]);
            oneDelete = max(oneDelete + arr[i], prevNoDelete);
            ans = max(ans, max(noDelete, oneDelete));
        }
        return ans;
    }
};