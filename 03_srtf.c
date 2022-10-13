#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process{
    int p,at,bt,ct,wt,rt,tat,start_time;
};

int main(){
    int n;
    bool isCompleted[100] = {false};
    printf("Enter the number of process ");
    scanf("%d",&n);

    struct process arr[n];
    int bt_remaining[n];

    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time of %d prcess ",i+1);
        scanf("%d %d",&arr[i].at,&arr[i].bt);
        bt_remaining[i] = arr[i].bt;
        arr[i].p = i+1;
    }

    int completed=0;
    int current_time=0;

    while(completed!=n){
        //find min
        int min_index=-1;
        int minimum = INT_MAX;

        for(int i=0;i<n;i++){
            if(arr[i].at <= current_time && isCompleted[i]==false){
                if(bt_remaining[i] < minimum){
                    minimum = bt_remaining[i];
                    min_index = i;
                }

                if(bt_remaining[i] == minimum){
                    if(arr[i].at < arr[min_index].at){
                        minimum = bt_remaining[i];
                        min_index=i;
                    }
                }
            }
        }

        if(min_index==-1){
            current_time++;
        }

        else{
            if(bt_remaining[min_index] == arr[min_index].bt){
                arr[min_index].start_time = current_time;
            }
            bt_remaining[min_index] -=1;
            current_time++;
            if(bt_remaining[min_index]==0){
                arr[min_index].ct = current_time;
                arr[min_index].tat = arr[min_index].ct-arr[min_index].at;
                arr[min_index].wt = arr[min_index].tat - arr[min_index].bt;
                arr[min_index].rt = arr[min_index].start_time - arr[min_index].at;

                isCompleted[min_index] = true;
                completed++;

            }
        }
    }

    printf("\nProcess\tAt\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].p,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
    }
}