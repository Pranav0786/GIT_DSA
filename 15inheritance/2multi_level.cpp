#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    int age ;
    int weight ; 

    void speak()
    {
        cout << "is speaking\n" ;
    }
};
class Dog : public Animal
{
    public:
    void say()
    {
        cout << "dog " ;
    }
};
class Cat : public Dog
{
    public:
    void display() 
    {
        cout << "I'm cat\n" ;
    }
};
int main()
{
    Cat c ;
    c.say() ;
    c.speak() ;
    c.display() ;
    return 0;
}