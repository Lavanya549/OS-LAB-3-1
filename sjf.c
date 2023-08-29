#include<stdio.h>
int main(){
	int i,n,wt[20],bt[20],tat[20],p[20],k,temp;
	float wtavg,tatavg;
	printf("Enter the number of process---");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("The bursttime p%d--",i);
		scanf("%d",&bt[i]);
	}
	for(i=1;i<=n;i++){
		for(k=i+1;k<=n;k++){
			if(bt[i]>bt[k]){
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
			}
			temp=p[i];
			p[i]=p[k];
			p[k]=temp;
		}
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
