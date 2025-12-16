//SJF, other
#include <iostream>
#include <iomanip>
using namespace std;

class Process {
public:
int id;
int bt;
int at;
int ct;
int tat;
int wt;
Process() : id(0), bt(0), at(0), ct(0), tat(0), wt(0) {}
};

void calculateCompletionTime(Process proc[], int n) {
	int currentTime = 0;
	const int INT_MAX_CUSTOM = 1000;
	bool completed[100] = {false};
	int completedCount = 0;
	
	while (completedCount < n) {
		int shortestIndex = -1;
		int shortestBurst = INT_MAX_CUSTOM;

		for (int i = 0; i < n; ++i) {
			if (!completed[i] && proc[i].at <= currentTime && proc[i].bt <shortestBurst) {
				shortestBurst = proc[i].bt;
				shortestIndex = i;
			}
		}
	
		if (shortestIndex == -1) {
			currentTime++;
		} else {
			proc[shortestIndex].ct = currentTime + proc[shortestIndex].bt;
			currentTime = proc[shortestIndex].ct;
			completed[shortestIndex] = true;
			completedCount++;
		}
	}
}

void calculateTurnaroundTime(Process proc[], int n) {
	for (int i = 0; i < n; ++i)
		proc[i].tat = proc[i].ct - proc[i].at;
}

void calculateWaitingTime(Process proc[], int n) {
	for (int i = 0; i < n; ++i)
		proc[i].wt = proc[i].tat - proc[i].bt;
}

int main() {
	int n, choice;
	Process proc[100];
	
	while (true) {
		cout << endl;
		cout << "Choose the mode for arrival times:\n";
		cout << "1. Arrival time for all processes = 0\n";
		cout << "2. Specify arrival time and burst time for eachprocess\n";
		cout << "3. Exit\n" << endl;
		cout << "Enter your choice (1/2/3): ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1:
				cout << "Enter the number of processes: ";
				cin >> n;
				cout << endl;
				for (int i = 0; i < n; i++) {
					proc[i].id = i + 1;
					proc[i].at = 0;
					cout << "Enter burst time for process " << i + 1 << ": ";
					cin >> proc[i].bt;
				}
				break;
			case 2:
				cout << "Enter the number of processes: ";
				cin >> n;
				cout << endl;
				
				cout << "Enter arrival time and burst time for each process:\n";
				for (int i = 0; i < n; i++) {
					proc[i].id = i + 1;
					cout << "Process " << i + 1 << " - Arrival Time: ";
					cin >> proc[i].at;
					cout << "Process " << i + 1 << " - Burst Time: ";
					cin >> proc[i].bt;
				}
				break;
			case 3:
				cout << "Exiting program.\n";
				return 0;
			default:
				cout << "Invalid choice.\n";
				continue;
		}

		calculateCompletionTime(proc, n);
		calculateTurnaroundTime(proc, n);
		calculateWaitingTime(proc, n);
	
		cout << endl;
		cout << left << setw(10) << "Process" << setw(15) << "Arrival Time" << setw(15) << "Burst Time" << setw(20) << "Completion Time" << setw(20) <<
		"Turnaround Time" << setw(15) << "Waiting Time" << endl;
		for (int i = 0; i < n; i++) {
			cout << left << setw(10) << proc[i].id << setw(15) <<proc[i].at << setw(15) << proc[i].bt << setw(20) << proc[i].ct << setw(20)
			<< proc[i].tat << setw(15) << proc[i].wt << endl;
		}

		double totalTAT = 0, totalWT = 0;
		for (int i = 0; i < n; i++) {
			totalTAT += proc[i].tat;
			totalWT += proc[i].wt;
		}
		cout << endl;
		cout << "Average Turnaround Time = " << totalTAT / n << endl;
		cout << "Average Waiting Time = " << totalWT / n << endl;
	}
	return 0;
}
