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
    TreeNode* solveDelete(TreeNode* root, unordered_set<int>& store, vector<TreeNode*>& Result){

        if(!root){
            return NULL;
        }

        root->left = solveDelete(root->left, store, Result);
        root->right = solveDelete(root->right, store, Result);

        if(store.find(root->val) != store.end()){

            if(root->left){
                Result.push_back(root->left);
            }

            if(root->right){
                Result.push_back(root->right);
            }
            
            return NULL;
        }
        else{
            return root;
        }



    }    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //LRN Traversal 

        vector<TreeNode*> Result;

        unordered_set<int> store;

        for(int &num : to_delete){
            store.insert(num);
        }

        solveDelete(root, store, Result );

        if(store.find(root->val) == store.end()){
            Result.push_back(root);            
        }

        return Result;


        
    }
};