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
 Node* findmidd(Node* &head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
Node* mergeLL(Node* &Left, Node* &Right){
        if(Left==0)return Right;
        if(Right==0)return Left;
        Node* ans= new Node(-1);
        Node*mptr=ans;
          while(Left && Right){
        if(Left->data<=Right->data){
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
    Node* sortLL(Node* head) {
        if(head==NULL || head->next==NULL){
        return head;
    }
        Node* mid = findmidd(head);
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        Node*Left =sortLL(left);
        Node* Right =sortLL(right);

        Node* merge= mergeLL(Left,Right);

           return merge;
    }
 
};