class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            // Negative number swaps max and min
            if (x < 0)
                swap(currMax, currMin);

            currMax = max(x, currMax * x);
            currMin = min(x, currMin * x);

            ans = max(ans, currMax);
        }

        return ans;
    }
};