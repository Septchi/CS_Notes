#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define size 10

typedef struct {
	char processName[50];
	int duration;
} process;

typedef struct {
	process proc[size];
	int front;
	int rear;
} queue;

void createQueue(queue *);
bool isEmpty(int, int);
bool isFull(int, int);
void enqueue(queue *, process);
process dequeue(queue *);

process inputProcess();
void timeShare();

int main(void) {
	timeShare();
}

void createQueue (queue *q) {
	for (int i = 0; i < size; i++) {
		strcpy(q->proc[i].processName, "");
		q->proc[i].duration = 0;
	}
	q->front = q->rear = 0;
}
bool isEmpty(int front, int rear) {
	return (front == rear) ? true : false;
}
bool isFull(int front, int rear) {
	return (front == ((rear+1)%size)) ? true : false;
}
void enqueue(queue *q, process input) {
	q->proc[q->rear].duration = input.duration;
	strcpy(q->proc[q->rear].processName, input.processName);
	q->rear = (q->rear + 1) % size;
}
process dequeue(queue *q) {
	process temp;
	temp.duration = q->proc[q->front].duration;
	strcpy(temp.processName, q->proc[q->front].processName);
	q->front = (q->front + 1) % size;
	return temp;
}

process inputProcess() {
	process userInput;
	printf("Enter process name: ");
	gets(userInput.processName);
	fflush(stdin);
	printf("Enter process duration: ");
	scanf("%d", &userInput.duration);
	fflush(stdin);
	printf("\n");
	return userInput;
}

void timeShare() {
	process temp;
	bool full, empty;
	queue procQ;
	
	createQueue(&procQ);
	while (!(isFull(procQ.front, procQ.rear))) {
		temp = inputProcess();
		enqueue(&procQ, temp);
	}
	
	system("cls");
	while (!(isEmpty(procQ.front, procQ.rear))) {
		temp = dequeue(&procQ);
		printf("Processing %s...\n", temp.processName);
		Sleep((temp.duration <= 10) ? temp.duration * 1000 : 10000);
		temp.duration = (temp.duration <= 10) ? 0 : temp.duration - 10;
		
		if  (temp.duration == 0) {
			printf("Process %s is finished!\n", temp.processName);
			Sleep(1000);
		}
		else {
			printf("Process %s is being requeued. Time remaining: %d\n", temp.processName, temp.duration);
			Sleep(1000);
			if (!(isFull(procQ.front, procQ.rear)))
				enqueue(&procQ, temp);
			else {
				printf("Error: Queue is already full.\n");
				Sleep(2000);
				return;
			}
		}
	}
	
	printf("All processes finished running.\n");
	Sleep(3000);
	return;
}

