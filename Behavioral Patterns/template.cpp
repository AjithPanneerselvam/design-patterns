/*
Template method design pattern 
*/

#include <iostream>
using namespace std;

class Routine{
public:
  void sleep(){
    cout<<"\nSleeping";
  }

  void walk(){
    cout<<"\nWalking";
  }

  void eat(){
    cout<<"\nEating";
  }

  virtual void work() = 0;

};


class Teacher: public Routine{
public:
  void work(){
    cout<<"\nTeaching";
  }
};


class Programmer: public Routine{
public:
  void work(){
    cout<<"\nCoding";
  }
};


class Cricketer: public Routine{
public:
  void work(){
    cout<<"\nBatting";
  }
};


int main(){
  Routine* objects[] = {new Teacher, new Programmer, new Cricketer};
  for(int i = 0; i < 3; i++){
    objects[i]->sleep();
    objects[i]->walk();
    objects[i]->eat();
    objects[i]->work();
    cout<<"\n\n";
  }
  return 0;
}
