#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i == len1;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    cout << sol.isSubsequence("abc", "ahbgdc") << endl;
    cout << sol.isSubsequence("axc", "ahbgdc") << endl;
    return 0;
}