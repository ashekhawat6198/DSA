#include <iostream>
using namespace std;

// 1.FIBONACCI SERIES NUMBER    ( TOP DOWN APPROACH )        ( TC:- O(N)   && SC:-O(N)+O(N)=O(N))

int fibb(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (fibb(n - 1, dp) % 1000000007 + fibb(n - 2, dp) % 1000000007) % 1000000007;

    return (dp[n] % 1000000007);
}

public:
int nthFibonacci(int n)
{
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    return fibb(n, dp);
}

// OR     ( BOTTOM UP APPROACH )      ( TC:- O(N) && SC:- O(N))

int nthFibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n] % 1000000007;
}

// OR       ( SPACE OPTIMISATION )               ( TC:- O(N) && SC:- O(1))
int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;
    return 0;
}

// 2. MINIMUM COST CLIMBING STAIRS    ( TOP DOWN APPROACH )          ( TC:- O(N)   && SC:-O(N)+O(N)=O(N))

int solve(int n, vector<int> &cost, vector<int> &dp)
{
    if (n == 0)
    {
        return cost[0];
    }

    if (n == 1)
    {
        return cost[1];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
    return dp[n];
}

public:
int minCostClimbingStairs(vector<int> &cost, int n)
{
    vector<int> dp(n + 1, -1);
    int ans = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
    return ans;
}

// OR   ( BOTTOM UP APPROACH )           ( TC:- O(N) && SC:- O(N))
int solve(int n, vector<int> &cost)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

public:
int minCostClimbingStairs(vector<int> &cost, int n)
{
    return solve(n, cost);
}

// OR        ( SPACE OPTIMISATION )       ( TC:- O(N) && SC:- O(1))
int solve(int n, vector<int> &cost)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

public:
int minCostClimbingStairs(vector<int> &cost, int n)
{
    return solve(n, cost);
}

// 3. MINIMUM NUMBER OF COINS     ( TOP DOWN APPROACH )      ( TC:- O(V*M)   && SC:-O(V)))

int solve(int coins[], int m, int v, vector<int> &dp)
{
    if (v == 0)
    {
        return 0;
    }
    if (v < 0)
    {
        return INT_MAX;
    }

    if (dp[v] != -1)
    {
        return dp[v];
    }

    int mini = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        int ans = solve(coins, m, v - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    dp[v] = mini;
    return dp[v];
}

public:
int minCoins(int coins[], int M, int V)
{
    vector<int> dp(V + 1, -1);
    int ans = solve(coins, M, V, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

// OR   ( BOTTOM UP APPROACH )                          ( TC:- O(V*M)   && SC:-O(V)))
int solve(int num[], int m, int v)
{
    vector<int> dp(v + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= v; i++)
    {
        // trying to solve for every amount figure from 1 to x
        for (int j = 0; j < m; j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    return dp[v];
}

public:
int minCoins(int coins[], int M, int V)
{
    int ans = solve(coins, M, V);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

// OR        ( SPACE OPTIMISATION )    NOT POSSIBLE

// 4. MAXIMUM SUM OF NON ADJACENT ELEMENTS      ( TOP DOWN APPROACH )               ( TC:- O(N)   && SC:-O(N)+O(N)=O(N))
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return nums[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int include = solve(nums, n - 2, dp) + nums[n];
    int exclude = solve(nums, n - 1, dp) + 0;

    dp[n] = max(include, exclude);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solve(nums, n - 1, dp);
    return ans;
}

// OR   ( BOTTOM UP APPROACH )                 ( TC:- O(N) && SC:- O(N))

int solve(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    int ans = solve(nums);
    return ans;
}

// OR        ( SPACE OPTIMISATION )             ( TC:- O(N) && SC:- O(1))
int solve(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{

    int ans = solve(nums);
    return ans;
}

// 5. HOUSE ROBBERY                      ( TC:- O(N) && SC:- O(N)
long long int solve(vector<long long int> &nums)
{
    long long int n = nums.size();
    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        long long int include = prev2 + nums[i];
        long long int exclude = prev1 + 0;
        long long int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    long long int n = valueInHouse.size();
    vector<long long int> left, right;

    if (n == 1)
    {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            left.push_back(valueInHouse[i]);
        }

        if (i != 0)
        {
            right.push_back(valueInHouse[i]);
        }
    }

    return max(solve(left), solve(right));
}

// 6. CUT ROAD INTO SEGMENTS  ( TOP DOWN APPROACH )      ( TC:- O(N)   && SC:-O(N)+O(N)=O(N))

int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = solve(n - x, x, y, z, dp) + 1;
    int b = solve(n - y, x, y, z, dp) + 1;
    int c = solve(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
    {
        return 0;
    }
    else
        return ans;
}

// OR ( BOTTOM UP APPROACH )             ( TC:- O(N)   && SC:-O(N))
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    if (dp[n] < 0)
        return 0;
    else
        return dp[n];
}

public:
// Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    int ans = solve(n, x, y, z, dp);
    return ans;
}

// OR         ( SPACE OPTIMISATION )    NOT POSSIBLE

// 7. COUNT DEARNGEMENTS    ( TOP DOWN APPROACH )      ( TC:- O(N)   && SC:-O(N)+O(N)=O(N))
#define MOD 1000000007
long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
        return 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = ((n - 1) % MOD) * (solve(n - 1, dp) % MOD + solve(n - 2, dp) % MOD) % MOD;
    return dp[n];
}

long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, -1);
    return solve(n, dp);
}

// OR (BOTTOM UP APPROACH )     ( TC:- O(N)   && SC:-O(N))
long long int solve(int n)
{
    vector<long long int> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int add = (first + second) % MOD;
        long long int ans = ((i - 1) * add) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}

long long int countDerangements(int n)
{

    return solve(n);
}

// OR ( SPACE OPTIMISATION )    ( TC:- O(N)   && SC:-O(1))

long long int solve(int n)
{
    vector<long long int> dp(n + 1);
    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int add = (first + second) % MOD;
        long long int curr = ((i - 1) * add) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int countDerangements(int n)
{

    return solve(n);
}