#include<iostream>
#include<cstring>

using namespace std;

class CustomerAccount
{
public:

    char accholder[50];
    int accnumber;
    double balance,Wbalance,Dbalance;


    CustomerAccount()
    {
        strcpy(accholder,"Unknown");
        accnumber=00;
        balance=00;
    }

    CustomerAccount(const char* name,int accno,double inamount=0)
    {
        strcpy(accholder,name);
        accnumber = accno;
        balance = inamount;
    }

    void creatacc()
    {

         cout<<"Enter your name : ";
         cin>>accholder;
         cout<<"Enter account number : ";
         cin>>accnumber;
         cout<<"Enter your balance :";
         cin>>balance;
         cout<<endl;
    }

    void putdata()
    {
        cout<<"Your name is : "<<accholder;
        cout<<"Your account number  is : "<<accnumber;
        cout<<"Your current balance is : "<<balance;
        cout<<endl;

    }

    void withdraw()
    {
        cout<<"Enter amount you want to withdraw : ";
        cin>>Wbalance;
        cout<<endl;

        balance = balance - Wbalance;

        cout<<"Now your account balance is  : "<<balance;
        cout<<endl;
    }

    void deposite()
    {
        cout<<"Enter amount you want to deposite : ";
        cin>>Dbalance;
        cout<<endl;

        balance = balance + Dbalance;

        cout<<"Now your account balance is  : "<<balance;
        cout<<endl;
    }

    void display()
    {
        cout<<"Your name is : "<<accholder;
        cout<<"Your account number  is : "<<accnumber;
        cout<<"Your current balance is : "<<balance;
        cout<<endl;

    }

};

int main()
{

    CustomerAccount P1;
    P1.creatacc();

    int a=4,B1,B2;

    do
    {
        cout<<"____CHOICE____"<<"\n";
        cout<<"1.Create Account."<<"\n";
        cout<<"2.Deposite Money"<<"\n";
        cout<<"3.Withdraw Money"<<"\n";
        cout<<"4.Display Account Details"<<"\n";
        cout<<"Exit"<<"\n";

        cout<<"Enter you choice : ";
        cin>>a;
        cout<<endl;

        switch(a)
        {
        case 1:
            P1.creatacc();
            break;

        case 2:
            cout<<"how much amount you want to deposite? : ";
            cin>>B1;

            P1.deposite();
            break;

        case 3:
            cout<<"how much amount you want to withdraw? : ";
            cin>>B2;

            P1.withdraw();

            break;

        case 4:
            P1.putdata();
            cout<<endl;

            break;

        case 5:
            cout<<"Programme is over !!!";
            cout<<endl;

        }

    }
    while(a!=5);

}

