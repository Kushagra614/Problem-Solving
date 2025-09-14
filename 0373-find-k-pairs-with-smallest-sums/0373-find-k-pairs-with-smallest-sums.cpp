class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //min heap
        priority_queue<P, vector<P>, greater<P>>pq;

        int n = nums1.size();
        int m = nums2.size();
    
        //pushing the 1st 2 ele
        pq.push({nums1[0] + nums2[0], {0,0}});
        //creating a set
        set<pair<int,int>>st;

        st.insert({0,0});
        vector<vector<int>>ans;

        while(k > 0 && pq.size() > 0)
        {
            auto topp = pq.top();
            pq.pop();
            
            int i = topp.second.first;
            int j = topp.second.second;
            ans.push_back({nums1[i],nums2[j]});
            k--;

            //now we have 2 chances
            if(i+1 < n && st.find({i+1,j}) == st.end())
            {
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                st.insert({i+1,j});
            }

            if(j+1 < m && st.find({i,j+1}) == st.end())
            {
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                st.insert({i,j+1});
            }
        }
        return ans;


    }
};