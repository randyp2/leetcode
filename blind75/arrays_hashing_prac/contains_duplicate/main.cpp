#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class Solution {

  public:
    /**
     *
     * RUNTIMES
     *  - (SORTING OPTION): O(nlogn)
     *  - (UNORDERD SET): O(n)
     *
     * Why on leetcode sorting option runs after?
     *  - Because of the overhead using an unorderd_set
     *  - Sorting uses just a vector that utilizes spatial locality
     *  - unorderd_set involves pointer chasing, rehashing and so on
     */
    bool containsDuplicate(std::vector<int> &nums) {

        const int N = nums.size();
        std::unordered_set<int> s;
        s.reserve(N); // Reserve space to avoid rehashing due to load factor

        for (int num : nums) {
            // Returns pair:
            //  * first -> iterator pionting to inserted number
            //  * second -> boolean: false -> num already exists, true -> num
            //  doesn't exist
            auto [it, inserted] = s.insert(num); // use structured binding

            if (!inserted)
                return true;
        }

        return false;
    }
};

int main() {
    std::cout << "--- CONTAINS DUPLICATE ---\n";
    return 0;
};
