#include<stdio.h>
main(){
	int bt[20],wt[20],tat[20],i,n;
	float tatavg,wtavg;
	printf("\n Enter the number of process----  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter BURST TIME for p%d----",i);
		scanf("%d",&bt[i]);
	}
	wt[1]=wtavg=0;
	tat[1]=tatavg=bt[1];
	for(i=2;i<=n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\nProcess\tBurstTime\tWaiting time\tTurnaround Time\n");
	for(i=1;i<=n;i++){
		printf("p%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time--%f\n",wtavg/n);
	printf("Average turnaround time--%f",tatavg/n);
}
