#include<stdio.h>
int n=4;
int min(int a,int b){
    if(a<b){
        return a;
    }
    else return b;
}

int max(int a,int b){
    if(a<b){
        return b;
    }
    else return a;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return ;
}


int main(){
    int pid[4]={1,2,3,4};
    int arrival_time[4]={1,2,1,4};
    int burst_time[4]={3,4,2,4};
    int completion_time[n];
    int turn_time[n];
    int wait_time[n];
    int response_time[n];
    int start_time[n];
    int isCompleted[5]={0,0,0,0,0};

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arrival_time[i]>arrival_time[j]){
                int temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;
                
                int temp2=burst_time[i];
                 burst_time[i]=burst_time[j];
                burst_time[j]=temp2;
                
                int temp3=pid[i];
                 pid[i]=pid[j];
                pid[j]=temp3;
            }
        }
    }

    int completed=0;
    int currtime=0;
    int prev=0;
    while(completed!=n){
        int idx=-1;
        int mn=10000000;
        for(int i=0;i<n;i++){
            if(arrival_time[i]<=currtime && isCompleted[i]==0){
                start_time[i]=currtime;
                if(burst_time[i]<mn){
                    mn=burst_time[i];
                    idx=i;
                }
                if(burst_time[i]==mn){
                    if(arrival_time[i]<arrival_time[idx]){
                        idx=i;
                        mn=burst_time[i];
                    }
                }
            
            }
        }
        if(idx!=-1){
            start_time[idx]=currtime;
            completion_time[idx]=start_time[idx]+burst_time[idx];
            turn_time[idx]=completion_time[idx]-arrival_time[idx];
            wait_time[idx]=turn_time[idx]-burst_time[idx];
            response_time[idx]=start_time[idx]-arrival_time[idx];

            isCompleted[idx]=1;
            completed++;
            currtime=completion_time[idx];
            prev=currtime;

        }
        else{
            currtime++;
        }
    }

     printf("ProcessId  ArrivalTime  BurstTime  Completiontime  TurnAroundTime  WaitingTime  ResponseTime\n");
    for(int i=0;i<n;i++){
        printf(" %d             %d              %d           %d             %d              %d          %d \n",pid[i],arrival_time[i],burst_time[i],completion_time[i],turn_time[i],wait_time[i],response_time[i]);
    }

    float average_wait_time=0,average_turn_time=0;
    for(int i=0;i<n;i++){
        average_wait_time+=wait_time[i];
    }
    average_wait_time=average_wait_time/n;
    
    for(int i=0;i<n;i++){
        average_turn_time+=turn_time[i];
    }
    average_turn_time=average_turn_time/n;
    
    printf(" \n \n");
    printf(" The average waiting time is : %f\n",average_wait_time);
    printf(" The average turn around time is : %f",average_turn_time);






    return 0;
}