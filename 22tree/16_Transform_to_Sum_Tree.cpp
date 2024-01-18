// gfg que

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node( int data )
    {
        this->data = data ;
        left = NULL ;
        right = NULL ;
    }
};

int sum( Node* root )
    {
        if( root == NULL )
            return 0 ;
            
        if( !root->left && !root->right )
        {
            int temp = root->data ;
            root->data = 0 ;
            return temp ;
        }
        
        int lsum = sum( root->left ) ;
        int rsum = sum( root->right ) ;
        
        int temp = root->data ;
        root->data = lsum +rsum ;
        
        return root->data + temp ;
        
    }
    void toSumTree(Node *node)
    {
        sum( node ) ;
    }

int main()
{
    return 0;
}