// Last updated: 7/18/2026, 2:05:18 PM

class Solution {
    void func(TreeNode* node, int &k , int &ans , int &count){
        if(node==NULL || count>k) return ;
        
        func(node->left , k,ans,count);
        count++;
        if(count==k) ans = node->val;
        func(node->right,k,ans,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int smallest = -1;
        int count = 0 ;
        func(root,k,smallest,count);
        return smallest;
    }
};