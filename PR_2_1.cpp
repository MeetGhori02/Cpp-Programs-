#include <iostream>
#include <string>

const int MAX_SIZE = 100;
using namespace std;

class rectangle
{
  double Length;
  double Width;

public:
  void get()
  {
    cout << "Enter the length of the rectangle: ";
    cin >> Length;
    cout << "Enter the width of the rectangle: ";
    cin >> Width;
  }

  int Perimeter()
  {
    return 2 * (Length + Width);
  }

  int Area()
  {
    return Length * Width;
  }

  void set(int index)
  {
    cout << "Length of the rectangle: " << Length << endl;
    cout << "Width of the rectangle: " << Width << endl;
    cout << "Area : " << Area() << endl;
    cout << "Perimeter : " << Perimeter() << endl;
  }
};

int main()
{
  rectangle R[100];
  int count = 0;
  int choice;

  do
  {
    cout << "1. Add Rectangle \n";
    cout << "2. Update details  \n";
    cout << "3. Display details\n";
    cout << "4. Exit\n";

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      R[count].get();
      cout << "Rectangle added successfully !!!\n";
      count++;
      break;

    case 2:
      if (count == 0)
      {
        cout << "Rectangle is not fonud !!!!!";
      }
      else
      {
        int C;
        cout << "Enter rectangle no. to update 1 to " << count << " : ";
        cin >> C;
        R[C - 1].get();
        cout << "Rectangle update successfully !! \n";
      }
      break;

    case 3:
      if (count == 0)
      {
        cout << "Rectangle is not found !!!";
      }

      else
      {
        for (int i = 0; i < count; i++)
        {
          R[i].set(i);
        }
      }
      break;

    case 4:
      cout << "Exitin Program !!!";
    }
  } while (choice != 4);
}
