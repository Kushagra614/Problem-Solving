class Solution {
public:
    int findMax(const vector<int>& v) {
        if (v.empty()) {
            throw runtime_error("Cannot find maximum of an empty vector");
        }
        return *max_element(v.begin(), v.end());
    }

    int maxProfit(vector<int>& prices) {
        vector<int> v;
        int diff = 0;
        int j = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[j] < prices[i]) {
                diff = prices[i] - prices[j];
                v.push_back(diff);
                continue;
            }
            else{
                prices[j] = prices[i];
            }

            
        }
        
       
        if (v.empty()) {
            return 0;  
        }
        return findMax(v);
    }
};