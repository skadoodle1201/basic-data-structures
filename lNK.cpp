#include <iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class node{
    public:
    char name;
    int rollno;
    int age;
    float avg;          
    node* next;
    node(char N, int RN,int A, float AV)
        {   
            name=N;
            rollno=RN;
            age=A;
            avg=AV;
            next= NULL;
        }
};

void insertathead(node*&head,char NA , int RO, int years, float mark)
{
    node*n= new node(NA, RO, years, mark);
    n->next=head;
    head=n;

}
int lenght (node*head)
{
    int len=0;
    while(head!=NULL)
    {
        head = head-> next;
        len +=1;
    }
    return len;
}
void insertattail(node*&head,char NA , int RO, int years, float mark)
{
    if (head == NULL)
    {
        head = new node (NA , RO,years, mark);
        return;
    }
    node*tail = head ;
    while (tail -> next != NULL)
    {
        tail = tail -> next;
    }
    tail->next = new node (NA , RO,years, mark);
}
void insertinmiddle(node*&head,char NA , int RO, int years, float mark, int p )
{
    if (head== NULL|| p==0)
    {
        insertathead(head,NA , RO, years,mark);
    }
    else if (p>lenght(head))
    {
        insertattail(head,NA ,RO,years,mark);
    }
    else 
    {
        int jump=1;
        node*temp= head;
        while(jump<=p-1){
            temp = temp->next;
            jump =jump+1;
        }

        node*n = new node (NA ,RO,years,mark);
        n -> next = temp -> next;
        temp -> next = n;
    }
}
void deleteNode(node*&head, int key) 
{ 
    node* temp = head, *prev; 
  
    if (temp != NULL && temp->rollno == key) 
    { 
        head = temp->next;   
        delete(temp);               
        return; 
    } 
   
    while (temp != NULL && temp->rollno != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
  
    prev->next = temp->next; 
  
    delete(temp);  
}
node* reverse(node*&head) 
    { 
     
        node* current = head; 
        node *prev = NULL, *next = NULL; 
  
        while (current != NULL) 
        { 
                next = current->next; 
                current->next = prev; 
                prev = current; 
                current = next; 
        } 
        head = prev; 
    } 
void printlinkklist(node*head)
{ 
    node*temp=head;
    int i = 1;

    while (temp != NULL) { 
        cout <<i << ": \t"<< temp -> name << " "<<temp -> rollno << " "<<temp -> age <<" "<<temp -> avg<<endl; 
        temp = temp -> next;
        i++; 
    } 
}

int main() 
{
    node*head= NULL;
    int POS=0,NUM;
    char initials;
    int EN,UMAR;
    float AM;
    cout<<"Eneter the no. students: \t";
    cin >> NUM;   

    for(int i=0; i< NUM; i++)
    {   
        cout<<"Enter the initials  of student: \t ";
        cin>> initials;
        cout<<"Enter the rollno of the student: \t";
        cin>> EN;
        cout<< "Enter the age of student: \t";
        cin>>UMAR;
        cout<<"enter the average marks of the student : \t";
        cin>> AM; 
        cout<< "Enter the position on which you want to enter the data of a student :\t  ";
        cin>> POS;
        insertinmiddle(head,initials, EN , UMAR , AM, POS);

    }

    printlinkklist(head);
    
    cout<<"\n\nEnter rollno to delete:";
    cin>>EN;
    
    deleteNode(head,EN);
    printlinkklist(head);
    
    cout<<"\n\nReversing the list : \n\n";
    reverse(head);
    printlinkklist(head);
    return 0;
    getch();
  
}