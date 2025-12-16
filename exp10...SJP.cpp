//EXP 10: SHORTEST JOB FIRST (Non Preemptive)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int process[10], arrival[10], burst[10], service[10], waiting[10], turnaround[10];
    float avg_waiting = 0, avg_turnaround = 0;
    
    cout << "Enter the number of processes: ";
    cin >> n;

    // Input for arrival and burst time for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrival[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst[i];
        process[i] = i + 1;
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival[j] > arrival[j + 1]) {
                swap(arrival[j], arrival[j + 1]);
                swap(burst[j], burst[j + 1]);
                swap(process[j], process[j + 1]);
            }
        }
    }

    // Calculate service and waiting time for each process
    service[0] = arrival[0];
    waiting[0] = 0;

    for (int i = 1; i < n; i++) {
        service[i] = max(service[i - 1], arrival[i] + burst[i - 1]); // Service starts at the max of previous service time and the arrival time plus previous burst time
        waiting[i] = service[i] - arrival[i];
        turnaround[i] = waiting[i] + burst[i];
    }

    // Display process details
    cout << "\nProcess\tArrival Time\tBurst Time\tService Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" << service[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << endl;
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }

    // Calculate average waiting and turnaround time
    avg_waiting /= n;
    avg_turnaround /= n;

    cout << "\nAverage waiting time: " << avg_waiting << endl;
    cout << "Average turnaround time: " << avg_turnaround << endl;

    return 0;
}

