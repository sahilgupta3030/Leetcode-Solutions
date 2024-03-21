// time O(N) , aux space O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> data;

        for (ListNode* curr = head; curr != NULL; curr = curr->next) {
            data.push_back(curr->val);
        }

        for (ListNode* curr = head; curr != NULL; curr = curr->next) {
            curr->val = data.back();
            data.pop_back();
        }
        return head;
    }
};
