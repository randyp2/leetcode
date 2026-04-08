#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class Solutino {

  public:
    bool hasDuplicate(std::vector<int> &nums) {

        std::unordered_set<int> s;
        for (int num : nums) {
            if (s.find(num) != s.end())
                return true;

            s.insert(num);
        }

        return false;

        throw std::runtime_error("Function not implemented...");
    }
};

int main() {
    std::cout << "--- CONTAINS DUPLICATE ---\n";
    return 0;
}
