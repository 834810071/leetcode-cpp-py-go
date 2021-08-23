#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int len = expression.size();
        if (len == 0) return {};
        bool hasflag = false;
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                hasflag = true;
                vector<int> left = diffWaysToCompute(string(expression, 0, i));
                vector<int> right = diffWaysToCompute(string(expression, i+1, len));
                for (int l : left) {
                    for (int r : right) {
                        if (expression[i] == '+')
                            res.push_back(l + r);
                        if (expression[i] == '-')
                            res.push_back(l - r);
                        if (expression[i] == '*')
                            res.push_back(l * r);
                    }
                }
            }
        }
        if (!hasflag) return {stoi(expression)};
        return res;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<int> res1 = sol.diffWaysToCompute("2-1-1");
    for (auto a : res1) {
        cout << a << ", ";
    } 
    cout << endl;

    vector<int> res2 = sol.diffWaysToCompute("2*3-4*5");
    for (auto a : res2) {
        cout << a << ", ";
    } 
    cout << endl;

    return 0;
}