#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {

  public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        std::stack<char> s_stack;

        for (char c : s) {
            if (!m.contains(c)) {
                s_stack.push(c);
                continue;
            }

            // Closing bracket w/ no available opening brackets
            if (s_stack.empty())
                return false;

            if (m[c] != s_stack.top()) // Not a matching bracket
                return false;

            s_stack.pop();
        }

        return s_stack.empty();
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
