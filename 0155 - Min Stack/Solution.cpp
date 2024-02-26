class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() {
         
        
    }
    
    void push(int val) {
         if(st.empty())
         {
            pair<int,int> p;
            p.first = val;
            p.second = val; //as 1st element so min val will be same as 1st val
            st.push_back(p);
         }
         else
         {
            pair<int,int>p;
            p.first = val;
            int oldMin = st.back().second;
            p.second = min(oldMin, val);
            st.push_back(p);
         }
    }
    
    void pop() {
        st.pop_back(); 
    }
    
    int top() {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.first;
        
    }
    
    int getMin() {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.second;
    }
};
