//Author: Dhruv Eldho Peter
//Program Number: 1d
//Program Name: Priority Scheduling
//Date: 24/8/20

#include <stdio.h>

struct process
{
	int at,bt,wt,tat,num,rem,prio;
}p[10];


//Find process with highest priority
int findHighPrior(int n,int t){
	int hi,hv;
	for(int i=0;i<n;++i){
		if(p[i].at<=t && p[i].rem!=0){
			hi=i;
			hv=p[i].prio;
			break;
		}
	}
	for(int i=hi;i<n;++i){
		if(p[i].at<=t && p[i].rem!=0){
			if(p[i].prio<hv){
				hv=p[i].prio;
				hi=i;
			}	
		}
	}
	return hi;
}




void main(){
	int i,j,tw=0,tt=0,n,t=0,tot_t=0,hi;
	float awt,atat;
	printf("-------------Priority Scheduling----------\n");
	printf("Number 0 has highest priority\n");
	printf("\nEnter the number of processes: ");
	scanf(" %d",&n);

	//Entering the values
	for ( i = 0; i < n; ++i)
	{
		printf("\nEnter the arrival time, burst time and priority for process %d: ",i);
		scanf(" %d %d %d",&p[i].at,&p[i].bt,&p[i].prio);
		p[i].num=i;
		tot_t+=p[i].bt;
		p[i].rem=p[i].bt;
	}

	//Gantt Chart
	printf("\n\nGantt Chart\n\n");
	printf("0");

	//Finding the waiting time
	while(t<tot_t){
		hi=findHighPrior(n,t);
		p[hi].rem=0;					
		p[hi].wt=t-p[hi].at;
		t+=p[hi].bt;
		printf("\t--P%d--\t%d",hi,t);
	}

    //Finding the turnaround time
    for(i=0;i<n;++i){
    	p[i].tat=p[i].bt+p[i].wt;
    }

    //Finding total waiting and turnaround time
    for(i=0;i<n;++i){
    	tw+=p[i].wt;
    	tt+=p[i].tat;
    }

    //Finding average of waiting and turnaround time
    awt=(float)tw/n;
    atat=(float)tt/n;

    //Printing values
    printf("\n\nProcess  \tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;++i){
    	printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].num,p[i].prio,p[i].at,p[i].bt,p[i].wt,p[i].tat);
    }
    printf("\nAverage waiting time is: %f",awt );
    printf("\nAverage turnaround time is: %f\n",atat );


}