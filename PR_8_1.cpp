#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    vector<int> sequence;
    int num;

    cout << "Enter a sequence of integers (end with a non-integer):" << endl;
    while (cin >> num) {
        sequence.push_back(num);
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Original sequence:" << endl;
    for (const auto& n : sequence) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> reversedSequence(sequence.size());
    for (size_t i = 0; i < sequence.size(); ++i) {
        reversedSequence[i] = sequence[sequence.size() - 1 - i];
    }

    cout << "Reversed sequence:" << endl;
    for (const auto& n : reversedSequence) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}