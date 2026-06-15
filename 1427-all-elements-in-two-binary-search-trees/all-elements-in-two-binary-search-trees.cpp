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

    void inorder(TreeNode* root, vector<int>& v)
    {
        if(root)
        {
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }

    void mergeVectors(vector<int> v1 , vector<int> v2 , vector<int> & merged)
    {
        int i = 0 ; 
        int j = 0;
        int k = 0;

        while(i <v1.size() && j<v2.size())
        {
            if(v1[i]<v2[j])
            {
                merged[k] = v1[i];
                k++;
                i++;
            }
            else
            {
                merged[k] = v2[j];
                k++;
                j++;
            }
        }

        while(i<v1.size())
        {
            merged[k] = v1[i];
            k++;
            i++;
        }

        while(j<v2.size())
        {
            merged[k] = v2[j];
            k++;
            j++;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1 , tree2;

        inorder(root1,tree1);
        inorder(root2 , tree2);

        vector<int> mergedvec(tree1.size() + tree2.size());
        mergeVectors(tree1,tree2,mergedvec);

        return mergedvec;
    }
};