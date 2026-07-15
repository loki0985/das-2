class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s) {
        if (memo.count(s))
            return memo[s];

        vector<string> result;

        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);

            if (dict.count(word)) {
                vector<string> suffixes = dfs(s.substr(i));

                for (string suffix : suffixes) {
                    if (suffix.empty())
                        result.push_back(word);
                    else
                        result.push_back(word + " " + suffix);
                }
            }
        }

        return memo[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }
};