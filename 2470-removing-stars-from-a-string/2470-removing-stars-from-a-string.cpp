class Solution {
public:
    string removeStars(string s) {
        //using deque
        deque<char>dq;
        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if(ch == '*')
            {
                if(!dq.empty())
                {
                    dq.pop_back();
                }
            }
            else
            {
                dq.push_back(ch);
            }
        }

        string res = "";
        while(!dq.empty())
        {
            char sh = dq.front();
            dq.pop_front();
            res += sh;
        }

        return res;
    }
};