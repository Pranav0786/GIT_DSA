#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    map<int,list<int>> adjlist ;

    void addedge( int u , int  v )
    {
        adjlist[u].push_back(v) ;
        adjlist[v].push_back(u) ;
    }
    void print()
    {
        for( auto i : adjlist )
        {
            cout << i.first << " -> " ;
            for( auto j : i.second )
                cout << j << " ";
            cout << endl ;
        }
    }
} ;
int main()
{
    int n ;
    cout << "enter th no of nodes\n" ;
    cin >> n ;
    int e ;
    cout << "enter the no of edges\n" ;
    cin >> e ;
    Graph g ;
    for( int i = 0 ; i < e ; i++ )
    {
        cout << "enter the value of u & v \n" ;
        int u ;
        int v ;
        cin >> u >> v ;
        g.addedge( u , v ) ;
    }
    cout << endl ;

    g.print() ;
    return 0;
}