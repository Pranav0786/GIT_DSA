// LeetCode 113

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
    void solve( TreeNode* root , int targetSum , vector<vector<int>>&ans , 
                vector<int> &path , int &sum )
    {
        // base 
        if( root == NULL )
            return ;

        // leaf node
        if( root->left == NULL && root->right == NULL )
        {
            path.push_back( root->val ) ;
            sum += root->val ;

            if( sum == targetSum )
                ans.push_back(path) ;

            path.pop_back() ;
            sum -= root->val ;
            return ;
        }

        path.push_back( root->val ) ;
        sum += root->val ;
        
        solve( root->left , targetSum , ans, path , sum ) ;
        solve( root->right , targetSum , ans , path , sum ) ;

        path.pop_back() ;
        sum -= root->val ;
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans ;
        vector<int> temp ;
        int sum = 0 ;
        solve( root , targetSum , ans , temp , sum ) ;
        return ans ;
    }
};

int main()
{
    return 0;
}