//Author: Dhruv Eldho Peter
//Program Number: 1c
//Program Name: Round Robin
//Date: 24/8/20
#include <stdio.h>

struct process
{
	int at,bt,wt,tat,num,rem_bt;
}p[10],temp;



//Finding process to be given cpu time
int findProc(int previ,int n, int t){
	int i;
	if(previ== n-1){
		previ=-1;
	}
	for(i=previ+1;i<n;++i){
		if(p[i].at<=t && p[i].rem_bt!=0){
			return i;
		}

		if(i== n-1){
			i=-1;
		}
	}
}

void main(){
	int i,j,tw=0,tt=0,n,tq,t=0,tot_t=0,pres_i=-1;
	float awt,atat;
	printf("-------------Round Robin-----------\n");
	printf("\nEnter the number of processes: ");
	scanf(" %d",&n);

	//Entering the values
	for ( i = 0; i < n; ++i)
	{
		printf("\nEnter the arrival time and burst time for process %d: ",i);
		scanf(" %d %d",&p[i].at,&p[i].bt);
		p[i].num=i;
		p[i].rem_bt=p[i].bt;
		tot_t+=p[i].bt;
	}
	printf("\nEnter the time quantum: ");
	scanf(" %d",&tq);

	
	//Sorting according to arrival time 
	for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (p[j].at > p[j+1].at){
           		temp=p[j];
           		p[j]=p[j+1];
           		p[j+1]=temp;
           }


    //Gantt Chart
    printf("\n\nGantt Chart\n\n");
    printf("0");

	//Finding the waiting time of each process
	while(t<tot_t){
		pres_i=findProc(pres_i,n,t);
		if(p[pres_i].rem_bt>tq){
			t=t+tq;
			p[pres_i].rem_bt=p[pres_i].rem_bt-tq;
			printf("\t--P%d--\t%d",p[pres_i].num,t );
		}
		else{
			t=t+p[pres_i].rem_bt;
			p[pres_i].wt=t-p[pres_i].bt-p[pres_i].at;
			p[pres_i].rem_bt=0;
			printf("\t--P%d--\t%d",p[pres_i].num,t );
		}
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
    printf("\n\nProcess  \tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;++i){
    	printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].num,p[i].at,p[i].bt,p[i].wt,p[i].tat);
    }
    printf("\nAverage waiting time is: %f",awt );
    printf("\nAverage turnaround time is: %f\n",atat );

}