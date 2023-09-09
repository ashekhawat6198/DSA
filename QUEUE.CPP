#include <iostream>
using namespace std;

// QUEUE :- FOLLOWS FIFO( FIRST IN FIRST OUT )
/*
queue<int>q;

q.push(17);
q.pop();
q.size();
q.empty()   T/F
q.front();





*/


// 1. IMPLEMENT QUEUE FROM SCRATCH

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size=10001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
           arr[rear]=data;
           rear++;
        }
    }

    int dequeue() {
       if(qfront==rear){
        return -1;
       }
       else{
           int ans=arr[qfront];
           arr[qfront]=-1;
           qfront++;
           if(qfront==rear){
               qfront=0;
               rear=0;
           }
           return ans;
       }
    }

    int front() {
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};

// 2. IMPLEMENT A CIRCULAR QUEUE
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size=n;
        arr=new int[size]; 
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){  // to check whether queueis full 
            return false;
        }
        else if(front==-1) {            //first element to push
            front=rear=0;
            arr[rear]=value;
        }          
        else if(rear==size-1 && front!=0){   // maintain cyclic nature
            rear=0;
            arr[rear]=value;
        }
        else{   //normal flow
            rear++;
            arr[rear]=value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1){  // to check queue is empty
            return -1;

        }
          int ans=arr[front];
          arr[front]=-1;
        if(front==rear){         // single element is present
            front=rear=-1;
        }
        else if(front==size-1){      // to maintain cyclic nature
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};

// 3. IMPLEMENT A DEQUE

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if((rear==size-1 && front==0) || (front!=0 && rear==(front-1)%(size-1))){
            return false;
        }
        else if(front==-1){
            front=rear=0;
            arr[front]=x;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
            arr[front]=x;
        }
        else{
            front--;
            arr[front]=x;
        }
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if((rear==size-1 && front==0) || (front!=0 && rear==(front-1)%(size-1))){
            return false;
        }

        else if(rear==-1){
            front=rear=0;
            arr[front]=x;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=x;
        }
        else{
            rear++;
            arr[rear]=x;
        }
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(rear==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
         if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front==-1){
            return true;
        } else {
          return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((rear==size-1 && front==0) || (front!=0 && rear==(front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};


// 4. REVERSE THE QUEUE

 queue<int> rev(queue<int> q)
    {
        stack<int>st;
        
        while(!q.empty()){
            int element=q.front();
            q.pop();
            st.push(element);
        }
        
        
        while(!st.empty()){
            int element=st.top();
            st.pop();
            q.push(element);
        }
        return q;
    }

    // 5. FIRST NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K

    vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    deque<long long>dq;
    vector<long long>ans;
    
    // process first window of k size
    
    for(int i=0;i<K;i++){
        if(A[i]<0){
           dq.push_back(i); 
        }
    }
    
    // store answer of first k sized window
    
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    
    for(int i=K;i<N;i++){
        
        // removal
        
        if(!dq.empty() && i-dq.front()>=K){
            dq.pop_front();
        }
        
        // addition
        
        if(A[i]<0){
            dq.push_back(i);
        }
        
         if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    }
    return ans;
                                                 
 }

 // 6. REVERSE THE FIRST K ELEMENTS OF QUEUE

 queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>st;
    for(int i=0;i<k;i++){
        int value=q.front();
        q.pop();
        st.push(value);
    }
    
    while(!st.empty()){
        int value=st.top();
        st.pop();
        q.push(value);
    }
    
    
    int t=q.size()-k;
    
    while(t--){
        int value=q.front();
        q.pop();
        q.push(value);
    }
    return q;
}

// 7. FIRST NON REPEATING CHARACTERS IN A STRING

string FirstNonRepeating(string A){
		   unordered_map<char,int>count;
		   queue<char>q;
		   string ans="";
		   for(int i=0;i<A.size();i++){
		       char ch=A[i];
		       
		       // increase count
		       
		       count[ch]++;
		       
		       // q mai push karo
		       q.push(ch);
		       
		       
		       while(!q.empty()){
		           if(count[q.front()]>1){
		               // repeating character
		               q.pop();
		           }
		           else{
		               // non repeating character milenege
		               ans.push_back(q.front());
		               break;
		           }
		       }
		       
		       if(q.empty()){
		           ans.push_back('#');
		       }
		   }
		   return ans;
		}


// 8. CIRCULAR TOUR PETROL PUMP                   50%

int tour(petrolPump p[],int n)
    {
      int start=0;
      int balance=0;
      int deficit=0;
      
      for(int i=0;i<n;i++){
          balance+=p[i].petrol-p[i].distance;
          if(balance<0){
              deficit+=balance;
              start=i+1;
              balance=0;
          }
      }
      
      if(deficit + balance>=0){
          return start;
      }
      else{
          return -1;
      }
    }

    // 9.  STOCK SPAN PROBLEM    ( stack question )

         vector <int> calculateSpan(int price[], int n)
    {
     vector<int>ans;
     stack<int>st;
     for(int i=0;i<n;i++){
         while(!st.empty() && price[st.top()]<=price[i]){
             st.pop();
         }
          
          if(st.empty()) ans.push_back(i+1);
          else ans.push_back(i-st.top());
          
          st.push(i);
     }
     return ans;
    }

    // 10. ROTTEN ORANGES 

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        q.push({-1,-1});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if(i==-1 && j==-1 && q.size()==1){
                q.pop();
                break;
            }
            else if(i==-1 && j==-1 && q.size()>1){
                count++;
                q.pop();
                q.push({-1,-1});
            }
            else{
                if((i-1)>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if((j-1)>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                
                if((i+1)<r && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
                if((j+1)<c && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                q.pop();
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }

    // 11. STACK USING TWO QUEUES

    void QueueStack :: push(int x)
{
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        int ans=0;
        if(q2.empty()){
            ans=-1;
            
        }
        else{
            ans=q2.front();
            q2.pop();
        }
        return ans;
}

// 12. STACK USING SINGLE QUEUE


 void QueueStack :: push(int x)
{
        q1.push(x);
        int size=q1.size()-1;
        while(size--){
            q1.push(q1.front());
            q1.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
       int ans=0;
       if(q1.empty()){
           ans=-1;
       }
       else{
           ans=q1.front();
           q1.pop();
       }
       return ans;
}
 
 // 13. QUEUE USING TWO STACK
 void QueueStack :: push(int x)
{
        while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
       int ans=0;
       if(q1.empty()){
           ans=-1;
       }
       else{
           ans=q1.front();
           q1.pop();
       }
       return ans;
}

 // 14. MAXIMUM OF ALL SUBARRAY Of SIZE K

  vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       vector<int>ans;
       deque<int>dq;
       for(int i=0;i<k;i++){
           
           while(!dq.empty() && arr[dq.back()]<arr[i]){
               dq.pop_back();
           }
           
           dq.push_back(i);
       }
       ans.push_back(arr[dq.front()]);
        
        
        for(int i=k;i<n;i++){
            // removal
            
            if(i-dq.front()>=k){
                dq.pop_front();
            }
            
            // addition
             while(!dq.empty() && arr[dq.back()]<arr[i]){
               dq.pop_back();
           }
           
           dq.push_back(i);
           ans.push_back(arr[dq.front()]);
            
        }
        return ans;
    }

   



int main(){



}