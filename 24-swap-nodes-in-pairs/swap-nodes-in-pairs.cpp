class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) // Base case: if head or head->next is nullptr
      return head;

    ListNode* newHead = head->next; // New head after swapping
    head->next = swapPairs(head->next->next); // Recur for remaining list
    newHead->next = head; // Swap current node with its next
    return newHead;
  }
};
