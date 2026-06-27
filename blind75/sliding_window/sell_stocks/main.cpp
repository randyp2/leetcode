#include <algorithm>
#include <iostream>
#include <vector>

class Solution {

  public:
    int maxProfit(std::vector<int> &prices) {
        const std::size_t N = prices.size();
        if (N == 1)
            return 0;

        int l = 0;
        int r = 1;
        int max_profit = 0;
        while (r < N) {
            int curr_profit = prices[r] - prices[l];
            max_profit = std::max(curr_profit, max_profit);
            if (curr_profit < 0)
                l = r;
            ++r;
        }

        return max_profit;
    }
};

int main() {
    std::cout << "--- MAX PROFIT ---\n";
    return 0;
};
