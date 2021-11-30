#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int idx = 0;
        int len = s.length();
        for (int start = 0; start < len; ++start)
        {
            if (s[start] != ' ')
            {
                if (idx != 0)
                {
                    s[idx++] = ' ';
                }

                int end = start;
                while (end < len && s[end] != ' ')
                    s[idx++] = s[end++];

                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main(int argc, char **args)
{
    Solution sol = Solution();
    cout << sol.reverseWords("the sky is blue") << endl;
    cout << sol.reverseWords("  hello world  ") << endl;
    cout << sol.reverseWords("a good   example") << endl;
    cout << sol.reverseWords("  Bob    Loves  Alice   ") << endl;
    cout << sol.reverseWords("Alice does not even like bob") << endl;

    return 0;
}