#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Word
{
    char* text;
    int count;
};

void toLowerCase(char* str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int findWord(Word* words, int size, const char* word)
{ 
    for (int i = 0; i < size; i++)
    {
        if (strcmp(words[i].text, word) == 0)
        {
            return i;
        }
    }
    return -1;
}

void addWord(Word*& words, int& size, const char* word)
{
    int index = findWord(words, size, word);
    if (index != -1)
    {
        words[index].count++;
    }
    else
    {
        Word* newWords = new Word[size + 1];
        for (int i = 0; i < size; i++)
        {
            newWords[i] = words[i];
        }
        newWords[size].text = new char[strlen(word) + 1];
        strcpy(newWords[size].text, word);
        newWords[size].count = 1;
        delete[] words;
        words = newWords;
        size++;
    }
}

void freeMemory(Word* words, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] words[i].text;
    }
    delete[] words;
}

int main()
{
    cout << "Enter a paragraph: ";
    string input;
    getline(cin, input);

    Word* words = nullptr;
    int size = 0;

    char* cstr = new char[input.length() + 1];
    strcpy(cstr, input.c_str());

    char* token = strtok(cstr, " ,.!?;:\n\t");
    while (token != nullptr)
    {
        toLowerCase(token);
        addWord(words, size, token);
        token = strtok(nullptr, " ,.!?;:\n\t");
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < size; i++)
    {
        cout << words[i].text << ": " << words[i].count << endl;
    }

    freeMemory(words, size);
    delete[] cstr;

    return 0;
}