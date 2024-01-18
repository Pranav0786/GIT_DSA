// LeetCode 236

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // base case 
        if( root == NULL )
            return NULL ;

        if( root->val == p->val )
            return p ;
        if( root->val == q->val )
            return q ;

        TreeNode* leftans = lowestCommonAncestor( root->left , p , q ) ;
        TreeNode* rightans = lowestCommonAncestor( root->right , p , q ) ;

        if( leftans == NULL && rightans == NULL )
            return NULL ;

        else if( leftans != NULL && rightans == NULL )
            return leftans ;
        else if( leftans == NULL && rightans != NULL )
            return rightans ;
        else
            return root ;

    }
};

int main()
{
    return 0;
}