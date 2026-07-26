#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        int carry_value = 0;
        ListNode *ans = new ListNode{0}; // ans->next will hold our real answer
        ListNode *temp = ans;
        while (l1 || l2 ||
               carry_value) { // Continue if l1 or l2 or carry has a value

            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;

            int sum = carry_value + l1_val + l2_val;

            int tens_unit = sum / 10;
            int ones_unit = sum % 10;

            temp->next = new ListNode{ones_unit};
            carry_value = tens_unit;

            temp = temp->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        ListNode *dummy = ans;
        ans = ans->next;
        delete dummy;

        return ans;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
