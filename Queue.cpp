#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

template <typename t>
Queue<t>::Queue()
{
  size = 0;
}

template <typename t>
Queue<t>::~Queue()
{

}

template <typename t>
void Queue<t>::insert(t d)
{
  queue.insertBack(d);
  size++;
}

template <typename t>
t Queue<t>::remove()
{
  size--;
  return queue.removeFront();
}

template <typename t>
t Queue<t>::peek() //front peek, next to be removed
{
  return (queue.peek(0));
}

template <typename t>
bool Queue<t>::isEmpty()
{
  return (size==0);
}
