
#include<iostream>
using namespace std;
#include <array>
#include<vector>
// 1. factorial
int factorial(int n){
     if(n==0) return 1;

    return n*factorial(n-1);
}

// 2. power of 2

int power2(int n){
    if(n==0) return 1;

    return 2*power2(n-1);
}

void print(int n){
    if(n==0) return;

    cout<<n<<endl;
    print(n-1);

}

//3.  fibonacci series

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

// 4. climb stairs

int climbStairs(int n){
    if(n<0) return 0;
    if(n==0) return 1;

    return climbStairs(n-1)+climbStairs(n-2);
}

// 5. isSorted 

bool isSorted(int arr[],int size){
    if(size==0 || size==1)  return true;
    
     if(arr[0]>arr[1]) return false;

     else{
        bool remainingPart=isSorted(arr+1,size-1);
        return remainingPart;
     }
}

// 6. sum

int tsum(int arr[],int size){
    if(size==0) return 0;
    if(size==1) return arr[0];

    int sum=arr[0]+tsum(arr+1,size-1);
    return sum;
}

// 7. LINEAR SEARCH

bool lsearch(int array[],int size,int k){

     if(size==0) return false;

     if(array[0]==k) return true;
  
     else{
        bool remainingpart=lsearch(array+1,size-1,k);
        return remainingpart;
     }


}

// 8. Binary search

bool bsearch(int arr[],int s,int e,int k){
    if(s>e) return false;

    int mid=s+(e-s)/2;

    if(arr[mid]==k) return true;

    if(arr[mid]<k){
        return bsearch(arr,mid+1,e,k);
    }
    else{
        return bsearch(arr,s,mid-1,k);
    }
}

// 9. Reverse string

void reverse(string& str,int i,int j){
   
   if(i>j) return;

   swap(str[i],str[j]);
   i++;
   j--;

   reverse(str,i,j);

} 
void print(string str,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<str[i];
    }
    
}

// 10. Check palindrome

bool palin(string name,int i,int j){

    if(i>j) return true;

    if(name[i]!=name[j]) return false;

    else{
        return palin(name,i+1,j-1);
    }
}

// 11. power a ki power b

int power(int a,int b){

     if(b==0) return 1;
     if(b==1) return a;

     int ans=power(a,b/2);

     if(b%2==0) return ans*ans;

     else{
        return a*ans*ans;
     }

}

// 12. Bubble sort 

void bsort(int array[],int n){

    if(n==0 || n==1) return ;

    for (int i = 0; i < n-1; i++)
    {
            if(array[i]>array[i+1]){
                swap(array[i],array[i+1]);
            }
    }

    bsort(array,n-1);
    
}

// 13. selection sort

void selectionsort(int array[],int n){
    if(n==0 || n==1) return;
      
      
      for (int i = 0; i < n; i++)
      {
            
            if (array[i]<array[0])
            {
                swap(array[i],array[0]);
            }
            
      }
       
      selectionsort(array+1,n-1);
      
}

// 14. merge sort 


void merge(int array[],int s,int e){
     
        int mid=(s+e)/2;
        int l1=mid-s+1;
        int l2=e-mid;

        int *left=new int[l1];
        int *right=new int[l2];

      int mainarrayindex=s;
        for (int i = 0; i < l1; i++)
        {
                 left[i]=array[mainarrayindex++];
        }

        mainarrayindex=mid+1;
        for (int i = 0; i < l2; i++)
        {
                right[i]=array[mainarrayindex++];
        }


        int i=0;
        int j=0;
        mainarrayindex=s;

        while(i<l1 && j<l2){
            if (left[i]<right[j])
            {
                array[mainarrayindex++]=left[i++];
            }
            else{
                array[mainarrayindex++]=right[j++];
            }
            
        }
        
        while(i<l1){
            array[mainarrayindex++]=left[i++];
        }

        while (j<l2){
             array[mainarrayindex++]=right[j++];
        }
        
        delete []left;
        delete []right;
        
}

void mergeSort(int array[],int s,int e){
    if(s>=e) return;

    int mid=(s+e)/2;


    // merge first part

    mergeSort(array,s,mid);

    //merge second part
    mergeSort(array,mid+1,e);

    merge(array,s,e);
}

// 15. quick sort


int partition(int array[],int s,int e){
    int pivot=array[s];
     int count=0;
    for (int i = s+1; i <=e ; i++)
    {
        if(array[i]<=pivot){
            count++;
        }
    }

    int pivotIndex=s+count;
    swap(array[pivotIndex],array[s]);

    int i=s;
    int j=e;

    while (i<pivotIndex && j>pivotIndex)
    {
        while (array[i]<=pivot)
        {
            i++;
        }
        while (array[j]>pivot)
        {
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(array[i],array[j]);
            i++;
            j--;
        }
        
        
    }
    
    return pivotIndex;
    
}

void quickSort(int array[],int s,int e){
    if(s>=e) return;

    int p=partition(array,s,e);

    quickSort(array,s,p-1);
    quickSort(array,p+1,e);
}

// 16. Subsets(power set)

 void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(output);
           return;
        }

        // exclude case
        solve(nums,output,index+1,ans);

        // include case
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }

    // 17. LETTER COMBINATION OF PHONE NUMBER
    void solve(string digits,string output,int index,vector<string>&ans,string mapping[]){
           if(index>=digits.length()){
               ans.push_back(output);
               return;
           }

           int number=digits[index]-'0';
           string value=mapping[number];

           for(int i=0;i<value.length();i++){
               output.push_back(value[i]);
               solve(digits,output,index+1,ans,mapping);
               output.pop_back();
           }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;
        string output="";
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }

    // 18. PERMUTATIONS

     void solve(vector<int>nums,vector<vector<int>>&ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            // backtrek
            swap(nums[index],nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }

    // 19. RAT IN MAZE 

    bool isSafe(int x,int y,int n,vector<vector<int>>visited,vector<vector<int>>&m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
        return false;
        }
    }
    
    void solve(vector<vector<int>> &m,int n,int x,int y,vector<vector<int>>visited,string path,vector<string>&ans){
        
        // reached destination
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }
        
        visited[x][y]=1;
        
        
        // 4 choices  D/L/R/U
        
        // down
        
        int newx=x+1;
        int newy=y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        
        // left
        
        newx=x;
        newy=y-1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('L');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        
        // right
        
        newx=x;
        newy=y+1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('R');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        
        
        // UP
        
        newx=x-1;
        newy=y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('U');
            solve(m,n,newx,newy,visited,path,ans);
            path.pop_back();
        }
        
        visited[x][y]=0;
        
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <string>ans;
        
        if(m[0][0]==0){
            return ans;
        }
        
        int srcx=0;
        int srcy=0;
        
        vector<vector<int>>visited=m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        string path="";
        
        solve(m,n,srcx,srcy,visited,path,ans);
        
        sort(ans.begin(),ans.end());
        return ans;
    }


    // 20. Elimination Game

       int lastRemaining(int n) {
        if(n==1){
            return n;
        }
        return 2*(1+(n/2) -lastRemaining(n/2));
    }


    // 21. sum of all subsets XOR total

       
    
  
   void solve(int arr[], int n,long long int &sum,long long int xorAns,int i){
       if(i==n){
           sum=sum+xorAns;
           return;
       }
       
       
       // include
       xorAns=xorAns^arr[i];
       solve(arr,n,sum,xorAns,i+1);
       xorAns=xorAns^arr[i];
       // exclude
        solve(arr,n,sum,xorAns,i+1);
   }
  
  
    long long int sumXOR(int arr[], int n)
    {
       long long int sum=0;
       long long int xorAns=0;
       int i=0;
       solve(arr,n,sum,xorAns,i);
       return sum;
    }
    

// 22.  GENERATE PARANTHESIS
void solve(int n,  vector<string>&ans,string temp,int currOpen,int currClose,int remOpen,int remClose){
        if(currOpen==n && currClose==n){
            ans.push_back(temp);
            return;
        }
        
        
        // openbracket
        if(remOpen>0){
            temp.push_back('(');
            solve(n,ans,temp,currOpen+1,currClose,remOpen-1,remClose);
            temp.pop_back();
        }
        
        if(remClose>0 && currOpen>currClose){
             temp.push_back(')');
            solve(n,ans,temp,currOpen,currClose+1,remOpen,remClose-1);
            temp.pop_back();
        }
    }
    
    
    
    vector<string> AllParenthesis(int n) 
    {
       vector<string>ans;
       string temp="(";
       int currOpen=1;
       int currClose=0;
       int remOpen=n-1;
       int remClose=n;
       solve(n,ans,temp,currOpen,currClose,remOpen,remClose);
       return ans;
    }



// 23. N-QUEEN Problem

 bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        
        
        int x=row;
        int y=col;
        
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        
        x=row;
        y=col;
         while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    
    
    void solve(int n, vector<vector<int>>&ans,vector<vector<int>>board,int col){
        if(col==n){
           vector<int>temp;
           for(int col=0;col<n;col++){
               for(int row=0;row<n;row++){
                   if(board[row][col]==1){
                       temp.push_back(row+1);
                   }
               }
           }
           
           ans.push_back(temp);
           return;
        }
        
        
        for(int row=0;row<n;row++){
          if(isSafe(row,col,board,n)){
             board[row][col]=1;
              solve(n,ans,board,col+1);
               board[row][col]=0;
          }
        }
    }

    vector<vector<int>> nQueen(int n) {
       vector<vector<int>>ans;
       vector<vector<int>>board(n,vector<int>(n,0));
       int col=0;
       solve(n,ans,board,col);
       return ans;
    }


//24. SUDOKO PROBLEM

 bool safe(int row,int col,int k,int grid[N][N]){
         
         for(int i=0;i<N;i++){
             
             
             if(grid[i][col]==k){
                 return false;
             }
             
             if(grid[row][i]==k){
                 return false;
             }
             
             
             if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==k){
                 return false;
             }
         }
         
         return true;
        
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
      for(int row=0;row<N;row++){
          for(int col=0;col<N;col++){
              if(grid[row][col]==0){
                  for(int k=1;k<=9;k++){
                      if(safe(row,col,k,grid)){
                          grid[row][col]=k;
                          bool aageAnswer=SolveSudoku(grid);
                          if(aageAnswer==true){
                              return true;
                          }
                          else{
                              grid[row][col]=0;
                          }
                      }
                  }
                  
                  return false;
              }
          }
      }
      
      return true;
       
       
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i =0; i< N; i++){
            for(int j = 0; j < N; j++){
                cout<<grid[i][j]<<" "; 
            } 
        }
    }




// 25. Distribute Repeating Integers

   bool solve(map<int,int>&cnt,vector<int>& quantity,int index){
    if(index>=quantity.size()){
        return true;
    }

    for(auto i=cnt.begin();i!=cnt.end();i++){
        if(i->second>=quantity[index]){
         cnt[i->first]=cnt[i->first]-quantity[index];
        bool ans=solve(cnt,quantity,index+1);
        if(ans==true){
            return true;
        }
        // backtrack
       cnt[i->first]=cnt[i->first]+quantity[index];

        }
       
    }

    return false;

   }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int,int>cnt;
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
        }

        sort(quantity.begin(),quantity.end(),greater<int>());
        bool ans=solve(cnt,quantity,0);
        return ans;
    }

// 26. WORD BREAK II
 void solve(string s,vector<string>&ans,set<string>&st,int index,string temp){
        if(index==s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

       string tempString="";
        for(int i=index;i<s.length();i++){
           tempString.push_back(s[i]);

           if(st.count(tempString)){
            solve(s,ans,st,i+1,temp+tempString+" ");
           }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        set<string>st;
        for(auto x:wordDict){
            st.insert(x);
        }
        string temp="";
        solve(s,ans,st,0,temp);
        return ans;
    }

  
// 27. Find Minimum Time to Finish All Jobs
 void solve(vector<int>& jobs, int k,int n, vector<int>&work,int ans,int &res,int index){
        if(index==n){
           ans=*max_element(work.begin(),work.end());
           res=min(ans,res);
           return;
        }

        if(*max_element(work.begin(),work.end())>=res){
            return;
        }
        for(int i=0;i<k;i++){
            // optimisation
            if(i>0 && work[i]==work[i-1]){
                continue;
            }
            work[i]+=jobs[index];
            solve(jobs,k,n,work,ans,res,index+1);
             work[i]-=jobs[index];
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end(),greater<int>());
        int n=jobs.size();
        if(n==k)
        return jobs[0];
         vector<int>work(k,0);
        int assignmentAns=0;
        int finalAns=INT_MAX;
        int i=0;
        solve(jobs,k,n,work,assignmentAns,finalAns,i);
        return finalAns;
    }


// 28. Remove Invalid Paranthesis
 int getCount(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }


        return st.size();

    }


    void solve(string s,int count,vector<string>&ans,map<string,bool>&mp){
       if(mp[s]==true)
       return;
       else
       mp[s]=true;

       if(count==0){
        int newCount=getCount(s);
        if(newCount==0){
            ans.push_back(s);
            return;
        }
       }

       for(int i=0;i<s.size();i++){
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        string temp=left+right;
        solve(temp,count-1,ans,mp);
       }
    }

    vector<string> removeInvalidParentheses(string s) {
         int count=getCount(s);  
         vector<string>ans;
         map<string,bool>mp;
         solve(s,count,ans,mp);
         return ans;
    }