class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int i = 0;
        int cal = 0;
        
        while (i < tokens.size()) {
            if (st.empty()) {
                string n = tokens[i];
                st.push(n);
                i++;
            }
            else {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                    string t1 = st.top();
                    st.pop();
                    int v1 = stoi(t1);

                    string t2 = st.top();
                    st.pop();
                    int v2 = stoi(t2);

                    if (tokens[i] == "+") {
                        cal = v2 + v1;
                    } else if (tokens[i] == "-") {
                        cal = v2 - v1;
                    } else if (tokens[i] == "/") {
                        cal = v2 / v1;
                    } else if (tokens[i] == "*") {
                        cal = v2 * v1;
                    }

                    st.push(to_string(cal));
                }
                else {
                    st.push(tokens[i]);
                }
                i++;
            }
        }
        
        return stoi(st.top());
    }
};