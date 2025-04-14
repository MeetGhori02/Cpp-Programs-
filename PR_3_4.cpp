#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
T findmax(T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; i++) {
        mx = max(mx, arr[i]);
    }
    return mx;
}

template <typename T>
void reverseArr(T arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

char findMaxChar(const string &str) {
    char maxChar = str[0];
    for (char c : str) {
        if (c > maxChar) {
            maxChar = c;
        }
    }
    return maxChar;
}

void reverseString(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

template <typename T>
void PerformOperations() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    T* arr = new T[n];
    cout << "Enter " << n << " elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "1. Maximum Value in the array." << endl;
    cout << "2. Reversing the order of elements." << endl;
    cout << "3. Exit." << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Maximum element of the array: " << findmax(arr, n) << endl;
        break;

    case 2:
        reverseArr(arr, n);
        cout << "Reversed array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        break;

    case 3:
        cout << "Exiting the program." << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }

    delete[] arr;
}

int main() {
    int choice;
    cout << "Choose data type:" << endl;
    cout << "1. Integer" << endl;
    cout << "2. Float" << endl;
    cout << "3. String" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        PerformOperations<int>();
        break;
    case 2:
        PerformOperations<float>();
        break;
    case 3:
        {
            int n;
            cout << "Enter the size of the array: ";
            cin >> n;
            string* arr = new string[n];
            cout << "Enter " << n << " strings:" << endl;
            for (int i = 0; i < n; i++) {
                cout << "Enter string " << i + 1 << ": ";
                cin >> arr[i];
            }

            cout << "Strings entered:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            
            for (int i = 0; i < n; i++) {
                char maxChar = findMaxChar(arr[i]);
                cout << "Maximum character in string " << i + 1 << ": " << maxChar << endl;
            }

            for (int i = 0; i < n; i++) {
                reverseString(arr[i]);
                cout << "Reversed string " << i + 1 << ": " << arr[i] << endl;
            }

            delete[] arr;
        }
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}