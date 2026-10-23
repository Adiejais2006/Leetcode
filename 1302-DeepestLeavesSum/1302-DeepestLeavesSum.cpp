// Last updated: 10/23/2026, 12:34:06 PM
1class Solution {
2public:
3    int deepestLeavesSum(TreeNode* root) {
4        if(root == NULL) return 0;
5        queue<TreeNode*> q;
6        q.push(root);int sum = 0;
7        while(!q.empty()){
8            int n = q.size();
9            sum = 0;
10            for(int i = 0; i < n; i++){
11                TreeNode* frontNode = q.front();
12                q.pop();
13                sum += frontNode -> val;
14                if(frontNode -> left != NULL){
15                    q.push(frontNode -> left);
16                }
17                if(frontNode -> right != NULL){
18                    q.push(frontNode -> right);
19                }
20            }
21        }
22        return sum;
23    }
24};