class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int num = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+') {
                res += sign * num;

                num = 0;
                sign = 1;
            }

            else if (ch == '-') {
                res += sign * num;

                num = 0;
                sign = -1;
            }

            else if (ch == '(') {
                st.push(res);
                st.push(sign);

                res = 0;
                sign = 1;
            }

            else if (ch == ')') {
                res += sign * num;
                num = 0;

                int prevSign = st.top();
                st.pop();
                int prevRes = st.top();
                st.pop();

                res = prevRes + prevSign * res;
            }
        }
        res += sign * num;
        return res;
    }
};