/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // three option
        
        
        function<int(TreeNode*)> DFS;
        int ans = INT_MIN;
        DFS = [&](TreeNode *root){
            if(root == NULL) return 0;
            
            int left = DFS(root->left);
            int right = DFS(root->right);
            
            int mx = max({root->val, root->val + left, root->val + right});
            ans = max({ans, mx, root->val + right + left});
            // cout << root->val << " " << mx << endl;
            return mx;
        };
        
        DFS(root);
        
        return ans;
    }
};