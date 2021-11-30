#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sell1 = 0, sell2 = 0;
        int buy1 = -prices[0], buy2 = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            buy1 = max(-prices[i], buy1);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
};

int main(int argc, char **args)
{
    Solution sol = Solution();
    vector<int> prices = {3,
                          3,
                          5,
                          0,
                          0,
                          3,
                          1,
                          4};
    cout << sol.maxProfit(prices) << endl;
    prices = {1, 2, 3, 4, 5};
    cout << sol.maxProfit(prices) << endl;
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;
    prices = {1};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}