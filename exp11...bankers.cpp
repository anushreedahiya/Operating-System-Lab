//EXP 11: Banker's Algorithm
#include <iostream>
using namespace std;

const int max_pro = 10;
const int max_res = 10;

int main() {
    int n, m; // Number of processes and resources

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    int allocation[max_pro][max_res];
    int max[max_pro][max_res];
    int available[max_res];
    int need[max_pro][max_res];

    // Input allocation matrix
    cout << "Enter the allocation matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> allocation[i][j];
        }
    }

    // Input max matrix
    cout << "Enter the max matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> max[i][j];
        }
    }

    // Input available vector
    cout << "Enter the available vector: ";
    for (int i = 0; i < m; ++i) {
        cin >> available[i];
    }

    // Calculate the need matrix
    cout << "Need Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    bool safe = false;
    bool marked[max_pro] = {false}; // Marked processes as safe
    int safeSequence[max_pro]; // Store the safe sequence
    int safeIndex = 0;
    while (!safe) {
        safe = true; // Assume all processes are safe
        for (int i = 0; i < n; ++i) {
            if (!marked[i]) {
                bool canExecute = true;
                for (int j = 0; j < m; ++j) {
                    if (need[i][j] > available[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    marked[i] = true;
                    safeSequence[safeIndex++] = i; // Add the process to safe sequence
                    for (int j = 0; j < m; ++j) {
                        available[j] += allocation[i][j];
                    }
                    safe = false; // There was a change, need to iterate again
                }
            }
        }
    }

    // Print the safe sequence
    cout << "Safe Sequence: ";
    for (int i = 0; i < safeIndex; ++i) {
        cout << "P" << safeSequence[i] << " ";
    }
    cout << endl;

    return 0;
}

