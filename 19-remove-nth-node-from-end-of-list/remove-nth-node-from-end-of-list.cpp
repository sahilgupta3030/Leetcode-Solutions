class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;  // Slow pointer
        ListNode* fast = head;  // Fast pointer

        // Move fast ptr by n steps
        for (int i = 0; i < n; ++i) {
            fast = fast->next;  // If fast is null, remove first node
            if (fast == nullptr) {
                return head->next;
            }
        }

        // Move slow & fast until fast reaches end
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove nth node from end
        slow->next = slow->next->next;

        return head;
    }
};
