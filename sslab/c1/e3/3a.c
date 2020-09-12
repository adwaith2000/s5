// Author : DHRUV ELDHO PETER
// Date : 09/09/2020

// FIFO Page Replacement Algorithm

#include<stdio.h>

int memorySize;
int pages;

int q[100], size = 200, front = -1, rear = -1;


//Enquue operation
void enque(int value) {

	if(rear == size-1) {
		printf("Queue Overflow\n");
	}
	else if(front == -1) {
		front = rear = 0;
		q[rear] = value;
	}
	else {
		rear++;
		q[rear] = value;
	}
}

//Dequeue operation
int deque() {
    
	if(front == -1) {
        return -1;
    }
	else if(front == rear) {
        int value = q[front];
		front = rear = -1;
        return value;
	}
	else {
        int value = q[front];
        front++;
        return value;
    }	
}

int getFreeMemoryIndex(int memory[], int n) {

    for(int i = 0; i < n; i++) {
        if(memory[i] == -1) {
            return i;
        }
    }
    return -1;
}

//Function to swap memory
void swapMemory(int memory[], int n, int old, int new) {

    for(int i = 0; i < n; i++) {
        if(memory[i] == old) {
            memory[i] = new;
            break;
        }
    }
}

void getMemoryStatusFIFO(int refString[], int n) {

    int pgTABLE[10];
    int memory[memorySize]; 
    int pageFaults = 0;

    // Set the queue to be empty
    front = -1;
    rear = -1;

    for(int i = 0; i < 8; i++) { 
        pgTABLE[i] = 0; // Initailly none of the process are in memory
    }
    for(int i = 0; i < memorySize; i++) {
        memory[i] = -1; // Set memory to be empty
    }

    printf("------------------FIFO---------------\n");
    printf("Memory Status :\n");

    for(int i = 0; i < n; i++) {
        int currentPage = refString[i];
        if(pgTABLE[currentPage]) {	
        	printf("%d%d%d\t", memory[0], memory[1], memory[2]);
			continue;
        }

        int freeIndex = getFreeMemoryIndex(memory, memorySize);
        if(freeIndex == -1) {
            int oldest = deque();
            swapMemory(memory, memorySize, oldest, currentPage);

            enque(currentPage);
            pgTABLE[oldest] = 0;
            pgTABLE[currentPage] = 1;
        }
        else {
            memory[freeIndex] = currentPage;
            enque(currentPage);

            pgTABLE[currentPage] = 1;
        }
        pageFaults++;

        printf("%d%d%d\t", memory[0], memory[1], memory[2]);
    }

    printf("\nTotal no. of page faults : %d\n", pageFaults);
}



//Main function
int main() {

    int refString[100];
    printf("\nEnter no. of pages: ");
    scanf(" %d",&pages);
    printf("\nEnter page reference string for a process with 8 pages(String is terminated by -1) : ");

    int n = 0;
    while(1) {
        int s;
        scanf("%d", &s);

        if(s == -1) {
            break;
        }

        refString[n++] = s;
    }
    printf("\nEnter no. of frames: ");
    scanf(" %d",&memorySize);
    getMemoryStatusFIFO(refString, n);
}
