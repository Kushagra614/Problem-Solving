class Solution {
public:
typedef pair<int, pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    //     //brute force
    //    priority_queue<
    //     pair<int, pair<int, int> >,
    //     vector<pair<int, pair<int, int> > >,
    //     greater<pair<int, pair<int, int> > >
    // > pq;

    //     for(int i = 0; i < nums1.size(); i++)
    //     {
    //         for(int j = 0; j < nums2.size(); j++)
    //         {
    //             int sum = nums1[i] + nums2[j];
    //             pq.push({sum, {nums1[i], nums2[j]}});
    //         }
    //     }

        

    //     // now pop till k
    //     vector<vector<int>>ans;
    //     while(k>0)
    //     {
    //         auto topp = pq.top(); pq.pop();
    //         auto res = topp.second;
    //         ans.push_back({res.first, res.second});
    //         k--;
    //         if(k == 0) break;
    //     }

    //     return ans;
    //     }

    // --------X-----------X-------------OPTIMIZED-------------X--------------X----------
    priority_queue<P, vector<P>, greater<P>>pq;

    int n = nums1.size();
    int m = nums2.size();

    set<pair<int,int>>vis;

    int sum = nums1[0]+nums2[0];
    pq.push({sum, {0,0}});
    vis.insert({0,0});


    vector<vector<int>>res;

    while(k>0 && !pq.empty())
    {
        auto topp = pq.top();
        pq.pop();

        int i = topp.second.first;
        int j = topp.second.second;

        res.push_back({nums1[i], nums2[j]});
        k--;

        // now we will check 
        // (i+1,j) -> if in bounds
        if(i+1 < n && vis.find({i+1,j})== vis.end())
        {
            pq.push({nums1[i+1]+nums2[j], {i+1,j}});
            vis.insert({i+1,j});
        }
        //(i, j+1) -> if in bounds
        if(j+1 < m && vis.find({i,j+1})== vis.end())
        {
            pq.push({nums1[i]+nums2[j+1], {i,j+1}});
            vis.insert({i,j+1});
        }

    }
    return res;
    }

};