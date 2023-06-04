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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        vector<int> answer, right;
        answer = inorderTraversal(root->left);

        answer.push_back(root->val);

        right = inorderTraversal(root->right);
        for(int i = 0; i < right.size(); i++) {
            answer.push_back(right[i]);
        }
        return answer;
    }
};