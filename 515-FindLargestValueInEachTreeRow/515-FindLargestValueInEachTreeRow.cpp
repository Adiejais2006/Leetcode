// Last updated: 7/18/2026, 2:04:12 PM

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int size = q.size();
            int maxu = INT_MIN;
            while(size--){  
                auto node = q.front();
                q.pop();
                maxu = max (maxu , node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxu);
        }
        return ans ;
    }
};