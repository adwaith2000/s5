//Author: Dhruv Eldho Peter
//Program Number: 1b
//Program Name: SJF
//Date: 24/8/20

#include <stdio.h>

struct process
{
	int at,bt,wt,tat,num,rem;
}p[10];


//Find process with smallest burst time
int findSmallBt(int n,int t){
	int smallv,smalli;
	for(int i=0;i<n;++i){
		if(p[i].at<=t && p[i].rem!=0){
			smalli=i;
			smallv=p[i].bt;
			break;
		}
	}
	for(int i=smalli;i<n;++i){
		if(p[i].at<=t && p[i].rem!=0){
			if(p[i].bt<smallv){
				smallv=p[i].bt;
				smalli=i;
			}	
		}
	}
	return smalli;
}




void main(){
	int i,j,tw=0,tt=0,n,t=0,tot_t=0,smalli;
	float awt,atat;
	printf("-------------SJF--------------\n");
	printf("Enter the number of processes: ");
	scanf(" %d",&n);

	//Entering the values
	for ( i = 0; i < n; ++i)
	{
		printf("\nEnter the arrival time and burst time for process %d: ",i);
		scanf(" %d %d",&p[i].at,&p[i].bt);
		p[i].num=i;
		tot_t+=p[i].bt;
		p[i].rem=p[i].bt;
	}



	printf("\n\nGantt Chart\n\n");
	printf("0");

	//Finding the waiting time
	while(t<tot_t){
		smalli=findSmallBt(n,t);
		p[smalli].rem=0;					
		p[smalli].wt=t-p[smalli].at;
		t+=p[smalli].bt;
		printf("\t--P%d--\t%d",p[smalli].num,t);
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