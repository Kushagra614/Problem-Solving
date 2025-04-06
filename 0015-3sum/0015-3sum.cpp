class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {


        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1;
            int k = nums.size()-1;

            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                vector<int>trip = {nums[i], nums[j], nums[k]};
                ans.push_back(trip);

                while (j < k && nums[j] == nums[j + 1]) j++;
                    
                while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;

                }
                else if(nums[i]+ nums[j]+ nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

return ans;




        // vector<vector<int>>ans;
        // //brute force

        // for(int i = 0; i<nums.size(); i++)
        // {
        //     for(int j = i+1; j<nums.size(); j++)
        //     {
        //         for(int k = j+1; k<nums.size(); k++)
        //         {
        //             if(nums[i] + nums[j] + nums[k] == 0)
        //             {
        //                 vector<int>trip = {nums[i], nums[j], nums[k]};
        //                 sort(trip.begin(), trip.end());
                        
        //                 bool exists = false;
        //                 for(auto vec: ans){
        //                     if(vec == trip)
        //                     {
        //                         exists = true;
        //                         break;
        //                     }
        //                 }

        //                 if(!exists)
        //                 {
        //                     ans.push_back(trip);
        //                 }

        //             }
        //         }
        //     }
        // }
        // return ans;




    }
};