class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        if(cardPoints.size() == 0) return 0;
        
        //main logic
        int sum = 0;
        int maxSum = INT_MIN;
        //for the leftmost k elememts
        for(int i = 0; i< k; i++)
        {
            sum+= cardPoints[i];
           
        }
        maxSum = max(sum, maxSum);

        //now sliding the window
        int l = k-1;
        int r = cardPoints.size()-1;

        for(int m = 0; m<k; m++)
        {
            sum -= cardPoints[l];
            l--;

            sum += cardPoints[r];
            r--;

            maxSum = max(sum, maxSum);
        }

        return maxSum;


             
    }
};