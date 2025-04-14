#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Fuel
{
protected:
    string Ftype;

public:
    Fuel(string F) : Ftype(F) {};

    void DF()
    {
        cout << "Fuel type is " << Ftype<<endl;
        
    }
};

class Brand
{
protected:
    string Bname;

public:
    Brand(string B) : Bname(B) {};

    void DB()
    {
        cout << "Brand name is " << Bname<<endl;
    }
};

class Car : public Fuel, public Brand
{
protected:
    string Mname;

public:
    Car(string F, string B, string M) : Fuel(F), Brand(B), Mname(M) {};

    void display()
    {
        DF();
        DB();
        cout << "Model name is " << Mname<<endl;
        cout<<"_________________"<<endl;


    }
};

int main()
{
    queue<Car> car;

    car.push(Car("Petrol","Toyota" , "Innova"));
    car.push(Car("Diesel","Toyota" , "Fortuner"));
    car.push(Car("Petrol","Hyndai" , "i10"));

    while(!car.empty())
    {

        Car ccar = car.front();
        car.pop();
        ccar.display(); 

    }

     return 0;

}

