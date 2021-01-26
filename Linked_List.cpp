#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node*next;
}*head=NULL,*tail;

void Create(int val)
{
	struct Node*newnode;
	newnode = new struct Node;
	newnode->data = val;
	newnode->next = NULL;
	if(head == NULL){
		head = tail =newnode;
	}else{
		tail->next = newnode;
		tail = newnode;
	}
}

bool isEmpty()
{
	if(head==NULL){return true;
	}else{return false;
	}
}
void Display()
{
	struct Node*temp=head;
	while(temp != NULL){
		cout<< temp->data <<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void InsertFront(int val){
	struct Node*newnode;
	newnode = new struct Node;
	newnode->data = val;
	newnode->next = head;
	head=newnode;
}

void InsertAtPos(int pos,int x){
	struct Node*p=head,*newnode;
	newnode = new struct Node;
	for(int i=0;i<pos-2;i++){
		p = p->next;
	}
	newnode->data = x;
	newnode->next = p->next;
	p->next = newnode;
}

void InsertEnd(int val){
	struct Node*newnode;
	newnode = new struct Node;
	newnode->data = val;
	tail->next = newnode;
	newnode->next = NULL;
	tail = newnode;
}

void DeleteFront();
void DeleteAtPos(int pos);
void DeleteEnd();

int main(){
	int n,ele,cho,dat,position;
	cout<<"*****Linked List - ADA(Abstract Data Type)*****"<<endl;
	cout<<"**Linked List Creation**"<<endl;
	cout<<"Enter number of nodes to be inserted:";
	cin>>n;
	for(int j=0;j<n;j++){
		cout<<"Enter the data element:";
		cin>>ele;
		Create(ele);
	}
	while(true){
		cout<<"##### Options Available #####";
	cout<<"1.Insert at Front"<<endl;
	cout<<"2.Insert at Position"<<endl;
	cout<<"3.Insert at End"<<endl;
	cout<<"4.Delete at Front"<<endl;
	cout<<"5.Delete at Position"<<endl;
	cout<<"6.Delete at End"<<endl;
	cout<<"7.Check if Empty"<<endl;
	cout<<"8.Display the Linked List"<<endl;
	cout<<"9.Exit the Menu"<<endl;
	
	cout<<"Enter your choice:";
	cin>>cho;
	if(cho==9){
		break;
	}else{
			switch(cho){
		case 1:{
			cout<<"Enter data element"<<endl;
			cin>>dat;
			InsertFront(dat);
			break;
		}
	    case 2:{
	    	cout<<"Enter data element"<<endl;
			cin>>dat;
			cout<<"Enter position to be inserted:"<<endl;
			cin>>position;
			InsertAtPos(position,dat);
			break;
		}
		case 3:{
			cout<<"Enter data element"<<endl;
			cin>>dat;
			InsertEnd(dat);
			break;
		}
		case 4:{
			DeleteFront();
			break;
		}
	    case 5:{
			cout<<"Enter position to be inserted:"<<endl;
			cin>>position;
			DeleteAtPos(position);
			break;
		}
		case 6:{
			DeleteEnd();
			break;
		}
		case 7:{
			if(isEmpty()){
				cout<<"The list is empty..."<<endl;
			}else{
				cout<<"The list is not empty..."<<endl;
			}
			break;
		}
		case 8:{
			Display();
			break;
		}
	}
	
	
	}

	}
	

}

void DeleteFront()
{
	if(isEmpty()){
		cout<<"The list is empty"<<endl;
	}else{
	struct Node*temp;
	temp = head;
	head = temp->next;
	cout<<"The deleted element is:"<<temp->data<<endl;
	delete temp;
	}
}
void DeleteAtPos(int pos){
   struct Node*temp,*p,*t;
   p = head;
	for(int i=0;i<pos-2;i++){
		t=p;
	    p=p->next;
    }
    t->next = p->next;
    cout<<"The data element deleted is:"<<p->data<<endl;
    delete p;
	
}
void DeleteEnd()
{
	if(isEmpty()){
		cout<<"The list is empty"<<endl;
	}else{
        struct Node*second_last=head,*temp;
        while(second_last->next->next!=NULL){
        	second_last = second_last->next;
		}
		temp = second_last->next;
		second_last->next = NULL;
		delete temp;
		tail = second_last;
	}
}
