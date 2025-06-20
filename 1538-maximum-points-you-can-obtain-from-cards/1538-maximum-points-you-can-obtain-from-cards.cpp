class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = k-1;
        int j = cardPoints.size()-1;
        int sum = 0;
        int maxSum = INT_MIN;

        for(int m = 0; m<k; m++)
        {
            sum+= cardPoints[m];
            
        }

        maxSum = sum;

        //sliding window
        for(int v = 0; v<k; v++)
        {
            sum -= cardPoints[i];
            i--;

            sum += cardPoints[j];
            j--;

            maxSum = max(maxSum, sum);

        }
        return maxSum;
    }
};