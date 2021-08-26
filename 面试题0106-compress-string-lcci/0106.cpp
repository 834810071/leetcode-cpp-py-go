#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        int len = S.length();
        if (len == 0) return "";
        string res = "";
        char pre = S[0];
        int count = 1;
        for (int i = 1; i < len; ++i) {
            if (S[i] == pre) {
                ++count;
            }
            else {
                res += pre + to_string(count);
                count = 1;
                pre = S[i];
            }
        }
        res += pre + to_string(count);
        return res.length() >= len ? S : res;
    }
};
int main(int argc, char** args) {
    Solution sol = Solution();
    cout << sol.compressString("aabcccccaaa") << endl;
    cout << sol.compressString("abbccd") << endl;

    return 0;
}