class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0))
            ans += '-';

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        ans += to_string(num / den);
        long long rem = num % den;

        if (rem == 0) return ans;

        ans += '.';

        unordered_map<long long, int> pos;

        while (rem) {
            if (pos.count(rem)) {
                ans.insert(pos[rem], "(");
                ans += ")";
                break;
            }

            pos[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }

        return ans;
    }
};