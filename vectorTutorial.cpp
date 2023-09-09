#include <iostream>
using namespace std;
#include <vector>
int main(){
   
   vector<int>a;
   cout<<"CAPACITY: "<<a.capacity()<<endl;
   a.push_back(1);
   a.push_back(2);
   a.push_back(3);
   cout<<"Capacity: "<<a.capacity()<<endl;
   cout<<"Size: "<<a.size()<<endl;

   for(int i:a){
      cout<<i<<" "<<endl;
   }

   //a.pop_back();


   for(int i:a){
      cout<<i<<" ";
   }cout<<endl;

   vector <int>v(5,3);
   for(int i:v){
      cout<<i<<" ";
   }cout<<endl;

   vector <int>t(v);
   for(int i:t){
      cout<<i<<" ";
   }cout<<endl;

      vector <int>s;
      s=v;
      for(int i:s){
         cout<<i<<" ";
      }
      vector<int>b(a.capacity());
      cout<<"capacity: "<<b.capacity();
}