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
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the pointer direction
            prev = current;       // Move prev pointer forward
            current = next;       // Move current pointer forward
        }

        return prev; // prev now points to the head of the reversed list
    }
};
