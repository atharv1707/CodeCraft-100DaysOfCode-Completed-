/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool check(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }

        if(!left || !right){
            return false;
        }

        return ((left->val == right->val) && (check(left->left, right->right)) && check(left->right, right->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }

        return check(root->left, root->right);
        
    }
};

// Approach 2 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        std::queue<TreeNode*> queue;

        queue.push(root->left);
        queue.push(root->right);

        while (!queue.empty()) {
           
            TreeNode* leftNode = queue.front();
            queue.pop();
            TreeNode* rightNode = queue.front();
            queue.pop();

            if (!leftNode && !rightNode) {
                continue;
            }

            if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) {
                return false;
            }

            queue.push(leftNode->left);
            queue.push(rightNode->right);
            queue.push(leftNode->right);
            queue.push(rightNode->left);
        }

        return true;
    }
};