class Solution {
public:
    int heightAndDiameter(TreeNode* root, int& diameter) {
        if (!root) return 0;

        int leftHeight = heightAndDiameter(root->left, diameter);
        int rightHeight = heightAndDiameter(root->right, diameter);

        // Calculate the diameter for the current node
        diameter = std::max(diameter, leftHeight + rightHeight);

        return std::max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diameter = 0;
        heightAndDiameter(root, diameter);

        return diameter;
    }
};