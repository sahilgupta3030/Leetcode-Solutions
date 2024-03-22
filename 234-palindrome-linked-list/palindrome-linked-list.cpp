class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* mid = middle(head);
        ListNode* last = reverse(mid->next);
        ListNode* curr = head;

        while (last != nullptr) {
            if (last->val != curr->val) {
                return false;
            }
            last = last->next;
            curr = curr->next;
        }
        return true;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // to track the node before slow

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        

        return prev;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
