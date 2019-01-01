#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int priorty;
	int id; // id
	struct Node *pre;
	struct Node *next;
}Node;

Node *Queue_push(Node *Queue, int cid, int p);
Node *Queue_pop(Node *Queue, int command);

Node *Q = NULL;
Node *tail = NULL;

int main(){
	int K; // identifier
	int P; // priority
	int command; // input : 0, 1 K P, 2, 3
	int minimum = 10000001, maximum = -1; // max, min of priority
	
	while(scanf("%d", &command)){
		// stop serving
		if(command == 0) break;
		
		// Add client K to the waiting list with priority P
		else if(command == 1){
			scanf("%d%d", &K, &P);
			if(K > 1000000 || P > 10000000) return;
			Q = Queue_push(Q, K, P);
		}
		// print and Serve the highest priority client and drop from the waiting list
		else if(command == 2) Q = Queue_pop(Q, command);
		// print and Serve the lowest priority client and drop from the waiting list
		else if(command == 3) Q = Queue_pop(Q, command);
		else return;
	}
	return 0;
}

Node *Queue_push(Node *Queue, int cid, int p){
	// cid: client id, p : priority
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->priorty = p;
	newNode->id = cid;
	newNode->pre = NULL;
	newNode->next = NULL;
	
	/* case 1: insert the first node */
	
	// this is first node
	if(Queue == NULL){
		Queue = newNode;
		tail = Queue;
		return Queue;
	}
	
	// insert the first node (priority is the smallest.)
	if(p < Queue->priorty){
		Queue->pre = newNode;
		newNode->next = Queue;
		Queue = Queue->pre;
		return Queue;
	}

	/* case 2 : insert not first node */
	Node *curr = Queue;
	while(curr->next != NULL){
		if(p > curr->priorty) curr = curr->next;
		else break;
	}
	
	// insert the last node (priority is the biggest.)
	if(curr->next == NULL && curr->priorty < p){
		tail->next = newNode;
		newNode->pre = tail;
		tail = newNode;
	}
	// insert the internal list
	else{
		newNode->next = curr;
		newNode->pre = curr->pre;
		curr->pre = newNode;
		newNode->pre->next = newNode;
	}
	return Queue;
}

Node *Queue_pop(Node *Queue, int command){
	if(Queue == NULL){
		printf("0\n");
		return 0; // empty
	}
	
	Node *temp = NULL;
	if(command == 2){
		printf("%d\n", tail->id);
		temp = tail;
		if(tail->pre != NULL){
			tail = tail->pre;
			tail->next = NULL;
		}
		else Queue = tail = NULL;
	}
	else if(command == 3){
		printf("%d\n", Queue->id);
		temp = Queue;
		if(Queue->next != NULL){
			Queue = Queue->next;
			Queue->pre = NULL;
		}
		else tail = Queue = NULL;
	}
	free(temp);
	return Queue;
}
