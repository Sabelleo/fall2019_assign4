#include "DoublyLinkedList.cpp"
#include <iostream>
#include <string>

using namespace std;

template <typename t>
class Queue
{
  public:
    DoublyLinkedList<t> queue; //Using LinkedList type t in Queue
    Queue(); //Constructor
    ~Queue(); //Destructor

    void insert(t d); //Insert to the back
    t remove(); //Take from the front
    t peek(); //Look at the front
    bool isEmpty();
    int size;
};
