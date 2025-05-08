#include <iostream>
#include <set>
#include <vector>
using namespace std;

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1)
        return size;

    int temp[size];
    int j = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[size - 1];

    for (int i = 0; i < j; ++i) {
        arr[i] = temp[i];
    }
    return j;
}

int main() {
    int n;
    cout << "Enter the number of transaction IDs: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<int> transactionIDs;
    cout << "Enter " << n << " transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        int id;
        while (!(cin >> id)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        transactionIDs.push_back(id);
    }

    set<int> uniqueTransactions(transactionIDs.begin(), transactionIDs.end());

    for (const int& id : uniqueTransactions) {
        cout << id << " ";
    }
    cout << endl;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = transactionIDs[i];
    }

    sortArray(arr, n);
    int newSize = removeDuplicates(arr, n);

    for (int i = 0; i < newSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}