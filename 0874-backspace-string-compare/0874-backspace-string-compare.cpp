class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char>st1;
        stack<char>st2;
        vector<char>s1;
        vector<char>s2;
        

        for(auto i : s)
        {
            if(!st1.empty() && i == '#')
            {
                st1.pop();
            }
            else if(i!='#')
            {
                st1.push(i);
            }
        }

        for(auto j : t)
        {
            if(!st2.empty() && j == '#')
            {
                st2.pop();
            }
            else if(j!='#')
            {
                st2.push(j);
            }
        }

if(st1 == st2) return true;
else return false; 
       

    }
};