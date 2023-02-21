/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        int cnt = 2;
        while(headA != headB and cnt) {
            headA = headA->next;
            headB = headB->next;
            if(headA == NULL) {
                headA = b;
                cnt--;
            }
            if(headB == NULL) {
                headB = a;
            }
        }
        if(headA == headB) return headA;
        return NULL;
    }
};