class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int x : nums) {
            for (int cnt = 2; cnt >= 0; cnt--) {
                for (int val = 0; val < MAXX; val++) {
                    if (dp[cnt][val]) {
                        dp[cnt + 1][val ^ x] = true;
                    }
                }
            }
        }

        vector<bool> ans(MAXX, false);

        // One element (i = j = k)
        for (int x : nums)
            ans[x] = true;

        // Three distinct elements
        for (int val = 0; val < MAXX; val++)
            if (dp[3][val])
                ans[val] = true;

        int res = 0;
        for (bool x : ans)
            if (x) res++;

        return res;
    }
};