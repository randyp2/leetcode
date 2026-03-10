#include <cctype>
#include <cwctype>
#include <iostream>
#include <stdexcept>

class Solution {
  public:
    /**
     * First approach:
     *  - Simply use two pointers -> 1 at start and 1 at end
     *  - Compare the two
     *  - Increment/Decrement respectively
     *  - If white space then skip over
     *
     *  RUNTIME: O(n)
     */
    bool isPalindrome(std::string s) {

        const int N = s.length();
        int left_pointer = 0;
        int right_pointer = N - 1;

        while (left_pointer < right_pointer) {
            // Move pointers until non space occurs
            while (left_pointer < right_pointer &&
                   !(std::isalnum(s[left_pointer])))
                ++left_pointer;
            while (left_pointer < right_pointer &&
                   !(std::isalnum(s[right_pointer])))
                --right_pointer;

            // Check if equal
            if (std::tolower(s[left_pointer]) != std::tolower(s[right_pointer]))
                return false;

            ++left_pointer;
            --right_pointer;
        }

        return true;

        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- Valid Palindrome ---\n";
    Solution sol;

    std::string input1 = "racecar";
    std::string input2 = "rac      ecar";

    std::cout << "Test case 1: " << sol.isPalindrome(input1) << "\n";
    std::cout << "Test case 2: " << sol.isPalindrome(input2) << "\n";
    return 0;
}
