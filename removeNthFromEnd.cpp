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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *dummy=new ListNode(-1);
            dummy->next=head;
            ListNode *ptr1=dummy;
            ListNode *ptr2=head;
            while(n>0){
                ptr2=ptr2->next;
                n--;
            }
            while(ptr2!=NULL){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            ptr1->next=ptr1->next->next;
            return dummy->next;
    }
};