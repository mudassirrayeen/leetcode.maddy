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
Node* reverse(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
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
    bool isPalindrome(Node *head) {
        //  code here
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return true;
        }
        if(head->next==NULL){
            return true;
        }
        //LL contained more than one nodes;
        Node* slow= head;
        Node* fast= head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
            // return slow;
            Node* reverseLLkaHead=reverse(slow->next);
            slow->next=reverseLLkaHead;
            Node* temp1= head;
            Node* temp2= reverseLLkaHead;
            while(temp2!=NULL){
                if(temp1->data != temp2->data){
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