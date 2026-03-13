#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class Solution {

  public:
    bool containsDuplicate(std::vector<int> &nums) {

        const int N = nums.size();

        std::unordered_set<int> s;

        for (int num : nums) {
            if (s.find(num) != s.end())
                return true;
            s.insert(num);
        }

        return false;

        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- CONTAINS DUPLICATE ---\n";
    return 0;
}
