#include <iostream>
#include <string>

using namespace std;

class Window
{
  public:
    Window(); //Default constructor
    Window(int index); //Overloaded constructor
    ~Window(); //Destructor

    int index;
    int idle;
    
    bool hasStudent;
};
