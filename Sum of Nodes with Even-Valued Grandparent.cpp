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
    int result = 0 ;
    int sumEvenGrandparent(TreeNode* root) {

        if(root->right || root->left){

            if(root->val % 2 == 0){

                if(root->left && root->left->left){
                    result += root->left->left->val;
                }
                if(root->left && root->left->right){
                    result += root->left->right->val;
                }
                if(root->right && root->right->left){
                    result += root->right->left->val;
                }
                if(root->right && root->right->right){
                    result += root->right->right->val;
                }
            }
        }

        if(root->left){
            sumEvenGrandparent(root->left);
        }
        if(root->right){
            sumEvenGrandparent(root->right);
        }


        return result;
        
    }
};