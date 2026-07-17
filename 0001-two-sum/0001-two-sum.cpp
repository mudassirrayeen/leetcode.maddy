class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++) {

            int element1 = nums[i];

            for(int j = i + 1; j < nums.size(); j++) {

                int element2 = nums[j];

                if(element1 + element2 == target) {

                    return {i, j};
                }
            }
        }

        return {};
    }
};