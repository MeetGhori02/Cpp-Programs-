#include<iostream>
using namespace std;
class BD
{
public:
    char name[50];
    int accno;
    float balance;

    void getdata()
    {
        cout<<"Enter your name : ";
        cin>>name;

        cout<<"Enter your account number : ";
        cin >>accno;

        cout<<"Enter your current balace : ";
        cin >>balance;

        cout<<endl;
    }

    void putdata()
    {
        cout<<"Your name is : "<<name<<endl;
        cout<<"Your account no. is : "<<accno<<endl;
        cout<<"Your current balance is : "<<balance<<endl;
    }

};

int main()
{
    BD p1;

    p1.getdata();
    p1.putdata();

    cout<<endl;

    int a=1,B1,B2;


    do
    {
        cout<<"____CHOICES____"<<endl;
        cout<<"1. Deposit Amount ."<<endl;
        cout<<"2. Withdraw Amount ."<<endl;
        cout<<"3.EXIT"<<endl;
        cout<<"Enter you choice";
        cin>>a;
        cout<<endl;

        switch(a)
        {

        case 1:
            cout<<"how much amount you want to deposite? : ";
            cin>>B1;

            p1.balance+=B1;

            cout<<"Your current bank balance is : "<<p1.balance;
            cout<<endl;

            break;


        case 2:
            cout<<"how much amount you want to withdraw? : ";
            cin>>B2;

            p1.balance-=B2;

            cout<<"Your current bank balance is : "<<p1.balance;
            cout<<endl;

            break;


        case 3:
            cout<<"Programm is over";
            cout<<endl;

            break;

        }
    }
    while(a!=3);



}





