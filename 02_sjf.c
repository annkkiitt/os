//shortest job first
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process{
    int p,at,bt,ct,tat,wt,rt;
};

int main(){
    int n,sum_tat;

    printf("Enter the number of process: ");
    scanf("%d",&n);

    struct process arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time of %d process: ",i+1);
        scanf("%d %d",&arr[i].at,&arr[i].bt);
        arr[i].p = i+1;
    }

    bool isCompleted[100] = {false};
    int current_time=0,completed=0;

    while(completed !=n){
        int min_index=-1;
        int minimum = INT_MAX;

        for(int i=0;i<n;i++){
            if(arr[i].at <= current_time && isCompleted[i]==false){
                if(arr[i].bt < minimum){
                    minimum = arr[i].bt;
                    min_index=i;
                }

                if(arr[i].bt == minimum){
                    if(arr[i].at < arr[min_index].at){
                        minimum = arr[i].bt;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index==-1){
            current_time++;
        }
        else{
            arr[min_index].ct = current_time + arr[min_index].bt;
            arr[min_index].tat = arr[min_index].ct - arr[min_index].at;
            arr[min_index].wt = arr[min_index].tat - arr[min_index].bt;
            arr[min_index].rt = arr[min_index].wt;


            completed++;
            current_time = arr[min_index].ct;
            isCompleted[min_index] = true;
        }

    }

    printf("\nProcess no\tAt\tBT\tCt\tTat\tWt\tRT\t\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].p,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
    }

}