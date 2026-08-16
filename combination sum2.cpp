class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int index, vector<int>& path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        solve(candidates, target, 0, path);
        return ans;
    }
};
