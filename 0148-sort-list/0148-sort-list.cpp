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
 ListNode* findmidd(ListNode* &head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
ListNode* mergeLL(ListNode* &Left, ListNode* &Right){
        if(Left==0)return Right;
        if(Right==0)return Left;
        ListNode* ans= new ListNode(-1);
        ListNode*mptr=ans;
          while(Left && Right){
        if(Left->val<=Right->val){
            mptr->next=Left;
            mptr=Left;
            Left=Left->next;
        }
        else{
            mptr->next=Right;
            mptr=Right;
            Right=Right->next;
        }
          }
        if(Left){
             mptr->next=Left;
            mptr=Left;
            Left=Left->next;
        }
        if(Right){
             mptr->next=Right;
            mptr=Right;
            Right=Right->next;
        }
        return ans->next;
    }

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
        return head;
    }
        ListNode* mid = findmidd(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode*Left =sortList(left);
        ListNode* Right =sortList(right);

        ListNode* merge= mergeLL(Left,Right);

           return merge;
    }
 
};