#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    int a ;

    void operator+ (A &obj)
    {
        cout << this->a - obj.a << endl ;
    }
};


int main()
{
    A obj1 , obj2 ;
    obj1.a = 10 ;
    obj2.a = 7 ;

    obj1 + obj2 ;
    return 0;
}