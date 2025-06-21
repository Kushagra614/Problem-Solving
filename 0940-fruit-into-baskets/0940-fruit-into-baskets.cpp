class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;
        unordered_map<int,int>st;

        while(j<fruits.size())
        {
            st[fruits[j]]++;

            while(st.size() > 2)
            {
                st[fruits[i]]--;
                if(st[fruits[i]] == 0)
                {
                    st.erase(fruits[i]);
                }
                i++;
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
        

    }
};