class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //put all the elements in the pq
        priority_queue<int>pq;
        for(auto i : nums)
        {
            pq.push(i);
        }

        //now iterate pq and pop ele till k
        for(int i = 0; i<k; i++)
        {
            if(i == k-1)
            {
                return pq.top();
            }
            else
            {
                pq.pop();
            }
        }
        return {};
    }
};