#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
	char processName[50];
	int duration;
} process;

typedef struct node *nd;
typedef struct node {
	process proc;
	nd next;
} NODE;


void createQueue(nd*, nd*);
bool isEmpty(nd );
void enqueue(nd *, nd *, process);
process dequeue(nd *, nd *);

process inputProcess();
void timeShare();

int main(void) {
	timeShare();
}

void createQueue (nd *front, nd *rear) {
	*front = NULL;
	*rear = NULL;
}
bool isEmpty(nd rear) {
	return (rear == NULL) ? true : false;
}
void enqueue(nd *front, nd *rear, process input) {
	nd newNode = malloc(sizeof(NODE));
	newNode->proc.duration = input.duration;
	strcpy(newNode->proc.processName, input.processName);
	newNode->next = NULL;
	
	if (*rear != NULL) {
		(*rear)->next = newNode;
		*rear = newNode;
	}
	else {
		*rear = newNode;
		*front = *rear;
	}
}
process dequeue(nd *front, nd *rear) {
	nd temp = *front;
	//returnVal.duration = temp->proc.duration;
	//strcpy(returnVal.processName, temp->proc.processName);
	process returnVal = temp->proc;
	*front = temp->next;
	if (*front == NULL) {
		*rear = NULL;
	}
	free(temp);
	return returnVal;
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
	nd front, rear;
	bool empty = false;
	
	createQueue(&front, &rear);
	for (int i = 0; i < 2; i++) {
		temp = inputProcess();
		enqueue(&front, &rear, temp);
	}
	system("cls");
	
	empty = isEmpty(rear);
	while (!empty) {
		temp = dequeue(&front, &rear);
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
			enqueue(&front, &rear, temp);
		}
		empty = isEmpty(rear);
	}
	
	printf("All processes finished running.\n");
	Sleep(3000);
	return;
}

