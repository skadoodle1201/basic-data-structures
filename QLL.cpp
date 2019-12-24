#include <iostream>
#include <stdio.h>

using namespace std; 
class QNode { 
public: 
	int key; 
	QNode* next; 
}; 
class Queue { 
public: 
	QNode *front=NULL, *rear=NULL; 
}; 
QNode* newNode(int k) 
{ 
	QNode* temp = new QNode(); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 
Queue* createQueue() 
{ 
	Queue* q = new Queue(); 
	q->front = q->rear = NULL; 
	return q; 
} 
void enQueue(Queue* q, int k) 
{ 
	QNode* temp = newNode(k); 
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		cout<<"Enqueued item is :"<<temp->key<<endl;
		return; 
	}
	q->rear->next = temp; 
	q->rear = temp;
	cout<<"Enqueued item is :"<<temp->key<<endl; 
} 

QNode* deQueue(Queue* q) 
{  
	if (q->front == NULL) 
		return NULL; 
	else 
		{
			QNode* temp = q->front;
			q->front = q->front->next; 
			if (q->front == NULL) 
				q->rear = NULL; 
			return temp;  
		delete(temp); 
		} 
}
void display(Queue* &q)
{
   if(q->front == NULL)
      printf("\nQueue is Empty!!!\n");
   else
   {
       	QNode *temp = q->front;
       	QNode *N=temp;
      while(temp->next != NULL)	
      	{
      		N=temp;
	 		printf("%d--->",N->key);
	 		temp = temp -> next;
      	}
      N=temp;	
      printf("%d--->NULL\n",N->key);
   }
}
int main() { 
	Queue* q = createQueue(); 
	QNode* n;
	enQueue(q, 10); 
	enQueue(q, 20);
	display(q); 
	n = deQueue(q); 
	if (n != NULL) 
		cout << "Dequeued item is " << n->key<<endl;
	n = deQueue(q); 
	if (n != NULL) 
		cout << "Dequeued item is " << n->key<<endl; 
	display(q);
	enQueue(q, 30);
	enQueue(q, 40); 
	enQueue(q, 50);
	display(q); 
	n = deQueue(q); 
	if (n != NULL) 
		cout << "Dequeued item is " << n->key<<endl; 
	display(q);
	return 0;
} 
