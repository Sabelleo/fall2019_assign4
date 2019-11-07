#include <fstream>
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
  fileName = "";
  line = "";
  studentArrivalTime = 0;
  numStudentsAtTime = 0;
  studentWindowTime = 0;
  studentIndex = 1;
  isArrivalTime = false;
  isNumStudents = false;
  isWindowTime = false;
  totalNumStudents = 0;
  totalNumWindows = 0;
  currentTime = 0;
  currStudentPos = 0;
  fileRead = false;

  meanWaitTime = 0.0;
  medianWaitTimePos = 0;
  medianWaitTime = 0;
  longestWaitTime = 0;
  numStudent10min = 0;
  meanWindowIdleSum = 0;
  meanWindowIdle = 0.0;
  longestWindowIdle = 0;
  numWindows5min = 0;
}

Simulation::~Simulation()
{
  delete[] allWindows;
  delete[] allStudents;
  delete[] studentWaitTimes;
  delete[] windowIdleTime;
}

void Simulation::Read(string name)
{
  fileName = name;
  inputStream.open(fileName);

  while (inputStream.fail())
  {
    cout << "Your file didn't work. Try running this program again." << endl;
    break;
  }
  //need totalNumWindows for making window array
  inputStream >> totalNumWindows;

  allWindows = new Window[totalNumWindows]; //array of windows
  for (int i = 0; i < totalNumWindows; i++)
  {
    allWindows[i].index = i;
  }

  //next = arrival, others false
  isArrivalTime = true;
  isNumStudents = false;
  isWindowTime = false;

  //find student array size
  while (getline(inputStream,line))
  {
    if (isArrivalTime == true && isNumStudents == false && isWindowTime == false)
    {
      inputStream >> studentArrivalTime;
      isArrivalTime = false;
      isNumStudents = true;
    }
    //arrival read, now number of students
    else if (isArrivalTime == false && isNumStudents == true && isWindowTime == false)
    {
      inputStream >> numStudentsAtTime;
      isNumStudents = false;
      isWindowTime = true;
    }
    //num students read, now wait times
    else if (isArrivalTime == false && isNumStudents == false && isWindowTime == true)
    {
      inputStream >> studentWindowTime;
      totalNumStudents++; //for the array
      numStudentsAtTime--; //students in this time frame, count em down
      if (numStudentsAtTime <= 0)
      {
        isWindowTime = false;
        isArrivalTime = true;
      }
    }
  }
  //we've read the total num of students
  inputStream.close();

  allStudents = new Student[totalNumStudents]; //array of students

  //read again, and get data
  inputStream.open(fileName);

  inputStream >> totalNumWindows;

  //similar to earlier loop
  isArrivalTime = true;
  isNumStudents = false;
  isWindowTime = false;

  while (getline(inputStream,line))
  {
    if (isArrivalTime == true && isNumStudents == false && isWindowTime == false)
    {
      inputStream >> studentArrivalTime;
      isArrivalTime = false;
      isNumStudents = true;
    }
    else if (isArrivalTime == false && isNumStudents == true && isWindowTime == false)
    {
      inputStream >> numStudentsAtTime;
      isNumStudents = false;
      isWindowTime = true;
    }
    else if (isArrivalTime == false && isNumStudents == false && isWindowTime == true)
    {
      inputStream >> studentWindowTime;
      numStudentsAtTime--; //students in this time frame, count em down
      if (studentIndex <= totalNumStudents)
      {
        //add to student, now that we have the array
        allStudents[studentIndex-1].arrival = studentArrivalTime;
        allStudents[studentIndex-1].windowTime = studentWindowTime;
        allStudents[studentIndex-1].lineIndex = studentIndex;
        studentIndex++;
      }
      if (numStudentsAtTime <= 0)
      {
        isWindowTime = false;
        isArrivalTime = true;
      }
    }
  }
  //boom. done.
  inputStream.close();
}

void Simulation::Simulate()
{
  //do ALL of the loops until file is done
  while(!fileRead)
  {
    //not done yet!!!
    ++currentTime;
  }
}

void Simulation::Calculate()
{
  studentWaitTimes = new int[totalNumStudents]; //array of wait times
  for (int i = 0; i < totalNumStudents; ++i)
  {
    studentWaitTimes[i] = allStudents[i].waitTime;
    meanWaitTime += studentWaitTimes[i];
    if (studentWaitTimes[i] > 10)
    {
      numStudent10min++;
    }
  }
  meanWaitTime = meanWaitTime/totalNumStudents;

  int temp = 0;
  for(int i = 0; i < totalNumStudents; i++)
    {
        if(studentWaitTimes[i] > temp)
        temp = studentWaitTimes[i];
    }
  longestWaitTime = temp;

  windowIdleTime = new int[totalNumWindows];
  for (int j = 0; j < totalNumWindows; ++j)
  {
    windowIdleTime[j] = allWindows[j].idle;
    meanWindowIdle += windowIdleTime[j];
    if (windowIdleTime[j] > 5)
    {
      numWindows5min++;
    }
  }
  meanWindowIdle = meanWindowIdle/totalNumWindows;

  temp = 0;
  for(int i = 0; i < totalNumWindows; i++)
    {
        if(windowIdleTime[i] > temp)
        temp = windowIdleTime[i];
    }
  longestWindowIdle = temp;

  cout << "Mean Student Wait Time Mean: " << meanWaitTime << endl;
  cout << "Median Student Wait Time: " << medianWaitTime << endl;
  cout << "Longest Student Wait Time: " << longestWaitTime << endl;
  cout << "Number Students waiting > 10 minutes: " << numStudent10min << endl;
  cout << "Mean Window Idle Time: " << meanWindowIdle << endl;
  cout << "Longest Window Idle Time: " << longestWindowIdle << endl;
  cout << "Number of Windows idle > 5 minutes: " << numWindows5min << endl;
}
