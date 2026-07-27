class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        if(mp.find(root) != mp.end())return mp[root];
        
        return mp[root] = 1+ max(levels(root->left),levels(root->right));
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