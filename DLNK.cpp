#include <iostream>
#include <stdio.h>
#include <conio.h> 
using namespace std; 
class Node 
{ 
	public: 
	int empcode,salary;
	char name; 
	Node* next; 
	Node* prev; 
}; 

void push(Node*&head,char Ename,int code,int sal) 
{ 
	
	Node* new_node = new Node(); 
	new_node->name = Ename;
	new_node->empcode = code;
	new_node->salary = sal; 
	new_node->next = head; 
	new_node->prev = NULL; 
	if (head != NULL) 
		head->prev = new_node; 
	head= new_node; 
} 
void insertAfter(Node* prev_node, char Ename,int code,int sal) 
{ 
	if (prev_node == NULL) 
	{ 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 

	Node* new_node = new Node(); 
	new_node->name = Ename;
	new_node->empcode = code;
	new_node->salary = sal;
	new_node->next = prev_node->next; 
	prev_node->next = new_node; 
	new_node->prev = prev_node; 
	if (new_node->next != NULL) 
		new_node->next->prev = new_node; 
} 
void append(Node*&head, char Ename,int code,int sal) 
{ 
	Node* new_node = new Node(); 

	Node* last = head; 
	new_node->name = Ename;
	new_node->empcode = code;
	new_node->salary = sal;
	new_node->next = NULL; 
	if (head == NULL) 
	{ 
		new_node->prev = NULL; 
		head = new_node; 
		return; 
	} 
	while (last->next != NULL) 
		last = last->next; 
	last->next = new_node; 
	new_node->prev = last; 

	return; 
} 
void deleteNode(Node*&head, Node* del)  
{  
    if (head == NULL || del == NULL)  
        return;  
  
    if (head == del)  
        head = del->next;  
  
    if (del->next != NULL)  
        del->next->prev = del->prev;  

    if (del->prev != NULL)  
        del->prev->next = del->next;  
  
    delete del;  
    return;  
} 
void deleteNodeAtGivenPos(Node*head, int n) 
{ 
    if (head == NULL || n <= 0) 
        return; 
  
    Node* current = head; 
    int i; 
    for (int i = 1; current != NULL && i < n; i++) 
        current = current->next; 
    if (current == NULL) 
        return; 
    deleteNode(head, current); 
}  
 
void printList(Node*node) 
{ 
	Node* last; 
	cout<<"\nTraversal in forward direction \n"; 
	cout<<" NAME"<<" CODE"<<" SALARY"<<endl;
	while (node != NULL) 
	{ 
		cout<<" "<<node->name<<" 	"<<node->empcode<<" "<<node->salary<<" "<<endl; 
		last = node; 
		node = node->next; 
	} 

	cout<<"\nTraversal in reverse direction \n"; 
	cout<<" NAME"<<" CODE"<<" SALARY"<<endl;
	while (last != NULL) 
	{ 
		cout<<" "<<last->name<<" 	"<<last->empcode<<" "<<last->salary<<endl; 
		last = last->prev; 
	} 
} 
int main() 
{ 
	
	Node* head = NULL; 
	append(head,'A',6,55555); 
	push(head,'B',7,8888); 
	push(head,'C',1,7777); 
	append(head,'D',4,8989); 
	insertAfter(head->next,'E',8,5656); 
	
	cout << "Created DLL is: "; 
	
	printList(head);
	cout<<"\nDeletion in the end:";  
	deleteNodeAtGivenPos(head,5);
	cout << "\nModified Linked list ";  
    printList(head);  
	return 0; 
} 


