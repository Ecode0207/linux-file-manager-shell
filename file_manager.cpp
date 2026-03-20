#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class FileManager {
public:

    // 🔹 Create File
    void createFile() {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;

        ofstream file(filename);
        file.close();

        cout << "File created successfully\n";
    }

    // 🔹 Delete File
    void deleteFile() {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;

        if (fs::remove(filename))
            cout << "Deleted successfully\n";
        else
            cout << "File not found\n";
    }

    // 🔹 List Files
    void listFiles() {
        for (const auto &entry : fs::directory_iterator(".")) {
            cout << entry.path().filename() << endl;
        }
    }

    // 🔹 Read File
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

    // 🔹 Write File
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

    // 🔹 Rename File
    void renameFile() {
        string oldName, newName;

        cout << "Enter old name: ";
        cin >> oldName;

        cout << "Enter new name: ";
        cin >> newName;

        fs::rename(oldName, newName);
        cout << "Renamed successfully\n";
    }

    // 🔹 Create Folder
    void createFolder() {
        string folder;
        cout << "Enter folder name: ";
        cin >> folder;

        if (fs::create_directory(folder))
            cout << "Folder created\n";
        else
            cout << "Folder already exists\n";
    }

    // 🔹 Search File (recursive)
    void searchFile() {
        string target;
        cout << "Enter file name: ";
        cin >> target;

        bool found = false;

        for (const auto &entry : fs::recursive_directory_iterator(".")) {
            if (entry.path().filename() == target) {
                cout << entry.path() << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "File not found\n";
        }
    }

    // 🔹 Menu
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
};

int main() {
    FileManager fm;
    int choice;

    while (true) {
        fm.menu();
        cin >> choice;

        switch (choice) {
            case 1: fm.createFile(); break;
            case 2: fm.deleteFile(); break;
            case 3: fm.listFiles(); break;
            case 4: fm.readFile(); break;
            case 5: fm.writeFile(); break;
            case 6: fm.renameFile(); break;
            case 7: fm.createFolder(); break;
            case 8: fm.searchFile(); break;
            case 9: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}