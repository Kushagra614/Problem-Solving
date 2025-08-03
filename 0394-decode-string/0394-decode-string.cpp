class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string res = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ']') {
                string var = "";
                
                while(!st.empty() && st.top() != '[') {
                    var = st.top() + var;  
                    st.pop();
                }
                
                
                if(!st.empty() && st.top() == '[') st.pop();
                
                
                string numStr = "";
                while(!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                
                int repeat = numStr.empty() ? 0 : stoi(numStr);
                string repeatedStr = "";
                for(int j = 0; j < repeat; j++) {
                    repeatedStr += var;
                }
                
                
                for(char c : repeatedStr) {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }
        
        
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};