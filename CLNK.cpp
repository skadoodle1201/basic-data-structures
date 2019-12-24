#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std; 

class node
{ 
	public:
	char colname;
	int colID,regno,nobranchs; 
	node*next;
	node (char clname,int clID,int regn,int nobranch)
	{
		this->colname = clname;
		this->colID = clID;
		this->regno = regn;
		this->nobranchs = nobranch;
	} 
}; 

void push(node *&head,char colname,int colID,int regno,int nobranchs ) 
{  
	node *ptr1= new node (colname,colID,regno,nobranchs);
    node *temp = head;   
    ptr1->next = head;  
    if (head != NULL)  
    {  
        while (temp->next != head)  
            temp = temp->next;  

        temp->next = ptr1;  
    }  
    else
        ptr1->next = ptr1;
  
    head = ptr1;  
}  
void deleteNode(node *head, int key)  
{
    if (head == NULL) 
        return; 
          
    if(head->colID==key && head->next==head) 
    { 
        delete (head); 
        head=NULL; 
    } 
      
    node *last=head,*d; 
  
    if(head->colID==key) { 
          
        while(last->next!=head) 
            last=last->next; 

        last->next=(head)->next; 
        delete (head); 
        head=last->next; 
    } 

    while(last->next!=head && last->next->colID!=key) { 
        last=last->next; 
    }
    if(last->next->colID==key) { 
        d=last->next; 
        last->next=d->next; 
        delete (d); 
    } 
    else
        cout<<"no such keyfound"; 
} 

void traverse(node*head) 
{ 
	node*p= head;
	cout<<"COLLEGE NAME"<<" COLLEGE ID"<<" COLLEGE REG NO."<<" NO. OF BRANCHES \n";
	while(p->next != head)
	{
		cout<<p->colname<<"\t\t "<<p->colID<<"\t\t "<<p->regno<<"\t\t "<<p->nobranchs<<endl;
		p=p->next;
	}
	cout<<p->colname<<"\t\t "<<p->colID<<"\t\t "<<p->regno<<"\t\t "<<p->nobranchs<<endl<<"END!!!!";

}  
int main() 
{ 
	node*head = NULL; 
	int ID;

	push(head,'H',1,401,6);
	push(head,'M',2,402,6);
	push(head,'R',3,403,6);
	push(head,'I',4,404,6);
	push(head,'T',5,405,6);
	push(head,'M',6,406,6);
	traverse(head); 
	cout<<"\nEnter the COLLEGE ID to delete the record: ";
	cin>>ID;
	deleteNode(head,ID);
	cout<<"\nAfter delete a node: \n";
	traverse(head);


	return 0; 
} 
