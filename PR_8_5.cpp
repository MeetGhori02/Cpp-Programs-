#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Folder
{
    string name;
    vector<string> files;
};
void sortFolders(vector<Folder> &folders)
{
    int n = folders.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (folders[j].name > folders[j + 1].name)
            {
                Folder temp = folders[j];
                folders[j] = folders[j + 1];
                folders[j + 1] = temp;
            }
        }
    }
}
int findFolder(vector<Folder> &folders, const string &folderName)
{
    for (int i = 0; i < folders.size(); ++i)
    {
        if (folders[i].name == folderName)
        {
            return i;
        }
    }
    return 1;
}
int main()
{
    vector<Folder> folders;
    int choice;
    do
    {
        cout << "\n=== Directory Management System ===\n";
        cout << "1. Create New Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory Structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            Folder f;
            cout << "Enter folder name: ";
            cin >> f.name;
            folders.push_back(f);
            sortFolders(folders);
            cout << "Folder created successfully.\n";
        }
        else if (choice == 2)
        {
            string folderName, fileName;
            cout << "Enter folder name: ";
            cin >> folderName;
            int idx = findFolder(folders, folderName);
            if (idx != -1)
            {
                cout << "Enter file name to add: ";
                cin >> fileName;
                folders[idx].files.push_back(fileName);
                cout << "File added successfully.\n";
            }
            else
            {
                cout << "Folder not found!\n";
            }
        }
        else if (choice == 3)
        {
            cout << "\n=== Directory Structure ===\n";
            for (auto it = folders.begin(); it != folders.end(); ++it)
            {
                cout << "Folder: " << it->name << endl;
                if (it->files.empty())
                {
                    cout << "  (No files)\n";
                }
                else
                {
                    for (auto fit = it->files.begin(); fit != it->files.end(); ++fit)
                    {
                        cout << "  - " << *fit << endl;
                    }
                }
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting the system.\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}