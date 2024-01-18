// LeetCode 437

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
    int ans = 0 ;
    void solve( TreeNode* root , long long sum )
    {
        if( !root  )
            return ;

        if( sum == root->val )
            ++ans ;

        solve( root->left , sum - root->val ) ;     
        solve( root->right , sum - root->val ) ;     
    }

    int pathSum(TreeNode* root, long long target) {

        if( root )
            solve( root , target ) ;
            
        if( root->left )
            solve( root->left , target ) ;

        if( root->right )
            solve( root->right , target ) ;

        return ans ;
    }
};

int main()
{
    return 0;
}