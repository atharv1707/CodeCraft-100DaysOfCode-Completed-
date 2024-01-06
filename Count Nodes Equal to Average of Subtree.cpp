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
    int sum(TreeNode* root, int &nodeCount){
        if(!root){
            return 0;
        }

        nodeCount++;

        int left = sum(root->left, nodeCount);
        int right = sum(root->right, nodeCount);

        return left + right +root->val;
    }
    void solve(TreeNode* root, int &result){
        if(!root){
            return;
        }

        int nodeCount = 0;
        int Sum = sum(root, nodeCount);

        if(root->val == (Sum)/nodeCount){
            result++;
        }

        solve(root->left, result);
        solve(root->right, result);
    }

    int averageOfSubtree(TreeNode* root) {
        int result = 0 ;

        solve(root, result);

        return result;
        
    }
};