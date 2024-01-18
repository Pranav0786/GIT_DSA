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

    bool k_ancester( TreeNode* root , TreeNode* p ,int &k )
    {
        // base
        if( root == NULL )
            return false ;

        if( root->val == p->val )
            return true ;

        bool leftans = k_ancester( root->left , p , k ) ;
        bool rightans = k_ancester( root->right , p , k ) ; 

        if( leftans || rightans )
            k-- ;

        if( k == 0 )
        {
            cout << root->val << endl ;
            k = -1 ;
        }

        return leftans || rightans ;
        
    }

};
int main()
{
    return 0;
}