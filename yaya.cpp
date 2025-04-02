int searchNode(Node* head,int key){
    Node* temp=head;
    int pos=0;
    while(temp!=NULL && temp->data!=key){
         pos++;
         temp=temp->next;
    }
    
    if(temp==NULL){
        return -1;
    }
    return (pos+1);
}
