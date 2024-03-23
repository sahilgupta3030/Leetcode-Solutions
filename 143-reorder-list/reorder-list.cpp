class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode* mid = middle(head);
        ListNode* last = reverse(mid->next);
        mid->next = nullptr;

        merge(head, last);
    }

    ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}


    ListNode* middle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}



    void merge(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        ListNode* l1_next = l1->next;
        ListNode* l2_next = l2->next;
        l1->next = l2;
        l2->next = l1_next;
        l1 = l1_next;
        l2 = l2_next;
    }
    // If there are remaining nodes in l2, append them to the end of l1
    if (l1) {
        while (l1->next)
            l1 = l1->next;
        l1->next = l2;
    }
}


};
