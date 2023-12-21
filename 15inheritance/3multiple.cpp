#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    int age ;
    int weight ; 

    void bark()
    {
        cout << "barking\n" ;
    }
};
class Human
{
    public:
    string color ;

    void speak()
    {
        cout << "speaking\n" ;
    }
}; 
class both : public Animal, public Human
{
    public:
    void say()
    {
        cout << "I'm both\n" ;
    }
};
int main()
{
    both b ;
    b.bark() ;
    b.speak() ;
    b.say() ;
    return 0;
}