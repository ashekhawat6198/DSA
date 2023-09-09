#include <iostream>
using namespace std;
#include <map>
class ListNode
{
};
class Node
{
};
// 1. REVERSE LINKED LIST ITERATIVELY
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// 2. REVERSE LINKED LIST THROUGH RECURSIVE

void solve(ListNode *&head, ListNode *curr, ListNode *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    ListNode *forward = curr->next;
    solve(head, forward, curr);
    curr->next = prev;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    solve(head, curr, prev);
    return head;
}

// 3. MIDDLE OF LINKED LIST

int getLength(ListNode *&head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

ListNode *middleNode(ListNode *head)
{
    int length = getLength(head);
    int ans = length / 2;
    ListNode *temp = head;
    int count = 0;
    while (count < ans)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

// OR

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

// 4. REVERSE K NODES OF LINKED LIST

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    if (size < k)
        return head;

    ListNode *forward = NULL;
    ListNode *curr = head;
    ListNode *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
    {
        head->next = reverseKGroup(forward, k);
    }

    return prev;
}

//  5. IS CIRCULAR LINKED LIST

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }
    return false;
}

// 6. IS LOOP PRESENT // IS LINKED LIKED CYCLE

bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;

    map<ListNode *, bool> visited;
    ListNode *temp = head;
    while (temp != NULL)
    {

        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// 7. FLOYD CYCLE DETECTION
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// 8. STARTING NODE OF CYCLE

Node *firstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            break;
        }
    }

    if (fast == NULL || slow == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != fast)
    {
        fast = fast->next;
        curr = curr->next;
    }
    return curr;
}
// 9. DETECT AND REMOVE LOOP
Node *detect(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node *fristNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *inter = detect(head);

    if (inter == NULL)
    {
        return NULL;
    }

    Node *slow = head;

    while (slow != inter)
    {
        slow = slow->next;
        inter = inter->next;
    }

    return slow;
}
Node *removeLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *start = fristNode(head);

    if (start == NULL)
    {
        return head;
    }

    Node *temp = start;

    while (temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

// 10. REMOVE DUPLICATES FROM SORTED LIST

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return NULL;

    ListNode *curr = head;

    while (curr != NULL)
    {

        if ((curr->next != NULL) && curr->val == curr->next->val)
        {
            ListNode *next_next = curr->next->next;
            ListNode *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

// 11. REMOVE DUPLICATES FROM UNSORTED LIST
Node *removeDuplicates(Node *head)
{
    map<int, int> m;
    Node *curr = head;
    m[curr->data] = 1;
    Node *prev = curr;
    curr = curr->next;
    while (curr != NULL)
    {
        if (m[curr->data])
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            m[curr->data] = 1;
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}

//  12.  SORT 0,1,2

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// 13. MERGE TWO SORTED LIST

ListNode *solve(ListNode *list1, ListNode *list2)
{
    if (list1->next == NULL)
    {
        list1->next = list2;
        return list1;
    }

    ListNode *curr1 = list1;
    ListNode *next1 = curr1->next;
    ListNode *curr2 = list2;
    ListNode *next2 = NULL;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->val >= curr1->val) && (curr2->val <= next1->val))
        {
            // add node between the 1'st list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // curr1 and next1 ko aage badhaan hai
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return list1;
            }
        }
    }
    return list1;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->val <= list2->val)
    {
        return solve(list1, list2);
    }
    else
    {
        return solve(list2, list1);
    }
}

// 14. PALINDROME OR NOT

Node *getMiddle(Node *&head)
{
    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node *reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

public:
bool isPalindrome(Node *head)
{
    if (head->next == NULL)
        return true;

    // 1. find the middle
    Node *middle = getMiddle(head);

    // 2. reverse list after middle

    Node *temp = middle->next;
    middle->next = reverse(temp);

    // 3. compare both halves

    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // 4. repeat step 2
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

//  15. ADD TWO NUMBERS REPRESENTED BY LINKED LIST

void insertAtTail(struct Node *&head, struct Node *&tail, int value)
{
    if (head == NULL)
    {
        struct Node *temp = new Node(value);
        head = temp;
        tail = temp;
    }
    else
    {
        struct Node *temp = new Node(value);
        tail->next = temp;
        tail = temp;
    }
}

struct Node *reverse(Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

struct Node *add(struct Node *first, struct Node *second)
{

    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;

    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }

    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        first = first->next;
    }

    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        second = second->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
}

public:
// Function to add two numbers represented by linked list.

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // reverse both list
    first = reverse(first);
    second = reverse(second);
    // add both list
    Node *ans = add(first, second);

    // reverse ans list
    ans = reverse(ans);
    return ans;
}

// 16. ADD 1 TO A NUMBER REPRESENTED BY LINKED LIST

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        Node *temp = new Node(val);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
    }
}
Node *add(Node *head1, Node *head2)
{

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        head2 = head2->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
}

Node *addOne(Node *head)
{
    Node *l2 = new Node(1);
    Node *head2 = l2;
    Node *tail2 = l2;
    Node *r1 = reverse(head);

    Node *ans = add(r1, l2);

    ans = reverse(ans);
    return ans;
}

// 17. CLONE A LINKED LIST WITH NEXT AND RANDOM POINTER            50%
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }

    else
    {
        Node *newNode = new Node(d);
        tail->next = newNode;
        tail = newNode;
    }
}

public:
Node *copyList(Node *head)
{
    // 1. create a clone list

    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // 2. cloneNodes add in between original list

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // 3. random pointer copy

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL)
        {
            curr->next->arb = curr->arb ? curr->arb->next : curr->arb;
        }
        curr = curr->next->next;
    }

    // 4. revert changes done in step 2

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {

        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }

        cloneNode = cloneNode->next;
    }

    // RETURN ANS

    return cloneHead;
}

// 18. INTERSECTIONS OF TWO LINKED LIST
 void insertAtTail(Node* &head,Node* &tail,int d){
        if(head==NULL){
            Node* temp=new Node(d);
            head=temp;
            tail=temp;
        }
        else{
             Node* temp=new Node(d);
             tail->next=temp;
             tail=temp;
        }
    }


Node* findIntersection(Node* head1, Node* head2)
{
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    Node* temp1=head1;
    Node* temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            temp1=temp1->next;
            
        }
        else if(temp2->data < temp1->data){
            temp2=temp2->next;
        }
        
        else if(temp1->data==temp2->data){
            insertAtTail(ansHead,ansTail,temp1->data);
             temp1=temp1->next;
             temp2=temp2->next;
        }
       
    }
    
    return ansHead;
}

// 19. Move last element to front of a given Linked List

LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {
     
     if(head->next==NULL){
         return head;
     }
   LinkedListNode<int>* curr=head;
   LinkedListNode<int>* next=curr->next;
   while(next->next!=NULL ){
    curr=curr->next;
      next=curr->next;
       
   } 

   next->next=head;
   curr->next=NULL;
   head=next;
   return head;


}

// 20. SPLIT A CIRCULAR LINKED LIST IN TWO HALVES

void splitCircularList(Node *head)
{
   Node* fast=head->next;
   Node* slow=head;
      
      while(fast!=head && fast->next!=head   ){
          fast=fast->next->next;
            slow=slow->next;
      }
      
      Node* head1=head;
      Node* head2=slow->next;
      
      Node* temp1=head1;
      while(temp1!=slow){
          temp1=temp1->next;
      }
      temp1->next=head;
      
      temp1=head2;
      while(temp1->next!=head){
          temp1=temp1->next;
      }
      temp1->next=head2;
}

// 21. MERGE SORT FOR LINKED LIST


    ListNode* getMiddle(ListNode* &head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* &left,ListNode* &right){
          if(left==NULL) return right;
          if(right==NULL) return left;

          ListNode* ans=new ListNode(-1);
           ListNode* temp=ans;


           while(left!=NULL && right!=NULL){
               if(left->val < right->val){
                   temp->next=left;
                   temp=left;
                   left=left->next;
               }
               else{
                   temp->next=right;
                   temp=right;
                   right=right->next;
               }
           }

           while(left!=NULL){
               temp->next=left;
               temp=left;
               left=left->next;
           }

           while(right!=NULL){
               temp->next=right;
               temp=right;
               right=right->next;
           }

           ans=ans->next;
           return ans;
    }

    ListNode* sortList(ListNode* head) {

        // BASE CASE
        if(head==NULL || head->next==NULL) return head;
   
     // BREAK LINKED LIST INTO TWO HALVES
      ListNode* middle=getMiddle(head);

      ListNode* left=head;
      ListNode* right=middle->next;
      middle->next=NULL;

      // RECURSIVE CALLS TO SORT BOTH PARTS

      left=sortList(left);
      right=sortList(right);

      // merge

      ListNode* result=merge(left,right);

      return result;

    }

    // 22. FLATTEN A LINKED LIST

    Node* merge(Node* &left,Node* &right){
	if(left==NULL) return right;
	if(right==NULL) return left;
	
	Node* ans=new Node(-1);
	Node* temp=ans;
	while(left!=NULL && right!=NULL){
		if(left->data < right->data){
			temp->child=left;
			temp=left;
			left=left->child;
		}
		else{
			temp->child=right;
			temp=right;
			right=right->child;
		}
	}
	while(left != NULL)

    {

        temp->child = left;

        temp = left;

        left = left->child;

    }
	  while(right != NULL)

    {

         temp->child = right;

         temp = right;

         right = right->child;

    } 

    ans = ans->child;

    return ans;
	
}


Node* flattenLinkedList(Node* head) 
{
	   if(head == NULL)

    {

        return head;

    }
	Node* down=head;
	
	Node* right=head->next;
	down->next=NULL;
	right=flattenLinkedList(right);
	
	Node* ans=merge(down,right);
	return ans;
}

// 23. INTERSECTION POINT OF TWO LINKED LIST

int getLength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    
    return len;
}
int intersectPoint(Node* head1, Node* head2)
{
   int len1=getLength(head1);
   int len2=getLength(head2);
   Node* curr1=head1;
   Node* curr2=head2;
   int diff=abs(len1-len2);
   
   if(len1<len2){
       while(diff--){
           curr2=curr2->next;
       }
   }
   else{
       while(diff--){
           curr1=curr1->next;
       }
   }
   
   while(curr1!=NULL && curr2!=NULL){
       if(curr1==curr2){
           return curr1->data;
       }
       curr1=curr1->next;
       curr2=curr2->next;
   }
   return -1;
}

// 24. SEGREGATE EVEN AND ODD IN LINKED LIST
 Node* divide(int N, Node *head){
        Node* even=NULL;
        Node* odd=NULL;
        Node* e=NULL;
        Node* o=NULL;
        
        while(head!=NULL){
            if(head->data%2==0){
                if(even==NULL){
                    even=head;
                    e=head;
                }
                else{
                    e->next=head;
                    e=e->next;
                }
            }
            else{
                if(odd==NULL){
                    odd=head;
                    o=head;
                }
                else{
                    o->next=head;
                    o=o->next;
                }
            }
            head=head->next;
        }
        if(e!=NULL){
            e->next=odd;
        }
        if(o!=NULL){
            o->next=NULL;
        }
        if(even!=NULL){
            return even;
        }
        return odd;
    }

    // 25 .   REVERSE A DOUBLY LINKED LIST

    Node* reverseDLL(Node * head)
{
    Node* prev1=NULL;
    Node* curr=head;
    Node* next1=NULL;
    
    while(curr!=NULL){
        next1=curr->next;
        curr->next=prev1;
        curr->prev=next1;
        prev1=curr;
        curr=next1;
        
    }
    return prev1;
}

// 26. MULTIPLY TWO NUMBERS OF LINKED LIST

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    const long long mod= (long long)1e9+7;
    long long num1=0;
    long long num2=0;
    
    while(l1!=NULL || l2!=NULL){
        if(l1!=NULL){
            num1=(num1*10+l1->data)%mod;
            l1=l1->next;
        }
        if(l2!=NULL){
            num2=(num2*10+l2->data)%mod;
            l2=l2->next;
        }
    }
    
    return (num1*num2)%mod;
}


// 27. DELETE NODES HAVING GREATER VALUE ON RIGHT      

 Node* reverse(Node* head){
         if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    }
    
    Node *compute(Node *head)
    {
       head=reverse(head);
       Node* temp=head;
       int max=temp->data;
       Node* prev=temp;
       temp=temp->next;
       while(temp!=NULL){
           if(temp->data >= max){
               max=temp->data;
               prev=temp;
               temp=temp->next;
           }
           else{
               prev->next=temp->next;
               temp=prev->next;
           }
       }
       head=reverse(head);
       return head;
    }
    

    // 28. Nth node from the end of linked list              

     int getNthFromLast(Node *head, int n)
    {
           Node* first=head;
           Node* second=head;
           
           for(int i=1;i<n;i++){
               second=second->next;
               if(second==NULL) return -1;
           }
           
           while(second->next!=NULL){
               first=first->next;
               second=second->next;
           }
           return first->data;
    }


int main()
{
}