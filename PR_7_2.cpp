#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
    ifstream file("Data.txt");    
    if(!file)                   
    {
        cerr << "File could not be opened" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    int linecount = 0, wordcount = 0, charcount = 0;

    while (getline(file,line))
    {
        lines.push_back(line);
        linecount++;

        charcount += line.length();

        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            wordcount++;
        }
    }
    file.close();

    cout << "Total number of lines: " << linecount << endl;
    cout << "Total number of words: " << wordcount << endl;
    cout << "Total number of characters: " << charcount << endl;
    cout << "The content of the file is: " << endl;

    for (const auto& l : lines)
    {
        cout << l << endl;
    }

    return 0;
}


