#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    void funA()
    {
        cout << "AAA\n" ;
    }
};
class B : public A
{
    public:
    void funB()
    {
        cout << "BBB\n" ;
    }
} ;
class C : public A
{
    public:
    void funC()
    {
        cout << "CCC\n" ;
    }
};
int main()
{
    A a ;
    a.funA() ;
    B b ;
    b.funA() ;
    b.funB() ;
    C c ;
    c.funA() ;
    c.funC() ;
    return 0;
}