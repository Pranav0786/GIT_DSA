#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A
{
    int x;
    int y = 3 ;
    public:
    A( int n )
    {
        x = n ;
        cout << x << endl ;
    }
    void show() 
    {
        cout << "hello\n" ;
    }
    friend class B ;
    friend void show( A &) ;
};

class B
{
    public:
    void print( A &a )
    {
        cout << "in B\n" ;
        cout << a.x << endl ;
    }
};
void show( A &a )
{
    cout << "in show\n" ;
    cout << a.y << endl ;
}
int main()
{
    A a(6);
    B b ;
    b.print(a) ;
    show(a) ;
    return 0;
}