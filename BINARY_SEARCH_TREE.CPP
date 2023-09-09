#include <iostream>
using namespace std;
#include <queue>

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// 1. IMPLEMENTATION

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeinput(Node *root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// 2.  SEARCH IN BST
bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
        {
            return true;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}

// OR

bool search(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (root->data > x)
    {
        search(root->left, x);
    }
    else if (root->data < x)
    {
        search(root->right, x);
    }
}

// 3. FIND MIN VALUE IN BST

int minValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *curr = root;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr->data;
}

// 4.  Kth LARGEST ELEMENT IN BST

int solve(Node *root, int &k)
{
    if (root == NULL)
    {
        return -1;
    }

    int right = solve(root->right, k);
    if (right != -1)
    {
        return right;
    }

    k--;
    if (k == 0)
    {
        return root->data;
    }

    int left = solve(root->left, k);
    return left;
}

public:
int kthLargest(Node *root, int k)
{

    return solve(root, k);
}

// 5. Kth SMALLEST ELEMENT IN BST
int solve(Node *root, int &k)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = solve(root->left, k);
    if (left != -1)
    {
        return left;
    }

    k--;
    if (k == 0)
    {
        return root->data;
    }

    int right = solve(root->right, k);
    return right;
}

public:
int kthLargest(Node *root, int k)
{

    return solve(root, k);
}

// 6. CHECK WHETHER BST CONTAINS DEAD END
bool solve(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return false;
    }

    if (min == max)
    {
        return true;
    }

    return solve(root->left, min, root->data - 1) or solve(root->right, root->data + 1, max);
}
bool isDeadEnd(Node *root)
{
    return solve(root, 1, INT_MAX);
}

// 7. FLATTEN BST TO SORTED LIST
void inorder(TreeNode<int> *root, vector<int> &inorderList)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, inorderList);
    inorderList.push_back(root->data);
    inorder(root->right, inorderList);
}

TreeNode<int> *makeList(int i, vector<int> &inorderList, int n)
{

    TreeNode<int> *mainRoot = new TreeNode<int>(inorderList[i]);
    TreeNode<int> *curr = mainRoot;

    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorderList[i]);
        curr->left = temp;
        curr->right = NULL;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    return mainRoot;
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorderList;
    inorder(root, inorderList);
    int n = inorderList.size();
    int inorderIndex = 0;
    return makeList(inorderIndex, inorderList, n);
}

// 8. COUNT BST NODES THAT LIE IN A GIVEN RANGE               50%

int getCount(Node *root, int l, int h)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data >= l && root->data <= h)
    {
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    }

    if (root->data < l)
    {
        return getCount(root->right, l, h);
    }
    else
    {
        return getCount(root->left, l, h);
    }
}

// 9. LEAST COMMON ANCESTOR IN BST
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < n1 && root->data < n2)
    {
        return LCA(root->right, n1, n2);
    }
    else if (root->data > n1 && root->data > n2)
    {
        return LCA(root->left, n1, n2);
    }
    else
    {
        return root;
    }
}

// 10. INORDER SUCCESSOR AND PREDESSOR IN BST          40%
pair<int, int> solve(BinaryTreeNode<int> *root, int key)
{

    int pred = -1;
    int succ = -1;
    BinaryTreeNode<int> *curr = root;
    while (curr->data != key)
    {
        if (curr->data > key)
        {
            succ = curr->data;
            curr = curr->left;
        }
        else
        {
            pred = curr->data;
            curr = curr->right;
        }
    }

    BinaryTreeNode<int> *leftA = curr->left;
    while (leftA != NULL)
    {
        pred = leftA->data;
        leftA = leftA->right;
    }

    BinaryTreeNode<int> *rightA = curr->right;
    while (rightA != NULL)
    {
        succ = rightA->data;
        rightA = rightA->left;
    }
    pair<int, int> ans;
    ans.first = pred;
    ans.second = succ;
    return ans;
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    pair<int, int> ans = solve(root, key);
    return ans;
}

// 11. VALID BST                    50%
bool solve(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = solve(root->left, min, root->data - 1);
        bool right = solve(root->right, root->data + 1, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

// 12. CONVERT BINARY TREE TO BST

void inorder(Node *root, vector<int> &inorderList)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, inorderList);
    inorderList.push_back(root->data);
    inorder(root->right, inorderList);
}

void solve(Node *&root, vector<int> &inorderList, int &i)
{
    if (root == NULL || i >= inorderList.size())
    {
        return;
    }

    solve(root->left, inorderList, i);
    root->data = inorderList[i++];
    solve(root->right, inorderList, i);
}

public:
Node *binaryTreeToBST(Node *root)
{
    vector<int> inorderList;
    inorder(root, inorderList);
    sort(inorderList.begin(), inorderList.end());
    int i = 0;
    solve(root, inorderList, i);
    return root;
}

// 13. NORMAL BST TO BALANCED BST
void inorder(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

TreeNode<int> *solve(vector<int> &v, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = s + (e - s) / 2;
    TreeNode<int> *newRoot = new TreeNode<int>(v[mid]);
    newRoot->left = solve(v, s, mid - 1);
    newRoot->right = solve(v, mid + 1, e);
    return newRoot;
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> inorderList;
    inorder(root, inorderList);
    int n = inorderList.size();
    TreeNode<int> *ans = solve(inorderList, 0, n - 1);
    return ans;
}

// 14. CONSTRUCT TREE FROM PREORDER TRAVERSAL            

TreeNode<int> *solve(vector<int> &preOrder, int &i, int min, int max)
{
    if (i >= preOrder.size())
    {
        return NULL;
    }

    if (preOrder[i] < min || preOrder[i] > max)
    {
        return NULL;
    }
    TreeNode<int> *newRoot = new TreeNode<int>(preOrder[i++]);
    newRoot->left = solve(preOrder, i, min, newRoot->data - 1);
    newRoot->right = solve(preOrder, i, newRoot->data + 1, max);
    return newRoot;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    int preOrderIndex = 0;
    TreeNode<int> *ans = solve(preOrder, preOrderIndex, 1, INT_MAX);
    return ans;
}

// 15. POPULATE INORDER SUCCESSOR OF ALL NODES    // TO DO

void solve(Node *root, Node *&prev)
{
    if (root == NULL)
    {
        return;
    }

    solve(root->left, prev);
    if (prev != NULL)
    {
        prev->next = root;
    }

    prev = root;
    solve(root->right, prev);
}

public:
void populateNext(Node *root)
{
    Node *prev = NULL;
    solve(root, prev);
}

// 16. DELETE NODE                // TO DO

int getMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
Node *deleteNode(Node *root, int X)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == X)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int mini = getMin(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }

    else if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, X);
        return root;r
    }

    return root;
}

// 17. Replace every element with the least greater element on its right         // TO DO
Node *insert(Node *root, int data, Node *&succ)
{
    if (root == NULL)
    {
        return root = new Node(data);
    }

    if (root->data > data)
    {
        succ = root;
        root->left = insert(root->left, data, succ);
    }
    else
    {
        root->right = insert(root->right, data, succ);
    }
    return root;
}

public:
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;
        root = insert(root, arr[i], succ);
        if (succ)
        {
            arr[i] = succ->data;
        }
        else
        {
            arr[i] = -1;
        }
    }
    return arr;
}

