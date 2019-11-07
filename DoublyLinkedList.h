#include "ListNode.cpp"
#include <iostream>

using namespace std;

template<typename t>
class DoublyLinkedList
{
  private:
    ListNode<t> *front;
    ListNode<t> *back;
    unsigned int size;

  public:
    DoublyLinkedList(); //Constructor
    ~DoublyLinkedList(); //Destructor

    void insertFront(t d);
    void remove(t d);
    void insertBack(t d);
    t removeFront();
    t removeBack();
    t deletePos(int pos);
    int find(t d);
    t peek(int pos);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};
