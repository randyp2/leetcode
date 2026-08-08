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
    /*
        1) Split the linked list in half
        2) Reverse the second half of linked list
        3) Merge together

        If list is:
         a) odd: put middle at the end
    */
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *second_head = split(head);
        second_head = rev(second_head);
        head = merge(head, second_head);
    }

    ListNode *split(ListNode *&head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Detatch the two halves from each other
        ListNode *second_head = slow->next;
        slow->next = nullptr;

        return second_head;
    }

    ListNode *rev(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *new_head = rev(head->next);
        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }

    ListNode *merge(ListNode *head, ListNode *second_head) {

        ListNode *dummy = new ListNode{};
        ListNode *temp = dummy;

        while (head && second_head) {
            temp->next = head;
            head = head->next;
            temp = temp->next;

            temp->next = second_head;
            second_head = second_head->next;
            temp = temp->next;
        }

        // Append extra node to end
        if (head)
            temp->next = head;

        return dummy->next;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
