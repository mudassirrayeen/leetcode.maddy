class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int target = 0;

            for(int j = i; j < nums.size(); j++) {
                target += nums[j];

                if(target == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};