//EXP 14: Displaying Memory Information
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// Function to execute a command and read its output
string executeCommand(const char* command) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(command, "r");

    if (!pipe) {
        cerr << "Error executing command." <<endl;
        return "";
    }

    while (!feof(pipe)) {
        if (fgets(buffer, sizeof(buffer), pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return result;
}

int main() {
    // Command to get memory information
    const char* command = "cat /proc/meminfo";  // You can also try "free -h"
    
    // Execute the command
    string output = executeCommand(command);
    
    // Display the output
    cout << "Memory Information:\n" << output << endl;

    return 0;
}
*/


#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memStatus)) {
        cout << "Memory Information:" << endl;
        cout << "Total Physical Memory: " << memStatus.ullTotalPhys / (1024 * 1024) << " MB" << endl;
        cout << "Available Physical Memory: " << memStatus.ullAvailPhys / (1024 * 1024) << " MB" << endl;
        cout << "Memory in Use: " << memStatus.dwMemoryLoad << "%" << endl;
    } else {
        cerr << "Error: Could not retrieve memory information." << endl;
        return 1;
    }

    return 0;
}

