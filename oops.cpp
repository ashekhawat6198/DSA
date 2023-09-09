#include <iostream>
using namespace std;

// creating class
// we can also include the class created in other file by : #include "filename"
class Hero
{

    /* ACCESS MODIFIERS
    1. private     - by defalut   :- you can access properties within the class, not outside the class
    2.public               :- you can acess properties outside the class as well as inside the class
    3. protected  */

    // properties

    
    private:           // agar kisi private ko acess krna hai toh, we can use getters and setters 
   int health;
    

public: // iske neeche ke sab public ho gye  and we can do same as with private also
    string name;
    char level;
    static int timetocomplete;      // belongs to class , need not required to create object
    int gethealth()
    {
        return health;
    }

    void sethealth(int health)
    {
        this->health = health;
    }

   Hero(){
    cout<<"Simple constructor"<<endl;
   }

   // COPY CONSTRUCTOR

   
   Hero(Hero& temp){
    cout<<"copy constructor called"<<endl;
    this->name=temp.name;
    this->level=temp.level;
   }

    Hero(string name,char level){
        this->name=name;
        this->level=level;
    }

    void print(){
        
        cout<<"The name is: "<<this->name<<endl;
        cout<<"The level is: "<<this->level<<endl;
    }


    // destructor

    ~Hero(){
        cout<<"destructor called"<<endl;
    }

    static int random(){
        // sirf static member ko hee access krte hai
        // object ni hota 
        // this bhee use ni kr sakte
        cout<<"static function"<<endl;
    }

    
};

int Hero::timetocomplete=5;

int main()
{

    // creation of object
   

   // static allocation
 /*   Hero h1;
    // h1.health=75;
    h1.sethealth(85);                       // accessing getter and setter
    cout << h1.gethealth() << endl;

    h1.name = "aman";
    h1.level = 'B';
    cout << h1.level << endl;
    cout << h1.name<<endl;*/
    
    

    // dynamic allocation

  /*  Hero *b=new Hero;
    b->level='Z';
    b->name="mohit";
    cout<<(*b).level<<endl;    // OR   COUT<< b->level<<endl;
    cout<<b->name<<endl;
    b->sethealth(105);
    cout<<b->gethealth()<<endl;*/




    Hero vinay("chiku",'A');

    vinay.print();

    //vinay.sethealth(89);
    //cout<<vinay.gethealth()<<endl;
     
     cout<<endl;
    cout<<"vinay ends"<<endl;
    cout<<endl;
   
  /* Hero mohit(vinay);          // copy constructor
    mohit.print();*/

    Hero mohit("tillu",'B');
    mohit.print();

    vinay=mohit;              // assignment operator

    vinay.print();   


     cout<<Hero::timetocomplete<<endl;
     Hero::random();
}