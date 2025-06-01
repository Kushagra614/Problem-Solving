class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        vector<vector<int>>ans;
        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) 
        {
           int s = max(firstList[i][0], secondList[j][0]);
           int e = min(firstList[i][1], secondList[j][1]);

           if(s<=e)
           {
            ans.push_back({s,e});
           }

           //moving pointer
           if(firstList[i][1] < secondList[j][1])
           {
            i++;
           }
           else
           {
            j++;
           }
        }
        return ans;
    }
};