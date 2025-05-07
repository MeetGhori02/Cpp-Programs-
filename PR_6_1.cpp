#include <iostream>
#include <string>

using namespace std;

class Pointer
{

private:
    int x, y;

public:
    Pointer(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Pointer* move(int &dx, int &dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    void display()
    {
        cout << "X : " << x << endl;
        cout << "Y : " << y << endl;
    }

};

    int main()
    {
        int x, y;
        int n;

        cout << "Enter initial x and y coordinates : ";
        cin >> x >> y;

        Pointer p(x, y);
        cout << "Enter number of moves : ";
        cin >> n;

        int move[n][2];

        for (int i = 0; i < n; i++)
        {
            cout << "Enter x and y coordinates : ";
            cin >> move[i][0] >> move[i][1];
        }

        for (int i = 0; i < n; i++)
        {
            p.move(move[i][0], move[i][1]);
            cout << "After move " << i + 1 << endl;
            p.display();
        }
        cout << "Final coordinates : " << endl;
        p.display();

        return 0;

    }
