class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;

    void backtrack(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (string &p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_set<string> visited;
        queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();

            unordered_set<string> levelVisited;

            while (size--) {
                string word = q.front();
                q.pop();

                string temp = word;

                for (int i = 0; i < word.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (!dict.count(temp))
                            continue;

                        if (visited.count(temp))
                            continue;

                        if (!levelVisited.count(temp)) {
                            levelVisited.insert(temp);
                            q.push(temp);
                        }

                        parents[temp].push_back(word);

                        if (temp == endWord)
                            found = true;
                    }

                    temp[i] = original;
                }
            }

            for (auto &w : levelVisited)
                visited.insert(w);
        }

        if (!found)
            return {};

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, path);

        return ans;
    }
};