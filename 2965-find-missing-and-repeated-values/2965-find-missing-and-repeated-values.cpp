class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;

        long long actualSum = 0, actualSqSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long x = grid[i][j];
                actualSum += x;
                actualSqSum += x * x;
            }
        }

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        // a = repeated, b = missing
        long long diff = actualSum - expectedSum; // a - b
        long long sqDiff = actualSqSum - expectedSqSum; // a² - b²

        // a² - b² = (a-b)(a+b)
        long long sum = sqDiff / diff; // a + b

        long long a = (diff + sum) / 2;
        long long b = sum - a;

        return {(int)a, (int)b};
    }
};