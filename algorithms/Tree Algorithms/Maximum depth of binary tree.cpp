class Solution {
public:
    int maxd(TreeNode* node)
    {
        if(node==NULL) return 0;
        int l = maxd(node->left);
        int r = maxd(node->right);
        
        return 1+ max(l,r);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return maxd(root);
    }
};
