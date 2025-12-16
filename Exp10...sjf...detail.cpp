#include <iostream> 
#include <iomanip>
#include <string.h> 
using namespace std;

int main() {

    int n;
    int process_id[10], arrival[10], burst[10], start[10], completion[10], turnaround[10], waiting[10];
    float avg_turnaround, avg_waiting;
    int total_turnaround = 0, total_waiting = 0, is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;
    // taking input for arrival and burst time
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>arrival[i];
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>burst[i];
        process_id[i] = i+1;
        cout<<endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;
    
    while(completed != n) {
        int idx = -1;
        int min_burst = 10000;
        for(int i = 0; i < n; i++) {
            if(arrival[i] <= current_time && is_completed[i] == 0) {
                if(burst[i] < min_burst) {
                    min_burst = burst[i];
                    idx = i;
                }
                if(burst[i] == min_burst) {
                    if(arrival[i] < arrival[idx]) {
                        min_burst = burst[i];
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) {
            start[idx] = current_time;
            completion[idx] = start[idx] + burst[idx];
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            
            total_turnaround += turnaround[idx];
            total_waiting += waiting[idx];

            is_completed[idx] = 1;
            completed++;
            current_time = completion[idx];
            prev = current_time;
        }
        else {
            current_time++;
        }
    }

    avg_turnaround = (float) total_turnaround / n;
    avg_waiting = (float) total_waiting / n;

    //Output
    cout<<endl<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<process_id[i]<<"\t"<<arrival[i]<<"\t"<<burst[i]<<"\t"<<start[i]<<"\t"<<completion[i]<<"\t"<<turnaround[i]<<"\t"<<waiting[i]<<"\t"<<"\n"<<endl;
    }
    
    cout<<"Average Waiting Time = "<<avg_waiting<<endl;
    cout<<"Average Turnaround Time = "<<avg_turnaround<<endl;
}
