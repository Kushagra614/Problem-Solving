class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int n = nums.size();
        // vector<int> nums1;

        // for (int i = 0; i < n; i++) {
        //     if (nums[i] != val) {
        //         nums1.push_back(nums[i]);
        //     }
        // }

        
        // nums.clear();
        // nums = nums1;

        // return nums.size();

    //     int i = 0;
    //     int n = nums.size();

    //     for(int j = 0; j<n; j++)
    //     {
    //         if(nums[j]!=val)
    //         {
    //             nums[i] = nums[j];
    //             i++;
    //         }
            
    //     }
    //     return i;
    // }

    int i = 0;
    int j = nums.size()-1;
    while(i<=j)
    {
        if(nums[j]==val)
        {
            j--;
        }
        else if(nums[i]==val && nums[j]!=val )
        {
            swap(nums[i],nums[j]);
            j--;
            i++;
        }
        else{
            i++;
        }
        
    }
    return i;
    }


};