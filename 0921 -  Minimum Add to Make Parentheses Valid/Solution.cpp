class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans;
        stack<char>st;
        for(int i = 0; i <s.size();i++)
        {
            char ch = s[i];
            if(ch=='(')
            {
                st.push(ch);
                // i++;

            }
            else if(ch == ')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                    // i++;
                }
                else
                {

                    st.push(ch);
                    // i++;
                }
            }
            
        }
        return st.size();
    }


};
