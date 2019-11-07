#include "Student.h"

using namespace std;

Student::Student()
{
  waitTime = 0;
  windowNum = 0;

  inLine = false;
  atWindow = false;
  done = false;
}

Student::Student(int arrival, int windowTime, int lineIndex)
{
  arrival = arrival;
  lineIndex = lineIndex;
  waitTime = 0;
  windowTime = windowTime;
  windowNum = 0;

  inLine = false;
  atWindow = false;
  done = false;
}

Student::~Student()
{

}
