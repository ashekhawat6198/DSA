#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <array>

// 1. maximum and minimum element in the array
int getMax(int frnds[], int n)
{
    int maxi = INT_MIN; // max is an element where the maximum value is stored
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, frnds[i]); // you can also use this pre-built function to find maximum value and same with minimum
                                    /* if (frnds[i]>max)
                                     {
                                         max=frnds[i];
                                     }*/
    }
    return maxi;
}

int getMin(int frnds[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (frnds[i] < min)
        {
            min = frnds[i];
        }
    }
    return min;
}

// 2.  sum of the array

int sum(int marks[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + marks[i];
    }
    return sum;
}

// 3. LINEAR SEARCH

bool found(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

// 4. REVERSE ARRAY

void reverse(int array[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(array[start], array[end]);
        start++;
        end--;
    }
}

void printArray(int array[], int n)

{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// 5. SWAP ALTERNATES

void swapArray(int array[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            swap(array[i], array[i + 1]); //  temp=array[1];
                                          //   array[1]=array[0];
        }                                 // arrray[0]=temp;
    }
}

// 6. FIND UNIQUE   (  https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube& campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1  )

int uniqueDigit(int array[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ array[i]; // doing XOR to eliminate duplicate
    }
    return ans;
}

// 7. DUPLICATES IN ARRAY  ( https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1 )

int duplicatesArray(int array[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ array[i]; // XOR is used to delete the duplicate element
                              // doing XOR of the array
    }

    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i; // now doing XOR with previous XOR
    }
    return ans;
}


//   OR   ( MULTIPLE DUPLICATES )
 vector<int> findDuplicates(vector<int>& nums) {
       vector<int>temp;
       sort(nums.begin(),nums.end());
           for(int i=0;i<nums.size()-1;i++){
               if(nums[i]==nums[i+1]){
                   temp.push_back(nums[i]);
               }
           }
       return temp;
    
    }
// 8. INTERSECTION OF TWO ARRAYS ( https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1 )
int intersection(int array1[], int array2[], int n, int m)
{
    int i = 0, j = 0;
    int ans = 0; //   IN VECTOR CASE    vector<int> ans;
    while (i < n && j < m)
    {
        if (array1[i] == array2[j])
        {
            ans = array1[i]; // in vector case    ans.push_back(array1[i]);
            i++;
            j++;
        }
        else if (array1[i] < array2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

// 9. Check if array is sorted

bool isSorted(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1])
        {
            return false;
        }
    }
    return true;
}

// 10 . Pair sum  ( https://www.codingninjas.com/codestudio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1 )

/* int pairSum(int array[],int n,int s){
     vector< vector<int> > ans;
     for (int i = 0; i < n; i++)
     {
         for(int j=i+1;j<n;j++){
             if(array[i]+array[j]==s){
                 vector <int> temp;
                 temp.push_back(min(array[i],array[j]));
                 temp.push_back(max(array[i],array[j]));
                 ans.push_back(temp);

             }
         }
     }
     sort(ans.begin(),ans.end());
     return ans;

 }*/

// 11. SORT 0,1  ( https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1 )

void SortOne(int array[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        if (array[left] == 1 && array[right] == 0)
        {
            swap(array[left], array[right]);
            left++;
            right--;
        }
        else if (array[left] == 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

// 12. LEFT ROTATE AN ARRAY BY ONE PLACE

void Rotate(int array[], int n)
{

    int temp = array[0];
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
        {
            array[i] = array[i + 1];
        }
    }
    array[n - 1] = temp;
}

// 13. LEFT ROTATE AN ARRAY BY K PLACE

void lRotate(int array1[], int n, int k)
{

    int array2[n];
    for (int i = 0; i < n; i++)
    {
        array2[(i + k) % n] = array1[i];
    }

    /* for (int i = 0; i < n; i++)              // putting value of array2 back to array
     {
        array1[i]=array2[i];
     }*/

    for (int i = 0; i < n; i++)
    {
        cout << array2[i] << " ";
    }
}

// 14. MISSING NUMBER
// SUM FROM 1 TO N  ==  N(N+1)/2
/*  int missingN(int array[]){
      int sumArray=0;

      for (int i = 0; i < array.size(); i++)
      {
          sumArray+= array[i];
      }
       int n=array.size();
      int expectedSum=(n*(n+1))/2;
      int reqNumber=expectedSum-sumArray;           // FORMULA  :   SUM OF GIVEN ARRAY + MISSING NUMBER= SUM FROM 1 TO N
          return reqNumber;

  }*/

// 15. FIND SECOND LARGEST AND SECOND SMALLEST NUMBER IN THE ARRAY
int SecondLargest(int array[], int n)
{

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (array[i] > largest)
        {
            secondLargest = largest;
            largest = array[i];
        }

        else
        {
            if (array[i] > secondLargest && array[i] < largest)
            {
                secondLargest = array[i];
            }
        }
    }
    return secondLargest;
}

int SecondSmallest(int array[], int n)
{
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (array[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = array[i];
        }

        else
        {
            if (array[i] < secondSmallest && array[i] > smallest)
            {
                secondSmallest = array[i];
            }
        }
    }
    return secondSmallest;
}

// 16. MAJORITY ELEMENT (OCCURENCE > SIZE/2)

int majorityE(int array[], int n)
{
    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = array[i];
        }

        if (array[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // checking that the element is mojority element
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            count++;
        }
    }

    if (count > n / 2)
    {
        return element;
    }
    return -1;
}

// 17. KADANES ALGORITHM AND MAXIMUM SUBARRAY

int MaxSub(int array[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i];

        maxi = max(sum, maxi);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

// 18. BUY AND SELL STOCK

int buyStock(int array[], int n)
{
    int mini = array[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = array[i] - mini;
        profit = max(diff, profit);
        mini = min(array[i], mini);
    }
    return profit;
}

// OR

 int stockBuyAndSell(int n, vector<int> &prices) {
      int profit=0;
      
      for(int i=1;i<n;i++){
          if(prices[i]>prices[i-1]){
             profit+=prices[i-1]-prices[i];
          }
      }
      return profit;
    }

    
// 19. MOVES ZEROES TO END      

void ShiftRightZero(int array[], int n)
{
    int nonzero = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] != 0)
        {
            swap(array[i], array[nonzero]);
            nonzero++;
        }
    }
}

// 20.    SORT 0 1 2

int sort_0_1_2(int array[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (array[mid] == 0)
        {
            swap(array[low], array[mid]);
            low++;
            mid++;
        }
        else if (array[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(array[mid], array[high])

                high--;
        }
    }
}

// 21. LEADERS IN AN ARRAY
vector int leaders(int array[], int n)
{
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i + --)
    {
        if (array[i] > maxi)
        {
            ans.push_back(array[i]);
        }
        maxi = max(array[i], maxi);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 22.  NEXT PERMUTATION

vector<int> nextPermutation(vector<int> arr)
{

    int index = -1;
    int n = arr.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

// 24. PASCALS'S TRIANGLE

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; i < i; j++)
        {
            row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        ans.push_back(row);
    }
    return ans;
}

// 25.  ADD TWO ARRAYS

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        j--;
    }

    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

//  26.  MERGE TWO SORTED ARRAYS

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int i = m - 1;
    int j = n - 1, k = nums1.size() - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

    while (i >= 0)
    {
        nums1[k] = nums1[i];
        i--;
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
    
}

// 27. CHECK IS ARRAY IS SORTED AND ROTATED
bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    if (nums[n - 1] > nums[0])
    {
        count++;
    }

    return count <= 1;
}

// 28. CHOCOLATE DISTRIBUTION PROBLEM

int findMinDiff(int n, int m, vector<int> chocolates)
{
    sort(chocolates.begin(), chocolates.end());
    int min = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = chocolates[i + m - 1] - chocolates[i]; // HIGHEST CHOCOLATE PACK ASSIGNED TO STUDENT - LOWEST CHOCOLATE PACK ASSIGNED TO STUDENT
        if (diff < min)
        {
            min = diff;
        }
    }
    return min;
}

// 29. 3 SUM

vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.size() < 3)
        return {};
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // remove duplicate array
    set<vector<int>> s;

    // now fix the first elements and find other two elements

    for (int i = 0; i < n - 2; i++)
    {

        // find other two elements using two sum approach

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                s.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    // removing duplicat array
    for (auto x : s)
    {
        ans.push_back(x);
    }
    return ans;
}

// 30. MERGE OVERLAPPING INTERVALS
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    if (intervals.size() <= 1)
    {
        return intervals;
    }

    // sort by ascending starting point
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++)
    {
        int currS = intervals[i][0];
        int currE = intervals[i][1];

        if (ans.size() == 0 || currS > ans[ans.size() - 1][1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], currE);
        }
    }
    return ans;
}

// 31. CONTAINER WITH MOST WATER

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        // area = height *width
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(area, maxArea);
        // minimum height will increment or decrement
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

// 32. TRAPPING RAIN WATER           DO IT AGAIN
int trap(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int rmax = 0;
    int lmax = 0;
    int r = 0;
    while (i <= j)
    {
        if (height[i] <= height[j])
        {
            if (height[i] < lmax)
            {
                r = r + (lmax - height[i]);
            }
            else
            {
                lmax = height[i];
            }
            i++;
        }
        else
        {
            if (height[j] < rmax)
            {
                r = r + (rmax - height[j]);
            }
            else
            {
                rmax = height[j];
            }
            j--;
        }
    }
    return r;
}

// 33. PRODUCT OF ARRAY EXCEPT SELF

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    vector<long long int> left(n);  // vector to store left all side multiplication
    vector<long long int> right(n); // vector to store right side multiplication
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    vector<long long int> ans(n); // vector to store multiplication of both vector
    for (int i = 0; i < n; i++)
    {
        ans[i] = left[i] * right[i];
    }
    return ans;
}

// 34. MAXIMUM PRODUCT SUBARRAY        DO IT AGAIN

int maximumProduct(vector<int> &arr, int n)
{
    int ans = arr[0];
    int mini = arr[0];
    int maxi = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(mini, maxi);
        }

        mini = min(arr[i], mini * arr[i]);
        maxi = max(arr[i], maxi * arr[i]);
        ans = max(ans, maxi);
    }
    return ans;
}

// 35. MINIMUM NUMBER OF MERGE OPERATIONS TO MAKE AN ARRAY PALINDROME

int palindrome(vector<int> A)         // DO IT AGAIN 
{
    int ans = 0;
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
        if (A[i] == A[j])
        {
            i++;
            j--;
        }

        else if (A[i] < A[j])
        {
            i++;
            A[i] = A[i] + A[i - 1];
            ans++;
        }
        else
        {
            j--;
            A[j] = A[j] + A[j + 1];
            ans++;
        }
    }
    return ans;
}

// 36.  LARGEST NUMBER                    DO IT AGAIN
static bool cmp(string a, string b)
{
    if (a + b > b + a)
        return true; // 3,30    330  or 303
    return false;
}
string largestNumber(vector<int> &nums)
{
    string ans;
    vector<string> nums_str;
    for (int x : nums)
    {
        nums_str.push_back(to_string(x)); // convert the values into string
    }

    sort(nums_str.begin(), nums_str.end(), cmp);

    for (string x : nums_str)
    {
        ans.append(x); // used to extend the string by appending at the end of the current value.
    }

    int start = 0;
    while (ans[start] == '0' && start < nums.size() - 1)
        start++;
    return ans.substr(start); // substr(pos,len) is used to return by given condition
}
// 37. FIND MEDIAN IN ARRAY
int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    int n=v.size();
		     int t=n/2;
		    if(n%2==0){
		        return (v[t]+v[t-1])/2;
		    }
		    else
		    {
		        return v[t];
		    }
		}

// 38. FIND MEDIAN OF TWO SORTED ARRAYS
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0;
        int j=0;
        int k=0;
        vector<int>nums3(m+n);
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
             nums3[k]=nums1[i]; 
               k++;
               i++;
            }
            else{
                nums3[k]=nums2[j];
                k++;
                j++;
            }
        }
        
        while(i<m){
            nums3[k]=nums1[i];
            k++;
            i++;
        }
        while(j<n){
            nums3[k]=nums2[j];
            k++;
            j++;
        }
        
        int t=nums3.size();
    int  x=t/2;
    double ans=0;
        
        if(t%2==0){
             ans=(nums3[x]+nums3[x-1])/2.0;
            return ans;
        }
        else{
            ans=nums3[x];
            return ans;
        }
    
    }
    
    // 38. MINIMIZE THE HEIGHTS 

    int getMinDiff(int arr[], int n, int k) {
        
      sort(arr,arr+n);
        
        int diff=arr[n-1]-arr[0];
        
        int maxi;
        int mini;
        
        for(int i=1;i<n;i++){
            
            if(arr[i]-k<0) continue;
            
            maxi=max(arr[i-1]+k,arr[n-1]-k);
            mini=min(arr[0]+k,arr[i]-k);
            
            diff=min(diff,maxi-mini);
        }
        return diff;
    }

int main()
{
    /*  1. max and min program
      int frnds[5];
      int n=5;
      cout<<"Give the elements of the array: "<<endl;
      for (int i = 0; i < n; i++)
      {
          // taking array elements from the user
          cout<<"Enter the "<<  i <<" element: "<<endl;
          cin>>frnds[i];
      }

      cout<<"The maximum element is: "<<getMax(frnds,n)<<endl;
      cout<<"The minimum element is: "<<getMin(frnds,n);*/

    /*  sum of array
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int marks[5];
    cout<<"Enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>marks[i];
    }
    sum(marks,n);
    cout<<"The sum of the matrix is: "<<sum(marks,n);*/

    /* LINEAR SEARCH
     int array[8]={1,5,8,-7,6,22,45,78};
     int n=8;
     int key;
     cout<<"Enter the key: ";
     cin>>key;
     bool milgya=found(array,n,key);
     if(milgya){
         cout<<"The given number is present in the array";
     }
     else{
         cout<<"The number is not present in the array";
     }*/

    /*   REVERSE THE ARRAY
      int array[6]={1,2,3,4,5,6};
      int array2[5]={10,11,12,13,14};

       reverse(array,6);
       reverse(array2,5);

       printArray(array,6);
       printArray(array2,5);*/

    /*   SWAP ALTERNATE
      int odd[7]={4,5,6,7,8,9,1};
      int even[8]={11,14,8,9,7,56,0,69};


      swapArray(even,8);
      swapArray(odd,7);
      printArray(odd,7);
      printArray(even,8);*/

    /* FIND QNIQUE
      int array[7]={1,2,1,4,8,2,8};
     int result= uniqueDigit(array,7);
      cout<<result<<endl;*/

    /*   DUPLICATES IN ARRAY
         int array[6]={5,1,2,3,4,2};

         int result=duplicatesArray(array,6);
         cout<<result;*/

    /* INTERSECTION OF TWO arrays
         int array1[3]={1,4,5};
         int array2[3]={3,4,5};
         intersection(array1,array2,3,3);*/

    /* Sorted arrays
         int array[5]={1,2,3,4,5};
         bool result=isSorted(array,5);
         if(result){
            cout<<"Array is sorted";
         }
         else{
            cout<<"Array is not sorted";
         }*/

    /*  SORT 0 1
      int array[8]={1,1,1,1,0,0,0,0};
      SortOne(array,8);
      printArray(array,8);*/

    /*   LEFT ROTATE AN ARRAY BY ONE PLACE
       int array[6]={88,98,45,68,78,55};
        Rotate(array,6);
        printArray(array,6);*/

    /*    LEFT ROTATE AN ARRAY BY K PLACE
        int array[5] = {11, 12, 13, 14, 15};
        int k = 3;
        lRotate(array, 5, k);*/

    /*   MISSING NUMEBR
      int array[5]={0,1,3,2,5};

      cout<<"The missing number is: "<< missingN(array)<<endl;*/

    /* SECOND LARGEST AND SECOND SMALLEST ELEMENT
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;
        int array[n];
        cout<<"Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin>>array[i];
        }
        cout<<"Second largest value is: "<<SecondLargest(array,n)<<endl;
        cout<<"Second smallest value is: "<<SecondSmallest(array,n);*/

    /*  MAJORITY ELEEMNT
 int array[13]={1,1,1,2,2,1,2,2,2,1,1,2,1};

 cout<<"Majority element is: " << majorityE(array,13);*/

    /* KADANES ALGORITHM
      int array[9]={-2,1,-3,4,-1,2,1,-5,4};

      cout<<"Maximum sum is: "<<  MaxSub(array,9);*/

    /*  BUY AND SELL STOCK
        int array[6]={7,1,5,3,6,4};
        cout<<"Maximum profit is: "<<buyStock(array,6);*/

    /* SHIFT RIGHT ZERO
      int array[6] = {1, 0, 2, 0, 0, 45};
      ShiftRightZero(array, 6);*/

    vector<int> array = {
        2,
        1,
        5,
        4,
        3,
        0,
        0,
    };
    vector<int> result = nextPermutation(array);
    for (int i : result)
    {
        cout << i << " ";
    }
}