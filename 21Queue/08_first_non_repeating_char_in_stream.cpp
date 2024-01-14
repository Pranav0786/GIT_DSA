// GFG Que

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str ;
    cout << "enter a string \n" ;
    cin >> str ;

    int freq[26] = {0} ;
    queue<char> q ;

    string ans = "" ;

    for( int i = 0 ; i < str.length() ; i++ )
    {
        char ch = str[i] ;

        // increment freq 
        freq[ch-'a']++ ;
        // push
        q.push(ch) ;

        while( !q.empty() )
        {
            if( freq[ q.front() -'a' ] > 1 )
                q.pop() ;

            else
            {
                ans.push_back( q.front() ) ;
                break ;
            }
        }

        if( q.empty() )
            ans.push_back('#') ;
    }

    for( int i= 0 ; i < ans.size() ; i++ )
        cout << ans[i] << " " ;
    cout << endl ;


    return 0;
}