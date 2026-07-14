class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // End word must exist in dictionary
        if (!dict.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int i = 0; i < word.length(); i++) {
                    string temp = word;

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (dict.count(temp)) {
                            q.push(temp);
                            dict.erase(temp);   // mark visited
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};