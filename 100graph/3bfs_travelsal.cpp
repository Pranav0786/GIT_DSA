#include<bits/stdc++.h>
using namespace std;
void prepare_list( unordered_map<int,list<int>> &adjlist , vector<pair<int,int>> &edges )
{
    for( int i= 0 ; i < edges.size() ; i++ )
    {
        int u = edges[i].first ;
        int v = edges[i].second ;

        adjlist[u].push_back(v) ;
        adjlist[v].push_back(u) ;
    }
}
void bfs(unordered_map<int,list<int>> &adjlist , unordered_map<int,bool> &visited , vector<int> &ans , int node )
{
    queue<int> q ;
    q.push(node) ;
    visited[node] = 1 ;
    
    while( !q.empty() )
    {
        int frontnode = q.front() ;
        q.pop() ;

        ans.push_back(frontnode) ;

        for( auto i : adjlist[frontnode] ) 
        {
            if( !visited[i] )
            {
                q.push(i) ;
                visited[i] = 1 ;
            }
        }
    }
}
vector<int> bfs_travelsal( int vertex , vector<pair<int,int>> &edges)
{
    unordered_map<int,list<int>> adjlist ;
    vector<int> ans ;
    unordered_map<int,bool> visited ;

    prepare_list( adjlist , edges ) ;

    // travelsal
    for( int i=0 ;i < vertex ; i++ )
    {
        if( !visited[i] )
            bfs(adjlist , visited , ans , i ) ;
    }

    return ans ;
}
int main()
{
    vector<pair<int,int>> edges = {
        {1 , 2 } , {1,5} , {2,3} , {4,6} , {6,7} 
    } ;

    vector<int> ans = bfs_travelsal( 7 , edges ) ;

    for( int i= 0 ; i < ans.size() ; i++ )
        cout << ans[i] << " " ;
    cout << endl ;
    return 0;
}