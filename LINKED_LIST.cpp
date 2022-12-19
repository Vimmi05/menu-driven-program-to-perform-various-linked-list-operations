#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};struct node *head=NULL, *ptr;

void insert_begin(int value){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if (head== NULL){
		head=temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
}
void insert_end(int value){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if (head== NULL){
		head=temp;
	}
	else{
		ptr=head;
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=NULL;
	}
}
void insert_after(int value,int ele){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if (head== NULL){
		head=temp;
	}
	else{
		ptr=head;
		while(ptr->data!= ele){
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}	
}

void build(struct node** head, int data)//function to build linked list
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

int sort(){
	struct node *ptr, *s;
	int value;
	if (head == NULL){
		cout<<"The List is empty"<<endl;
	}
	ptr = head;
	while (ptr != NULL){
		for (s = ptr->next;s !=NULL;s = s->next){
		if (ptr->data > s->data){
			value = ptr->data;
			ptr->data = s->data;
			s->data = value;
			}
		}
		ptr = ptr->next;
	}
}
struct node* newNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insert_sort(node** head, node* newNode){
	if (*head == NULL || (*head)->data >= newNode->data){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	struct node* current = *head;
	while (current->next != NULL && current->next->data < newNode->data)
		current = current->next;
	newNode->next = current->next;
	current->next = newNode;
}
void delete_begin(){
	if (head== NULL){
		cout<<"List is Empty, Deletion is not Possible!!!";
	}
	else{
		ptr=head;
		head=head->next;
		ptr->next=NULL;
		free(ptr);
	}
}
void delete_end(){
	if (head== NULL){
		cout<<"List is Empty, Deletion is not Possible!!!";
	}
	else{
		struct node *p; 
		ptr=head;
		while(ptr->next!= NULL){
		p=ptr;
		ptr=ptr->next;	
		}
		p->next=NULL;
		free(ptr);
	}
}
void delete_spec(int ele){
	if (head== NULL){
		cout<<"List is Empty, Deletion is not Possible!!!";
	}
	else{
		struct node *p; 
		ptr=head;
		while(ptr->data!= ele){
			p=ptr;
			ptr=ptr->next;
		}
		p->next=ptr->next;
		free(ptr);
	}
}
void search(){
	int value, pos = 0;
	bool flag = false;
	if (head == NULL){
		cout<<"List is empty!!!"<<endl;
		return;
		}
	node *s;
	s = head;
	while (s!= NULL){
		pos++;
	if (s->data==value){
		flag = true;
		cout<<"Element "<<value<<" is present at position "<<pos<<endl;
		}
		s = s->next;
	}
	if (!flag)
		cout<<"Element "<<value<<" is not present in the list."<<endl;  
}
void display(){
	if (head== NULL){
		cout<<"List is Empty."<<endl;
	}
	else{
		ptr=head;
		cout<<"Linked List : ";
		while( ptr != NULL){
			cout<<ptr->data<<"-->";
			ptr=ptr->next;
		}
		cout<<"Null "<<endl;
	}
}

int main(){
	int value,ele,ch;
	node* head=NULL;
	cout<<"MAIN MENU OF THE PROGRAM - "<<endl;
	cout<<"1.Insertion in the beginning of the Linked List."<<endl;
	cout<<"2.Insertion in the end of the Linked List."<<endl;
	cout<<"3.Insertion after the specified element in the Linked List."<<endl;
	cout<<"4.Insertion in the sorted Linked List."<<endl;
	cout<<"5.Deletion from the beginning of the Linked List."<<endl;
	cout<<"6.Deletion from the end of the Linked List."<<endl;
	cout<<"7.Deletion of a specific element from the Linked list."<<endl;
	cout<<"8.Search a specific element in the Linked List."<<endl;
	cout<<"9.Display the elements of the Linked List."<<endl;
	cout<<"10.Exit from the main program."<<endl;
	jump:
	do{
		cout<<"\nEnter the program number : ";
		cin>>ch;
		switch(ch){
		case 1:{
			cout<<"Enter the element to be inserted in the beginning : ";
			cin>>value;
			insert_begin(value);
			display();
			break;
			}
		case 2:{
			cout<<"Enter the element to be inserted in the last : ";
			cin>>value;
			insert_end(value);
			display();
			break;
			}	
		case 3:{
			cout<<"Enter the element to be inserted after specific element : ";
			cin>>value;
			cout<<"After which element u want to insert ? : ";
			cin>>ele;
			insert_after(value,ele);
			display();
			break;
			}
		case 4:{
			cout<<"Before Sorting : ";
			display();
			sort();
			cout<<"After Sorting : ";
			display();
			cout<<"Enter the element to be inserted : ";
			cin>>value;
			insert_sort(&head,newNode(value));
			display();
			break;
			}
		case 5:{
			delete_begin();
			display();
			cout<<"Element from the beginning is deleted."<<endl;
			break;
			}
		case 6:{
			delete_end();
			display();
			cout<<"Element from the end is deleted. "<<endl;
			break;
			}
		case 7:{
			cout<<"Enter the element you want to delete : ";
			cin>>ele;
			delete_spec(ele);
			display();
			break;
			}	
		case 8:{
			cout<<"Enter the value to be searched : ";
			cin>>value;
			search();
			break;
			}
		case 9:{
			display();
			break;
			}
		case 10:{
			cout<<"Do you want to exit ? - Yes or No ?";
		   	cout<<"\nPress Y or N :";
	 	 	char option;
		   	cin>>option;
		   	if(option=='N' || option=='n')
	 	 	goto jump;
         	else
			exit(0);
			}
		default:
			cout<<"Error!Please enter a valid choice. "<<endl;
			break;
		}
	}while(ch!=10);
}
	
