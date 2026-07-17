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
private:
    TreeNode* invertNode(TreeNode* node) {
        auto temp = node->left;
        node->left = node->right;
        node->right = temp;
        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        return invertNode(root);
    }
};
