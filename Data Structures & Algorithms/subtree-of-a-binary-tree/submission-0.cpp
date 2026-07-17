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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if(!a || !b) {
            return a == b;
        }
        bool isSameValue = a->val == b->val;
        isSameValue &= isSameTree(a->left, b->left);
        isSameValue &= isSameTree(a->right, b->right);
        return isSameValue;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root, subRoot)) {
            return true;
        }

        bool isSubTree = false;
        if(!isSubTree && root->left) {
            isSubTree = isSubtree(root->left, subRoot);
        }
        if(!isSubTree && root->right) {
            isSubTree = isSubtree(root->right, subRoot);
        }
        return isSubTree;
    }
};
