#include <algorithm>
#include <iostream>
#include <vector>

class Solution {

  public:
    int maxProfit(std::vector<int> &prices) {

        const size_t N = prices.size();

        size_t l = 0;
        size_t r = 1;
        int max_profit = 0;
        while (r < N) {
            // Discard l
            if (prices[l] > prices[r]) {
                l = r++;
            } else {
                // Update max_profit
                int curr_profit = prices[r] - prices[l];
                max_profit = std::max(curr_profit, max_profit);

                // Move r to check for next possible profit
                ++r;
            }
        }

        return max_profit;
    }
};

int main() {
    std::cout << "--- BEST TIME TO BUY AND SELL STOCK --- \n";
    return 0;
}
