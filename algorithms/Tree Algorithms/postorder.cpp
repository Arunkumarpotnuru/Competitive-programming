//recursive code
class Solution {
public:
    void fun(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL) return;
        fun(root->left,ans);
        fun(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        fun(root,ans);
        return ans;
    }
};

//iterative code using two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;

        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* temp = st1.top(); st1.pop();
            st2.push(temp);
            if(temp->left) st1.push(temp->left);
            if(temp->right) st1.push(temp->right);
        }
        while(!st2.empty())
        {
            TreeNode* root = st2.top(); st2.pop();
            ans.push_back(root->val);
        }
        return ans;
    }
};
