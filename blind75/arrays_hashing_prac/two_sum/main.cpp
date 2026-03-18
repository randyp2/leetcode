#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Soluton {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        const int N = nums.size();
        std::unordered_map<int, int> m;

        for (int i = 0; i < N; ++i) {
            int curr_num = nums[i];
            int diff = target - curr_num;

            if (m.find(diff) != m.end())
                return {m[diff], i};
            m[curr_num] = i;
        }
        return {};
    }
};

int main() {
    std::cout << "--- TWO SUM ---\n";
    return 0;
}
