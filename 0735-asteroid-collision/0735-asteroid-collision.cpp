class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        // stack<int>st;
        deque<int>st;
        for(int i = 0; i<asteroids.size();)
        {
            
            if(st.empty())
            {
                st.push_back(asteroids[i]);
                i++;
            }
            else
            {//checking the diff signs
            int topp = st.back();
            if(asteroids[i] < 0 && topp > 0)
            {
                if(abs(asteroids[i]) > abs(topp))
                {
                    st.pop_back();
                }
                else if(abs(asteroids[i]) == abs(topp))
                {
                    st.pop_back();
                    i++;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                st.push_back(asteroids[i]);
                i++;
            }
            }

        }

        vector<int>res;
        
        while(!st.empty())
        {
            int toop = st.front();
            st.pop_front();
            res.push_back(toop);
        }

        return res;
    }
};