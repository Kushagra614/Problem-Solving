class Solution {
public:
    int maxArea(vector<int>& height) {
        int n  = height.size();
        int l = 0;
        int r = n-1; 
        int ans = 0;

        while(l<r)
        {
            if(height[l]<height[r])
            {
                ans = max(ans,height[l]*(r-l));
                l++;
            }
            else{
                ans = max(ans,height[r]*(r-l));
                r--;
            }
        }
        return ans;
       
    }
};