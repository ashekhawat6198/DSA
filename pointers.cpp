#include <iostream>
using namespace std;
int main(){
    int num=5;
    cout<<num<<endl;
    
    cout<<"Adress of operator is: "<<&num<<endl;

    int *ptr=&num;
    cout<<*ptr<<endl;          // gives value of the address stored in the pointer ( num ki value ) 
    cout<<ptr<<endl;             // gives address of the stored variable( num ka adress )


   cout<<"Size of num is: "<<sizeof(num)<<endl;
   cout<<"Size of poiinter is: "<<sizeof(ptr)<<endl;



   int i=8;
   int *p1=0;
   p1=&i;
   cout<<p1<<endl;
   cout<<*p1<<endl;


   int *p2=&i;
   cout<<p2<<endl;
   cout<<*p2<<endl;



   int sankhya=100;
   int *point=&sankhya;
   int a=*point;
   a++;                 // remains same
   (*point)++;         // change in this case
   cout<<sankhya<<endl;
   

    int num1[10]={2,5,7,8};
    cout<<num1<<endl;             //all three gives same result
    cout<<&num1[0]<<endl;
    cout<<&num1<<endl;
    cout<<*num1<<endl;      // value 
    
    int vect[10];
    cout<<vect<<endl;
   //  vect=vect+1;        error
   int *b=&vect[0];
   b=b+1;    // ( point next integer )
   cout<<b<<endl;



   char ch[6]={'a','b','c','d','e'};
   char *g=&ch[0];
   cout<<g<<endl;      // prints :- abcde 
    
}
   



