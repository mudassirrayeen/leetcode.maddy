




      void insertatBottom(stack<int> &st,int target){
          if(st.empty()){
              st.push(target);
              return;
          }
          
          int topelement=st.top();
          st.pop();
          
          insertatBottom(st,target);
          
          st.push(topelement);
          
      }
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int target=st.top();
        st.pop();
        
        reverseStack(st);
        
        insertatBottom(st,target);
    }
};