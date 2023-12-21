#include<bits/stdc++.h>
using namespace std;

void prepare_list(unordered_map<int,list<int>> &adjlist , vector<pair<int,int>> &edges )
{
    for( int i=0 ; i< edges.size() ; i++ )
    {
        int u = edges[i].first ;
        int v = edges[i].second ;

        adjlist[u].push_back(v) ;
        adjlist[v].push_back(u) ;
    }
}

void bfs(unordered_map<int,list<int>> &adjlist , vector<int> &ans , unordered_map<int,bool> &visited , int node )
{
    stack<int> s ;
    s.push(node) ;
    visited[node] = 1 ;

    while( !s.empty() )
    {
        int topnode = s.top() ;
        s.pop() ;
        ans.push_back(topnode) ;

        for( auto i : adjlist[topnode] )
        {
            if( !visited[i] )
            {
                s.push(i) ;
                visited[i] = 1 ;
            }
        }
    }
}

vector<int> dfs_travelsal( int vertex , vector<pair<int,int>> &edges )
{
    unordered_map<int,list<int>> adjlist ;
    vector<int> ans;
    unordered_map<int,bool> visited ;

    prepare_list(adjlist , edges ) ;

    for( int i=0 ;i <vertex ; i++ )
    {
        if( !visited[i] )
            bfs( adjlist , ans , visited , i ) ;
    }

    return ans ;
}
int main()
{
    vector<pair<int,int>> edges = {
        {1 , 2 } , {1,5} , {2,3} , {4,6} , {6,7} 
    };

    vector<int> ans = dfs_travelsal( 7 , edges ) ;

    for( int i =0 ;i < ans.size() ; i++ )
        cout << ans[i]<< " " ;
    cout << endl ;
    return 0;
}