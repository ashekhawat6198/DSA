// BINARY SEARCH

#include <iostream>
using namespace std;

// 1. BASE PROGRAM  or  finding the index of the key

int binarySearch(int array[], int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (array[mid] == key)
        {
            return mid;
        }

        else if (key > array[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

// 2. LOWER BOUND

// BRUTE

int searchInsert(vector<int> &nums, int target)
{

    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= target)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

// OPTIMISED

int searchInsert(vector<int> &nums, int target) // O ( log N)
{
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

// OR LOWER BOUND IN C++ STL

int searchInsert(vector<int> &nums, int target)
{
    auto it = lower_bound(nums.begin(), nums.end(), target);
    auto ans = it - nums.begin();
    return ans;
}

// 3. UPPER BOUND

int searchInsert(vector<int> &nums, int target) // O ( log N)
{
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

// 4. FLOOR AND CIEL

int flor(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return arr[mid];
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (high >= 0)
    {
        return arr[high];
    }
    else
    {
        return -1;
    }
}

int ciel(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = arr[mid];
            return arr[mid];
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (low < n)
    {
        return arr[low];
    }
    else
    {
        return -1;
    }
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    sort(arr, arr + n);
    int a = flor(arr, n, x);
    int b = ciel(arr, n, x);
    pair<int, int> ans;
    ans.first = a;
    ans.second = b;
    return ans;
}

// 5. FIND FIRST AND LAST OCCURENCE OF X

// BRUTE FORCE USING LINEAR SEARCH     O(N)

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int first = -1;
    int last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target && first == -1)
        {
            first = i;
        }
    }

    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

//  BINARY SEARCH                           2 * O( log N)

int firstOccurence(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return first;
}

int lastOccurence(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int first = firstOccurence(nums, target);
    if (first == -1)
        return ans = {-1, -1};
    int last = lastOccurence(nums, target);
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

// 6. Count occurrences of a number in a sorted array with duplicates

int firstOccurence(int nums[], int target, int n)
{

    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return first;
}

int lastOccurence(int nums[], int target, int n)
{

    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return last;
}

int count(int arr[], int n, int x)
{
    int first = firstOccurence(arr, x, n);
    if (first == -1)
        return 0;
    int last = lastOccurence(arr, x, n);
    int ans = last - first + 1;
    return ans;
}

// 7. SEARCH IN ROTATED AND SORTED ARRAY        rotated sorted array mai ek part hamesha sorted hota hai toh ham binary search    sorted part mai lagate hai kuki vo uski property hai 

int search(vector<int> &nums, int target)
{ // O ( LOG N )
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;

        // left part sorted
        if (nums[low] <= nums[mid])
        {
            // checking that is targt lies in left part
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // right part sorted
        else
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// 8.  Search in Rotated Sorted Array II

bool search(vector<int> &nums, int target)
{ // AVERAGE CASE : O ( log N)     WORST CASE: O (N/2)
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;

        if (nums[low] == nums[mid] && nums[mid] == nums[high])   // you cant identify which part is sorted if you dont use this part
        { // [3 1 2 3 3 3 3] for this type of case
            low++;
            high--;
            continue;
        }

        // left part sorted
        if (nums[low] <= nums[mid])
        {
            // checking that is targt lies in left part
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // right part sorted
        else
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

// 9. MINIMUM IN ROTATED SORTED ARRAY 

   /* sorted half may or may not have the answer
    */
/*
  1) identify the sorted half
  2)  take min from sorted half and eleminate as i have picked the mini, now move to next part
  3) take the min and now eleminate again
*/

int findMin(vector<int> &nums)
{ // O ( log n)
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

// 10. FIND HOW MANY TIMES ARRAY HAS BEEN ROTATED

int findKRotation(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

// 11. FIND SINGLE ELEMENT IN SROTED ARRAY

// BRUTE FORCE     O(N)

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        else if (i == n - 1)
        {
            if (nums[i] != nums[i - 1])
                return nums[i];
        }
        else
        {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
                return nums[i];
        }
    }
    return -1;
}

// OPTIMAL APPROACH
int singleNonDuplicate(vector<int> &nums)
{ // O( log2 N)
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

           // elemmination that part where element is not there    [1,1,2,2,3,3,4,5,5,6,6,7,7]
                                                               //  [e,o,e,o,e,o,e,o,e,o,e,o,e]

        if (mid % 2 == 1 && nums[mid] == nums[mid - 1] || mid % 2 == 0 && nums[mid] == nums[mid + 1])
        { // left part so element is in right part
            low = mid + 1;
        }
        else
        { // right part so element is in left part
            high = mid - 1;
        }
    }
    return -1;
}

// 12. FIND PEAK ELEMENT

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// 13. FIND SQUARE ROOT OF A NUMBER

// BRUTE FORCE

long long int floorSqrt(long long int x)
{
    long long int ans = 1;
    for (int i = 1; i <= x; i++)
    {
        if (i * i <= x)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }

    return ans;
}

// OPTIMAL APPROACH
long long int floorSqrt(long long int x)
{
    long long int ans = 1;
    long long int low = 1;
    long long int high = x;
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if ((mid * mid) <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

// 14. KOKO EATING BANANAS          O (N) * LOG (MAX ELEMENT)

int getMaxValue(vector<int> &piles)
{
    int maxi = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

double getTotalHours(vector<int> &piles, int hourly)
{
    double totalH = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        totalH += ceil((double)piles[i] / (double)hourly);
    }

    return totalH;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = getMaxValue(piles);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        double totalH = getTotalHours(piles, mid);
        if (totalH <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

// 15. Minimum Number of Days to Make m Bouquets

// BRUTE FORCE          o( maxi-mini+1) * N

int getMin(vector<int> &v, int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, v[i]);
    }
    return mini;
}

int getMax(vector<int> &v, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

bool isPossible(vector<int> &v, int m, int k, int day)
{
    int cnt = 0;
    int n = v.size();
    int makeBque = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= day)
        {
            cnt++;
        }
        else
        {
            makeBque += cnt / k;
            cnt = 0;
        }
    }

    makeBque += cnt / k;
    if (makeBque >= m)
        return true;
    else
        return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (n < (m * k))
        return -1;
    int mini = getMin(bloomDay, n);
    int maxi = getMax(bloomDay, n);

    for (int i = mini; i <= maxi; i++)
    {
        if (isPossible(bloomDay, m, k, i))
        {
            return i;
        }
    }

    return -1;
}

// OPTIMISATION      O ( N * log2 (maxi-mini+1) )

int getMin(vector<int> &v, int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, v[i]);
    }
    return mini;
}

int getMax(vector<int> &v, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

bool isPossible(vector<int> &v, int m, int k, int day)
{
    int cnt = 0;
    int n = v.size();
    int makeBque = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= day)
        {
            cnt++;
        }
        else
        {
            makeBque += cnt / k;
            cnt = 0;
        }
    }

    makeBque += cnt / k;
    if (makeBque >= m)
        return true;
    else
        return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (n < ((long long)m * k))
        return -1;
    int mini = getMin(bloomDay, n);
    int maxi = getMax(bloomDay, n);
    int low = mini;
    int high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(bloomDay, m, k, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

// 16. FIND THE SMALLEST DIVISOR GIVEN A THRESHHOLD

// BRUTE FORCE             O (MAXI *N )

int smallestDivisor(vector<int> &nums, int threshold)
{

    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }
    for (int i = 1; i <= maxi; i++)
    {
        int sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += ceil((double)nums[j] / (double)i);
        }
        if (sum <= threshold)
        {
            return i;
        }
    }

    return -1;
}

// OPTIMISED   0 ( log2 (max) * N)
int getTotalSum(vector<int> &nums, int divis)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += ceil((double)nums[i] / (double)divis);
    }
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)

{

    /* if minimum sum is greater than threshhold than return -1 means divided by greater eleement */

    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }
    int low = 1;
    int high = maxi;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int totalSum = getTotalSum(nums, mid);
        if (totalSum <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// 17. Capacity to Ship Packages within D Days

// BRUTE FORCE      O( ( SUM - MAX + 1) * N )
int reqDays(vector<int> &weights, int capacity)
{
    int load = 0;
    int days = 1;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > capacity)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }

    return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
    }

    for (int i = maxi; i <= sum; i++)
    {
        int daysReq = reqDays(weights, i);
        if (daysReq <= days)
        {
            return i;
        }
    }
    return -1;
}

// OPTIMISED      O ( log(sum-maxi+1) * N )
int reqDays(vector<int> &weights, int capacity)
{
    int load = 0;
    int days = 1;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > capacity)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }

    return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
    }
    int ans = -1;
    int low = maxi;
    int high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int reultDays = reqDays(weights, mid);
        if (reultDays <= days)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

// 18. Kth Missing Positive Number            **

// BRUTE FORCE   O(N)
int findKthPositive(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }

    return k;
}

// OPTIMISED SOLUTION

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // index -> 0 1 2 3 4
        if (arr[mid] - (mid + 1) < k)
        {                  //      [2 3 4 7 11 ]
            low = mid + 1; // missing  1 1 1 3 6      formula=nums[i]-(i+1)
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

// 19. AGGRESSIVE COWS

// BRUTE FORCE

bool canWePlace(vector<int> &arr, int cows, int dist)
{

    int cntCows = 1;
    int last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= dist)   // as we have to find maximum of minimum
        {
            cntCows += 1;
            last = arr[i];
        }
    }

    if (cntCows >= cows)   // if cows is greater than or equal to k
        return true;
    return false;
}

int maxDistance(vector<int> &stalls, int m)
{
    sort(stalls.begin(), stalls.end());
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());
    for (int i = 1; i <= maxi - mini; i++)
    {
        if (canWePlace(stalls, m, i))
        {
            continue;
        }
        else
        {
            return i - 1;
        }
    }

    return -1;
}

// OPTIMISED SOLUTION

int maxDistance(vector<int> &stalls, int m)
{
    // we sort because minimum will happen between consecutive place
    sort(stalls.begin(), stalls.end());
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());
    int low = 1;
    int high = maxi - mini;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canWePlace(stalls, m, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

// 20. BOOK ALLOCATION

// BBRUTE FORCE   O (SUM-MAXI+1) * N

int getStudents(vector<int> &arr, int pages)
{
    int students = 1;
    int weight = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + weight <= pages)
        {
            weight += arr[i];
        }
        else
        {
            students += 1;
            weight = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{

    int maxi = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    for (int i = maxi; i <= sum; i++)
    {
        int students = getStudents(arr, i);
        if (students == m)
            return i;
    }

    return -1;
}

// OPTIMAL APPROACH

int getStudents(vector<int> &arr, int pages)
{
    int students = 1;
    int weight = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + weight <= pages)
        {
            weight += arr[i];
        }
        else
        {
            students += 1;
            weight = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int low = maxi;
    int high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cntStudents = getStudents(arr, mid);
        if (cntStudents > m)
        {

            low = mid + 1;     // student jada hai toh no of pages badhaao bache kam honge
        }
        else
        {
            high = mid - 1;     // student kam hai toh no of pages kam karo bache badhenge
        }
    }

    return low;
}

// 21. PAINTERS PARTITION 
// 22. SPLIT ARRAY                  BOTH IS SAME AS OF BOOK ALLOCATION


// 23. MEDIAN OF TWO SORTED ARRAYS 
   
  // BRUTE FORCE      O(N1+N2)
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();
       int l=n+m;
       vector<int>nums3(l);
       int i=0;
       int j=0;
       int k=0;
       while(i<n && j<m){
        if(nums1[i]<=nums2[j]){
            nums3[k++]=nums1[i++];
        }
        else{
            nums3[k++]=nums2[j++];
        }
       }   

       while(i<n){
        nums3[k++]=nums1[i++];
       }

       while(j<m){
         nums3[k++]=nums2[j++];
       }

       if(l%2==1){
          return nums3[l/2];
       }
       else{
        return (nums3[l/2]+nums3[(l/2)-1])/2.0;
       }
    }

    // OPTIMISED  

      double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();
        if(n2<n1) return findMedianSortedArrays(b,a);
        int n=n1+n2;
        int low=0;
        int high=n1;
        int left=(n2+n1+1)/2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        } 

        return 0;
    }

    // 24. ROW WITH MAX 1

       // brute force
       	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int maxCount=0;
	   int index=-1;
	   for(int i=0;i<n;i++){
	       int count=0;
	       for(int j=0;j<m;j++){
	           if(arr[i][j]==1){
	               count++;
	           }
	           if(count>maxCount){
	               maxCount=count;
	               index=i;
	           }
	       }
	   }
	   
	   return index;
	}

      // BRUTE FORCE    O (N+M)
     	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int i=0;
	   int j=m-1;
	   int row=-1;
	   while(i<n && j>=0){
	       if(arr[i][j]==1){
	           j--;
	           row=i;
	       }
	       else{
	           i++;
	       }
	   }
	   
	   return row;
	}

    // BETTER   O( N * log m)

     int getCount(vector<int>& nums, int target) {
      
        int n=nums.size();
          int ans=n;
        for(int i=0;i<n;i++){
          if(nums[i]>=target){
              ans=i;
              break;
          }
        } 

        return ans;
    }
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int index=-1;
	    int maxCount=0;
	    for(int i=0;i<n;i++){
	        int count=m-getCount(arr[i],1);
	        if(count>maxCount){
	            maxCount=count;
	            index=i;
	        }
	    }
	    
	    return index;
	}

    // 25. Search in a row and column wise sorted matrix

    // BRUTE FORCE APPROACH  O(N*M)
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }

        return false;
    }


    // OPTIMAL APPROACH   O(N+M)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        int i=0;
        int j=c-1;
        while(i<r && j>=0){
            if(target==matrix[i][j]) return true;
            else if(target<matrix[i][j]) j--;
            else i++;
        }

        return false;
    }






     // 26. Search in a row  wise sorted matrix

     // BRUTE FORCE   LINEAR SEARCH   O(N*M)

     // BETTER SOLUTION     O(N * long m)

      bool solve(int target,vector<int>&arr,int m){
     int low=0;
     int high=m-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
     }
     return false;
   }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            if(matrix[i][0] <=target && target <= matrix[i][c-1]){
                bool ans=solve(target,matrix[i],c);
                if(ans==true) return true;
            }
        }

        return false;
    }

    // OPTIMAL SOLUTION   O( log2 (n*m))

        bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r=matrix.size();
       int c=matrix[0].size(); 
       int total=(r*c);
       int low=0;
       int high=total-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        int element=matrix[mid/c][mid%c];
        if(element==target) return true;
        else if(element<target) low=mid+1;
        else high=mid-1;
       }

       return false;-----------
    }

    // 27. FIND PEAK ELEMENT IN 2-D MATRIX      O(N * log m)       ( do it again )

     int solve(vector<vector<int>>& mat,int r,int c,int col){
        int index=-1;
        int maxValue=-1;
        for(int i=0;i<r;i++){
            if(mat[i][col]>maxValue){
                maxValue=mat[i][col];
                index=i;
            }
        }

        return index;
    } 


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int low=0;
        int high=c-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxRowIndex=solve(mat,r,c,mid);
            int left=mid-1>=0 ? mat[maxRowIndex][mid-1] : -1;
            int right=mid+1<c ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid]>right ){
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid] < left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return {-1,-1};
    } 


   // 28. MEDIAN IN ROW WISE SORTED MATRIX


    // counting the no of element that are less than mid
     int check(vector<vector<int>> &matrix,int mid,int R){
        
        int len=0;
        for(int i=0;i<R;i++){
            auto it=upper_bound(x.begin(),x.end(),mid);   // upper bound gives index of greater element
            len+=(it-x.begin());
        }
        
        return len;
        
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        
        int ans=-1;
        int total=R*C;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(matrix,mid,R)>total/2){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
        
        
    }


    




    
    