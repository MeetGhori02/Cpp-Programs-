#include <iostream>
#include <vector>
using namespace std;

class CALC
{
public:
    int add(double N1, double N2)
    {
        return N1 + N2;
    }

    double add(int N1, double N2)
    {
        return N1 + N2;
    }
};

int main()
{
    CALC C;
    vector<double> setresult;

    setresult.push_back(C.add(10, 50));
    setresult.push_back(C.add(10.50, 50));
    setresult.push_back(C.add(10, 50.50));

    cout << "Result using STL !!!! \n";
    for (const auto &i : setresult)
    {
        cout << "Result : " << i << "\n";
    }


    cout<<"Result using array !!!! \n";

    double arr[3];
    arr[0] = C.add(10,50);
    arr[1] = C.add(10.50,50);
    arr[2] = C.add(10,50.50);

    for(int i=0 ; i<3 ; i++)
    {
        cout << "Result "<<i + 1 <<" : " << arr[i] << "\n";
    }

return 0;
}