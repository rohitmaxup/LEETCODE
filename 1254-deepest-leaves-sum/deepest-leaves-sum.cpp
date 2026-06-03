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

    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh,rh);
    }

    void sum(TreeNode* root , int level , int& total)
    {
        if(root == NULL)
        {
            return;
        }
        if(level ==1)
        {
            total += root->val;
        }

        sum(root->right , level-1, total);
        sum(root->left ,level -1 , total);
    }
    int deepestLeavesSum(TreeNode* root) {
        
        int total =0;
        
        int level = height(root);

        sum(root,level,total);

        return total;
    }
};