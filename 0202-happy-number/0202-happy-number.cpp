class Solution {
public:
    bool isHappy(int n) {
        vector<int>vec;
        int sum = 0;
        set<int>st;
        while(n != 1 && st.find(n) == st.end()){
            st.insert(n); 
            vec.clear();
            sum = 0;

            while(n)
            {
                int digi = n % 10;
                n =  n / 10;
                vec.push_back(digi);
            }
            
            for(auto i : vec)
            {
                sum = sum + (i*i);
            }
            if(sum != 1)
            {
                n = sum;
                

            }
            else
            {
                return true;
            }
        }
        return n==1;
    }
};