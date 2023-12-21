#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    void fun()
    {
        cout << "AAA\n" ;
    }
};
class B 
{
    public:
    void fun()
    {
        cout << "BBB\n" ;
    }
} ;
class C : public A , public B
{
    public:
    void funC()
    {
        cout << "CCC\n" ;
    }
};
int main()
{
    C c;
    c.A::fun() ;
    c.funC() ;
    return 0;
}