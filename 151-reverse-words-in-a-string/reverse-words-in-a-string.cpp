class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;

        // Extract words
        for (char c : s) {
            if (c != ' ') {
                word += c;
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
        }

        if (!word.empty())
            words.push_back(word);

        // Reverse order of words
        reverse(words.begin(), words.end());

        // Join words with single spaces
        string ans;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                ans += " ";
            ans += words[i];
        }

        return ans;
    }
};