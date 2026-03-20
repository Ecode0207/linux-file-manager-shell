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

        if (fs::exists(filename)) {
            cout << "File already exists\n";
            return;
        }

        ofstream file(filename);
        if (file) {
            cout << "File created successfully\n";
        } else {
            cout << "Error creating file\n";
        }
    }

    // 🔹 Delete File
    void deleteFile() {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;

        if (fs::exists(filename)) {
            if (fs::remove(filename))
                cout << "Deleted successfully\n";
            else
                cout << "Error deleting file\n";
        } else {
            cout << "File not found\n";
        }
    }

    // 🔹 List Files
    void listFiles() {
        cout << "\nFiles in current directory:\n";
        try {
            for (const auto &entry : fs::directory_iterator(".")) {
                cout << entry.path().filename() << endl;
            }
        } catch (...) {
            cout << "Error reading directory\n";
        }
    }

    // 🔹 Read File
    void readFile() {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;

        if (!fs::exists(filename)) {
            cout << "File not found\n";
            return;
        }

        ifstream file(filename);
        string line;

        cout << "\n--- File Content ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    // 🔹 Write File
    void writeFile() {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;

        ofstream file(filename, ios::app);

        if (!file) {
            cout << "Error opening file\n";
            return;
        }

        string text;
        cout << "Enter text: ";
        cin.ignore();
        getline(cin, text);

        file << text << endl;

        cout << "Written successfully\n";
    }

    // 🔹 Rename File
    void renameFile() {
        string oldName, newName;

        cout << "Enter old name: ";
        cin >> oldName;

        cout << "Enter new name: ";
        cin >> newName;

        try {
            fs::rename(oldName, newName);
            cout << "Renamed successfully\n";
        } catch (...) {
            cout << "Error renaming file\n";
        }
    }

    // 🔹 Create Folder
    void createFolder() {
        string folder;
        cout << "Enter folder name: ";
        cin >> folder;

        if (fs::create_directory(folder))
            cout << "Folder created\n";
        else
            cout << "Folder already exists or error\n";
    }

    // 🔹 Search File (recursive)
    void searchFile() {
        string target;
        cout << "Enter file name: ";
        cin >> target;

        bool found = false;

        try {
            for (const auto &entry : fs::recursive_directory_iterator(
                     ".", fs::directory_options::skip_permission_denied)) {

                if (entry.path().filename() == target) {
                    cout << "Found: " << entry.path() << endl;
                    found = true;
                }
            }
        } catch (...) {
            cout << "Error during search\n";
        }

        if (!found) {
            cout << "File not found\n";
        }
    }

    // 🔹 Menu
    void menu() {
        cout << "\n===== File Manager =====\n";
        cout << "1. Create File\n";
        cout << "2. Delete File\n";
        cout << "3. List Files\n";
        cout << "4. Read File\n";
        cout << "5. Write File\n";
        cout << "6. Rename File\n";
        cout << "7. Create Folder\n";
        cout << "8. Search File\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
    }
};

int main() {
    FileManager fm;
    int choice;

    while (true) {
        fm.menu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input\n";
            continue;
        }

        switch (choice) {
            case 1: fm.createFile(); break;
            case 2: fm.deleteFile(); break;
            case 3: fm.listFiles(); break;
            case 4: fm.readFile(); break;
            case 5: fm.writeFile(); break;
            case 6: fm.renameFile(); break;
            case 7: fm.createFolder(); break;
            case 8: fm.searchFile(); break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}