#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        for (auto& word : wordDict) {
            uset.insert(word);
        }
        int len = s.size();
        vector<int> dp = vector<int>(len+1, false);
        dp[0] = true;
        for (int i = 1; i < len+1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && uset.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << sol.wordBreak(s1, wordDict1) << endl;

    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << sol.wordBreak(s2, wordDict2) << endl;

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << sol.wordBreak(s3, wordDict3) << endl;
    return 0;
}