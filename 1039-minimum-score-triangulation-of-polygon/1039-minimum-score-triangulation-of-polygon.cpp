class Solution {
public:
    int solveRes(vector<int> &vertex, int i, int j)
    {
        // if triangle can't be formed
        if (j - i < 2)
        {
            return 0;
        }

        // initialize result as infinite
        int res = INT_MAX;

        // loop over all vertices between i and j
        for (int k = i + 1; k < j; k++)
        {
            res = min(res, solveRes(vertex, i, k) +
                              solveRes(vertex, k, j) +
                              vertex[i] * vertex[k] * vertex[j]);
        }
        return res;
    }
    
    int solveMem(vector<vector<int>> &dp, vector<int> &vertex, int i, int j)
    {
        if (dp[i][j] == 0)
        {
            /* iterate over all the vertices between i and j */
            for (int k = i + 1; k < j; k++)
            {
                int curr_score = vertex[i] * vertex[k] * vertex[j];

                // Left sub polygon
                int left_polygon = solveMem(dp, vertex, i, k);

                // Right subpolygon
                int right_polygon = solveMem(dp, vertex, k, j);

                dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], left_polygon + curr_score + right_polygon);
            }
        }
        return dp[i][j];
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = solveMem(dp, values, 0, n - 1);
        return ans;
    }
};