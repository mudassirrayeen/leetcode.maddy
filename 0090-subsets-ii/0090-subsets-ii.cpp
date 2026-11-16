class Solution {
public:
void subset(vector<int> &nums,vector<int> &v,vector<vector<int>> &ans,int i){
    if(i==nums.size()){
        ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    subset(nums,v,ans,i+1);
    v.pop_back();
        int j = i + 1;
while (j < nums.size() && nums[j] == nums[i]) j++;   // same values skip
subset(nums, v, ans, j);      
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<int> v;
        vector<vector<int>> ans;
        subset(nums,v,ans,0);
        return ans;
    }
};