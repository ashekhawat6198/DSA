#include <iostream>
using namespace std;

// 1. IMPLEMENTATION
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

// 2. BFS (BREADTH FIRST SEARCH TRAVERSAL )   ( TC:- O(V+E) && SC:- O(V))
void bfs(vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;

    unordered_map<int, bool> visited;

    bfs(adj, visited, ans);

    return ans;
}

// 3. DFS (DEAPTH FIRST SEARCH ALGORITHM)
void dfs(vector<int> &ans, unordered_map<int, bool> &visited, vector<int> adj[], int node)
{
    visited[node] = true;
    ans.push_back(node);
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(ans, visited, adj, i);
        }
    }
}

public:
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    dfs(ans, visited, adj, 0);
    return ans;
}

// 4. NO OF PROVINCES
void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(adj, visited, neighbour, node);
        }
    }
}

int findCircleNum(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adjL[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1 && i != j)
            {
                adjL[i].push_back(j);
                adjL[j].push_back(i);
            }
        }
    }

    unordered_map<int, bool> visited;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(adjL, visited, i, -1);
        }
    }
    return count;
}

// 5. 0/1 MATRIX
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int i = temp.first;
        int j = temp.second;
        if ((i + 1) < r && dist[i + 1][j] == -1)
        {
            dist[i + 1][j] = dist[i][j] + 1;
            q.push({i + 1, j});
        }
        if ((j + 1) < c && dist[i][j + 1] == -1)
        {
            dist[i][j + 1] = dist[i][j] + 1;
            q.push({i, j + 1});
        }
        if ((i - 1) >= 0 && dist[i - 1][j] == -1)
        {
            dist[i - 1][j] = dist[i][j] + 1;
            q.push({i - 1, j});
        }
        if ((j - 1) >= 0 && dist[i][j - 1] == -1)
        {
            dist[i][j - 1] = dist[i][j] + 1;
            q.push({i, j - 1});
        }
    }

    return dist;
}

// 6. Surrounded Regions

bool isValid(int i, int j, int r, int c, vector<vector<char>> &board)
{
    if (i >= 0 && i < r && j >= 0 && j < c && board[i][j] == 'O')
    {
        return true;
    }

    return false;
}

void dfs(vector<vector<char>> &board, int i, int j, int r, int c)
{
    board[i][j] = 'B';

    if (isValid(i + 1, j, r, c, board))
    {
        dfs(board, i + 1, j, r, c);
    }
    if (isValid(i, j + 1, r, c, board))
    {
        dfs(board, i, j + 1, r, c);
    }
    if (isValid(i - 1, j, r, c, board))
    {
        dfs(board, i - 1, j, r, c);
    }
    if (isValid(i, j - 1, r, c, board))
    {
        dfs(board, i, j - 1, r, c);
    }
}

void convert(vector<vector<char>> &board)
{
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'B')
            {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++)
    {

        // left -> top to bottom
        int j = 0;
        if (board[i][j] == 'O')
        {
            dfs(board, i, j, r, c);
        }

        // right -> top to bottom
        j = c - 1;
        if (board[i][j] == 'O')
        {
            dfs(board, i, j, r, c);
        }
    }

    for (int j = 0; j < c; j++)
    {

        // top->left to right
        int i = 0;
        if (board[i][j] == 'O')
        {
            dfs(board, i, j, r, c);
        }

        // bottom->left to right
        i = r - 1;
        if (board[i][j] == 'O')
        {
            dfs(board, i, j, r, c);
        }
    }

    convert(board);
}

// 7. WORD LADDER

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == endWord)
            return steps;
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                // it exist
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            // back to original means hit where t is changing then after changing we are placing t
            // its original position
            word[i] = original;
        }
    }

    return 0;
}

// 8. NO OF ENCLAVES
bool isValid(vector<vector<int>> &grid, int r, int c, int i, int j)
{
    if (i >= 0 && i < r && j >= 0 && j < c && grid[i][j] == 1)
    {
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> &grid, int r, int c, int i, int j)
{
    grid[i][j] = 0;
    if (isValid(grid, r, c, i + 1, j))
    {
        dfs(grid, r, c, i + 1, j);
    }
    if (isValid(grid, r, c, i - 1, j))
    {
        dfs(grid, r, c, i - 1, j);
    }
    if (isValid(grid, r, c, i, j + 1))
    {
        dfs(grid, r, c, i, j + 1);
    }
    if (isValid(grid, r, c, i, j - 1))
    {
        dfs(grid, r, c, i, j - 1);
    }
}

void getCount(vector<vector<int>> &grid, int &count)
{
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; i++)
    {
        int j = 0;
        if (grid[i][j] == 1)
        {
            dfs(grid, r, c, i, j);
        }

        j = c - 1;
        if (grid[i][j] == 1)
        {
            dfs(grid, r, c, i, j);
        }
    }
    for (int j = 0; j < c; j++)
    {
        int i = 0;
        if (grid[i][j] == 1)
        {
            dfs(grid, r, c, i, j);
        }

        i = r - 1;
        if (grid[i][j] == 1)
        {
            dfs(grid, r, c, i, j);
        }
    }

    int count = 0;
    getCount(grid, count);
    return count;
}

// 9. Find eventual safe states
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<int> adj[n];
    vector<int> indegree(n, 0);

    // transpose and indegree
    for (int i = 0; i < n; i++)
    {
        for (auto j : graph[i])
        {
            adj[j].push_back(i);
            indegree[i]++;
        }
    }

    // node with 0 indegree push in queue
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // kjans algo
    vector<int> ans;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for (auto neighbour : adj[top])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// 10. DETECT CYCLE IN UNDIRECTED GRAPH USING BFS
bool bfs(vector<int> adj[], unordered_map<int, bool> &visited, int node)
{
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adj[frontNode])
        {
            if (visited[neighbour] == true && neighbour != parent[frontNode])
            {
                return true;
            }

            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

public:
bool isCycle(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = bfs(adj, visited, i);
            if (ans == true)
                return true;
        }
    }

    return false;
}

// 11. DETECT CYCLE IN UNDIRECTED GRAPH USING DFS
bool dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool ans = dfs(adj, visited, neighbour, node);
            if (ans)
                return true;
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

public:
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(adj, visited, i, -1);
            if (ans == true)
                return true;
        }
    }

    return false;
}

// 12. DETECT CYCLE IN DIRECTED GRAPH USING DFS
bool dfsdirected(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, int node)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool ans = dfsdirected(adj, visited, dfsVisited, neighbour);
            if (ans == true)
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = dfsdirected(adj, visited, dfsVisited, i);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}

// 13. TOPOLOGICAL SORT USING DFS
void solve(vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &st, int node)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            solve(adj, visited, st, neighbour);
        }
    }

    st.push(node);
}

public:
// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            solve(adj, visited, st, i);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// 14.TOPOLOGICAL SORT USING BFS OR KAHN'S ALGORITHM          ( TC:- O(N+E) && O(N+E))         dekhna ek baar
vector<int> topoSort(int V, vector<int> adj[])
{
    // find all indegrees
    vector<int> in(V);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            in[j]++;
        }
    }

    // 0 degree waalo ko push krdo
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs kro
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto neighbour : adj[frontNode])
        {
            in[neighbour]--;
            if (in[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

// 15. DETECT CYCLE IN DIRECTED GRAPH USING BFS/KAHNS ALGO             ( TC:- O(N+E) && O(N+E))
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        count++;

        for (auto neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if (count == V)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// 16.  SHORTEST PATH IN UNDIRECTED AND UNWEIGHTED GRAPH

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    vector<int> ans;

    int currNode = t;
    ans.push_back(currNode);

    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// 17. SHORTEST PATH IN DIRECTED ACYCLIC GRAPH               ( TC:- O(N+E) && O(N+E))

void solve(unordered_map<int, list<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &st, int node)
{
    visited[node] = true;

    for (auto x : adj[node])
    {
        if (!visited[x.first])
        {
            solve(adj, visited, st, x.first);
        }
    }

    st.push(node);
}

public:
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int dt = edges[i][2];

        adj[u].push_back({v, dt});
    }

    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            solve(adj, visited, st, i);
        }
    }

    vector<int> dis(N);
    for (int i = 0; i < N; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (dis[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                if (dis[top] + i.second < dis[i.first])
                {
                    dis[i.first] = dis[top] + i.second;
                }
            }
        }
        else
        {
            dis[top] = -1;
        }
    }

    return dis;
}

// 18. PRIMS ALGORITHM

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {

        int mini = INT_MAX;
        int u;

        // fin min value

        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true

        mst[u] = true;

        // check its adjacent nodes
        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {                                               // o se isliye ni chalaya(kuki mapping 1 se start hai )
        result.push_back({{parent[i], i}, key[i]}); // 1 se isliye ni chalay (kuki 1 ka parent -1 hai)
    }

    return result;
}

// 19. DIJKSTRA'S ALGORITHM            (TC:- O( E LOG V) && SC:- O(N+E))

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dis(vertices);
    set<pair<int, int>> st;

    for (int i = 0; i < vertices; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {

        // top nikala
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int node = top.second;

        // set se hataya
        st.erase(st.begin());

        // neighbour par jaao

        for (auto neighbour : adj[node])
        {
            if (nodeDistance + neighbour.second < dis[neighbour.first])
            {
                // check in set for already present record

                auto record = st.find(make_pair(dis[neighbour.first], neighbour.first));
                // found than erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                dis[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dis[neighbour.first], neighbour.first));
            }
        }
    }

    return dis;
}

// 20. KRUSKAL'S ALGORTIHM (using disjoint set find mst)

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(vector<int> &parent, int u, int v, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }

    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }

    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];
        if (u != v)
        {
            minWeight += w;
            unionSet(parent, u, v, rank);
        }
    }
    return minWeight;
}

// OR  (MST)

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0);

    // weight,node
    int sum = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }

    return sum;
}

// 21. BRIDGES IN GRAPH

/*
tin(time of insertion):-track when you are reaching a node or at which step you are reaching a node
low:-lowest time insertion of all adjacent nodes apart from parent
*/

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[],
         vector<vector<int>> &bridges, int timer)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(it, node, vis, adj, tin, low, bridges, timer);
            low[node] = min(low[node], low[it]);
            // node --- it
            if (low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            // bridge is not possible as it is visited
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    int timer = 0;
    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges, timer);
    return bridges;
}

// 22. ARTICUALTION POINT


/*
tin(time of insertion):-track when you are reaching a node or at which step you are reaching a node
low:-lowest time insertion of all adjacent nodes apart from parent && visited nodes
*/

 void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],vector<int>&mark,
  vector<int>adj[],int timer){
      vis[node]=1;
      tin[node]=low[node]=timer++;
      int child=0;
      for(auto it:adj[node]){
          if(it==parent) continue;
          if(!vis[it]){
              dfs(it,node,vis,tin,low,mark,adj,timer);
              low[node]=min(low[node],low[it]);
              if(low[it]>=tin[node] && parent!=-1){        //  parent!=-1 :- as it still stays the 1 component
                  mark[node]=1;
                  
              }
              child++;
          }
          else{
              low[node]=min(low[node],tin[it]);   // we are taking tin instead of low as the node might be removed
          }
      }
      if(child>1 && parent==-1){   // is starting node has more than 1 child
         mark[node]=1; 
      }
  }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>vis(V,0);
        int tin[V];
        int low[V];
        vector<int>mark(V,0);
        int timer=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,mark,adj,timer);
            }
        } 
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }  
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
// 23.Count Strongly Connected Components (Kosaraju’s Algorithm)

void dfs(int node, stack<int> &st, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, st, visited, adj);
        }
    }

    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;
    for (auto neighbour : transpose[node])
    {
        if (!visited[neighbour])
        {
            revDfs(neighbour, visited, transpose);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // topological sort

    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, st, visited, adj);
        }
    }

    // tanspose

    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            revDfs(top, visited, transpose);
        }
    }
    return count;
}

// 24. BELLMAN FORD ALGORITHM

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dis(n + 1, 1e9);
    dis[src] = 0;

    // n-1 times
    for (int i = 1; i < n; i++)
    {
        // traverse in edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dis[u] != 1e9 && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    bool flag = false;

    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dis[u] != 1e9 && dis[u] + w < dis[v])
        {
            flag = true;
        }
    }

    if (flag == false)
    {
        return dis[dest];
    }
    return -1;
    // return dis[dest];
}

// 25. CLONE A GRAPH

Node *dfs(Node *node, unordered_map<Node *, Node *> &mp)
{
    vector<Node *> neighbours;
    Node *clone = new Node(node->val);
    mp[node] = clone;

    for (auto it : node->neighbors)
    {
        if (mp.find(it) != mp.end())
        {
            neighbours.push_back(mp[it]);
        }
        else
        {
            neighbours.push_back(dfs(it, mp));
        }
    }

    clone->neighbors = neighbours;
    return clone;
}

public:
Node *cloneGraph(Node *node)
{
    unordered_map<Node *, Node *> mp;
    if (node == NULL)
    {
        return NULL;
    }
    if (node->neighbors.size() == 0)
    {
        Node *clone = new Node(node->val);
        return clone;
    }
    return dfs(node, mp);
}

// 26. FLOOD FILL ALGORITHM

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &image, int newColor, int r, int c, int oldColor)
{
    if (i < 0 || j < 0 || i >= r || j >= c)
        return;
    if (vis[i][j] || image[i][j] != oldColor)
        return;
    vis[i][j] = 1;
    image[i][j] = newColor;
    dfs(i + 1, j, vis, image, newColor, r, c, oldColor);
    dfs(i - 1, j, vis, image, newColor, r, c, oldColor);
    dfs(i, j + 1, vis, image, newColor, r, c, oldColor);
    dfs(i, j - 1, vis, image, newColor, r, c, oldColor);
}

public:
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int r = image.size();
    int c = image[0].size();
    vector<vector<int>> vis(r, vector<int>(c, 0));
    int oldColor = image[sr][sc];
    dfs(sr, sc, vis, image, color, r, c, oldColor);
    return image;
}

// 21. FIND NO OF ISLAND
void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited, int r, int c)
{
    if (i < 0 || j < 0 || i >= r || j >= c)
        return;
    if (grid[i][j] == 0)
        return;
    if (!visited[i][j] && grid[i][j] == '1')
    {
        visited[i][j] = 1;
        dfs(i + 1, j, grid, visited, r, c);
        dfs(i - 1, j, grid, visited, r, c);
        dfs(i, j + 1, grid, visited, r, c);
        dfs(i, j - 1, grid, visited, r, c);
        dfs(i + 1, j + 1, grid, visited, r, c);
        dfs(i - 1, j - 1, grid, visited, r, c);
        dfs(i + 1, j - 1, grid, visited, r, c);
        dfs(i - 1, j + 1, grid, visited, r, c);
    }
}

public:
// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> visited(r, vector<int>(c, 0));
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                dfs(i, j, grid, visited, r, c);
                count++;
            }
        }
    }
    return count;
}

// 27. MAKING WIRED CONNECTIONS

void dfs(int node, unordered_map<int, bool> &vis, vector<vector<int>> &connections, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, vis, connections, adj);
        }
    }
}

public:
int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
    {
        return -1;
    }
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> vis;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, connections, adj);
            count++;
        }
    }

    return count - 1;
}

// 28. STEPS BY KNIGHT

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    int n = N;
    int tx = TargetPos[0], ty = TargetPos[1];
    int sx = KnightPos[0], sy = KnightPos[1];

    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (tx == sx && ty == sy)
        return 0;
    queue<pair<int, int>> q;
    q.push({sx - 1, sy - 1});

    while (!q.empty())
    {

        pair<int, int> p = q.front();
        q.pop();

        int i = p.first;
        int j = p.second;

        if ((i + 1) >= 0 && (i + 1) < n && (j + 2) >= 0 && (j + 2) < n && vis[i + 1][j + 2] == 0)
        {
            vis[i + 1][j + 2] = vis[i][j] + 1;
            q.push(make_pair(i + 1, j + 2));
        }

        if ((i + 1) >= 0 && (i + 1) < n && (j - 2) >= 0 && (j - 2) < n && vis[i + 1][j - 2] == 0)
        {
            vis[i + 1][j - 2] = vis[i][j] + 1;
            q.push(make_pair(i + 1, j - 2));
        }

        if ((i - 1) >= 0 && (i - 1) < n && (j + 2) >= 0 && (j + 2) < n && vis[i - 1][j + 2] == 0)
        {
            vis[i - 1][j + 2] = vis[i][j] + 1;
            q.push(make_pair(i - 1, j + 2));
        }

        if ((i - 1) >= 0 && (i - 1) < n && (j - 2) >= 0 && (j - 2) < n && vis[i - 1][j - 2] == 0)
        {
            vis[i - 1][j - 2] = vis[i][j] + 1;
            q.push(make_pair(i - 1, j - 2));
        }

        if ((i + 2) >= 0 && (i + 2) < n && (j + 1) >= 0 && (j + 1) < n && vis[i + 2][j + 1] == 0)
        {
            vis[i + 2][j + 1] = vis[i][j] + 1;
            q.push(make_pair(i + 2, j + 1));
        }

        if ((i + 2) >= 0 && (i + 2) < n && (j - 1) >= 0 && (j - 1) < n && vis[i + 2][j - 1] == 0)
        {
            vis[i + 2][j - 1] = vis[i][j] + 1;
            q.push(make_pair(i + 2, j - 1));
        }

        if ((i - 2) >= 0 && (i - 2) < n && (j + 1) >= 0 && (j + 1) < n && vis[i - 2][j + 1] == 0)
        {
            vis[i - 2][j + 1] = vis[i][j] + 1;
            q.push(make_pair(i - 2, j + 1));
        }

        if ((i - 2) >= 0 && (i - 2) < n && (j - 1) >= 0 && (j - 1) < n && vis[i - 2][j - 1] == 0)
        {
            vis[i - 2][j - 1] = vis[i][j] + 1;
            q.push(make_pair(i - 2, j - 1));
        }
    }

    return vis[tx - 1][ty - 1];
}

// 29. PREREQUISITE TASKS
bool dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
         unordered_map<int, bool> &dfsvisited)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool ans = dfs(neighbour, adj, visited, dfsvisited);
            if (ans)
                return true;
        }
        else if (dfsvisited[neighbour])
        {
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

public:
bool isPossible(int N, int P, vector<pair<int, int>> &pre)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < P; i++)
    {
        int u = pre[i].first;
        int v = pre[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bool ans = dfs(i, adj, visited, dfsVisited);
            if (ans == true)
                return false;
        }
    }
    return true;
}

// 30. MINIMUM TIME TAKEN BY EACH JOB TO BE COMPLETED GIVEN BY DAG
vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (auto nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    vector<int> job(n + 1);

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            job[i]++;
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                job[neighbour] = job[node] + 1;
                q.push(neighbour);
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(job[i]);
    }

    return res;
}

// 31. BIPARTITE GRAPH    = COLOR THE GRAPGH WITHIN TWO COLORS SUCH THAT NO ADJACENT NODES HAVE SAME COLOR        *** TO DO
// LINEAR GRAPH WHICH HAVE NO CYCLE ARE ALWAYS  BIPARTITE GRAPH
// ANY GRAPH WITH EVEN CYCLE LENGTH CAN ALSO BE BIPARTITE
// ANY GRAPH WITH ODD CYCLE LENGTH CAN NEVER BE A BIPARTITIE

bool solve(int start, vector<int> adj[], vector<int> &color, int V)
{
    queue<int> q;
    q.push(start);

    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            // if adjacent node is not colored yet
            // you will give opposite colour of node
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            // is adjacent node have same color
            // someone did color on it same other path
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

public:
bool isBipartite(int V, vector<int> adj[])
{

    vector<int> color(V);
    for (int i = 0; i < V; i++)
        color[i] = -1;

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            bool ans = solve(i, adj, color, V);
            if (ans == false)
                return false;
        }
    }
    return true;
}

// 32. JOURNEY TO THE MOON

void solve(int node, unordered_map<int, list<int>> &adj, int &counter, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    counter++;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            solve(neighbour, adj, counter, visited);
        }
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < astronaut.size(); i++)
    {
        int u = astronaut[i][0];
        int v = astronaut[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sol;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int counter = 0;
            solve(i, adj, counter, visited);
            sol.push_back(counter);
        }
    }

    int val = (n * (n - 1)) / 2;
    for (int i = 0; i < sol.size(); i++)
    {
        int x = (sol[i] * (sol[i] - 1)) / 2;
        val = val - x;
    }

    return val;
}

// 33. Shortest path in a binary maze
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    if (grid[0][0] == 1)
        return -1;
    dist[0][0] = 0;
    q.push({0, {0, 0}});
    int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if (r == n - 1 && c == m - 1)
            return 1 + dis;
        for (int i = 0; i < 8; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                grid[newr][newc] == 0 && dis + 1 < dist[newr][newc])
            {
                dist[newr][newc] = 1 + dis;
                // if(newr==n-1 && newc==m-1){
                //     return dis+1;
                // }
                q.push({1 + dis, {newr, newc}});
            }
        }
    }
    return -1;
}

// 34. ALIEN DIRECTORY
vector<int> topoSort(int V, vector<int> adj[])
{
    // find all indegrees
    vector<int> in(V);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            in[j]++;
        }
    }

    // 0 degree waalo ko push krdo
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs kro
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto neighbour : adj[frontNode])
        {
            in[neighbour]--;
            if (in[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

string findOrder(string dict[], int N, int K)
{

    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        int len = min(word1.size(), word2.size());
        for (int j = 0; j < len; j++)
        {
            if (word1[j] != word2[j])
            {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);

    string ans = "";
    for (auto i : topo)
    {
        ans = ans + char(i + 'a');
    }
    return ans;
}

// 35. PATH WITH MINIMUM EFFORT
int minimumEffortPath(vector<vector<int>> &heights)
{ // {diff,{row,col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return diff;
        for (int i = 0; i < 4; i++)
        {
            int newr = row + dr[i];
            int newc = col + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m)
            {
                int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                if (newEffort < dist[newr][newc])
                {
                    dist[newr][newc] = newEffort;
                    pq.push({dist[newr][newc], {newr, newc}});
                }
            }
        }
    }
    return 0;
}

// 36. Cheapest flights within k stops
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    dist[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if (stops > k)
            continue; // you can go 1+stops not more than that i.e. (k==2) here k will be 3
        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int adjW = iter.second;
            if (cost + adjW < dist[adjNode] && stops <= k)
            { // yaha tak stops equal ho ya kam ho
                dist[adjNode] = cost + adjW;
                q.push({stops + 1, {adjNode, cost + adjW}});
            }
        }
    }

    if (dist[dst] == INT_MAX)
        return -1;
    return dist[dst];
}

// 37. Number of Ways to Arrive at Destination
int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, long long int>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    vector<long long int> dist(n, LONG_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    int mod = (1e9 + 7);
    pq.push({0, 0}); // dist,node
    while (!pq.empty())
    {
        long long int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            long long int edW = it.second;
            // this is the first time i am arriving
            // with this short distance
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + edW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

// 38. BELLMEN FORD ALGO (ONLY FOR DIRECTED)

/* YOU HAVE TO DO N-1 RELAXATION

  RELAXATION (on every edge):-
  if(dist[u]+wt<dist[v]){
  dist[v]=dist[u]+wt;

  }

*/

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // n th relaxation to check negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}

