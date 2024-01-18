#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node( int data )
    {
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

void LevelOrderTravelsal( Node* root )
{
    queue<Node*> q ;
    q.push( root ) ;
    q.push(NULL) ;

    while( !q.empty() ) 
    {
        Node* temp = q.front() ;
        q.pop() ;

        if( temp == NULL )
        {
            cout << endl ;
            if( !q.empty() ) 
                q.push(NULL) ;
        }
        else
        {
            cout << temp->data <<" " ;
            if( temp->left ) 
                q.push( temp->left) ;
            if( temp->right )
                q.push( temp->right ) ;
        }
    
    }
}
int find_position( int arr[] , int n , int element )
{
    for( int i=0 ; i < n ; i++ )
    {
        if( arr[i] == element )
            return i ;
    }
    return -1 ;
}

void create_mapping( unordered_map<int,int> mapping , int postorder[] , int n )
{
    for( int i = 0 ; i< n ; i++ )
        mapping[postorder[i]] = i ;
}
Node* build_tree_from_post_in_order(int inorder[] , int postorder[] , int size , int &post_index ,
                                    int in_start , int in_end , unordered_map<int,int> &mapping )
{
    // base case 
    if( post_index < 0 || in_start > in_end )
        return NULL ;

    // Step A
    int element = postorder[post_index--] ;
    Node* root = new Node(element) ;
    int pos = mapping[element] ;

    // root->right
    root->right = build_tree_from_post_in_order(inorder , postorder , size , post_index , pos+1 , in_end , mapping ) ;
    root->left = build_tree_from_post_in_order(inorder , postorder , size , post_index , in_start , pos-1, mapping );

    return root ;
}
int main()
{
    int inorder[] = {40,20,10,50,30,60} ;
    int postorder[] = {40,20,50,60,30,10} ;
    int size = 6 ;
    int post_index = size-1 ;
    int in_start = 0 ;
    int in_end = size - 1;


    unordered_map<int,int> mapping ;

    create_mapping( mapping , postorder , size ) ;

    Node* root = build_tree_from_post_in_order(inorder , postorder , size , post_index , in_start , in_end , mapping ) ;

    cout << "printing\n" ;

    LevelOrderTravelsal( root ) ;

    return 0;
}