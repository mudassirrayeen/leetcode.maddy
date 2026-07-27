class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};