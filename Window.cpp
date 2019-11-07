#include "Window.h"

using namespace std;

Window::Window()
{
  index = 0;
  hasStudent = false;
  idle = 0;
}

Window::Window(int index)
{
  index = index;
  hasStudent = false;
  idle = 0;
}

Window::~Window()
{

}
