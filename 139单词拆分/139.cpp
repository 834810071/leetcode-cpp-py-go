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