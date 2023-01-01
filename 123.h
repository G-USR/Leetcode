#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.empty())
            return 0;

        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));

        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return dp.back().back();
    }
};