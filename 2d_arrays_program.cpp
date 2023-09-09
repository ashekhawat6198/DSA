#include <iostream>
using namespace std;
#include <bits/stdc++.h>
    
    //    1.   LINEAR SEARCH

    bool linearS(int array[][4],int r,int c,int t){
        for (int row = 0; row < 3; row++)
        {
                for (int col = 0; col < 4; col++)
                {
                    if (array[row][col]==t)
                    {
                      return true;
                    }
                    
                }
                
        }
        return false;
        
    }

    // 2. ROW WISE SUM / COL WISE SUM


    void rowSum(int array[3][4],int r,int c){
        for (int row = 0; row < 3; row++)
        {
            int sum=0;
            for (int col = 0; col < 4; col++)
            {
                sum+=array[row][col];
            }
            cout<<sum<<" ";
        }
        
    }


     void colSum(int array[3][4],int r,int c){
        for (int col = 0; col < 4; col++)
        {
            int sum=0;
            for (int row = 0; row < 3; row++)
            {
                sum+=array[row][col];
            }
            cout<<sum<<" ";
        }
        
     }

     //  3*  LARGEST ROW SUM / LARGEST COL SUM

     void largestRowSUM(int array[][4],int r,int c){
        int maxi=INT_MIN;
        
        int rowNo=0;
        for (int row = 0; row < r; row++)
        {
            int sum=0;
            for (int col= 0; col < c; col++)
            {
               sum+=array[row][col]; 
               rowNo=row;      
            }

            if(sum>maxi){
                maxi=sum;
            }
            
        }

        cout<<"The maximum sum is "<<maxi<<" and the row number is "<<rowNo;
        
     }

     void largestColSUM(int array[][4],int r,int c){
        int maxi=INT_MIN;
        
        int ColNo=0;
        for (int col = 0; col < c; col++)
        {
            int sum=0;
            for (int row= 0; row < r; row++)
            {
               sum+=array[row][col]; 
               ColNo=col;      
            }

            if(sum>maxi){
                maxi=sum;
            }
            
        }

        cout<<"The maximum sum is "<<maxi<<" and the row number is "<<ColNo;
        
     }

    // 4.  PRINT LIKE A WAVE   ( TIME COMPLEXITY : 0(NM) N-ROW   M-COLF)

    vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector <int> ans;
    for(int col=0;col<mCols;col++){
        if(col & 1){
            // for odd case
            for(int row=nRows-1;row>=0;row--){
                 ans.push_back(arr[row][col]);
            }
        }

        else{
            // for even and 0 case
            for(int row=0;row<nRows;row++){
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}
     // 5.  SPIRAL MATRIX

      vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
   vector <int> ans;

   int row=matrix.size();
   int col=matrix[0].size();

   int startingRow=0;
   int startingCol=0;
   int endingRow=row-1;
   int endingCol=col-1;

   int count=0;
   int total=row*col;

   while(count<total){

       for(int index=startingCol;  count<total && index<=endingCol;index++){
           ans.push_back(matrix[startingRow][index]);
           count++;
       }
       startingRow++;

        for(int index=startingRow; count<total && index<=endingRow;index++){
           ans.push_back(matrix[index][endingCol]);
           count++;
       }
       endingCol--;


        for(int index=endingCol; count<total && index>=startingCol;index--){
           ans.push_back(matrix[endingRow][index]);
           count++;
       }
       endingRow--;

         for(int index=endingRow; count<total && index>=startingRow;index--){
           ans.push_back(matrix[index][startingCol]);
           count++;
       }
       startingCol++;

   }
   return ans;

    }

    // 6. BINARY SEARCH MATRIX
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0;
        int e=row*col-1;
        int mid=s+(e-s)/2;
        while(s<=e){
      int element=matrix[mid/col][mid%col];          // formula to find element of mid in nd 2d matrix
            if(element==target){
                return true;
            }

            else if(target>element){
                s=mid+1;
            }

            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }


    // 7. SEARCH IN 2D MATRIX (  LAST QUESTION OF 25TH LECTURE )     // DO IT AGAIN
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1;
        while(rowIndex<row && colIndex>=0){
            int element=matrix[rowIndex][colIndex];
            if(element==target){
                return true;
            }
            else if( target>element){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return false;

    }


//  8.  TRANSPOSE OF A MATRIX       


vector<vector<int>> transpose(vector<vector<int>>& matrix) {          // RETURNING IN A LIST FORM      DO IT AGAIN
       
        int n=matrix.size();
        int m=matrix[0].size();
        vector < vector <int>> ans(m,vector <int> (n,0));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               ans[j][i]=matrix[i][j];
           }
        }
        return ans;
    }



    void transpose(vector < vector <int>> &matrix,int n){        // in void case

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
            
        }
        
    }

    // 9. ROTATE MATRIX BY 90 DEGREE    DEKHLENA EK BAAR

     // CLOCKWISE DIRECTION
        void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        // transpose
        for(int i=0;i<row;i++){
            for(int j=0;j<i;j++){
                 swap(matrix[i][j],matrix[j][i]);
            }
        }

        // rotate by 90 degree
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col/2;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][col-j-1];
                matrix[i][col-j-1]=temp;
            }
        }

    }

    // ANTICLOCKWISE DIRECTION
    vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
   vector<vector<int>>ans(m,vector<int>(n,0));
     for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
          ans[i][j]=matrix[j][i];

       }
   }

 for(int i=0;i<m/2;i++){
    for(int j=0;j<n;j++){
        int temp=ans[i][j];
        ans[i][j]=ans[m-i-1][j];
        ans[m-i-1][j]=temp;
    }
 }

   return ans;

}

// 10. SET MATRIX ZERO

void setZeros(vector<vector<int>> &matrix)
{
	bool firstRow=false,firstCol=false;
	int n=matrix.size();
	int m=matrix[0].size();

	for(int i=0;i<n;i++){               // in this we traversing except first row and column AND MARKING 0 IN FIRST ROW AND COL
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				if(i==0){
					firstRow=true;
				}                               
				if(j==0){
					firstCol=true;
				}
                  matrix[0][j]=0;
				  matrix[i][0]=0;
			}

		}
	}

	for(int i=1;i<n;i++){                                   // IN THIS WE MAKING THEM 0 EXCEPT FIRST ROW/COLUMN 
		for(int j=1;j<m;j++){
			if(matrix[i][0]==0 || matrix[0][j]==0){
				matrix[i][j]=0;
			}
		}
	}

	if(firstRow){                                       // IN BOTH IF WE MAKING THE FIRST ROW AND COL COMPLETELY ZERO  
		for(int j=0;j<m;j++){
			matrix[0][j]=0;
		}
	}

	if(firstCol){
		for(int i=0;i<n;i++){
			matrix[i][0]=0;
		}
	}
}
    

    // 11. ROW WITH MAXIMUM 1'S                 

    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int max_row_index=-1;
    int r=0;
    int c=m-1;
    while(r<n && c>=0){
        if(matrix[r][c]==1){
            max_row_index=r;
            c--;
        }
        else{
            r++;
        }
    }
    return max_row_index;
}

// 12. MEDIAN IN ROW WISE SORTED MATRIX           DO IT AGAIN >> 2

int count(int mid,vector<vector<int>>matrix){
	int count=0;
	for(auto row:matrix){
		 auto it=upper_bound(row.begin(),row.end(),mid);
		count+=(it-row.begin());
	}
	return count;
}
int findMedian(vector<vector<int> > &arr, int n, int m){
	
	int low=INT_MAX;
	int high=INT_MIN;

	for(int i=0;i<n;i++){
		low=min(low,arr[i][0]);
		high=max(high,arr[i][m-1]);
	}
    int total=n*m;
	int ans=-1;

	while(low<=high){
		int mid=low+(high-low)/2;

		if(count(mid,arr)>total/2){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}


int main(){
    int array[3][4];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>array[i][j];
        }
        
    }
   /*  FIRST PROGRAM  
    if (linearS(array,3,4,84))
    {
        cout<<"Present";
    }

    else{
        cout<<"Not present";
    }
    */
    

    /* SECOND PROGRAM
     rowSum(array,3,4);
    colSum(array,3,4);  */


  // largestRowSUM(array,3,4);
   largestColSUM(array,3,4);
}