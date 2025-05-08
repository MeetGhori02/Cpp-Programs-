

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n1, n2;
    cout << "Enter the first array siize : ";
    cin >> n1;

    cout << "Enter the second array size : ";
    cin >> n2;

    int *ptr2 = new int[n1];
    int *ptr1 = new int[n2];

    cout << "Enter the first array elements : ";
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter " << i + 1 << "element : ";
        cin >> ptr1[i];
    }

    cout << "Enter the second array element :";
    for (int i = 0; i < n2; i++)
    {
        cout << "Enter" << i + 1 << " element : ";
        cin >> ptr2[i];
    }

    int *merged = new int[n1 + n2];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (ptr1[i] < ptr2[j])
        {
            merged[k++] = ptr1[i++];
        }
        else
        {
            merged[k++] = ptr2[j++];
        }
    }

    cout << "The merged array is : " << endl;
    while (i < n1)
    {
        merged[k++] = ptr1[i++];
    }
    while (j < n2)
    {
        merged[k++] = ptr2[j++];
    }

    for (int i = 0; i < n1 + n2; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;
    delete[] ptr1;
    delete[] ptr2;
    delete[] merged;
    return 0;
}
