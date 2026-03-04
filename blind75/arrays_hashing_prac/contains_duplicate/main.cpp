#include <iostream>
#include <stdexcept>
#include <unordered_set>

class Solution {
  public:
    bool hasDuplicate(std::vector<int> &nums) {

        const int N = nums.size();
        std::unordered_set<int> s;

        for (int num : nums) {
            if (s.find(num) == s.end())
                s.insert(num);
            else
                return true;
        }

        return false;
    };
};

int main() {
    std::cout << "=== TWO SUM ===\n";

    return 0;
}
