class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            bool used[256]={false};
        
        for(int j=i; j<n;j++){
            if(used[s[j]]){
                break;
            }
            used[s[j]]=true;
            len=max(len,j-i+1);
        }
           
            
        }
        return len;
        
    }
};