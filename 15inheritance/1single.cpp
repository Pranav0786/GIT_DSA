#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Animal
{
    private:
    int age ;
    int weight ; 

    public:
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
int main()
{
    Dog d ;
    d.say() ;
    d.speak() ;
    return 0;
}