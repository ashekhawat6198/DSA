#include <iostream>
using namespace std;

class Node{
  
  public:
  int data;
  Node* next;

 Node(int data){
   this->data=data;
   this->next=NULL;
 }

};


void insertionAtHead(Node* &head,int d){
    // create new node
    Node *temp=new Node(d);
     temp->next=head;
     head=temp;

}

void insertionAtTail(Node* &tail,int d){

Node *temp=new Node(d);
      tail->next=temp;
      tail=temp;

}
void deleteNode(Node* &head,int position){
  

   if(position==1){
     // deleting first node
      Node* temp=head;
       head=head->next;
       temp->next=NULL;
       delete temp;
   }
   else{
      // delete any middle node and last node

      Node* curr=head;
      Node* prev=NULL;
      int count=1;

      while(count<position){
         prev=curr;
         curr=curr->next;
         count++;
      }

      prev->next=curr->next;
      curr->next=NULL;
      delete curr;

   }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
  

  // insert at head
  if(position==1){
    insertionAtHead(head,d);
    return;
  }
  Node * temp=head;
  int count=1;
  while(count<position-1){
    temp=temp->next;
    count++;
  }

  // insert at last

  if(temp->next==NULL){
    insertionAtTail(tail,d);
    return;
  }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;

}
int main(){

Node* node1=new Node(12);

Node * head=node1;
Node* tail=node1;


//cout<<node1->data<<endl;
//cout<<node1->next<<endl;


// INSERT IN HEAD

/*Node* head=node1;
print(head);
insertionAtHead(head,12);
print(head);*/


// INSERT IN TAIL
insertionAtTail(tail,14);
insertionAtTail(tail,18);




// INSERT AT POSITION
insertAtPosition(head,tail,4,16);
print(head);

}