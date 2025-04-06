class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size()-1;
        int maxW = INT_MIN;

        while(i<j)
        {
            int indi = j-i;
            int h = min(height[i], height[j]);
            int ans = indi*h;
            maxW = max(maxW, ans);

            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxW;

        // int maxW = INT_MIN;
        // for(int i = 0; i<height.size(); i++)
        // {
        //     int j = i+1;
            
        //     while(j<height.size())
        //     {
        //         int indi = j-i;
        //         if(height[i]>height[j])
        //         {
                   
        //             int ans = indi* height[j];
        //             if(ans>maxW)
        //             {
        //                 maxW = ans;
        //             }
                    
        //         }
        //         else
        //         {
        //             int ans = indi* height[i];
        //             if(ans>maxW)
        //             {
        //                 maxW = ans;
        //             }
        //         }
        //         j++;
        //     }
        // }
        // return maxW;
    }
};