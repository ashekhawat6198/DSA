#include <iostream>
using namespace std;

// 1. INSERTION IN HEAP      TC:- O( LOG N )
class HEAP
{

public:
  int arr[100];
  int size = 0;

  void insert(int value)
  {
    size = size + 1;
    int index = size;
    arr[index] = value;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[parent] < arr[index])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        return;
      }
    }
  }

  // 2. DELETION IN HEAP     TC:- O( LOG N )
  void deleteFromHeap()
  {
    if (size == 0)
    {
      cout << "empty" << endl;
      return;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i < size)
    {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if (leftIndex < size && arr[i] < arr[leftIndex])
      {
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      }

      else if (rightIndex < size && arr[i] < arr[rightIndex])
      {
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      }

      else
      {
        return;
      }
    }
  }
};

// 3. HEAPIFY    OR   CREATE MAX HEAP        TC:- O(N)

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left < n && arr[largest] < arr[left])
  {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

// 4. CREATE MIN HEAP
void heapify(vector<int> &arr, int n, int i)
{
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[smallest] > arr[left])
  {
    smallest = left;
  }

  if (right < n && arr[smallest] > arr[right])
  {
    smallest = right;
  }

  if (smallest != i)
  {
    swap(arr[smallest], arr[i]);
    heapify(arr, n, smallest);
  }
}

vector<int> buildMinHeap(vector<int> &arr)
{
  int n = arr.size();
  for (int i = n / 2; i >= 0; i--)          /* we are starting from n/2 as remaining (n/2+1 to n are leaf nodes and they are already heap */
  {
    heapify(arr, n, i);
  }
  return arr;
}

// 5. HEAP SORT

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[largest] < arr[left])
  {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

public:
// Function to build a Heap from array.
void buildHeap(int arr[], int n)
{

  for (int i = n / 2; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
}

public:
// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
  buildHeap(arr, n);
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

// 6. Kth SMALLEST ELEMENT

int kthSmallest(int arr[], int l, int r, int k)
{
  priority_queue<int> pq;

  // 1.  first k elements ka max heap banao
  for (int i = 0; i < k; i++)
  {
    pq.push(arr[i]);
  }

  /* 2. baaki elements ko compare kro max heap ke top se agar element ki value kam hai toh heap ko pop kro
   aur element ko push krdo*/
  for (int i = k; i <= r; i++)
  {
    if (arr[i] < pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  // 3. ans hoga pq.top

  int ans = pq.top();
  return ans;
}

// 7. IS TREE A HEAP                  TC:-O(N)  && SC:-O(N)
int countNode(struct Node *tree)
{
  if (tree == NULL)
    return 0;

  int ans = 1 + countNode(tree->left) + countNode(tree->right);
  return ans;
}

bool isCBT(struct Node *tree, int i, int count)
{
  if (tree == NULL)
    return true;

  if (i >= count)
    return false;

  else
  {
    bool left = isCBT(tree->left, 2 * i + 1, count);
    bool right = isCBT(tree->right, 2 * i + 2, count);
    return left && right;
  }
}

bool isMaxHeap(struct Node *root)
{
  if (root->left == NULL && root->right == NULL)
  {
    return true;
  }

  else if (root->right == NULL)
  {
    return (root->data > root->left->data);
  }

  else
  {
    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);

    return (left && right && root->data > root->left->data && root->data > root->right->data);
  }
}

public:
bool isHeap(struct Node *tree)
{
  int index = 0;
  int totalNodes = countNode(tree);
  if (isCBT(tree, index, totalNodes) && isMaxHeap(tree))
  {
    return true;
  }
  else
    return false;
}

// 8. MERGE TWO BINARY MAX HEAPS          TC:-O(M+N)  && SC:-O(M+N)
void heapify(vector<int> &arr, int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  ;
  int right = 2 * i + 2;

  if (left < n && arr[largest] < arr[left])
  {
    largest = left;
  }

  if (right < n && arr[largest] < arr[right])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

public:
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
  vector<int> c;
  for (auto i : a)
  {
    c.push_back(i);
  }

  for (auto j : b)
  {
    c.push_back(j);
  }
  int size = c.size();
  for (int i = size / 2; i >= 0; i--)
  {
    heapify(c, size, i);
  }

  return c;
}

// 9. MINIMUM COST OR ROPES             TC:-O(N LOG N)  && SC:-O(N)

long long minCost(long long arr[], long long n)
{
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (int i = 0; i < n; i++)
  {
    pq.push(arr[i]);
  }

  long long cost = 0;
  while (pq.size() > 1)
  {
    long long a = pq.top();
    pq.pop();

    long long b = pq.top();
    pq.pop();

    long long sum = a + b;
    cost += sum;

    pq.push(sum);
  }

  return cost;
}

// 10. CONVERT BST TO MIN HEAP                  1. NODE<LEFT && NODE<RIGHT     2.  LEFT<RIGHT      RESULT=NODE<LEFT<RIGHT
void inorder(BinaryTreeNode *root, vector<int> &v)
{
  if (root == NULL)
  {
    return;
  }

  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}

void fillpreOrder(BinaryTreeNode *root, vector<int> &v, int &i)
{
  if (root == NULL)
  {
    return;
  }
  root->data = v[i++];
  fillpreOrder(root->left, v, i);
  fillpreOrder(root->right, v, i);
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
  vector<int> inList;
  inorder(root, inList);
  int i = 0;
  fillpreOrder(root, inList, i);
  return root;
}

// 11. K-th Largest Sum Contiguous Subarray            TC:-O(N LOG N)  && SC:-O(K)

int kthLargest(vector<int> &arr, int N, int k)
{
  priority_queue<int, vector<int>, greater<int>> mini;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      if (mini.size() < k)
      {
        mini.push(sum);
      }
      else
      {
        if (sum > mini.top())
        {
          mini.pop();
          mini.push(sum);
        }
      }
    }
  }

  return mini.top();
}

// 12. MERGE K SORTED ARRAYS           TC:- O(N*K O(K))    SC:-O(N*K)
class node
{

public:
  int data;
  int i;
  int j;

  node(int data, int row, int col)
  {
    this->data = data;
    this->i = row;
    this->j = col;
  }
};

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->data > b->data;
  }
};

// Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
  priority_queue<node *, vector<node *>, compare> pq;
  vector<int> ans;

  // 1. saare array ke first element insert kro
  for (int i = 0; i < k; i++)
  {
    node *temp = new node(arr[i][0], i, 0);
    pq.push(temp);
  }

  // 2.

  while (pq.size() > 0)
  {
    node *temp = pq.top();
    ans.push_back(temp->data);
    pq.pop();

    int i = temp->i;
    int j = temp->j;

    if (j + 1 < arr[i].size())
    {
      node *temp = new node(arr[i][j + 1], i, j + 1);
      pq.push(temp);
    }
  }

  return ans;
}

// 13. MERGE K SORTED LINKED LIST               TC:- O(N*K LOG K)    SC:-O(K)

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->data > b->data;
  }
};

Node *mergeKLists(Node *arr[], int k)
{
  priority_queue<Node *, vector<Node *>, compare> pq;
  for (int i = 0; i < k; i++)
  {
    if (arr[i] != NULL)
    {
      pq.push(arr[i]);
    }
  }

  Node *head = NULL;
  Node *tail = NULL;
  while (pq.size() > 0)
  {
    Node *temp = pq.top();
    pq.pop();

    if (head == NULL)
    {
      head = temp;
      tail = temp;
      if (head->next != NULL)
      {
        pq.push(tail->next);
      }
    }
    else
    {
      tail->next = temp;
      tail = temp;
      if (tail->next != NULL)
      {
        pq.push(tail->next);
      }
    }
  }

  return head;
}

// 14. K LARGEST ELEMENTS
priority_queue<int> pq;
for (int i = 0; i < n; i++)
{
  pq.push(arr[i]);
}

vector<int> ans;
for (int i = 0; i < k; i++)
{
  ans.push_back(pq.top());
  pq.pop();
}

return ans;

// 15.  KTH LARGEST ELEMENT
int findKthLargest(vector<int> &nums, int k)
{
  priority_queue<int> pq;
  for (int i = 0; i < nums.size(); i++)
  {
    pq.push(nums[i]);
  }

  for (int i = 1; i < k; i++)
  {
    pq.pop();
  }

  return pq.top();
}

// or  (optimised)

int findKthLargest(vector<int> &nums, int k)
{
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < k; i++)
  {
    pq.push(nums[i]);
  }

  for (int i = k; i < nums.size(); i++)
  {
    if (nums[i] > pq.top())
    {
      pq.pop();
      pq.push(nums[i]);
    }
  }

  return pq.top();
}

// 16. SMALL RANGE IN K LIST

class node
{
public:
  int data;
  int i;
  int j;

  node(int data, int r, int c)
  {
    this->data = data;
    this->i = r;
    this->j = c;
  }
};

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->data > b->data;
  }
};

pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
  int mini = INT_MAX;
  int maxi = INT_MIN;
  priority_queue<node *, vector<node *>, compare> miniH;

  for (int i = 0; i < k; i++)
  {
    int element = arr[i][0];
    mini = min(mini, element);
    maxi = max(maxi, element);
    node *temp = new node(arr[i][0], i, 0);
    miniH.push(temp);
  }

  int start = mini;
  int end = maxi;

  while (!miniH.empty())
  {
    node *temp = miniH.top();
    miniH.pop();

    mini = temp->data;

    if (maxi - mini < end - start)
    {
      start = mini;
      end = maxi;
    }

    int i = temp->i;
    int j = temp->j;

    if (j + 1 < n)
    {
      maxi = max(maxi, arr[i][j + 1]);
      node *newN = new node(arr[i][j + 1], i, j + 1);

      miniH.push(newN);
    }
    else
    {
      break;
    }
  }

  pair<int, int> ans;
  ans.first = start;
  ans.second = end;

  return ans;
}

// 17. FIND MEDIAN IN STREAM               TC:- O(N LOG N )
int signum(int a, int b)
{
  if (a == b)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}
void callMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{

  switch (signum(maxi.size(), mini.size()))
  {

  case 0:
    if (element > median)
    {
      mini.push(element);
      median = mini.top();
    }
    else
    {
      maxi.push(element);
      median = maxi.top();
    }
    break;

  case 1:
    if (element > median)
    {
      mini.push(element);
      median = (mini.top() + maxi.top()) / 2;
    }
    else
    {
      mini.push(maxi.top());
      maxi.pop();
      maxi.push(element);
      median = (mini.top() + maxi.top()) / 2;
    }
    break;

  case -1:
    if (element > median)
    {
      maxi.push(mini.top());
      mini.pop();
      mini.push(element);
      median = (mini.top() + maxi.top()) / 2;
    }
    else
    {
      maxi.push(element);
      median = (mini.top() + maxi.top()) / 2;
    }
    break;
  }
}

vector<int> findMedian(vector<int> &arr, int n)
{

  vector<int> ans;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int median = 0;
  for (int i = 0; i < n; i++)
  {
    callMedian(arr[i], maxHeap, minHeap, median);
    ans.push_back(median);
  }

  return ans;
}
