class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }

        int minP = prices[0];
        int maxP = 0;

        for(int i = 1; i< prices.size(); i++)
        {
            if(prices[i] < minP)
            {
                minP = prices[i];
            }
            else{
                maxP = max(maxP, prices[i]-minP);
            }
        }
        return maxP;
    }
};