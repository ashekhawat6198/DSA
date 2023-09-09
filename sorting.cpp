#include <iostream>
using namespace std;
  

  // SELECTION SORT                 DO IT AGAIN
void SelectionSort(int array[],int n){
   for(int i=0;i<n-1;i++){
          int minValue=i;
          for(int j=i+1;j<n;j++){
              if(array[j]<array[minValue]){
                   swap(array[minValue],array[i]);
              }
          }
         
      }
    
    
}

// BUBBLE SORT 

void bubbleSort(int array[],int n){
    for (int i = 1; i < n; i++)    {
        
        for (int j = 0; j < n-i-1; j++)
        {
            bool swapped=true;
            if (array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
                swapped=true;
            }
            
        }
        if (swapped==false)
        {
            break;

            
        }
        
        
    }
    
}

void printArr(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}

//  INSERTION SORT

void insertionSort(int array[],int n){
    for (int i = 1; i < n; i++)
    {
        int temp=array[i];
        int j = i-1;
        for (; j >=0; j--)
        {
            if (array[j]>temp)
            {
                array[j+1]=array[j];
            }
            else{
                break;
            }
            
        }
        
        array[j+1]=temp;
    }
    
    
}


int main(){
       int array[5]={6,2,8,4,10};
       SelectionSort(array,5);
       printArr(array,5);
}