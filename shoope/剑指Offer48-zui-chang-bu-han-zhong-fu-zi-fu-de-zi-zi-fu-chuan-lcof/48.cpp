#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> m;
        int l = -1, r = 0, res = 0;
        while (r < s.length())
        {
            if (m.count(s[r]))
            {
                l = max(l, m[s[r]]);
            }
            m[s[r]] = r;
            res = max(res, r - l);
            ++r;
        }
        return res;
    }
};

int main(int argc, char **args)
{
    Solution sol = Solution();
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
    cout << sol.lengthOfLongestSubstring(" ") << endl;
    return 0;
}