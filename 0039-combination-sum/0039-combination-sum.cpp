
class Solution {
public:

    void solve(int index, vector<int>& candidates,
               int target, vector<int>& current,
               vector<vector<int>>& result) {

        // Base case: target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Try all possible candidates
        for (int i = index; i < candidates.size(); i++) {

            // If number is greater than target, skip it
            if (candidates[i] > target)
                continue;

            // Choose the current element
            current.push_back(candidates[i]);

            // Recursion: same index because repetition is allowed
            solve(i, candidates, target - candidates[i],
                  current, result);

            // Backtrack: remove the last chosen element
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> current;

        solve(0, candidates, target, current, result);

        return result;
    }
};
