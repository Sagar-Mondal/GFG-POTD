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
    vector<TreeNode*> nodes;
    void findInorder(TreeNode* curr){
        if(curr == NULL){
            return;
        }
        findInorder(curr->left);
        nodes.push_back(curr);
        findInorder(curr->right);
    }
    TreeNode* buildTree(int left, int right){
        if(left > right){
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* newRoot = nodes[mid];
        newRoot->left = buildTree(left, mid -1 );
        newRoot->right = buildTree(mid + 1, right);
        return newRoot;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        findInorder(root);
        return buildTree(0, nodes.size() - 1);
    }
};