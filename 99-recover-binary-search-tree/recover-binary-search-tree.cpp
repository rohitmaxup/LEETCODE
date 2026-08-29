
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

    vector<int> traversal;

    void recoverTree(TreeNode* root) 
    {
        
        inorder(root);

        
        sort(traversal.begin(), traversal.end());

        
        int i = 0;
        final(root, i);
    }

    void final(TreeNode* root, int &i)
    {
        if(root == NULL)
        {
            return;
        }

        final(root->left, i);

        if(traversal[i] != root->val)
        {
            root->val = traversal[i];
        }

        i++;

        final(root->right, i);
    }

    void inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left);

        traversal.push_back(root->val);

        inorder(root->right);
    }
};
