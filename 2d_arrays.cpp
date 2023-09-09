#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// LINEAR SEARCH
bool isPresent(int array[][4], int row, int col, int target)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

//  ROW WISE SUM

void rowSum(int array[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += array[i][j];
        }
        cout << sum << " ";
    }
}


// COL WISE SUM

 void colSum(int array[][4],int r,int c){
    for (int col= 0; col < c; col++)
    {
        int sum=0;
            for (int row = 0; row < r; row++)
            {
                sum+=array[row][col];
            }
            cout<<sum<<" ";
    }
    
 }


 // LARGEST ROW SUM

  int largestRowSum(int array [][4],int r,int c){
    
    int maxi=INT_MIN;
    int rowNo=0;
    for (int row = 0; row < r; row++)
    {
        int sum=0;
            for (int col = 0; col < c; col++)
            {
                sum+=array[row][col];
            }

            if(sum>maxi){
                maxi=sum;
              rowNo=row;
            }
            
    }
      cout<<"The maximum sum is: "<<maxi<<endl;
     return rowNo; 
  }
int main()
{
    int arr[3][4];
    int array[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int array1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    //  input  -  row wise
    /*cout << "Enter the elemens of the array: "<<endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }*/

    // input - col wise

    /* for (int col = 0; col < 4; col++)
     {
             for (int row = 0; row < 3; row++)
             {
                 cin>>arr[row][col];
                             }

     }*/

    /* cout << "The elements of the array are: "<<endl;
     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 4; j++)
         {
             cout << arr[i][j]<<" ";
         }
         cout<<endl;
     }*/

    /*if (isPresent(array,3,4,95))
    {
        cout<<"Elemnet is present";
    }
    else{
        cout<<"Element is not present";
    }*/

    // sum(array, 3, 4);
    // colSum(array,3,4);

    cout<<largestRowSum(array,3,4);
}