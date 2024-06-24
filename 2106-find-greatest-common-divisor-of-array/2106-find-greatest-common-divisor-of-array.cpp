class Solution {
public:

    int findMax(vector<int>& nums)
    {
        int max = INT_MIN;
        
        // any no. greater than this will be updated
        for(int i = 0; i< nums.size();i++)
        {
            if(nums[i]>max){
                max = nums[i];
            }
            
        }
        return max;
        
        
    }

    int findMin(vector<int>& nums)
    {
        
        int min = INT_MAX;
        // any no. greater than this will be updated
        for(int i = 0; i< nums.size();i++)
        {
            
            if(nums[i]<min){
                min = nums[i];
            }

        }
        
        return min;
        
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Function to find the GCD of the maximum and minimum values in the vector
    int findGCD(std::vector<int>& nums) {
        int maxVal = findMax(nums);
        int minVal = findMin(nums);
        return gcd(maxVal, minVal);
    }

    


    
    
};