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


void insertNode(Node* &tail,int element,int d){
   
   // empty list
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }

    // non empty list
    else{
    Node* curr=tail;
    while(curr->data!=element){
        curr=curr->next;
    }

    // element found
    Node* temp=new Node(d); 
    temp->next=curr->next;
    curr->next=temp;
    }

}

void print(Node* &tail){
    Node*temp=tail;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=tail);
    cout<<endl;
}

int main(){

Node* tail=NULL;
insertNode(tail,5,3);
insertNode(tail,3,4);
insertNode(tail,4,5);
insertNode(tail,5,6);
print(tail);
}