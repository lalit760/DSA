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
    int levels(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+ max(levels(root->left),levels(root->right));
    }

    void helper(TreeNode* root, int &maxDia){ //pass by refrence,reason: is that you want all recursive calls to update the same variable.
        if(root==NULL)return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia,dia); //updating the diameter with max length
        helper(root->left, maxDia); //calling recurssion
        helper(root->right, maxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root,maxDia);
        return maxDia;
    }
};