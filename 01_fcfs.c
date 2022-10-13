//First come first server : Non-preemtive

#include <stdio.h>

struct process{
    int at,bt,ct,tat,wt,rt;
};

int main(){
    int n;
    printf("Enter the number of process: ");
    scanf("%d",&n);

    struct process arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time of %d process: ",i+1);
        scanf("%d %d",&arr[i].at,&arr[i].bt);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].at>arr[j].at){
                struct process temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int j=0;

    for(int i=0;i<n;i++){
        if(j<arr[i].at) j=arr[i].at;

        arr[i].ct = j + arr[i].bt;
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        arr[i].rt = arr[i].wt;
        j=arr[i].ct;
    }

    printf("-----------------------------------------------------\n");
    printf("Arrival time | Burst time | Completion time | TAT | WT | RT\n");
    printf("-----------------------------------------------------\n");

    for(int i=0;i<n;i++){
    printf(" %d           |  %d         |  %d              |  %d |  %d |  %d\n",arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
    }
}