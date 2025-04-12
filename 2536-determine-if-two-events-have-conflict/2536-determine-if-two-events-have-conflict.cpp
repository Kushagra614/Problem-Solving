class Solution {
public:

    int toMin(string time)
    {
        return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
        int i = 0, j = 0;
        bool ans = false;

            int s1 = toMin(event1[0]);
            int s2 = toMin(event2[0]);
            int e1 = toMin(event1[1]);
            int e2 = toMin(event2[1]);
            
            int s = max(s1,s2);
            int e = min(e1,e2);

            if(s <= e)
            {
                ans = true;
            }

            return ans;

    }
};