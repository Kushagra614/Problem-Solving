class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        // calculating dist of each point
        for (auto num : points) {
            int dist = 0;
            int x = num[0];
            int y = num[1];
            dist = x * x + y * y;
            pq.push({dist, {x, y}});

            // now this is the main part of the code
            // as we only need the k closest points and we are using a max Heap
            // we will pop the largest point one by one and only keep the k smallest points
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto topp = pq.top();
            pq.pop();
            auto res = topp.second;
            ans.push_back({res.first, res.second});
        }

        return ans;
    }
};