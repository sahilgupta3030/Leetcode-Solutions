// // time O(N) , aux space O(N)
// // reverse with a vector
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         vector<int> data;

//         for (ListNode* curr = head; curr != NULL; curr = curr->next) {
//             data.push_back(curr->val);
//         }

//         for (ListNode* curr = head; curr != NULL; curr = curr->next) {
//             curr->val = data.back();
//             data.pop_back();
//         }
//         return head;
//     }
// };

// three pointer approach
// iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};