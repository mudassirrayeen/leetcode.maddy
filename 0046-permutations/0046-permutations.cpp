class Solution {
public:
   void permutation(vector<int> &nums,vector<int> &v,vector<vector<int>> &ans,vector<bool> &used){
    if(v.size()==nums.size()){
        ans.push_back(v);
        return;
    }
     for(int i=0;i<nums.size();i++){
          if (used[i]) continue;

            used[i]=true;
              v.push_back(nums[i]);
            permutation(nums,v,ans,used);
        
             v.pop_back();
            used[i]=false;
        
     }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> used(nums.size(),false);
        permutation(nums,v,ans,used);
        return ans;
    }
};