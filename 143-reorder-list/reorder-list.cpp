class Solution {
public:
    void reorderList(ListNode* head) {
        // Check if the list has less than 3 nodes
        if (!head || !head->next || !head->next->next)
            return;

        // Find the middle node of the list
        ListNode* mid = middle(head);
        // Reverse the second half of the list
        ListNode* last = reverse(mid->next);
        mid->next = nullptr; // Break the list into two halves

        // Merge the two halves alternatively
        merge(head, last);
    }

    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Find the middle node of a linked list
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two linked lists alternatively
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 && l2) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            l1->next = l2;
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
        // Append remaining nodes from l2 to l1 if any
        if (l1) {
            while (l1->next)
                l1 = l1->next;
            l1->next = l2;
        }
    }
};
