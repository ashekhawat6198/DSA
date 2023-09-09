#include <iostream>
using namespace std;

/* ENCAPSULATION :-  wrapping up of data members and functions in single entity(class)
FULLY CAPSULATED :-  when we mark all data members private
 ADVANTAGES:-  1.) data hiding as we using private  [security aspects increases]   2.) we can make class read only  3.) code reusability   4.)  helps in unit testing               */
class student
{

private:
    string name;
    int age;
    int rollNo;
};

/* INHERITANCE :- process of inheriting the properties and behaviour of an existing class/parent class/super class into a new class/
                   child class/sub class.

            PROTECTD :- apni class aur child class mai access kr sakte hai aur kahi ni same with private
   ACCESS MODIFIERS AND INHERITANCE :-              parent class                       child class

                                                       public                            public        =       public
                                                       public                            private       =       private
                                                       public                            protected     =       protected

                                                       protected                         private       =        private
                                                       protected                         protected     =        protected
                                                       protected                         public        =        protected

                                                       private                           private       =         NOT ACCESSIBLE ( child class mai bhee ni)
                                                       private                           public        =         NA( child class mai bhee ni)
                                                       private                           protected     =         NA( child class mai bhee ni)

 PRIVATE DATA MEMBER OF ANY CLASS CANNOT BE INHERITED

TYPE OF INHERITANCE :- 1. SINGLE   2. MULTILEVEL  3. MULTIPLE   4. HYBRID    5.  HIERARICHAL

*/

// 1.SINGLE INHERITANCE
class Human
{

protected:
    int height;

public:
    int weight;
    int age;

    int getAge()
    {
        return this->age;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

class Male : private Human
{

public:
    string color;

    void sleep()
    {
        cout << "Male Sleeping" << endl;
    }

    Male(string color)
    {
        this->color = color;
    }
};


//  2.MULTI LEVEL INHERITANCE
class Animal{
     string type;
     string color;
  
};

class dog:public Animal{
    

};

class husky:public dog{

};

// 3. MULTIPLE INHERITANCE
 
 class Male1{
    public:
   int height;
   void sleep(){
    cout<<"sleeping"<<endl;
   }

 };

 class Female{
    public:
   int age;
   void eat(){
    cout<<"eating"<<endl;
   }

 };

 class dono:public Male1,public Female{

 };


// 4. HIERARCHICAL INHERITANCE

class A{
    
};

class B:public A{


};

class C:public A{

};

// 5. HYBRID INHERITANCE

class p1{

};

class p2{

};

class c1:public p1{


};

class c2:public p1, public p2{


};


//  [ we can use ( obj.class::function_nacme()  ) if we have same function in multiple class when using inheritance ]

int main()
{

   /* Male m1("green");
    m1.sleep();
    m1.setAge(55);
    cout << m1.getAge() << endl;
    m1.height = 175;
    cout << m1.height << endl;
     cout << m1.color << endl;*/

     dono d1;
      d1.sleep();
}