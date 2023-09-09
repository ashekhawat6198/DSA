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

Node *buildTree(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// 1. LEVEL ORDER TRAVERSAL

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        { // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    // OR

    vector<int> levelOrder(Node * node)
    {
        vector<int> ans;
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        return ans;
    }
}

// 2. INORDER TRAVERSAL

vector<int> ans;
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}

public:
vector<int> inorderTraversal(TreeNode *root)
{
    inorder(root);
    return ans;
}

// 3. PREORDER TRAVERSAL

vector<int> ans;
void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}

public:
vector<int> preorderTraversal(TreeNode *root)
{
    preorder(root);
    return ans;
}

// 4. POSTORDER TRAVERSAL

vector<int> ans;
void postOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    ans.push_back(root->val);
}

public:
vector<int> postorderTraversal(TreeNode *root)
{
    postOrder(root);
    return ans;
}

// 5. COUNT LEAF NODES

Void preorder(BinaryTreeNode<int> *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    preorder(root->left, count);

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    preorder(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    preorder(root, count);
    return count;
}

// 6. HEIGHT OF A TREE

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

// 7. DIAMETER OF TREE

pair<int, int> diameterFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

public:
// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{
    return diameterFast(root).first;
}

// 8. CHECK A BINARY TREE BALANCED OR NOT

pair<bool, int> checkBalanced(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = checkBalanced(root->left);
    pair<bool, int> right = checkBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

public:
// Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    return checkBalanced(root).first;
}

// 9. DETERMINE IF TWO TREES ARE IDENTICAL
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 10. SUM TREE

pair<bool, int> SumTree(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftA = SumTree(root->left);
    pair<bool, int> rightA = SumTree(root->right);

    bool first = leftA.first;
    bool second = rightA.first;

    bool cond = root->data == leftA.second + rightA.second;

    pair<bool, int> ans;

    if (first && second && cond)
    {
        ans.first = true;
        ans.second = root->data + leftA.second + rightA.second;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

public:
bool isSumTree(Node *root)
{
    return SumTree(root).first;
}

// 11. ZIG-ZAG TREE TRAVERSAL

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        leftToRight = !leftToRight;

        for (int i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

// 12. BOUNDARY TRAVERSAL OF BINARY TREE              dekhna ek baar

void traverseLeft(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void leafTraverse(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    leafTraverse(root->left, ans);
    leafTraverse(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{

    if ((root == NULL) || root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

public:
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left part print/store

    traverseLeft(root->left, ans);

    // traverse leaf nodes

    // left subtree
    leafTraverse(root->left, ans);
    // right subtree
    leafTraverse(root->right, ans);

    // traverse right part

    traverseRight(root->right, ans);
    return ans;
}

// 13. VERTICAL TRAVERSAL OF BINARY TREE
vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// 14. TOP VIEW OF BINARY TREE

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for HD than do nothing
        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// 15. BOTTOM VIEW OF BINARY TREE

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// 16. LEFT VIEW OF BINARY TREE
void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// 17. RIGHT VIEW OF BINARY TREE

void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// 18. Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)

void solve(Node *root, int len, int &maxLen, int sum, int &maxSum)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, len + 1, maxLen, sum, maxSum);
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

public:
int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}

// 19. LOWEST COMMON ANCESTOR IN BINARY TREE

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }

    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else
    {
        return NULL;
    }
}

// 20. K PATH SUM

void solve(TreeNode *root, int k, int &count, vector<int> path)
{

    if (root == NULL)
    {
        return;
    }

    path.push_back(root->val);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    // check for k sum

    int size = path.size();
    long long sum = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }

    path.pop_back();
}

public:
int pathSum(TreeNode *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

// 21. Kth ANCESTOR

Node *solve(Node *root, int &k, int node)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    // wapas
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

// 22. MAXIMUM SUM OF NON ADJACENT NODES

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

// 23. CONSTRUCT TREE FROM INORDER AND PREORDER
int findPosition(int in[], int element, int inorderStart, int inorderEnd)
{
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (element == in[i])
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &index, int inorderS, int inorderE, int n)
{

    if (index >= n || inorderS > inorderE)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = findPosition(in, element, inorderS, inorderE);

    root->left = solve(in, pre, index, inorderS, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderE, n);
    return root;
}

public:
Node *buildTree(int in[], int pre[], int n)

{
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

// 24.  CONSTRUCT TREE FROM INORDER AND POSTORDER

int findPosition(int in[], int element, int inorderStart, int inorderEnd)
{
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (element == in[i])
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int post[], int &index, int inorderS, int inorderE, int n)
{

    if (index < 0 || inorderS > inorderE)
    {
        return NULL;
    }

    int element = post[index--];
    Node *root = new Node(element);
    int position = findPosition(in, element, inorderS, inorderE);

    root->right = solve(in, post, index, position + 1, inorderE, n);
    root->left = solve(in, post, index, inorderS, position - 1, n);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{

    int postOrderIndex = n - 1;
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n);
    return ans;
}

// 25. MORRIS INORDER TRAVERSAL
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

// 26. MORRIS PREORDER TRAVERSAL
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

// 27. FLATTEN BINARY TREE TO LINKED LIST
void flatten(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            Node *prev = curr->left;
            while (prev->right != NULL)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// 28. INVERT A BINARY TREE    OR  MIRROR TREE
TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

// 29. CHECK IF A TREE IS ISOMORPHIC
bool isIsomorphic(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1->data != r2->data)
    {
        return false;
    }

    bool a = isIsomorphic(r1->left, r2->left);
    bool b = isIsomorphic(r1->right, r2->right);
    bool c = isIsomorphic(r1->right, r2->left);
    bool d = isIsomorphic(r1->left, r2->right);

    if ((a && b) || (c && d))
    {
        return true;
    }
    else
    {
        return false;
    }
}

   