class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n) {
            n &= (n - 1);   // Remove the lowest set bit
            count++;
        }

        return count;
    }
};