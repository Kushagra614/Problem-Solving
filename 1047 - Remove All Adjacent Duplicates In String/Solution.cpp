class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (!st.empty() && ch == st.top()) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            result+=st.top();
            st.pop();
            
            
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
};
