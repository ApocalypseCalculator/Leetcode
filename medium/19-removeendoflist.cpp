// 19. Remove Nth Node From End of List

// strat: find length, delete node at length - n

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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int total = 0;
            ListNode* tmpiter = head;
            while(true) {
                total++;
                if(tmpiter->next == nullptr) {
                    break;
                }
                tmpiter = tmpiter->next;
            }
            int toremove = total - n;
            if(toremove == 0) {
                return head->next;
            }
            
            ListNode* beforeremove = head;
            for(int i = 1; i < toremove; i++) {
                beforeremove = beforeremove->next;
            }
            
            beforeremove->next = beforeremove->next->next;
            // free removed head somewhere here
            return head;
        }
};