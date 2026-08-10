class Solution {
public:
    int toSumTree(Node *root) {
        if (root == NULL)
            return 0;

        int oldValue = root->data;

        int leftSum = toSumTree(root->left);
        int rightSum = toSumTree(root->right);

        root->data = leftSum + rightSum;

        return oldValue + leftSum + rightSum;
    }
};
