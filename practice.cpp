



//---------------------------------------------------------------
/*
//Banker's
#include <iostream>
using namespace std;
const int max_pro=10;
const int max_res=10;

int main(){
	int n, m;  //process and resource
	int max[max_pro][max_res];
	int avail[max_res];
	int need[max_pro][max_res];
	int alloc[max_pro][max_res];
	
	cout<< "enter process:"<<endl;
	cin>>n;
	cout<< "enter resources:"<<endl;
	cin>>m;
	
	cout<<"enter max values"<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0;j<m; j++) {
			cin>>max[i][j];
		}
	}
	
	cout<<"enter alloc values"<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0;j<m; j++) {
			cin>>alloc[i][j];
		}
	}

	cout<<"enter avail values"<<endl;
	for(int i=0; i<m; i++) {
		cin>>avail[i];
	}
	
	cout<<"need"<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0;j<m; j++) {
			need[i][j]=max[i][j]-alloc[i][j];
			cout<<need[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

*/
//----------------------------------------
/*
//FCFS
#include <iostream>
using namespace std;

int main() {
	int n, i;
	int time=0, waiting[10], arrival[10], burst[10], turnaround[10],completion[10];
	float avg_wait=0, avg_turn=0;
	int choice;
	
	cout<< "enter process:";
	cin>> n;
	cout<<"choose";
	cout<<"1 for arrival =0";
	cout<< "2for arrival different";
	cin>>choice;
	switch(choice){
		case 1:
			for(i=0;i< n; i++) {
				arrival[i]=0;
				cout<<"enter burst"<<i+1<<":"<<endl;
				cin>>burst[i];
			}
			break;
		case 2:
			for(i=0; i<n; i++) {
				cout<<"arrival"<<i+1<<":"<<endl;
				cin>>arrival[i];
				cout<<"burst"<<i+1<<":"<<endl;
				cin>>burst[i];
			}
			break;
		default:
			cout<<"invalid";
			return 0;
	}
	
	for(i=0;i<n; i++) {
		if(time<arrival[i]) {
			time=arrival[i];
		}
		time=time+burst[i];
		turnaround[i]=time-arrival[i];
		waiting[i]=turnaround[i]-burst[i];
		completion[i]=time;
	}
	
	cout<<"process\tat\tbt\twt\ttt\tct"<<endl;
	for (i=0;i<n;i++) {
		cout<<"p"<<i+1<<"\t"<<arrival[i]<<"\t"<<burst[i]<<"\t"<<waiting[i]<<"\t"<<turnaround[i]<<"\t"<<completion[i]<<endl;	
	}
	
	for(i=0;i<n;i++) {
		avg_wait += waiting[i];
		avg_turn += turnaround[i];
	}
	avg_wait /=n;
	avg_turn /=n;
	
	cout<<"average wat"<<avg_wait<<endl;
	cout<<"average wat"<<avg_turn<<endl;
	
	return 0;
}

*/
