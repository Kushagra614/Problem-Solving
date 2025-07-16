class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        stack<char>rev;
        string res = "";

        for(int i = 0; i<s.size(); i++)
        {
            char ch = s[i];
            if(ch == '*')
            {
                st.pop();
            }
            else if (ch != '*')
            {
                st.push(ch);
            }
            
        }

        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            rev.push(node);
        }

        while(!rev.empty())
        {
            res += rev.top();
            rev.pop();
        }

        return res;
    }
};