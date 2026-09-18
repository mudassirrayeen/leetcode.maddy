class Solution {
public:
   void nextPermutation(vector<int>& nums) {

    int i = nums.size() - 1;

    // Find pivot
    while(i > 0 && nums[i] <= nums[i-1]) {
        i--;
    }

    // If pivot exists
    if(i > 0) {

        int j = nums.size() - 1;

        // Find just greater element
        while(j >= i) {
            if(nums[j] > nums[i-1]) {
                swap(nums[i-1], nums[j]);
                break;
            }
            j--;
        }
    }

    // Reverse remaining part
    reverse(nums.begin() + i, nums.end());
}
};