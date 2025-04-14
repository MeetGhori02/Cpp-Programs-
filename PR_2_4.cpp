#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ITEMS = 150;

class Store
{
    int ID;
    string ItemName;
    double ItemPrice;
    int Quantity, Exquantity;
public:
    void getdata()
    {
        cout << "Enter your ID : ";
        cin >> ID;
        cout << "Enter your name : ";
        cin >> ItemName;
        cout << "Enter Price : ";
        cin >> ItemPrice;
        cout << "Enter Quantity : ";
        cin >> Quantity;
    }

    void putdata()
    {
        cout << "Your name is : " << ItemName << endl;
        cout << "Your ID is : " << ID << endl;
        cout << "Price is : " << ItemPrice << endl;
        cout << "Quantity is : " << Quantity << endl;
    }

    Store(){};

    Store(string name, int id, int quantity, double price)
    {
        ItemName = name;
        ID = id;
        ItemPrice = price;
        Quantity = quantity;
    }

    void increaseQ()
    {
        cout << "Enter extra quantity you want : ";
        cin >> Exquantity;

        Quantity += Exquantity;

        cout << "Now Quantity available is : " << Quantity;
    }

    void decreaseQ()
    {
        cout << "Enter extra quantity you want : ";
        cin >> Exquantity;
        cout << endl;

        Quantity -= Exquantity;

        cout << "Now Quantity available is : " << Quantity;
    }
};

int main()
{    int n;
   cout<<"Enter number of inventory items : ";
   cin>>n;
   Store I[MAX_ITEMS];

   for(int i=0;i<n;i++)
  {
        cout<<"Enter item for "<<i+1<<" : \n";
        I[i].getdata();
        cout<<endl;
  }
  
  for(int i=0;i<n;i++)
  {
        I[i].putdata();
        cout<<endl;
  }    

  int choice;
  do
  {
      cout << "\nMenu: ";
      cout << "\n1. Increase Stock";
      cout << "\n2. Decrease Stock";
      cout << "\n3. View Inventory";
      cout << "\n4. Exit";
      cout << "\nEnter your choice: ";
      cin >> choice;

      switch (choice)
      {
      case 1:
          cout << "\nSelect item to increase stock (1 to " << n << "): ";
          int incIndex;
          cin >> incIndex;
          if (incIndex >= 1 && incIndex <= n)
              I[incIndex - 1].increaseQ();
          else
              cout << "Invalid item number!" << endl;
          break;

      case 2:
          cout << "\nSelect item to decrease stock (1 to " << n << "): ";
          int decIndex;
          cin >> decIndex;
          if (decIndex >= 1 && decIndex <= n)
              I[decIndex - 1].decreaseQ();
          else
              cout << "Invalid item number!" << endl;
          break;

      case 3:
          cout << "\n--- Updated Inventory ---";
          for (int i = 0; i < n; i++)
          {
              I[i].putdata();
          }
          break;

      case 4:
          cout << "Exiting program..." << endl;
          break;

      default:
          cout << "Invalid choice! Try again." << endl;
      }
  } while (choice != 4);

  return 0;
}


