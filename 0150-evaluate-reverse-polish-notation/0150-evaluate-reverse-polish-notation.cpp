class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int ans = 0;
        for(auto i : tokens)
        {
            
            if(isdigit(i[0]) || i.size() > 1) st.push(i);
            else
            {
                if(st.size() >= 2)
                {
                    if(i == "+")
                    {
                        string v1 = st.top(); st.pop();
                        string v2 = st.top(); st.pop();
                        ans = stoi(v1) + stoi(v2);
                    }
                    else if(i == "-")
                    {
                        string v1 = st.top(); st.pop();
                        string v2 = st.top(); st.pop();
                        ans = stoi(v2) - stoi(v1);
                    }
                    else if(i == "*")
                    {
                        string v1 = st.top(); st.pop();
                        string v2 = st.top(); st.pop();
                        ans = stoi(v1) * stoi(v2);
                    }
                    else if(i == "/")
                    {
                        string v1 = st.top(); st.pop();
                        string v2 = st.top(); st.pop();
                        ans = stoi(v2) / stoi(v1);
                    }
                    st.push(to_string(ans));
                }
            }
        }
        return stoi(st.top());
    }
};