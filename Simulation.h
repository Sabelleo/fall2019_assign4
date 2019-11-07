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
    bool isArrivalTime; //checking for which case
    bool isNumStudents; //checking for which case
    bool isWindowTime; //checking for which case

    int totalNumStudents;
    int totalNumWindows;
    int currentTime;
    Queue<Student> sQueue; //queue of students
    Student* allStudents;
    Window* allWindows;
    Student currStudent;
    int currStudentPos;
    bool fileRead; //checking for done

    int* studentWaitTimes;
    double meanWaitTime;

    int medianWaitTimePos;
    int medianWaitTime;
    int longestWaitTime;
    int numStudent10min;

    int* windowIdleTime;
    int meanWindowIdleSum;
    double meanWindowIdle;
    int longestWindowIdle;
    int numWindows5min;
};
