class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxV = *max_element(nums.begin(), nums.end());

        // freq[x] = count of x in nums
        vector<long long> freq(maxV + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[g] = how many numbers are divisible by g
        vector<long long> cnt(maxV + 1, 0);
        for (int g = 1; g <= maxV; g++) {
            for (int m = g; m <= maxV; m += g) {
                cnt[g] += freq[m];
            }
        }

        // exact[g] = number of pairs with gcd exactly g
        vector<long long> exact(maxV + 1, 0);

        for (int g = maxV; g >= 1; g--) {
            long long total = cnt[g] * (cnt[g] - 1) / 2;

            for (int m = 2 * g; m <= maxV; m += g) {
                total -= exact[m];
            }

            exact[g] = total;
        }

        // prefix over gcd values in ascending order
        vector<long long> pref(maxV + 1, 0);
        for (int g = 1; g <= maxV; g++) {
            pref[g] = pref[g - 1] + exact[g];
        }

        // Answer queries
        vector<int> ans;
        ans.reserve(queries.size());

        for (long long k : queries) {
            // find smallest g with pref[g] > k
            int g = upper_bound(pref.begin(), pref.end(), k) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};