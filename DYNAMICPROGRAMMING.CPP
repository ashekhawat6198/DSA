

// 1. MAXIMUM SUM OF NON ADJACENT ELEMENTS

//  A. RECURSIVE

int solve(vector<int> &nums, int i)
{
    if (i >= nums.size())
    {
        return 0;
    }

    int include = nums[i] + solve(nums, i + 2);
    int exclude = 0 + solve(nums, i + 1);

    return max(include, exclude);
}

int rob(vector<int> &nums)
{
    int i = 0;
    return solve(nums, i);
}

//  B. RECUSIVE + MEMOIZATION

int solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int include = nums[i] + solve(nums, i + 2, dp);
    int exclude = 0 + solve(nums, i + 1, dp);
    dp[i] = max(include, exclude);
    return max(include, exclude);
}

int rob(vector<int> &nums)
{
    int i = 0;
    vector<int> dp(nums.size() + 1, -1);
    return solve(nums, i, dp);
}

// C.   BOTTOM-UP APPROACH
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 2, 0);
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int incl = nums[i] + dp[i + 2];
        int excl = 0 + dp[i + 1];
        dp[i] = max(incl, excl);
    }

    return dp[0];
}

//  D.  BOTTOM-UP APPROACH WITH SPACH OPTIMISATION

int rob(vector<int> &nums)
{
    int next2 = 0;
    int next1 = 0;
    int curr;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int incl = nums[i] + next2;
        int excl = 0 + next1;
        curr = max(incl, excl);

        next2 = next1;
        next1 = curr;
    }

    return next1;
}

// 2. COIN CHANGE

// A. RECURSION

int solve(vector<int> &coins, int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, n - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = solve(coins, amount);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

// B. RECURSION + MEMOIZATION

int solve(vector<int> &coins, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MAX;
    if (dp[n] != -1)
        return dp[n];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, n - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[n] = mini;
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int ans = solve(coins, amount, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

// C. BOTTOM-UP APPROACH

int solve(vector<int> &coins, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int target = 1; target <= n; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];
                if (ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini;
    }

    return dp[n];
}

int coinChange(vector<int> &coins, int amount)
{

    int ans = solve(coins, amount);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

// 3. PERFECT SQUARES

// A. RECURSION

int solve(int n)
{
    if (n == 0)
        return 0;

    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i));
    }
    return ans;
}

int numSquares(int n)
{
    return solve(n);
}

// B.  RECURSION + MEMOIZATION
int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i, dp));
    }
    dp[n] = ans;
    return ans;
}

int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// C. BOTTOM-UP APPROACH
int solve(int N)
{
    vector<int> dp(N + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + dp[n - i * i]);
        }
        dp[n] = ans;
    }
    return dp[N];
}

int numSquares(int n)
{

    int ans = solve(n);
    return ans;
}

// 4. KNAPSACK PROBLEM

// A. RECURSIVE
int solve(int W, int wt[], int val[], int n, int i)
{
    if (i == n || W == 0)
    {
        return 0;
    }

    int include = 0;
    if (W >= wt[i])
    {
        include = val[i] + solve(W - wt[i], wt, val, n, i + 1);
    }

    int exclude = 0;
    exclude = 0 + solve(W, wt, val, n, i + 1);

    return max(include, exclude);
}
int knapSack(int W, int wt[], int val[], int n)
{
    int ans = solve(W, wt, val, n, 0);
    return ans;
}

// B. RECURSIVE AND MEMOIZATION
int solve(int W, int wt[], int val[], int n, int i, vector<vector<int>> &dp)
{
    if (i == n || W == 0)
    {
        return 0;
    }
    if (dp[i][W] != -1)
        return dp[i][W];

    int include = 0;
    if (W >= wt[i])
    {
        include = val[i] + solve(W - wt[i], wt, val, n, i + 1, dp);
    }

    int exclude = 0;
    exclude = 0 + solve(W, wt, val, n, i + 1, dp);

    dp[i][W] = max(include, exclude);
    ;
    return max(include, exclude);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    int ans = solve(W, wt, val, n, 0, dp);
    return ans;
}

// C BOTTOM-UP APPROACH
int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int W = 0; W <= w; W++)
        {
            int include = 0;
            if (W >= wt[i])
            {
                include = val[i] + dp[i + 1][W - wt[i]];
            }

            int exclude = 0;
            exclude = 0 + dp[i + 1][W];

            dp[i][W] = max(include, exclude);
        }
    }

    return dp[0][w];
}

// 5. Longest Common Subsequence

// A. RECURSION
int solve(string a, string b, int i, int j)
{
    if (i == a.size() || j == b.size())
    {
        return 0;
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solve(a, b, i + 1, j + 1);
    }
    else
    {
        ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    }

    return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int i = 0;
    int j = 0;
    return solve(text1, text2, i, j);
}

// B. RECURSION + MEMOIZATION

int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.size() || j == b.size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solve(a, b, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(solve(a, b, i + 1, j, dp), solve(a, b, i, j + 1, dp));
    }

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    int i = 0;
    int j = 0;
    return solve(text1, text2, i, j, dp);
}

// C. BOTTOM-UP APPROACH

int longestCommonSubsequence(string a, string b)
{

    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

// D.  BOTTOM-UP APPROACH WITH SPACE OPTIMISATION

vector<int> curr(b.length() + 1, 0);
vector<int> next(b.length() + 1, 0);

for (int i = a.length() - 1; i >= 0; i--)
{
    for (int j = b.length() - 1; j >= 0; j--)
    {
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + next[j + 1];
        }
        else
        {
            ans = max(next[j], curr[j + 1]);
        }

        curr[j] = ans;
    }
    next = curr;
}
return dp[0][0];

// 6. Longest Palindromic Subsequence

int solve(string a, string b)
{

    vector<int> curr(b.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j + 1]);
            }

            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int longestPalindromeSubseq(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int ans = solve(s, rev);
    return ans;
}

// 7. EDIT DISTANCE

// A. RECURSION
int solve(string a, string b, int i, int j)
{
    if (i == a.length())
    {
        return b.length() - j;
    }
    if (j == b.length())
    {
        return a.length() - i;
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = solve(a, b, i + 1, j + 1);
    }
    else
    {
        int insertAns = solve(a, b, i, j + 1);
        int replaceAns = solve(a, b, i + 1, j + 1);
        int deleteAns = solve(a, b, i + 1, j);
        ans = min(insertAns, min(replaceAns, deleteAns)) + 1;
    }
    return ans;
}
int minDistance(string word1, string word2)
{
    return solve(word1, word2, 0, 0);
}

// B. RECURSION + MEMOIZATION
int solve(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length())
    {
        return b.length() - j;
    }
    if (j == b.length())
    {
        return a.length() - i;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = solve(a, b, i + 1, j + 1, dp);
    }
    else
    {
        int insertAns = solve(a, b, i, j + 1, dp);
        int replaceAns = solve(a, b, i + 1, j + 1, dp);
        int deleteAns = solve(a, b, i + 1, j, dp);
        ans = min(insertAns, min(replaceAns, deleteAns)) + 1;
    }
    dp[i][j] = ans;
    return ans;
}
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    return solve(word1, word2, 0, 0, dp);
}

// BOTTOM-UP APPROACH

int minDistance(string a, string b)
{
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    for (int j = 0; j < b.length(); j++)
    {
        dp[a.length()][j] = b.length() - j;
    }

    for (int i = 0; i < a.length(); i++)
    {
        dp[i][b.length()] = a.length() - i;
    }

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                int insertAns = dp[i][j + 1];
                int replaceAns = dp[i + 1][j + 1];
                int deleteAns = dp[i + 1][j];
                ans = min(insertAns, min(replaceAns, deleteAns)) + 1;
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

// 8. Unique Binary Search Trees

// A. RECURSION
int solve(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1) * solve(n - i);
    }
    return ans;
}

int numTrees(int n)
{
    return solve(n);
}

// B. RECURSION + MEMOIZATION
int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1, dp) * solve(n - i, dp);
    }
    dp[n] = ans;
    return ans;
}

int numTrees(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// C. BOTTOM-UP APPROACH
int numTrees(int N)
{
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int n = 2; n <= N; n++)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dp[i - 1] * dp[n - i];
        }
        dp[n] = ans;
    }
    return dp[N];
}

// 9. Guess Number Higher or Lower II

// A. RECURSION

int solve(int start,int end){
    if(start>=end){
        return 0;
    }

    int mini=INT_MAX;
    for(int i=start;i<=end;i++){
        mini=min(mini,i+max(solve(start,i-1),solve(i+1,end)));
    }

    return mini;
  }
    int getMoneyAmount(int n) {
      return solve(1,n);   
    }


// B. RECURSION + MEMOIZATION

 int solve(int start,int end,vector<vector<int>>&dp){
    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1)
    return dp[start][end];

    int mini=INT_MAX;
    for(int i=start;i<=end;i++){
        mini=min(mini,i+max(solve(start,i-1,dp),solve(i+1,end,dp)));
    }
   dp[start][end]=mini;
    return mini;
  }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      return solve(1,n,dp);   
    }

// BOTTOM-UP APPROACH