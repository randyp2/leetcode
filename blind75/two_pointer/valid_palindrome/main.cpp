#include <cctype>
#include <iostream>

class Solution {

  public:
    bool isPalindrome(std::string s) {

        const size_t N = s.length();
        if (N == 1)
            return true;

        int l = 0;
        int r = N - 1;
        while (l < r) {
            while (l < r && !(std::isalnum(s[l])))
                ++l;
            while (l < r && !(std::isalnum(s[r])))
                --r;

            // Compare
            if (std::tolower(s[l]) != std::tolower(s[r]))
                return false;

            ++l;
            --r;
        }

        return true;
    }
};

int main() {
    std::cout << "--- VALID PALINDROME ---\n";

    std::string input01 = "racecar";
    std::string input02 = "Was it a car or a cat I saw?";

    Solution sol;

    bool actualOutput01 = sol.isPalindrome(input01);
    bool actualOutput02 = sol.isPalindrome(input02);

    std::cout << "Actual output test case 1: " << actualOutput01 << "\n";
    std::cout << "Actual output test case 2: " << actualOutput02 << "\n";

    return 0;
};
