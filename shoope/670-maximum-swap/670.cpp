#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        int maxnum = INT_MIN;
        int maxloc = -1;
        int maxchange = 0;
        int index = 0;
        int res = num;
        while (num) {
            if (maxnum < num%10) {
                maxnum = num % 10;
                maxloc = index;
            } else {
                int change = (maxnum - num%10) * pow(10, index) + (num%10 - maxnum) * pow(10, maxloc);
                maxchange = max(change, maxchange);
            }
            ++index;
            num /= 10;
        }
        return res + maxchange;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    cout << sol.maximumSwap(2736) << endl;
    cout << sol.maximumSwap(9973) << endl;
    cout << sol.maximumSwap(9378) << endl;
    
    return 0;
}