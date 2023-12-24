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

    int countNodes(TreeNode* root){
        if(!root){
            return  0;
        }

        return 1+countNodes(root->left) + countNodes(root->right);
    }
    bool DFS(TreeNode* root, int i, int totalNodes){

        if(!root){
            return true;
        }
        if(i > totalNodes){
            return false;
        }

        return DFS(root->left, 2*i, totalNodes) && DFS(root->right, 2*i +1, totalNodes);

    }

    bool isCompleteTree(TreeNode* root) {

        int totalNodes = countNodes(root);


        return DFS(root, 1, totalNodes);
        
    }
};