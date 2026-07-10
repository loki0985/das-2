class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int index, int parts, string current) {
        // If 4 parts are created
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try taking 1 to 3 digits for each part
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);

            // Leading zero condition
            if (part.size() > 1 && part[0] == '0')
                break;

            // Value must be between 0 and 255
            if (stoi(part) > 255)
                continue;

            backtrack(s, index + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return ans;
    }
};