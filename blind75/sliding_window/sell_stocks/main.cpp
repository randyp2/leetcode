#include <iostream>
#include <vector>

class Solution {

  public:
    int maxProfit(std::vector<int> &prices) {
        const std::size_t N = prices.size();
        if (N == 1)
            return 0;

        int max_profit = -1;
        int l = 0;

        for (int r = 1; r < N; ++r) {
            int curr_profit = prices[r] - prices[l];
            if (curr_profit < 0)
                l = r;

            max_profit = std::max(max_profit, curr_profit);
        }

        return max_profit < 0 ? 0 : max_profit;
    }
};

int main() {
    std::cout << "--- MAX PROFIT ---\n";
    return 0;
};
