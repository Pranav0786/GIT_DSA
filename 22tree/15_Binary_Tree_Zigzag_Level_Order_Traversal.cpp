// LeetCode 103

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if( root == NULL )
            return ans ;

        bool L_R = true ;
        queue<TreeNode*> q ;
        q.push(root) ;

        while( !q.empty() ) 
        {
            int size = q.size() ;
            vector<int> temp( size ) ;

            for( int i = 0 ; i < size ; i++ )
            {
                TreeNode* front = q.front() ;
                q.pop() ;
                int index = L_R ? i : size-i-1 ;
                temp[index] = front->val ;
                
                if( front->left )
                    q.push(front->left) ;
                if( front->right )
                    q.push( front->right ) ;
            }

            L_R = !L_R ;
            ans.push_back(temp) ;

        }
        
        return ans ;
    }

};

int main()
{
    return 0;
}