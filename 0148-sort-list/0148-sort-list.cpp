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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
       ListNode* slow=head;
       ListNode* fast=head->next;
       while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* second=slow->next;
       slow->next=NULL;
         head   = sortList(head);
    second = sortList(second);
       ListNode* ans= new ListNode(-1);
       ListNode* mptr=ans;
       while (head && second){
         if(head->val <= second->val){
            mptr->next=head;
            mptr=head;
            head=head->next;
         }
         else{
            mptr->next=second;
            mptr=second;
            second=second->next;
         }
       }
       if(head){
         mptr->next=head;
            mptr=head;
            head=head->next;
       }
       if(second){
          mptr->next=second;
            mptr=second;
            second=second->next;
       }
       return ans->next;
    }
};