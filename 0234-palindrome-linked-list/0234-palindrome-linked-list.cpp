/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/
ListNode* reverse(ListNode* &head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next=NULL;
    while(curr!= NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        //  code here
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return true;
        }
        if(head->next==NULL){
            return true;
        }
        //LL contained more than one nodes;
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
            // return slow;
            ListNode* reverseLLkaHead=reverse(slow->next);
            slow->next=reverseLLkaHead;
            ListNode* temp1= head;
            ListNode* temp2= reverseLLkaHead;
            while(temp2!=NULL){
                if(temp1->val != temp2->val){
                    // cout<<"not a palindrome"<<endl;
                    return false;
                    
                }
                
                else {
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
            }
            return true;
            
        }
    
};