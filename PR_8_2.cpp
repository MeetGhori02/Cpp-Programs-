#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string text;
    map<string, int> wordFrequency;

    cout << "Enter a sentence:" << endl;
    getline(cin, text);

    stringstream ss(text);
    string word;

    while (ss >> word) {
        ++wordFrequency[word];
    }

    cout << "Word Frequency Distribution:" << endl;
    for (const auto& entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}