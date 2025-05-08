#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Product
{
    string name;
    int quantity;
    double price;
};

void addProduct(const string &filename)
{
    ofstream file(filename, ios::app);
    if (!file)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    Product product;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Enter quantity: ";
    cin >> product.quantity;
    cout << "Enter price: ";
    cin >> product.price;

    file << product.name << "," << product.quantity << "," << product.price << endl;
    file.close();
    cout << "Product added successfully." << endl;
}

void viewInventory(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    cout << "\nInventory:\n";
    while (getline(file, line))
    {
        stringstream ss(line);
        Product product;
        getline(ss, product.name, ',');
        ss >> product.quantity;
        ss.ignore();
        ss >> product.price;

        cout << "Name: " << product.name << ", Quantity: " << product.quantity << ", Price: " << product.price << endl;
    }
    file.close();
}

void searchProduct(const string &filename, const string &productName)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line))
    {
        stringstream ss(line);
        Product product;
        getline(ss, product.name, ',');
        ss >> product.quantity;
        ss.ignore();
        ss >> product.price;

        if (product.name == productName)
        {
            cout << "\nProduct Found:\n";
            cout << "Name: " << product.name << ", Quantity: " << product.quantity << ", Price: " << product.price << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nProduct not found." << endl;
    }
    file.close();
}

int main()
{
    const string filename = "inventory.txt";
    int choice;

    do
    {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct(filename);
            break;
        case 2:
            viewInventory(filename);
            break;
        case 3:
        {
            string productName;
            cout << "Enter product name to search: ";
            cin.ignore();
            getline(cin, productName);
            searchProduct(filename, productName);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}