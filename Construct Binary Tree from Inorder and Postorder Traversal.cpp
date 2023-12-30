#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int PStart, int Pend) {
        if (inStart > inEnd) {
            return nullptr; // Base case: empty subtree
        }

        TreeNode* root = new TreeNode(postorder[Pend]);

        int i = inStart;

        for (; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }

        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root->left = solve(inorder, postorder, inStart, i - 1, PStart, PStart + leftSize - 1);
        root->right = solve(inorder, postorder, i + 1, inEnd, Pend - rightSize, Pend - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        int inStart = 0;
        int inEnd = n - 1;

        int PStart = 0;
        int PEnd = n - 1;

        return solve(inorder, postorder, inStart, inEnd, PStart, PEnd);
    }
};
