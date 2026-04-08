#include <iostream>
#include <set>
#include <stack>
#include <vector>

class Solution {
  public:
    /**
     * Use stack
     * - everytime we come across an operator pop off the last two values
     */
    int evalRPN(std::vector<std::string> &tokens) {
        const int N = tokens.size();

        std::stack<int> s;

        std::set<std::string> s_set = {"+", "-", "*", "/"};

        for (int i = 0; i < N; ++i) {

            std::string atomic = tokens[i];

            // If it's an expression
            //  Pop off the last two expressions brefore evaluate and push
            if (s_set.find(atomic) != s_set.end()) {
                int first_num = s.top();
                s.pop();

                int second_num = s.top();
                s.pop();

                int new_val = -1;

                std::cout << "First number: " << first_num << "\n";
                std::cout << "Second number: " << second_num << "\n";

                // Evaluate given the operator
                if (atomic == "+") {
                    new_val = second_num + first_num;
                } else if (atomic == "-") {
                    new_val = second_num - first_num;
                } else if (atomic == "*") {
                    new_val = second_num * first_num;
                } else if (atomic == "/") {
                    new_val = second_num / first_num;
                }

                // Push the new value onto the stack
                s.push(new_val);
            } else {
                s.push(std::stoi(atomic));
            }
        }

        return s.top();
    }

    /*
     * Evalue it in the vector
     * Use if statements to save memory?
     */
    int evalRPN2(std::vector<std::string> &tokens) {
        const int N = tokens.size();

        std::stack<int> s;

        for (int i = 0; i < N; ++i) {

            std::string atomic = tokens[i];

            // If it's an expression
            //  Pop off the last two expressions brefore evaluate and push
            if (atomic == "+" || atomic == "*" || atomic == "/" ||
                atomic == "-") {

                int second_num = std::stoi(tokens[i - 1]);
                int first_num = std::stoi(tokens[i - 2]);

                int new_val = -1;

                std::cout << "First number: " << first_num << "\n";
                std::cout << "Second number: " << second_num << "\n";

                // Evaluate given the operator
                if (atomic == "+") {
                    new_val = second_num + first_num;
                } else if (atomic == "-") {
                    new_val = second_num - first_num;
                } else if (atomic == "*") {
                    new_val = second_num * first_num;
                } else if (atomic == "/") {
                    new_val = second_num / first_num;
                }

                tokens[i] = new_val;
            }
        }
        return std::stoi(tokens[N - 1]);
    }
};
int main() {
    std::cout << "Reverse Polish Notation" << std::endl;
    std::vector<std::string> input1 = {"4", "13", "5", "/", "+"};

    Solution sol;
    std::cout << "Output1: " << sol.evalRPN(input1) << "\n";

    return 0;
}
