class Solution {
    bool is_palindrome(string_view const& s) {
        int last = s.size() - 1;
        for (int i = 0; i < last-i; ++i) {
            if (s[i] != s[last-i]) return false;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string_view,int> data;
        const int m = words.size();
        for (int i = 0; i < m; ++i) {
            data[words[i]] = i;
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            string word = words[i];
            const int n = word.size();
            reverse(word.begin(), word.end());
            string_view word_view(word);
            
            for (int j = 0; j <= n; ++j) {
                auto it = data.find(word_view.substr(0, j));
                if (it != data.end() && it->second != i && is_palindrome(word_view.substr(j))) {
                    result.push_back({it->second, i});
                }
            }
            for (int j = 0; j < n; ++j) {
                auto it = data.find(word_view.substr(n-j, j));
                if (it != data.end() && is_palindrome(word_view.substr(0, n-j))) {
                    result.push_back({i, it->second});
                }
            }
        }
        return result;
    }
};