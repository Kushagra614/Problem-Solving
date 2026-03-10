class Solution {
public:

void solve(int start, int target, vector<int>& candidates,
         vector<int>& curr, vector<vector<int>>& result)
{
    if(target == 0)
    {
        result.push_back(curr);
        return;
    }

    for(int i = start; i < candidates.size(); i++)
    {
        if(candidates[i] > target)
            break;

        curr.push_back(candidates[i]);
        solve(i, target - candidates[i], candidates, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> curr;

    solve(0, target, candidates, curr, result);

    return result;
}
   
};

