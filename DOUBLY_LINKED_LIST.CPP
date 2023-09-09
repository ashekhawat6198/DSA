#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;

    }
};


void insertAtHead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    Node *temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }

    int count=1;
    Node* temp=head;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;


}


void deleteNode(Node* &head,int position){
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
           curr->prev=NULL;
           prev->next=curr->next;
           curr->next=NULL;
        delete curr;

    
}
int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){

  
  Node* head=NULL;
  Node* tail=NULL;
 /* insertAtHead(head,12);
  insertAtHead(head,14);
  insertAtHead(head,16);
  print(head);*/
 // cout<<"head"<<head->data<<endl;
  //cout<<"tail"<<tail->data<<endl;
  insertAtTail(tail,head,12);
  insertAtTail(tail,head,14);
  insertAtTail(tail,head,18);
  insertAtTail(tail,head,20);
   insertAtPosition(tail,head,5,16);
  print(head);
  deleteNode(head,5);
}