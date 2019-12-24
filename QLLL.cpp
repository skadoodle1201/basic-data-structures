#include <stdio.h> 
#include <stdlib.h> 

struct QNode { 
	int key; 
	struct QNode* next; 
}; 

struct Queue { 
	struct QNode *front, *rear; 
}; 

struct QNode* newNode(int k) 
{ 
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 

struct Queue* createQueue() 
{ 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 


void enQueue(struct Queue* q, int k) 
{ 

	struct QNode* temp = newNode(k); 

	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 

	q->rear->next = temp; 
	q->rear = temp; 
} 

struct QNode* deQueue(struct Queue* q) 
{ 
	if (q->front == NULL) 
		return NULL;  
	else 
		{
			struct QNode* temp = q->front; 
			q->front = q->front->next; 
			if (q->front == NULL) 
				q->rear = NULL; 
			return temp;
			free(temp); 
		}
	q->front = q->front->next; 
}
void Display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
} 

int main() 
{ 
	struct Queue* q = createQueue(); 
	struct QNode* n; 
	enQueue(q, 10); 
	enQueue(q, 20); 
	
	n = deQueue(q);
	if (n != NULL) 
		printf("Dequeued item is %d", n->key); 
	n = deQueue(q); 
	if (n != NULL) 
		printf("Dequeued item is %d", n->key);
	enQueue(q, 30); 
	enQueue(q, 40); 
	enQueue(q, 50); 
	n = deQueue(q); 
	if (n != NULL) 
		printf("Dequeued item is %d", n->key); 
	return 0; 
} 
