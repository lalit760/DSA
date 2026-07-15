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
    // iop - in order predecessor
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    // ios - in order successor
    TreeNode* ios(TreeNode* root){
        TreeNode* suc = root->right;
        while(suc->left != NULL){
            suc = suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val == key){
            //case-1 NO child (leaf Node)
            if(root->left==NULL && root->right==NULL)return NULL;

            //case-2 one child
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL)return root->left;
                else return root->right;
            }

            //case-3 have two child
            // then replace the node value its predecessor or succcessor & delete that pred/succ
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* pred = iop(root);
                root->val = pred->val; // 1st replace the value at root with value of pred
                root->left = deleteNode(root->left,pred->val); //modify the LST by deleting that value
            }
            
        }
        else if(root->val > key){//go left
            root->left = deleteNode(root->left,key);
        }
        else{//go right
            root->right = deleteNode(root->right,key);
        }
        
        
        return root;
        
    }
};