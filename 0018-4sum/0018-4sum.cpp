class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Minimum possible sum
            long long minSum = (long long)nums[i] + nums[i + 1] 
                             + nums[i + 2] + nums[i + 3];

            if (minSum > target)
                break;

            // Maximum possible sum
            long long maxSum = (long long)nums[i] + nums[n - 1] 
                             + nums[n - 2] + nums[n - 3];

            if (maxSum < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Minimum possible sum for this j
                long long minSum2 = (long long)nums[i] + nums[j]
                                   + nums[j + 1] + nums[j + 2];

                if (minSum2 > target)
                    break;

                // Maximum possible sum for this j
                long long maxSum2 = (long long)nums[i] + nums[j]
                                   + nums[n - 1] + nums[n - 2];

                if (maxSum2 < target)
                    continue;

                int p = j + 1;
                int q = n - 1;

                while (p < q) {

                    long long sum = (long long)nums[i] + nums[j]
                                  + nums[p] + nums[q];

                    if (sum < target) {
                        p++;
                    }
                    else if (sum > target) {
                        q--;
                    }
                    else {
                        ans.push_back({
                            nums[i], nums[j], nums[p], nums[q]
                        });

                        p++;
                        q--;

                        // Skip duplicates
                        while (p < q && nums[p] == nums[p - 1])
                            p++;

                        while (p < q && nums[q] == nums[q + 1])
                            q--;
                    }
                }
            }
        }

        return ans;
    }
};