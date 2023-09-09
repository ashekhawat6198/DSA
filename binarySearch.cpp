// BINARY SEARCH

#include <iostream>
using namespace std;

// 1. BASE PROGRAM  or  finding the index of the key

int binarySearch(int array[],int s, int e, int key)
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

// 2.  FIRST AND LAST POSITION OF AN ELEMENT IN SORTED ARRAY  ( https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2 )

int firstOcc(int array[], int n, int key)
{
  int start = 0;
  int end = n - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  while (start <= end)
  {
    if (array[mid] == key)
    {
      ans = mid;
      end = mid - 1;
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
  return ans;
}

int lastOcc(int array[], int n, int key)
{
  int start = 0;
  int end = n - 1;
  int mid = start + (end - start) / 2; // trick , if the size of integer is greater then 2^31-1
  int ans = -1;
  while (start <= end)
  {
    if (array[mid] == key)
    {
      ans = mid;
      start = mid + 1;
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
  return ans;
}

// 3. TOTAL NUMBER OF OCCURENCE USING LASTOCCURENCE AND FIRST OCCURENCE FUNCTION

void totalOcc(int array[], int n, int key)
{
  int total = 0;
  total = (lastOcc(array, n, key) - firstOcc(array, n, key)) + 1;
  cout << "Total Number of occurence of the key is: " << total << endl;
}

// 4. PEAK INDEX IN A MMOUNTAIN ARRAY  ( https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa3R4M3NIQWtUZTZ4eU5sZGtWVDJCX09rcUFld3xBQ3Jtc0ttMEhsZE9TU1JOOTBhODR1VzBWOUM4Q3RjTU03THZJVmVoWUpzR1JIWk1fSGhQbzdjS18tYjhSblJOM2JuejgxNGpJdjZ3bnE2SUdLZmRBMnlrWVBydXgybzBheXNIWnFJMzJGenlVYmhnNTRRcXV3VQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fpeak-index-in-a-mountain-array%2F&v=zD2Jg3alZV8 )

int peakIndex(int array[], int n)
{
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;
  while (s < e)
  {
    if (array[mid] < array[mid + 1])
    {
      s = mid + 1;
    }
    else
    {
      e = mid;
    }
    mid = s + (e - s) / 2;
  }
  return s;
}

//  5. FIND PIVOT INDEX   ( https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqazRXM2hpdHUxZ1AxaGtIMW55S2ZmQWYtYWxxd3xBQ3Jtc0tsX19OdTNsbHU1MXU0WVJfSGZpRHRmMFRadDZQeUNnWmc3amJkRVdjaEM2dmZ2YjhpREJEY2l1RkVxbHo0RDBLQllZSW9RWjVWOXp6d2J1a180VmtkTm9tdGtjWFZIeS1rQTd6YWdJVEFBZDdEcmUyOA&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Ffind-pivot-index%2F&v=zD2Jg3alZV8 )


int Fpivot(int array[],int n){
  int s=0;
  int e=n-1;
  int mid=s+(e-s)/2;
  while (s<e)
  {
    if(array[mid]>=array[0]){
      s=mid+1;
    }
    else{
      e=mid;
    }
     mid=s+(e-s)/2;
  }
  return s;
  
}


// 6. SEARCH IN ROTATED SORTED ARRAY USING PIVOT AND  BINARY SEARCH(1) ( https://www.codinmidgninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2  )
 
 int foundE(int array[],int n,int key){
  int s=0;
  int e=n-1;
    int pivot=Fpivot(array,n);
      if(key>=array[pivot] && key<= array[n-1]){
        return binarySearch(array,pivot,n-1,key);
      }
      else{
          return binarySearch(array,0,pivot-1,key);

      }
 }

 // 7. SQUARE ROOT[only integer part not float] ( https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2 )


int BinaryS(int n){
  int s=0;
  int e=n;
  int mid=s+(e-s)/2;
  int square=mid*mid;
  int ans=-1;
  while (s<=e)
  {
     if(mid*mid==n){   
          return mid;
     }
     else if(mid*mid<n){
         ans=mid;
         s=mid+1;
     }
     else {
      e=mid-1;
     }
     mid=s+(e-s)/2;
  }
return ans;
}

 int squareR(int n)
  {
  return BinaryS(n);

 }


// 8. BOOK ALLOCATION  ==  9.  PAINTERS PARTITION PROBLEM  V.V.V. IMPORTANT ( https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa3BWdzM3QTdxdkdZSnF3SThCVXl3M1ZRSUZDUXxBQ3Jtc0tsRUY3NHhJVmtwdVA4UTFZQUJmZ1FyaVFHSVdxNGs3WEI3VllTaS0zVWNaY05HUWx5dl8tajVtUFN0N0ZkbUgxTmpCcnREYVVncG0xUDdDZGp0VXBJOTlLUE56aGNlQXR2Y3gwVU4xWHZnWlpJS2Z4MA&q=https%3A%2F%2Fbit.ly%2F3GiCqY0&v=YTTdLgyqOLY  )


bool isPossible(int array[],int n,int m,int mid){
  int studentCount=1;
  int pageSum=0;
  for (int i = 0; i < n; i++)
  {
    if(pageSum+array[i]<=mid){
      pageSum +=array[i];
    }
    else{
      studentCount++;
      if (studentCount >m || array[i]>mid)
      {
        return false;
      }
      pageSum=array[i];
      
    }
  }
  return true;
}



int bookA(int array[],int n,int m){
  int s=0;
  int sum=0;
  int ans=-1;
  for (int i = 0; i < n; i++)
  {
    sum=sum+array[i];
  }
  int e=sum;
  int mid=s+(e-s)/2;
  while (s<=e)
  {
    if(isPossible(array,n,m,mid)){
        ans=mid;
        e=mid-1;
    }
    else{
      s=mid+1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
  
}

//   9.  AGGRESSIVE COWS

bool isPossible1(vector<int>& stalls,int k,int mid){
  int cowCount=1;
  int lastPow=stalls[0];
  for (int i = 0; i < stalls.size(); i++)
  {
    if(stalls[i]-lastPow>=mid){
      cowCount++;
      lastPow=stalls[i];
    }

    if(cowCount==k){
      return true;
    }
  }
  return false;

}
int solve(int n, int k, vector<int> &stalls){
  
  sort(stalls.begin(),stalls.end());
  int s=0;
  int maxi=-1;
  for (int i = 0; i < n; i++)
  {
    maxi=max(maxi,stalls[i]);
  }
  int ans=-1;
  int e=maxi;
  int mid=s+(e-s)/2;
  while (s<=e){
    if (isPossible1(stalls,k,mid)){
       ans=mid;
       s=mid-1;
    }
    else{
      mid-1;
    }
    mid=s+(e-s)/2;
  }
  return ans;
  
}

int main()
{
  /*   1.
    int array1[5]={5,18,36,88,105};
    int array2[8]={11,28,45,69,78,125,150,180};


    cout<<  binarySearch(array1,5,36)<<" "<<endl;
     cout<< binarySearch(array2,8,11)<<" "<<endl;*/

  /*  2.
   int array[8]={1,2,3,3,3,3,3,8};
   int key=3;
    cout<<"The first occurence of the "<<key<<" is: "  <<firstOcc(array,8,key)<<endl;
    cout<<"The last occurence of the "<<key<<" is: "  <<lastOcc(array,8,key)<<endl;*/

  /*  3.
           int array[8]={1,2,3,3,3,5,5,8};
          int key=5;
      totalOcc(array,8,key); */

  
  /*   4.
    int array[4]={3,4,5,1,};
    cout<<"The peak index is: "<<peakIndex(array,4); */

    /*   5. 
    int array[6]={7,9,1,2,3};
    cout<<"The pivot element is: "<<Fpivot(array,5)<<endl;*/


/*   6.  
    int array[4]={2,3,5,8};
    int key=8;
    cout<<foundE(array,4,key)<<endl;*/

/*  7. 
   cout<<BinaryS(25)<<endl;*/

   /*int array[4]={10,20,30,40};
   int m=2;
   cout<<bookA(array,4,m)<<endl;*/


   vector <int> stalls={1,2,4,8,9};
   cout<<solve(5,3,stalls);

}
