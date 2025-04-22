class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n = magazine.size();
        int m = ransomNote.size();
        map<char, int>mp;

        for(auto i : magazine)
        {
            mp[i]++;
        }

        //now we will check if ransom can be made
        for(auto i : ransomNote)
        {
            if(mp[i]> 0)
            {
                mp[i]--;
            }
            else
            {
                return false;
            }
        }

        return true;


    }
};