#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int top ; 
    int *arr ;  
    int size ; 

    Stack( int size )
    {
        arr = new int[size] ; 
        this->size = size ; 
        top = -1 ; 
    }
    bool isempty()
    {
        if( top == -1 )
            return true ;
        return false ;
    }

    void push( int data )
    {
        if( size - top > 1 )
        {
            // space available
            arr[++top] = data ;
        }
        else
        {
            cout <<"stack overflow\n" ;
            return ;
        }
    }

    void pop()
    {
        if( isempty() )
        {
            cout <<"stack is empty\n" ;
            return ;
        }

        top-- ;
    }

    int getsize() // no of valide elements present in stack
    {
        if( isempty() ) return 0 ;

        return top+1 ;
    }

    int gettop()
    {
        if( isempty() )
        {
            cout << "stack is empty\n" ;
            return ;
        }

        return arr[top] ;
    }

};

int main()
{
    Stack s(10) ;
    return 0;
}