
// POTD PROBLEMS OR NEW PROBLEMS

// 1. Maximum path sum from any node    ( 9th FEB 2025 )

 
int solve(Node* root,int &maxi){
    if(root==NULL) return 0;
    
    int leftSum=solve(root->left,maxi);
    int rightSum=solve(root->right,maxi);
    
    if(leftSum > 0 && rightSum > 0){                 // leftsum or rightsum dono positive ho
        maxi=max(maxi,root->data+leftSum+rightSum);
    }
    else if(leftSum < 0 && rightSum < 0){           // leftsum or rightsum dono negative ho
        maxi=max(maxi,root->data);
    }
    else{
        maxi=max(maxi,root->data + max(leftSum,rightSum));      // koi ek negative ho
    }
    
    return max(0,root->data + max(leftSum,rightSum));         // 0 se isliye kiye kuki agar root is negative hua toh or 
    
}

// Function to return maximum path sum from any node in a tree.
int findMaxSum(Node *root) {
    int maxi=INT_MIN;
    
    solve(root,maxi);
    return maxi;
    
}

// 2.   Fixing two nodes of bst

// BRUTE FORCE

void inorder(Node* root,vector<int>&in){
    if(root==NULL) return;
        
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

void makeTree(Node* root,vector<int>&in,int &i){
  if(root==NULL ) return;
  
  makeTree(root->left,in,i);
  root->data=in[i++];
  makeTree(root->right,in,i);
}


void correctBST(Node* root) {
   vector<int>in;
   inorder(root,in);
   sort(in.begin(),in.end());
   int i=0;
   makeTree(root,in,i);
}


// optimized     TC: O(N) SC:-O(1)

// 3 25 7 8 10 15 20 5       WHERE FIRST AND SECOND IS AVAILABLE  (SWAP NOT ADJACENT)
// 3 5 8 7 10 15 20 25       WHERE FIRST AND MIDDLE IS AVAIALABLE (SWAP ADJACENT)
 
  void inorder(Node* &root,Node* &first,Node* &middle,Node* &prev,
    Node* &second){
        if(root==NULL) return;
        
        inorder(root->left,first,middle,prev,second);
        
        if(prev!=NULL && root->data < prev->data){
            
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                
                second=root;
            }
        }
        
        prev=root;
        inorder(root->right,first,middle,prev,second);
    }
  
    void correctBST(Node* root) {
      Node* prev=new Node(INT_MIN);
      Node* first=NULL;
      Node* middle=NULL;
      Node* second=NULL;
      inorder(root,first,middle,prev,second);
      if(first && second) swap(first->data,second->data);
      else if(first && middle) swap(first->data, middle->data);
    }


// 3. Serialize and deserialize a binary tree   ( 16th Feb 2025 )

void solve(Node* root,vector<int>&ans){
    if(root==NULL ) return;
    
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}

 vector<int> serialize(Node *root) {
    vector<int>ans;
    solve(root,ans);
    return ans;
 }

 // Function to deserialize a list and construct the tree.
 
 Node* makeTree(vector<int> &arr,int inS,int inE){
     if(inS>inE) return NULL;
     
     int mid=inS+(inE-inS)/2;
     Node* root=new Node(arr[mid]);
     root->left=makeTree(arr,inS,mid-1);
     root->right=makeTree(arr,mid+1,inE);
     return root;
 }
 
 Node *deSerialize(vector<int> &arr) {
    int i=0;
    int n=arr.size();
   return makeTree(arr,0,n-1);
 }
