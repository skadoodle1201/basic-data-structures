
#include<stdio.h> 
#include<iostream>
#include<stdlib.h> 

using namespace std;

struct node 
{ 
	string type,name;
	int year; 
	struct node *left, *right; 
}; 

struct node *newNode(string N, string T,int Y) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->type = T;
	temp->year = Y; 
	temp->name = N;
	temp->left = temp->right = NULL; 

	return temp; 
}
void printPostorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
	printPostorder(node->left); 
	printPostorder(node->right);
	cout<<node->year<<"  "<<node->name<<" "<<node->type<<endl;  
}  
void printPreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
 	cout<<node->year<<"  "<<node->name<<" "<<node->type<<endl;
	printPreorder(node->left); 
	printPreorder(node->right); 
} 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout<<root->year<<"  "<<root->name<<" "<<root->type<<endl;
		inorder(root->right); 
	} 
} 

struct node* insert(struct node* node,string N, string T,int Y ) 
{ 

	if (node == NULL) return newNode(N,T,Y); 

	if (Y < node->year) 
		node->left = insert(node->left,N,T,Y ); 
	else if (Y > node->year) 
		node->right = insert(node->right,N,T,Y); 

	return node; 
} 
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 

    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->year) 
        root->left = deleteNode(root->left, key); 

    else if (key > root->year) 
        root->right = deleteNode(root->right, key); 
    else
    { 

        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 

        struct node* temp = minValueNode(root->right); 
        root->year = temp->year;  
        root->right = deleteNode(root->right, temp->year); 
    } 
    return root; 
} 
int main() 
{ 
	struct node *root = NULL; 
	root = insert(root, "Cresta","Hatchback",2018); 
	insert(root, "Civic","Sedan",2017); 
	insert(root, "City","Sedan",2016); 
	insert(root, "Compass","SUV",2015); 
	insert(root, "Scorpio","SUV",2014); 
	insert(root, "Wangon R","Hatchback",2013); 
	insert(root, "Rover","Hatchback",2013); 

	cout<<"PREORDER :\n";
	cout<<"YEAR"<<" COMPANY NAME  "<<"TYPE"<<endl;
	printPreorder(root);
	
	cout<<"INORDER : \n";
	cout<<"YEAR"<<" COMPANY NAME  "<<"TYPE"<<endl;
	inorder(root); 

	cout<<"POSTODER: \n";
	cout<<"YEAR"<<" COMPANY NAME  "<<"TYPE"<<endl;
	printPostorder(root);

	int saal;
	cout<<"Enter the Year to delete the data : ";
	cin>>saal;
	deleteNode(root,saal);
	cout<<"YEAR"<<" COMPANY NAME  "<<"TYPE"<<endl;
	printPreorder(root);

	return 0; 
} 
