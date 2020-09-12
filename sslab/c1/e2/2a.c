// Author : Dhruv Eldho Peter
// Date : 08/09/2020
// FCFS Disk Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>

//Function to print head movement
void printhdpointer(int rQueue[], int n, int hdPointer) {

    int seektime = 0;
    int curPointer = hdPointer;

    printf("--------------FCFS----------------\n");
    printf("Header Movement : %d", hdPointer);

    for(int i = 0; i < n; i++) {
        int nextPointer = rQueue[i];
        printf(" -> %d", nextPointer);

        seektime += abs(nextPointer - curPointer);
        curPointer = nextPointer;
    }

    printf("\nTotal Seak Time: %d\n", seektime);

}

void main() {
    int rQueue[100];
    int n = 0; 
    int hdPointer;

    printf("\nEnter the request sequence(Sequence is terminated by -1) : ");

    while(1) {
        int r;
        scanf("%d", &r);

        if(r== -1) {
            break;
        }

        rQueue[n++] = r;
    }

    printf("Enter the initial head pointer : ");
    scanf("%d", &hdPointer);

    printhdpointer(rQueue, n, hdPointer);
}

