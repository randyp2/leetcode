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
    ListNode *reverseList(ListNode *head) {

        if (!head || !head->next)
            return head;

        ListNode *prev = nullptr, *curr_node = head, *next = nullptr;

        while (curr_node) {
            next = curr_node->next;
            curr_node->next = prev;
            prev = curr_node;
            curr_node = next;
        }

        return prev;
    }
};

int main() {
    std::cout << "--- REVERSE A LINKED LIST ---\n";
    return 0;
};
