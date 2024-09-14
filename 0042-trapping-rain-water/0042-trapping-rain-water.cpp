class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)return 0;

        int l = 0;
        int r = n-1;
        int lmax = 0;
        int rmax = 0;
        int wt = 0;

        while(l<r){
            if(height[l]<=height[r])
            {
                if(height[l]>=lmax)
                {
                    lmax = height[l];
                }
                else
                {
                    wt += lmax - height[l];
                }
                l++;
            }
            else
            {
                if(height[r]>= rmax)
                {
                    rmax = height[r];

                }
                else
                {
                    wt += rmax - height[r];
                }
                r--;
            }
        }
        return wt;
    }
};