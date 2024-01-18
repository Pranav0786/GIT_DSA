// gfg que

#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* left, * right;
}; 

void solve( Node* root , vector<int> &ans , queue<Node*> &q)
{
    if( root == NULL )
        return ;
        
    q.push(root) ;
    while( !q.empty() ) 
    {
        Node* temp = q.front() ;
        q.pop() ;
        
        while(temp)
        {
            ans.push_back(temp->data) ;
            if( temp->left )
                q.push(temp->left) ;
                
            temp = temp->right ;
        }
    }
}
vector<int> diagonal(Node *root)
{
   vector<int> ans ;
   queue<Node*> q ;
   solve( root , ans , q) ;
   
   return ans ;
}

int main()
{
    return 0;
}