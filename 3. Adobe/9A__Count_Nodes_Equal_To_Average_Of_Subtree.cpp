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
    int ans = 0;
    
    pair<int,int> dfs( TreeNode* root )
    {
        if ( root == NULL )
            return {0,0} ;

        auto x = dfs(root->left) ;
        auto y = dfs(root->right);

        int avg = x.first + y.first + root->val;
        int nodes = x.second + y.second + 1 ;
        if ( avg / nodes == root->val ) ans ++ ;

        return {avg,nodes} ;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int avg = 0, n = 0 ;
        dfs(root) ;
        return ans ;
    }
};
