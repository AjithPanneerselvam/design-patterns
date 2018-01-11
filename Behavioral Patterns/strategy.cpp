/*
 Strategy Pattern
*/

#include <iostream>
using namespace std;


class Vehicle{
public:
  virtual int getTravelTime() = 0;
  virtual int getFare() = 0;
};


class Transport{
int choice;

public:
  Vehicle* vehicle;
  void chooseVehicle();
  void startRide();
};


class Car: public Vehicle{
public:
  int getTravelTime(){ return 30; }
  int getFare(){ return 100; }
};


class Taxi: public Vehicle{
public:
  int getTravelTime(){ return 45; }
  int getFare(){ return 150; }
};


class AutoRickshaw: public Vehicle{
public:
  int getTravelTime(){ return 70; }
  int getFare(){ return 300; }
};


void Transport :: chooseVehicle(){
  cout<<"\nHere is the list of vehicles to for you to choose: \n1.Car \n2.Taxi \n3.Auto Rickshaw\n";
  cin>>choice;

  if(choice == 1) vehicle = new Car;
  if(choice == 2) vehicle = new Taxi;
  if(choice == 3) vehicle = new AutoRickshaw;
}


void Transport :: startRide(){
  cout<<"\nRide Started";
  cout<<"\nRide is completed in " << vehicle->getTravelTime();
  cout<<"\nYour ride fare is "<< vehicle->getFare();
}


int main(){
  // Class Transport is coupled with the client and not the implementation
  Transport t;
  t.chooseVehicle();
  t.startRide();
  return 0;
}
