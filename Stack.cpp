#include <iostream>
using namespace std;
#include<stack>
// FOLLOWS  LIFO= LAST IN FIRST OUT
// PUSH  = USED TO ADD ELEMENT
// POP = UED TO DELETE ELEMENT FROM TOP
// PEEK = TOP ELEMENT
// Empty = to check it is empty or not
//  syntax =  stack <type> stack_name;
// st.push(2);
// st.pop();
// st.top();
// st.empty()



// 1. IMPLEMENT STACK FROM SCRATCH
class stack
{

 public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
          top++;
          arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }

    }

    void pop(){   
        if(top>=0){
            top--;

        }
        else{

            cout<<"Stack Underflow"<<endl;
        }

    }

    int peek(){
         if(top >=0 ){
            return arr[top];
         }
         else{
            return -1;
         }
    }

    bool isEmpty(){
          if(top==-1){
            return true;
          }
          else{
            return false;
          }
    }

};


// 2. IMPLEMENT 2 STACKS IN AN ARRAY

class TwoStack {
    int size;
    int top1;
    int top2;
    int *arr;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
         top1=-1;
         top2=s;
         arr=new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
      if(top2- top1 >1){
          top1++;
          arr[top1]=num;
      }
      
    }

    // Push in stack 2.
    void push2(int num) {
       if(top2-top1 >1){
           top2--;
           arr[top2]=num;
       }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
         if(top1>=0){
             int ans=arr[top1];
             top1--;
             return ans;
         }
         else{
             return -1;
         }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
       if(top2<size){
           int ans=arr[top2];
           top2++;
           return ans;
       }
       else{
           return -1;
       }
    }
};

// 3. REVERSE A STRING USING STACK

char* reverse(char *S, int len)
{
    stack <char> st;
    for(int i=0;i<len;i++){
        
        st.push(S[i]);
    }
    
       int i=0;
    while(!st.empty()){
       S[i++]=st.top();
       st.pop();
    }
    return S;


}

// 4. DELETE MIDDLE ELEMENT IN STACK


void solve(stack<int>&inputStack, int N,int count){

   if(count==N/2){
      inputStack.pop();
      return;
   }

   int num=inputStack.top();
   inputStack.pop();

   solve(inputStack, N,  count+1);
   inputStack.push(num);


}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;
   solve(inputStack,N,count);
   
}

// 5. INSERT A ELEMENT AT ITS BOTTOM IN A GIVEN STACK

void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num=myStack.top();
      myStack.pop();

      solve(myStack,x);

      myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}


// 6. REVERSE STACK USING RECURSION


void insertAtBottom(stack<int> &stack,int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }

    int x=stack.top();
    stack.pop();

    insertAtBottom(stack, num);

    stack.push(x);
    
    
    }
    
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }

    int num=stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack,num);
}

    // 7. SORT A STACK

    void insertSorted(stack<int> &stack,int x){
	if((stack.empty()) ||  (stack.top()<x)){
		stack.push(x);
		return;
	}

	int num=stack.top();
	stack.pop();

	insertSorted(stack,x);
    stack.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int num=stack.top();
	stack.pop();
   sortStack(stack);

	insertSorted(stack,num);

}


// 8. REDUNDANT BRACKET

bool findRedundantBrackets(string &s)
{
    stack<char>st;
   for(int i=0;i<s.length();i++){
       char ch=s[i];
       if(ch=='(' || ch=='+' ||ch=='-' || ch=='*' || ch=='/'){
           st.push(ch);
       }
       else{
           if(ch==')'){
             bool  isRedundant=true;

               while(st.top()!='('){
                   char top=st.top();
                   if(top=='+' ||top=='-' || top=='/' || top=='*'){
                       isRedundant=false;
                   }
                   st.pop();
               }

               if(isRedundant==true)
                   return true;
                   st.pop();
               
           }

        
       }
   }
   return false;
}

// 9. MINIMUM COST TO MAKE STRING VALID

int findMinimumCost(string str) {
  if(str.length()%2 !=0){
    return -1;
  }
  stack<char>st;
  for(int i=0;i<str.length();i++){
    char ch=str[i];

    if(ch=='{'){
      st.push(ch);
    }
    else{
      if(!st.empty() && st.top()=='{' ){
        st.pop();
      }
      else{
        st.push(ch);
      }
    }
  }

  // stack contain invalid paranthesis
  
  int a=0,b=0;
  
  while(!st.empty()){
    if(st.top()=='{'){
      b++;
    }
    else{
      a++;
    }
    st.pop();
  }

  int ans=(a+1)/2 +(b+1)/2;
  return ans;
  
}

// 10. NEXT SMALLER ELEMENT

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    
    
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];

        while(st.top()>=curr){
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}


// 11. NEXT GRATER ELEMENT

   vector<long long> nextLargerElement(vector<long long> arr, int n){
      vector<long long> ans(n);
        
        stack<long long> st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            else    ans[i]=-1;
        
            st.push(arr[i]);
        }
        
        return ans;
    }


    // 12.  LARGEST RECTANGULAR AREA IN HISTOGRAM

     vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    
    
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];

        while(st.top()!= -1 && arr[st.top()]>=curr){
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}


vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    
    
    for(int i=0;i<n;i++){
        int curr=arr[i];

        while(st.top()!=-1 && arr[st.top()]>=curr){
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>next(n);
        next=nextSmallerElement(heights,n);

        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);

      int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
           
            if(next[i]==-1){                //   when all elements are same
              next[i]=n;
            }
             int b=next[i]-prev[i]-1;
            int area=l*b;
            maxArea=max(area,maxArea);

        }

        return maxArea;
    }

    // 13. THE CELEBRITY PROBLEM

     bool knows(vector<vector<int> >& M,int a,int b,int n){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>st;
       
       
       // push all elements in stack
       for(int i=0;i<n;i++){
           st.push(i);
           
       }
       
       // get 2 elements and compare them
       while(st.size()>1){
           int a=st.top();
           st.pop();
           
           int b=st.top();
           st.pop();
           
           
           if(knows(M,a,b,n)){
               st.push(b);
           }
           else{
               st.push(a);
           }
       }
       
       int candidate=st.top();
       
       // single element in stack so verify it
       
       // row check all must be zero
       
       int zeroCount=0;
       for(int i=0;i<n;i++){
           if(M[candidate][i]==0){
               zeroCount++;
           }
       }
       
       if(zeroCount!=n){
           return -1;
       }
       
       
       int oneCount=0;
       for(int i=0;i<n;i++){
           if(M[i][candidate]==1){
               oneCount++;
           }
       }
       
       if(oneCount!=n-1){
           return -1;
       }
       
     return candidate;
       
       
    }

    // 14. N STACKS IN ARRAY

    class NStack
{



    int *arr;
    int *top;     // ndex of top element of the stack
    int *next;   // 2 things : (i) represent next element of the top and (ii) represent next free space (when array is empty)

    int n,s;

    int freespot;     // represent or tells us on which index of next we have to go

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {    n=N;
          s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        // initialise top
        for(int i=0;i<n;i++){
            top[i]=-1;
        }

        // intialise next

        for(int i=0;i<s;i++){
            next[i]=i+1;
        }

        // update last index
        next[s-1]=-1;

        // intialise free spot
           freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check overflow

        if(freespot==-1){
            return false;
        }

        // find index

        int index=freespot;

        // update freespot

        freespot=next[index];
        
        //insert element into array
        arr[index]=x;

        //update index as in array there is element and m-1 is as array is zero based indexing top[m](puarana stack)
        next[index]=top[m-1];

        //update top
        top[m-1]=index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // stack underflow

        if(top[m-1]==-1){
            return -1;
        }

       int index=top[m-1];

        top[m-1]=next[index];

        next[index]=freespot;

        freespot=index;

        return arr[index];
    }
};   

// 15. LENGTH OF VALID SUBSTRING        0 %
int findMaxLen(string s) {
       stack<int>st;
       for(int i=0;i<s.size();i++){
           char ch=s[i];
           if(ch=='('){
               st.push(i);
           }
           else{
               if(st.size()>0 && s[st.top()]=='('){
                   st.pop();
               }
               else{
                   st.push(i);
               }
           }
       }
       int maxi=0;
       int len=s.size();
       while(!st.empty()){
           int top=st.top();
           maxi=max(maxi,len-top-1);
           len=top;
           st.pop();
       }
       return max(len,maxi);
    }


// 16. INFIX TO POSTFIX       TC : O(N)+O(N)    SC : O(N)+O(N)   

 int priority(char ch){
      if(ch=='^'){
          return 3;
      }    
      else if(ch=='*' || ch=='/'){
          return 2;
      }
      else if(ch=='+' || ch=='-'){
          return 1;
      }
      else{
          return -1;
      }
    }
    
    
    string infixToPostfix(string s) {
      string ans="";
      stack<char>st;
      for(int i=0;i<s.size();i++){
          char ch=s[i];
          if( (ch>='A' && ch<='Z' ) || (ch>='a' && ch<='z') || ch>='0' && ch<='9'){
              ans=ans+ch;
          } 
          else if(ch=='('){
              st.push(ch);
          }
          else if(ch==')'){
              while(!st.empty() && st.top()!='('){
                  ans=ans+st.top();
                  st.pop();
              }
              st.pop();
          }
          else{
              while(!st.empty() && priority(ch)<=priority(st.top())){
                  ans=ans+st.top();
                  st.pop();
              }
              st.push(ch);
          }
      }
      
      while(!st.empty()){
          ans+=st.top();
          st.pop();
      }
      
      return ans;
    }

//17.  INFIX TO PREFIX            TC : O(N/2)+O(N/2)+O(2N) => O(3N)  SC:O(N)
    SC : O(N)+O(N) 
/*
   1. Reverse 
   2. infix to postfix
   3. revrse ans
*/

string reverse(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]=='(' ){
            s[i]=')';
        }
        else if(s[j]=='(' ){
            s[j]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
        else if(s[j]==')'){
            s[j]='(';
        }
        
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}

 int priority(char ch){
      if(ch=='^'){
          return 3;
      }    
      else if(ch=='*' || ch=='/'){
          return 2;
      }
      else if(ch=='+' || ch=='-'){
          return 1;
      }
      else{
          return -1;
      }
    }

string solve(string s){
    s=reverse(s);
    string ans="";
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9') ){
            ans=ans+ch;
        }
        else if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(ch=='^'){
                while(!st.empty() && priority(ch)<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else{
                 while(!st.empty() && priority(ch)<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
      
    }
      while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        ans=reverse(ans);
        return ans;
}


int main() {
    string s="(A+B)*C-D+F";
    string ans=solve(s);
    cout<<ans;
}

// 18 POSTFIX TO INFIX

string postToInfix(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){
           char ch=s[i];
           if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
               st.push(string(1,ch));
           }
           else{
               
             
                string s2=st.top();
               st.pop();
               string s1=st.top();
               st.pop();
               
               st.push('('+ s1 + ch + s2 +')');    
               
               
           }
        }
        
        return st.top();

    }

// 19. IMPLEMENT MIN STACK  
 
 // BRUTE FORCE   TC:-O(1)  SC:-O(2*N)

class MinStack {                
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }
}


// OPTIMIZED APPROACH

 stack<long long>st;
    long long mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val>mini){
                st.push(val);
            }
            else{
                st.push(2LL*val-mini); // Use 2LL to ensure the calculation is done in long long
                mini=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return; 
        }
        long long ans=st.top();
        st.pop();
        
           if(ans<mini)
                mini=2*mini-ans;
           
        
    }
    
    int top() {
        if(st.empty()) return -1;
        long long ans=st.top();
        if(mini<ans){
            return ans;
        }
        else return mini;

    }
    
    int getMin() {
        if(st.empty()) return -1;
        else return mini;
    }


// 20. REMOVE K DIGITS                  TC: O(3N) + O(K)    SC:- O(N) + O(N) 

 string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k>0){    // k is still remaining 
            
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        while(res.size()!=0 && res.back()=='0'){           // trim initial zeroes ( 00123 )
            res.pop_back();
        }
        reverse(res.begin(),res.end());
      if(res.empty()) return "0";
      return res;

    }