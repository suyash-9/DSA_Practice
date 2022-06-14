#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
using namespace std;

int main() {

    int n=4;
    int pid[n]={1,2,3,4};
    int arrival_time[n]={0,1,2,4};
    int burst_time[n]={5,3,4,1};
    int start_time[n];
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];
    int response_time[n];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;


    for(int i = 0; i < n; i++) {
        burst_remaining[i] = burst_time[i];
        cout<<endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idn = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(arrival_time[i] <= current_time && is_completed[i] == 0) {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idn = i;
                }
                if(burst_remaining[i] == mn) {
                    if(arrival_time[i] < arrival_time[idn]) {
                        mn = burst_remaining[i];
                        idn = i;
                    }
                }
            }
        }

        if(idn != -1) {
            if(burst_remaining[idn] == burst_time[idn]) {
                start_time[idn] = current_time;
                total_idle_time += start_time[idn] - prev;
            }
            burst_remaining[idn] -= 1;
            current_time++;
            prev = current_time;
            
            if(burst_remaining[idn] == 0) {
                completion_time[idn] = current_time;
                turnaround_time[idn] = completion_time[idn] - arrival_time[idn];
                waiting_time[idn] = turnaround_time[idn] - burst_time[idn];
                response_time[idn] = start_time[idn] - arrival_time[idn];

                total_turnaround_time += turnaround_time[idn];
                total_waiting_time += waiting_time[idn];
                total_response_time += response_time[idn];

                is_completed[idn] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
    }

    int min_arrival_time = 10000000;
    int man_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,arrival_time[i]);
        man_completion_time = max(man_completion_time,completion_time[i]);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
  

    cout<<"ProcessId   ArrivalTime    BurstTime    Completiontime    TurnAroundTime    WaitingTime    ResponseTime\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<pid[i]<<"\t \t"<<arrival_time[i]<<"\t \t"<<burst_time[i]<<"\t \t"<<completion_time[i]<<"\t \t"<<turnaround_time[i]<<"\t \t"<<waiting_time[i]<<"\t \t"<<response_time[i]<<"\t \t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;


  return 0;
}
