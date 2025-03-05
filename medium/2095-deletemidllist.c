// 2095. Delete the Middle Node of a Linked List

// I did this one during an interview
// strat: find middle in first pass, delete in second pass

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findIdx(struct ListNode* head, int idx) {
    for(int i = 0; i < idx; i++) {
        head = head->next;
    }
    return head;
}

int length(struct ListNode* head) {
    int curlength = 0;
    while(head != NULL) {
        curlength++;
        head = head->next;
    }
    return curlength;
}

struct ListNode* deleteMiddle(struct ListNode* head) {
    int lstlength = length(head);
    if(lstlength == 1) {
        free(head);
        return NULL;
    } else if (lstlength == 2) {
        free(head->next);
        head->next = NULL;
        return head;
    }
    else {
        struct ListNode* curmid = findIdx(head, lstlength/2 - 1);
        struct ListNode* tmp = curmid->next;
        curmid->next = curmid->next->next;
        free(tmp);
        return head;
    }
}