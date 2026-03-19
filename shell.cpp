#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    string command;

    while (true) {
        cout << "myShell> ";
        getline(cin, command);

        if (command == "exit") break;

        if (command.substr(0, 2) == "cd") {
            string path = command.substr(3);
            chdir(path.c_str());
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execl("/bin/sh", "sh", "-c", command.c_str(), NULL);
        } else {
            wait(NULL);
        }
    }

    return 0;
}