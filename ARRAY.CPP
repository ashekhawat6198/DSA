                                                  // ARRAY TUTORIAL

#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    
    cout<<"Printing is done";
}

int main(){

// declaring an array
 int array[5];
 
 //accessing an array
 cout<<"Value at differnt index: "<<array[4]<<endl;

// initializing an array
int num[3]={4,8,9};

// accessing elements using loop
int marks[15]={45,65}; 
int n=15;                             // starting 2 index are given , rest of the index will be zero
for (int i = 0; i < n; i++)
{
    cout<<marks[i]<<"  "<<endl;
}

// array with function
int ankh[10]={8,2,3};
printArray(ankh,3);

// to calculate size of array
int ankhSize=sizeof(ankh)/sizeof(int);
cout<<ankhSize;

}