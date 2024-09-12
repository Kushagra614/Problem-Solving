class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int hIndex = 0;
        
        sort(citations.begin(), citations.end());
        
        for(int i = 0; i< n ;i ++)
        {
            
            int ele = n-i;
            if(citations[i]>=ele)
            {
                hIndex  = ele;
                break;
            }
        }
        return hIndex;
        
    }
};