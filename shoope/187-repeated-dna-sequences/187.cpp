#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        if (len < 11) return {};
        unordered_set<string> one, second;
        one.insert(s.substr(0, 10));
        for (int i = 1; i < len-9; ++i) {
            string tmp = s.substr(i, 10);
            if (one.count(tmp)) {
                second.insert(tmp);
            }
            else {
                one.insert(tmp);
            }
        }
        return vector<string>(second.begin(), second.end());
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<string> res1 = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto a : res1) {
        cout << a << " ";
    }
    cout << endl;

    vector<string> res2 = sol.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    for (auto a : res2) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}