
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {

        if(!root){
            return 0 ;
        }

        int value = root->val;
        if(value >= low && value <= high){
            sum += value;
        }

        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);

        return sum;

    }
};