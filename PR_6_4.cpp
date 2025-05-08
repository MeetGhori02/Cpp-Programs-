#include<iostream>
using namespace std;
class Base
{
    public:
    Base()
    {
       cout<<"Base clsass constructor called"<<endl;
    }

    ~Base()
    {
        cout<<"Base class destructor called"<<endl;
    }
};

class Derived: public Base
{
    int* data;
    public:
    Derived()
    {
        data = new int[5];
        cout<<"Derived class constructor called"<<endl;
    }

    ~Derived()
    {
        delete[] data;
        cout<<"Derived class destructor called"<<endl;
    }
     
    
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}