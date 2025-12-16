//EXP:9, ASSIGNMENT1: First Come First Serve(FCFS)
#include <iostream>
using namespace std;

int main() {
    int n, i, j, time = 0, arrival[10], burst[10], waiting[10], turnaround[10], completion[10];
    float avg_waiting, avg_turnaround;
    int choice;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter your choice:\n";
	cout << "1. Arrival time for all process=0\n";
	cout << "2. Arrival time of each process is different.\n";
    cin >> choice;

    switch (choice) {
        case 1:
            // setting arrival time to 0 for all processes
            for (i = 0; i < n; i++) {
                arrival[i] = 0;
                cout << "Enter burst time for process " << i + 1 << ": ";
                cin >> burst[i];
            }
            break;
        case 2:
            // taking input for burst and arrival time
            for (i = 0; i < n; i++) {
                cout << "Enter arrival time for process " << i + 1 << ": ";
                cin >> arrival[i];
                cout << "Enter burst time for process " << i + 1 << ": ";
                cin >> burst[i];
            }
            break;
        default:
            cout << "Invalid choice!";
            return 0;
    }

    // calculating waiting, turnaround, and completion time for each process
    for (i = 0; i < n; i++) {
        if (time < arrival[i]) {
            time = arrival[i];
        }
        time += burst[i];
        turnaround[i] = time - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        completion[i] = time;
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time" << endl;
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << endl;
    }

    avg_waiting = 0;
    avg_turnaround = 0;
    for (i = 0; i < n; i++) {
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }

    avg_waiting /= n;
    avg_turnaround /= n;

    cout << "\nAverage waiting time: " << avg_waiting << endl;
    cout << "Average turnaround time: " << avg_turnaround << endl;

    return 0;
}



