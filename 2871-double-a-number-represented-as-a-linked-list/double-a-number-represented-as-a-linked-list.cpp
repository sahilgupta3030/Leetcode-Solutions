// Approach-2 (Using Recursion)
class Solution {
public:    
    int recursive_double(ListNode* head) {
        if(head == NULL)
            return 0;      

        int carry  = recursive_double(head->next);
        int newVal = (head->val)*2 + carry;
        head->val = newVal % 10;    
        return newVal / 10;        
    }
    
    ListNode* doubleIt(ListNode* head) {        
        int lastCarry = recursive_double(head);
        
        if(lastCarry > 0) {
            ListNode* newHead = new ListNode(lastCarry);
            newHead->next = head;
            return newHead;
        }        
        return head;        
    }
};



// // Approach-1 (Using Reverse of LinkedList)
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) {
//             return head;
//         }        
//         ListNode* last = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;        
//         return last;
//     }
    
//     ListNode* doubleIt(ListNode* head) {
//         head = reverseList(head);
        
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         int carry = 0;        
//         while(curr != NULL) {            
//             int newValue = curr->val * 2 + carry;
//             curr->val = newValue%10;
            
//             if(newValue >= 10) {
//                 carry = 1;
//             } else {
//                 carry = 0;
//             }            
//             prev = curr;
//             curr = curr->next;            
//         }        
//         if(carry != 0) {
//             ListNode* newHead = new ListNode(carry);
//             prev->next = newHead;
//         }
//         return reverseList(head);
//     }
// };