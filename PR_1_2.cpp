#include <iostream>
#include <cstring>
using namespace std;

class Product
{
    int id;
    char name[50];
    int quantity;
    float price;

public:
    void addProduct()
    {
        cout << "Enter product ID: ";
        cin >> id;
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price per unit: ";
        cin >> price;
    }

    void displayProduct() const
    {
        cout << "Product ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity in stock: " << quantity << endl;
        cout << "Price per unit: " << price << endl;
    }

    int getID() const
    {
        return id;
    }

    void updateQuantity(int change)
    {
        quantity += change;
        if (quantity < 0)
            quantity = 0;
    }

    float getTotalValue() const
    {
        return quantity * price;
    }
};

int main()
{
    const int MAX_PRODUCTS = 100;
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;

    int choice;
    do
    {
        cout << "\nInventory Management System\n";
        cout << "1. Add new product\n";
        cout << "2. Update product quantity\n";
        cout << "3. Display all products\n";
        cout << "4. Calculate total inventory value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (productCount < MAX_PRODUCTS)
            {
                inventory[productCount].addProduct();
                productCount++;
            }
            else
            {
                cout << "Inventory full!\n";
            }
            break;

        case 2:
        {
            int id, qty;
            cout << "Enter product ID to update: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < productCount; i++)
            {
                if (inventory[i].getID() == id)
                {
                    cout << "Enter quantity to add (or negative to reduce): ";
                    cin >> qty;
                    inventory[i].updateQuantity(qty);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Product ID not found.\n";
            }
            break;
        }

        case 3:
            for (int i = 0; i < productCount; i++)
            {
                cout << "\nProduct " << (i + 1) << ":\n";
                inventory[i].displayProduct();
            }
            break;

        case 4:
        {
            float totalValue = 0;
            for (int i = 0; i < productCount; i++)
            {
                totalValue += inventory[i].getTotalValue();
            }
            cout << "Total inventory value: " << totalValue << endl;
            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
