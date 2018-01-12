/*
State Design Pattern
*/
#include <iostream>
using namespace std;


class State{
public:
  virtual void run() = 0;
};


class Goodnight{
public:
  State* currentState;
  void setState(State* state){
    state->run();
  }

};




class Normal: public State{
public:
  void run(){
    cout<<"\nRunning Normal mode";
  }
};


class Active: public State{
public:
  void run(){
    cout<<"\nRunning Active mode";
  }
};


int main(){
  Goodnight trigger;
  trigger.setState(new Normal);
  trigger.setState(new Active);
  trigger.setState(new Normal);
  return 0;
}
