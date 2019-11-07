#include <iostream>
#include <string>

using namespace std;

class Student
{
  public:
    Student(); //Default constructor
    Student(int arrival, int windowTime, int lineIndex); //Overloaded constructor
    ~Student(); //Destructor

    int arrival; //arrival time
    int lineIndex; //index, keep track of order
    int waitTime; //time in line
    int windowTime; //time spent at window
    int windowNum; //student's window

    bool inLine; //is student in line for window?
    bool atWindow; //is student at window?
    bool done; //is student done?

};
