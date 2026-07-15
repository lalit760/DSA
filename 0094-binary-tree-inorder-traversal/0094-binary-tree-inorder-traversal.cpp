/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) { // 1- get to pred to its possible value
                TreeNode* pred = curr->left;
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }
                if (pred->right ==
                    NULL) { // 2- after reaching the possible value of pred lik
                            // it temporarily to curr & move curr left
                    pred->right = curr;
                    curr = curr->left;
                } 
                else { // pred->right == curr : if pred found already linked
                         // then unlink and to the work
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            } 
            else { // curr->left == NULL then directly push the value to
                     // vector and move rigght
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};