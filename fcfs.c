#include<stdio.h>
void findWaitingTime(int n,int bt[], int wt[]){
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1];
}

void findTurnAroundTime( int n,int bt[], int wt[], int tat[]){
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(n, bt, wt);
    findTurnAroundTime(n, bt, wt, tat);
    printf("P   BT   WT   TAT\n");
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d   %d    %d   %d\n",(i+1),bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time = %f\n",(float)total_wt / (float)n);
    printf("Average turn around time = %f ",(float)total_tat / (float)n);
}
int main()
{
    int processes[] = { 1, 2, 3};
    int n = 3;
    int  burst_time[] = {10, 5, 8};
    findavgTime(processes, n,  burst_time);
    return 0;
}

