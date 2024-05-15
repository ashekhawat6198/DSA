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

// 4. DETECT CYCLE IN UNDIRECTED GRAPH USING BFS
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

// 5. DETECT CYCLE IN UNDIRECTED GRAPH USING DFS
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

// 6. DETECT CYCLE IN DIRECTED GRAPH USING DFS
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

// 7. TOPOLOGICAL SORT USING DFS
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

// 8.TOPOLOGICAL SORT USING BFS OR KAHN'S ALGORITHM          ( TC:- O(N+E) && O(N+E))         dekhna ek baar
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

// 9. DETECT CYCLE IN DIRECTED GRAPH USING BFS/KAHNS ALGO             ( TC:- O(N+E) && O(N+E))
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

// 10.  SHORTEST PATH IN UNDIRECTED AND UNWEIGHTED GRAPH

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

// 11. SHORTEST PATH IN DIRECTED ACYCLIC GRAPH               ( TC:- O(N+E) && O(N+E))

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

// 12. PRIMS ALGORITHM

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

// 13. DIJKSTRA'S ALGORITHM            (TC:- O( E LOG V) && SC:- O(N+E))

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

// 14. KRUSKAL'S ALGORTIHM
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

// 15. BRIDGES IN GRAPH
void dfs(int node, int parent, vector<int> &dis, vector<int> &low, int timer,
         unordered_map<int, bool> &vis, vector<vector<int>> &result, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;
    dis[node] = low[node] = timer++;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (!vis[neighbour])
        {
            dfs(neighbour, node, dis, low, timer, vis, result, adj);
            low[node] = min(low[node], low[neighbour]);
            // check edge is bridge
            if (low[neighbour] > dis[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }

        else
        {
            // node already visited and not parent
            // back edge
            low[node] = min(low[node], dis[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(v);
    vector<int> low(v);
    int timer = 0;
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        dis[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, dis, low, timer, vis, result, adj);
        }
    }

    return result;
}

// 16. ARTICUALTION POINT

void dfs(int node, int parent, vector<int> &dis, vector<int> &low, int timer,
         unordered_map<int, bool> &vis, vector<vector<int>> &result, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;
    dis[node] = low[node] = timer++;
    int child = 0;
    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (!vis[neighbour])
        {
            dfs(neighbour, node, dis, low, timer, vis, result, adj);
            low[node] = min(low[node], low[neighbour]);
            // check AP or not
            if (low[neighbour] >= dis[node] && parent != -1)
            {
                ap[node] = true;
            }
            child++;
        }

        else
        {
            // node already visited and not parent
            // back edge
            low[node] = min(low[node], dis[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(v);
    vector<int> low(v);
    int timer = 0;
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        dis[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, dis, low, timer, vis, result, adj);
        }
    }

    return result;
}

// 17.Count Strongly Connected Components (Kosaraju’s Algorithm)

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

// 18. BELLMAN FORD ALGORITHM

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

// 19. CLONE A GRAPH

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

// 20. FLOOD FILL ALGORITHM

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

// 22. MAKING WIRED CONNECTIONS

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

// 23. STEPS BY KNIGHT

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

// 24. PREREQUISITE TASKS
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

// 25. MINIMUM TIME TAKEN BY EACH JOB TO BE COMPLETED GIVEN BY DAG
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

// 26. BIPARTITE GRAPH    = COLOR THE GRAPGH WITHIN TWO COLORS SUCH THAT NO ADJACENT NODES HAVE SAME COLOR        *** TO DO
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

// 27. JOURNEY TO THE MOON

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
