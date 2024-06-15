//recursive code
//TC = O(n) 
//sc is height of tree, O(n) when tree is skewed 
class Solution {
public:
    void fun(TreeNode* root, vector<int>&ans)
    {
        if(root == NULL) return;
        ans.push_back(root->val);
        fun(root->left,ans);
        fun(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        fun(root,ans);
        return ans;
    }
};
// iterative code using stack
// TC = O(n) SC = O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp = st.top(); st.pop();
            ans.push_back(temp->val);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return ans;
    }
};
