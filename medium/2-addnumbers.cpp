// 2. Add Two Numbers

// strat: maintain a carry and just iterate and add

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode{0, nullptr};
        int carry = 0;
        ListNode* cur = sum; // maintain ptr to start
        while(true) {
            if(l1 == nullptr && l2 == nullptr && carry == 0) break;
            sum->next = new ListNode{0, nullptr};
            sum = sum->next;

            int l1val = l1 == nullptr ? 0 : l1->val;
            int l2val = l2 == nullptr ? 0 : l2->val;

            sum->val = l1val + l2val + carry;
            carry = 0;
            if(sum->val > 9) {
                sum->val-=10;
                carry = 1;
            }
            
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return cur->next;
    }
};