#include <iostream>
using namespace std;

/* POLYMORPHISM :- it is a concept that allows you to perform a single action in different ways. It means many forms.
    TYPES :- 1.  RUNTIME POLYMORPHISM    2. COMPILE TIME POLYMORPHISM
*/

// 1. COMPILE TIME POLYMORPHISM

// 1.1 FUNCTION OVERLOADING                  // by using different datatype arguments,different in no of arguments

class A{
  public:
  void print(){
    cout<<"Hello aman"<<endl;
  }

  void print(string name){
    cout<<"Hello "<<name<<endl;
  }

   void print(string name1,string name2){
       cout<<"Heloo "<<name1<<" and "<<name2<<endl;
   }
};
  

// 1.2 OPERATOR OVERLOADING



int main(){
   A bachha;
   bachha.print();
   bachha.print("mohit");
   bachha.print("aman","vinay");
}