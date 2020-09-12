//Author: Dhruv Eldho Peter
//Program Number: 1a
//Program Name: FCFS
//Date: 24/8/20

#include<stdio.h>


struct process
{
	int at,bt,wt,tat,num;
}proc[10],temp;

void main()
{
	int i,j,tw=0,tt=0,n;
	float awt,atat;
	printf("-------------FCFS-----------\n");
	printf("Enter the number of processes: ");
	scanf(" %d",&n);

	//Entering the values
	for ( i = 0; i < n; ++i)
	{
		printf("\nEnter the arrival time and burst time for process %d: ",i);	
		scanf(" %d %d",&proc[i].at,&proc[i].bt);
		proc[i].num=i;
	}

	//Sorting according to arrival time 
	for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (proc[j].at > proc[j+1].at){
           		temp=proc[j];
           		proc[j]=proc[j+1];
           		proc[j+1]=temp;
           }

    //Finding waiting time of each
    proc[0].wt=0;
    int s=0;
    for(i=1;i<n;++i){
    	s+=proc[i-1].bt;
    	proc[i].wt=s-proc[i].at;
    }

    //Finding turnaround time
    for(i = 0; i<n; i++){
    	proc[i].tat=proc[i].wt+proc[i].bt;
    }


    //Finding total waiting and turnaround time
    for(i=0;i<n;++i){
    	tw+=proc[i].wt;
    	tt+=proc[i].tat;
    }

    //Finding average of waiting and turnaround time
    awt=(float)tw/n;
    atat=(float)tt/n;


    //Gantt Chart
    int t=0;
    printf("\n\nGantt Chart\n\n");
    printf("0");
    for(i=0;i<n;++i){
    	t=t+proc[i].bt;
    	printf("\t--P%d--\t%d",proc[i].num,t);
    }



    //Printing values
   	printf("\n\nProcess  \tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;++i){
    	printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",proc[i].num,proc[i].at,proc[i].bt,proc[i].wt,proc[i].tat);
    }
    printf("\nAverage waiting time is: %f",awt );
    printf("\nAverage turnaround time is: %f\n",atat );
}