#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    void speak()
    {
        cout << "speaking\n" ; 
    }
} ; 
class Dog : public Animal
{
    public:
    void speak()
    {
        cout << "barking\n" ; 
    }
} ; 
int main()
{
    Dog d ; 
    d.speak() ; 
    Animal A ; 
    A.speak() ; 
    return 0; 
}