class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Start a slow and fast pointer
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        while (slowPtr != nullptr && fastPtr != nullptr && fastPtr->next != nullptr) {
            // Advance both the pointers
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            // If they meet, means we found a loop
            if (slowPtr == fastPtr) {
                return true;
            }
        }

        return false;
    }
};