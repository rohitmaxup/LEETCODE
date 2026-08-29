
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
    vector<int> store;

    void inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left);
        store.push_back(root->val);
        inorder(root->right);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        
        inorder(root);

        unordered_set<int> s;

        for(int i = 0; i < store.size(); i++)
        {
            int required = k - store[i];

            if(s.find(required) != s.end())
            {
                return true;
            }

           
            s.insert(store[i]);
        }

        return false;
    }
};
