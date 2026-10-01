class Solution {
public:
    void getall(int index, vector<int>& nums, vector<int>& current,
                vector<vector<int>>& ans) {
        
        // Every current subset is a valid answer
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            // Choose
            current.push_back(nums[i]);

            // Explore
            getall(i + 1, nums, current, ans);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        getall(0, nums, current, ans);

        return ans;
    }
};