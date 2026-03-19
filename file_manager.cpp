#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// Create File
void createFile() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ofstream file(filename);
    file.close();

    cout << "File created successfully\n";
}

// Delete File
void deleteFile() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    if (remove(filename.c_str()) == 0)
        cout << "Deleted successfully\n";
    else
        cout << "Error deleting file\n";
}

// List Files
void listFiles() {
    system("ls");
}

// Read File
void readFile() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename);
    string line;

    if (!file) {
        cout << "File not found\n";
        return;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// Write File
void writeFile() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ofstream file(filename, ios::app);

    string text;
    cout << "Enter text: ";
    cin.ignore();
    getline(cin, text);

    file << text << endl;

    file.close();

    cout << "Written successfully\n";
}
//rename file
void renameFile() {
    string oldName, newName;

    cout << "Enter old file name: ";
    cin >> oldName;

    cout << "Enter new file name: ";
    cin >> newName;

    if (rename(oldName.c_str(), newName.c_str()) == 0)
        cout << "Renamed successfully\n";
    else
        cout << "Error renaming file\n";
}
// create folder
void createFolder() {
    string folder;
    cout << "Enter folder name: ";
    cin >> folder;

    string cmd = "mkdir " + folder;
    system(cmd.c_str());

    cout << "Folder created\n";
}
// search folder
void searchFile() {
    string filename;
    cout << "Enter file name to search: ";
    cin >> filename;

    string cmd = "find . -name " + filename;
    system(cmd.c_str());
}

// Menu
void menu() {
    cout << "\n--- File Manager ---\n";
    cout << "1. Create File\n";
    cout << "2. Delete File\n";
    cout << "3. List Files\n";
    cout << "4. Read File\n";
    cout << "5. Write File\n";
    cout << "6. Rename File\n";
    cout << "7. Create Folder\n";
    cout << "8. Search File\n";
    cout << "9. Exit\n";
}

int main() {
    int choice;

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
    case 1: createFile(); break;
    case 2: deleteFile(); break;
    case 3: listFiles(); break;
    case 4: readFile(); break;
    case 5: writeFile(); break;
    case 6: renameFile(); break;
    case 7: createFolder(); break;
    case 8: searchFile(); break;
    case 9: return 0;
    default: cout << "Invalid\n";
}
    }

    return 0;
}