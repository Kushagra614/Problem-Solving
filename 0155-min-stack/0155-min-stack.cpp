/*class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() { mini = INT_MAX; }

    void push(int val) {
        // 1st ele
        long long value = val;
        if (st.empty()) {
            st.push(value);
            mini = value;
        }

        else {
            if (value < mini) {
                st.push(2 * value - mini);
                mini = value;
            }

            else {
                st.push(value);
            }
        }
    }

    void pop() {
        if (st.empty())
            return;

        long long curr = st.top();
        st.pop();

        if (curr < mini) {
            mini = 2 * mini - curr;
        }
    }

    int top() {
        if (st.empty())
            return -1;

        long long curr = st.top();
        if (curr >= mini) {
            return curr;
        } else {
            return mini;
        }
    }

    int getMin() { return (int)mini; }
};*/

class MinStack {
private:
    stack<pair<int, int>> st; 

public:
    void push(int val) {
        if (st.empty()) {
            st.push({val, val}); 
        } else {
            
            int mini = min(st.top().second, val);
            st.push({val, mini});
        }
    }

    void pop() {
        st.pop(); // Automatically removes the min record
    }

    int top() {
        return st.top().first; // Actual value
    }

    int getMin() {
        return st.top().second; // Current min (from the pair)
    }
};




/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */