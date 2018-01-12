/*
Obeserver Pattern
In the following example, Content Producer is the subject, whereas Sponsor and Subscriber are the Observers
This is a 'push' implementation of the design pattern. 'pull' implementation can also be implemented based on the use case.
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


class Observer{
public:
  virtual void update(char* s) = 0;
};


class ContentProducer{
public:
  vector<Observer* > subscribers;

  void attach(Observer* o){
    subscribers.push_back(o);
  }

  void addVideo(){
    cout<<"\nA new video is added";
    update("Add");
  }

  void deleteVideo(){
    cout<<"\nA video is deleted";
    update("Delete");
  }

  void update(char* s){
      for(int i = 0; i < subscribers.size(); i++){
        subscribers[i]->update(s);
      }
  }
};


class Sponsor: public Observer{
int marketVal = 50000;

public:
  void update(char* s){
    if(strcmp("Add", s) == 0)
      marketVal += 1000;
    else{
      // marketVal is a +ve number
      if(marketVal - 1000 >= 0)
        marketVal -= 1000;
    }
    cout<<"\nMarket value is $"<<marketVal;
  }
};


class Subsriber: public Observer{
int videoCount = 20;

public:
  void update(char* s){
    if(strcmp("Add", s) == 0)
      videoCount += 1;
    else
      videoCount -= 1;
    cout<<"\nVideo count is "<<videoCount;
  }
};


int main(){
  ContentProducer c;
  c.attach(new Sponsor);
  c.attach(new Subsriber);
  c.addVideo();
  c.addVideo();
  c.deleteVideo();
  c.addVideo();
  c.deleteVideo();
  return 0;
}
