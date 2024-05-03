class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    // Base case: if head is nullptr or there is only one node
    if (!head || !head->next)
      return head;

    // Save the newHead after swapping
    ListNode* newHead = head->next;

    // Recursively swap pairs of nodes starting from the third node
    head->next = swapPairs(head->next->next);

    // Swap the current node with its next node
    newHead->next = head;

    // Return the new head of the swapped list
    return newHead;
  }
};
