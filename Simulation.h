#include <fstream>
#include "Student.cpp"
#include "Window.cpp"
#include "Queue.cpp"

using namespace std;

class Simulation
{
  public:
    Simulation(); //Constructor
    ~Simulation(); //Destructor

    void Read(string name); //read file
    void Simulate(); //simulate a single time
    void Calculate(); //calculate stuff

    ifstream inputStream;
    string fileName;
    string line;

    int studentArrivalTime;
    int numStudentsAtTime;
    int studentWindowTime;
    int studentIndex;
    bool arrivalTime; //checking for which case
    bool numStudents; //checking for which case
    bool windowTime; //checking for which case

    int totalNumStudents;
    int totalNumWindows;
    int currentTime;
    Queue<Student> sQueue; //queue of students
    Student* allStudents;
    Window* allWindows;

    int* studentWaitTimes;
    double meanWaitTime;

    int medianWaitTime;
    int longestWaitTime;
    int numStudent10min;

    int* windowIdleTime;
    double meanWindowIdle;
    int longestWindowIdle;
    int numWindows5min;
};
