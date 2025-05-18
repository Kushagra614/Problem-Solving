class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int ans = 0;
        int res = INT_MIN;

        while(i<j)
        {
            if(height[i] < height[j])
            {
                ans = height[i] * (j-i);
                res = max(res, ans);
                i++;

            }

            else
            {
                ans = height[j] * (j-i);
                res = max(res, ans);
                j--;
            }

        }
        return res;
    }
};