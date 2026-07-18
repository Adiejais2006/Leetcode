// Last updated: 7/18/2026, 2:05:02 PM

class Codec {
public:

    
    string serialize(TreeNode* root) {
         if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
                ans.append("#,");
            else
                ans.append(to_string(node->val) + ",");
            if (node != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }


    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream ss(data);
        string temp;
        getline(ss, temp, ',');
        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> q;  //
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(ss, temp, ',');
            if (temp != "#") {
                TreeNode* leftnode = new TreeNode(stoi(temp));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(ss, temp, ',');
            if (temp != "#") {
                TreeNode* rightNode = new TreeNode(stoi(temp));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

