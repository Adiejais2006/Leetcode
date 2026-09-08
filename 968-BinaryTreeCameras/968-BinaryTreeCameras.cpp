// Last updated: 9/8/2026, 11:43:18 PM
1class Solution {
2public:
3    vector<int> dfs(TreeNode* node){
4        if( !node ) return {99999, 99999, 0} ;
5        vector<int> l = dfs(node->left) ;
6        vector<int> r = dfs(node->right) ;
7        int zero = l[2] + r[2] ;
8        int one = 1 + min({l[0], l[1], l[2]}) + min({r[0], r[1], r[2]}) ;
9        int two_A = l[1] + min(r[1], r[2]) ;
10        int two_B = r[1] + min(l[1], l[2]) ;
11        int two_res = min(two_A, two_B) ;
12        return {zero, one, two_res} ;
13    }
14    int minCameraCover(TreeNode* root) {
15        vector<int> ans = dfs(root) ;
16        return min(ans[1], ans[2]) ;
17    }
18};