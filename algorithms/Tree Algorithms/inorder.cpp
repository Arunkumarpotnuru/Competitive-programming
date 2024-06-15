// recursive code
// TC = O(n) SC = O(n) or height of the tree
class Solution {
public:
    void fun(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL) return;
        fun(root->left,ans);
        ans.push_back(root->val);
        fun(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        fun(root,ans);
        return ans;
    }
};

// iterative code


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;

        stack<TreeNode*>st;
        TreeNode* curr  = root;
        while(true)
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if(st.empty()) break;
                TreeNode* temp = st.top(); st.pop();
                ans.push_back(temp->val);
                curr = temp->right;
            }
        }
        return ans;
    }
};
