class Solution {
public:
    int romanToInt(string s) {
        //storing the values in unordered map
        unordered_map<char,int>romanMap{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int total = 0;
        int curr = 0;
        int n = s.size();

        for(int i = 0; i<n;i++ )
        {
            curr = romanMap[s[i]];

            if(i<n-1 && romanMap[s[i]]<romanMap[s[i+1]])
            {
                
                total -= curr;
            }
            else{
                total += curr;
            }
        }
        return total;
    }
};