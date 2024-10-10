class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int maxSum = 0;
        int rsum = 0;
        int rIndex = n-1;
        // 1st we will find the sum of the 1st K elements
        for(int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
            maxSum = lsum;
        }

        for(int i = k-1; i >=0; i--)
        {
            lsum -=  cardPoints[i];
            rsum += cardPoints[rIndex];
            rIndex--;
            maxSum = max(maxSum , lsum+rsum);
            
        }

        return maxSum;
    }
            
};