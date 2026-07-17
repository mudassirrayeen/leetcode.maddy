/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
// int getlength(Node* &head){
//       int len=0;
//       Node*temp=head;
//       while(temp!=NULL){
//           temp=temp->next;
//           len++;
//       }
//       return len;
// }
class Solution {
  public:
  
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL){
            cout<<"LL is empty";
            return head;
        }
        // int l=getlength(head);
        // if(l<k){
        //     // cout<<"enter a valid value of k"<<endl;
        //     return head;
        // }
        //l>k
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=NULL;
        int count=0;
         while(curr!=NULL && count<k){
             forward=curr->next;
             curr->next=prev;
             prev=curr;
             curr=forward;
             count++;
         }
         if(forward!=NULL){
         head->next=reverseKGroup(forward,k);
         }
            return prev;
}
};