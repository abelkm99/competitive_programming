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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        function<void(TreeNode*, int, int)> dfs;
        dfs = [&](TreeNode* root,int col, int row) {
            if(root == nullptr) {
                return;
            }
            mp[col].push_back({row, root->val});
            dfs(root->left, col-1, row+1);
            dfs(root->right, col+1, row+1);
        };
        dfs(root, 0,0);
        vector<vector<int>> ans;
        for (auto &[x, y]: mp) {
            sort(y.begin(), y.end(), [&](auto a, auto b) {
                if(a.first == b.first) {
                    return a.second < b.second;
                }
                return a.first < b.first;
            });
            vector<int> temp;
            for (auto v: y) {
                temp.push_back(v.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};