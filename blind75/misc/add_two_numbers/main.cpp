#include <iostream>
#include <stdexcept>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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

        ListNode *result = new ListNode(0);

        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *res_temp = result;

        int carry = 0;

        // Loop until there exists and a node and carry is not null
        while (temp1 || temp2 || carry) {
            int l1_num = !temp1 ? 0 : temp1->val;
            int l2_num = !temp2 ? 0 : temp2->val;

            // Calculate the sum and carry
            int sum = l1_num + l2_num + carry;
            res_temp->next = new ListNode(sum % 10);
            carry = sum / 10;

            // Traverse thorugh linked lists
            if (temp1)
                temp1 = temp1->next;

            if (temp2)
                temp2 = temp2->next;

            res_temp = res_temp->next;
        }

        return result->next;
    }
};

int main() {
    std::cout << "--- ADD TWO NUMBERS IN LINKED LIST --- \n";
    return 0;
}
