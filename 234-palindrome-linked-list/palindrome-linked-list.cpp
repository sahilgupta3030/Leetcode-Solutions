class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the middle node of the list
        ListNode* mid = middle(head);
        // Reverse the second half of the list starting from the middle node
        ListNode* last = reverse(mid->next);
        // Pointer to traverse the first half of the list
        ListNode* curr = head;

        // Compare corresponding nodes of first and reversed second half
        while (last != nullptr) {
            if (last->val != curr->val) {
                return false; 
            }
            last = last->next; 
            curr = curr->next; 
        }
        return true; 
    }

    // Function to find the middle node of the list
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // to track the node before slow

        // Move the fast pointer two steps ahead and the slow pointer one step ahead
        // When the fast pointer reaches the end, the slow pointer will be at the middle node
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // If the list has odd number of nodes, move slow one step ahead
        if (fast != nullptr) {
            slow = slow->next;
        }
        return prev; // this is middle node
    }

    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // Return the new head of the reversed list i.e. last node of linked list
    }
};
