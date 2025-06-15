class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
      int i = 0;
      int j = 0;
      unordered_map<int,int>mp;
      int maxLen = INT_MIN;

      while(j<fruits.size())
      {
        mp[fruits[j]]++;
        

        while(mp.size() > 2)
        {
            mp[fruits[i]]--;
            if(mp[fruits[i]] == 0)
            {
                mp.erase(fruits[i]);
            }
            i++;
        }

        maxLen = max(maxLen, j - i +1);
        j++;
      }

      return maxLen;

    }
};