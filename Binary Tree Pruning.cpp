class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {

        if (!root) {
            return NULL;
        }

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // Prune if the current node is a leaf and has a value of 0
        if (root->val == 0 && !root->left && !root->right) {
            return NULL;
        }

        return root;
    }
};