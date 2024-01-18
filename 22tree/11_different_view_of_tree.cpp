#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data ;
    node* left ;
    node * right ;
    
    node( int data )
    {
        this->data = data ;
        left = NULL ;
        right = NULL ;
    }
};

node* buildTree( node* root )
{
    cout << "entre the data for root\n" ;
    int data ;
    cin >> data ; 
    root = new node( data ) ;
    if( data == -1 )
        return NULL ;

    cout << "enter the data for left of " <<data << endl  ;
    root->left = buildTree(root->left) ;
    cout << "enter the data for right of "<<data << endl ;
    root->right = buildTree(root->right) ;

    return root ;
}

void print_top_view( node* root )
{
    if( root == NULL )
        return ;

    // map for horizontal dist ->topnode->data
    map<int,int> top_node ;

    // level queue  
    // node & horizontal dist
    queue<pair<node*,int>> q ;
    q.push( make_pair( root , 0 ) ) ;

    while( !q.empty() )
    {
        pair<node*,int> temp = q.front() ;
        q.pop() ;

        node* front_node = temp.first ;
        int hd = temp.second ;

        // hd is already exit 
        // if not
        if( top_node.find( hd ) == top_node.end() ) // create entry 
            top_node[hd] = front_node->data ;

        if( front_node->left )
            q.push( make_pair( front_node->left , hd-1 ) ) ;

        if( front_node->right )
            q.push( make_pair( front_node->right , hd+1 ) ) ;

    }
    // ans is stored in map
    cout << "printing ans\n" ;
    for( auto i : top_node )
        cout << i.first <<" -> " << i.second << endl ;

    cout << endl ;

}

void print_bottom_view( node* root )
{
    if( root == NULL )
        return ;

    // map for horizontal dist ->topnode->data
    map<int,int> top_node ;

    // level queue  
    // node & horizontal dist
    queue<pair<node*,int>> q ;
    q.push( make_pair( root , 0 ) ) ;

    while( !q.empty() )
    {
        pair<node*,int> temp = q.front() ;
        q.pop() ;

        node* front_node = temp.first ;
        int hd = temp.second ;

        top_node[hd] = front_node->data ;

        if( front_node->left )
            q.push( make_pair( front_node->left , hd-1 ) ) ;

        if( front_node->right )
            q.push( make_pair( front_node->right , hd+1 ) ) ;

    }
    // ans is stored in map
    cout << "printing ans\n" ;
    for( auto i : top_node )
        cout << i.first <<" -> " << i.second << endl ;

    cout << endl ;

}

void print_left_view( node* root , vector<int> &ans , int level )
{
    if( root== NULL )
        return ;

    if( level == ans.size() ) 
        ans.push_back(root->data) ;

    //left
    print_left_view(root->left , ans , level+1 ) ;
    //right
    print_left_view(root->right , ans , level+1 ) ;

}

void print_right_view( node* root , vector<int> &ans , int level )
{
    if( root== NULL )
        return ;

    if( level == ans.size() ) 
        ans.push_back(root->data) ;

    //right
    print_right_view(root->right , ans , level+1 ) ;
    //left
    print_right_view(root->left , ans , level+1 ) ;
    

}

int main()
{
    node* root = NULL ;
    root = buildTree( root  ) ;

    cout << "Top view"  << endl ;
    print_top_view( root ) ;

    cout << "Bottom view" << endl ;
    print_bottom_view( root ) ;

    vector<int> left ;
    cout << "Left view" << endl ;
    print_left_view( root , left , 0 ) ;
    
    for( auto i : left ) 
        cout << i << " " ;

    cout << endl ;

    vector<int> right ; 
    cout << "Right view" << endl ;
    print_left_view( root , right , 0 ) ;
    
    for( auto i : right ) 
        cout << i << " " ;

    cout << endl ;

    return 0;
}