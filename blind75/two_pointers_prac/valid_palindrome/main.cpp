#include <cctype>
#include <cwctype>
#include <iostream>
#include <stdexcept>

class Solution {
  public:
    bool isPalindrome(std::string s) {

        const int N = s.length();
        int l = 0;
        int r = N - 1;

        while (l < r) {
            while (l < r && !std::isalnum(s[l]))
                ++l;
            while (l < r && !std::isalnum(s[r]))
                --r;

            if (std::towlower(s[l]) != std::tolower(s[r]))
                return false;

            ++l;
            --r;
        }

        return true;

        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- VALID PALINDROM ---\n";
    return 0;
}
