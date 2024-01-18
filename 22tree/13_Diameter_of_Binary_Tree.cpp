// LeetCode 543

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

    int d = 0 ;
    int height( TreeNode* root )
    {
        if( root == NULL )
            return 0 ;

        int lh = height(root->left) ;
        int rh = height(root->right) ;

        int dd = lh+rh ;

        d = max( dd  , d ) ;
        return max(lh,rh)+1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root) ;
        return d ;
    }
};

int main()
{
    return 0;
}