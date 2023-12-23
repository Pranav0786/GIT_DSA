#include<bits/stdc++.h>
using namespace std;

class NStacks
{
    int *a , *top , *next ;
    int n ; // no. of stacks
    int size ; // size of main array
    int freespot ; // tells freespace in main array

    public:
    NStacks( int n , int s )
    {
        this->n = n ;
        size = s ;
        freespot = 0 ;
        a = new int[size] ;
        top = new int[n] ;
        next = new int[size] ;

        for( int i=0 ; i < n ; i++ )    
            top[i] = -1 ;

        for( int i=0 ; i< size ; i++ )
            next[i] = i+1 ;
        next[size-1] = -1 ;
    }

    bool push( int NewElement , int m )
    {
        if( freespot == -1 )
            return false ; // stack is overflow 

        // step 1 -> find index
        int index = freespot ;

        // step 2 -> update freespot
        freespot = next[index] ;

        // step 3 -> insert
        a[index] = NewElement ;

        // step 4 -> update next
        next[index] = top[m-1] ;

        // step 5 -> update top
        top[m-1] = index ;

        return true ;
    }

    int pop( int m ) // pop from mth stack
    {
        if( top[m-1] == -1 )
            return -1 ; // stack is underflow

        int index = top[m-1] ;

        top[m-1] = next[index] ;

        int PopElement = a[index] ;

        freespot = index ;

        return PopElement ; 

    }

    ~NStacks()
    {
        delete[] a ;
        delete[] top ;
        delete[] next ;
    }
};

int main()
{
    NStacks s(3,6) ;

    cout << s.push( 10 , 1 ) << endl ;
    cout << s.push( 100 , 2 ) << endl ;

    cout << s.pop(1) << endl ;

    cout << s.push(1000 , 2 ) << endl ;
    return 0;
}