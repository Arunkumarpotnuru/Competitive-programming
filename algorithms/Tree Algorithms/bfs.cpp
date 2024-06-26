// bfs or level order traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            vector<int>level;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr= q.front(); q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
            
        }

        return ans;
    }
};
