#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template<typename t>
DoublyLinkedList<t>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template<typename t>
DoublyLinkedList<t>::~DoublyLinkedList()
{
  ListNode<t> *current = front;
  while (current) //runs until next, and therefore current, is NULL
  {
      ListNode<t> *next = current->next;
      delete current;
      current = next;
  }
}

template<typename t>
void DoublyLinkedList<t>::insertFront(t d)
{
  ListNode<t> *node = new ListNode<t>(d);
  if (isEmpty())
  { //empty list, front and back point to same node
    back = node;
  }
  else
  { //not an empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template<typename t>
void DoublyLinkedList<t>::insertBack(t d)
{
  ListNode<t> *node = new ListNode<t>(d);
  if (isEmpty())
  { //empty list, front and back point to same node
    front = node;
  }
  else
  { //not an empty list
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <typename t>
void DoublyLinkedList<t>::remove(t d)
{
  int pos = find(d);
  deletePos(pos);
}
/*
int DoublyLinkedList::remove(int d) // AKA INT KEY
{
  //check if empty before attempting to remove a node at the position
  ListNode *curr = front;

  while (curr->data != d)
  {
    curr = curr->next;

    if (curr == NULL) //value isn't in the list, makes sure something is returned anyway.
      return -1;
  }
  //value/node to be removed has been found

  //checking cases!
  if (curr == front)
  {
    front = curr->next;
  }
  else //not in the front...
  {
    curr->prev->next = curr->next;
  }
  if (curr == back)
  {
    back = curr->prev;
  }
  else
  {
    curr->next->prev = curr->prev;
  }
  return curr->data;
}*/

template<typename t>
t DoublyLinkedList<t>::removeFront()
{
  //check if isEmpty
  ListNode<t> *ft = front;

  if(front->next == NULL)
  { //only 1 element in the list
    back = NULL;
  }
  else
  { // more than 1 element in list
    front->next->prev = NULL;
  }

  front = front->next;
  t tmp = ft->data;
  ft->next = NULL; //ft is placeholder so we don't lose the pointer in memory
  size--;
  delete ft;
  return tmp;
}

template<typename t>
t DoublyLinkedList<t>::removeBack()
{
  //check if isEmpty
  ListNode<t> *bk = back;

  if(bk->prev == NULL)
  { //only 1 element in the list
    front = NULL;
  }
  else
  { // more than 1 element in list
    back->prev->next = NULL;
  }

  back = back->prev;
  t tmp = bk->data; //the pointer to the data in bk, so the data
  bk->prev = NULL; //ft is placeholder so we don't lose the pointer in memory
  size--;
  delete bk;
  return tmp;
}

//NOT EDITED FROM HERE DOWN

template<typename t>
t DoublyLinkedList<t>::deletePos(int pos)
{
  int idx = 0;
  ListNode<t> *prev = front;
  ListNode<t> *curr = front;

  while(idx != pos)
  {
    prev = curr;
    curr = curr->next;
    idx++;
  }
  //found node that is to be deleted

  prev->next = curr->next;
  curr->next = NULL;
  t tmp = curr->data;

  delete curr;
  size--;

  return tmp;
}

template<typename t>
int DoublyLinkedList<t>::find(t d)
{
  int idx = 0;
  ListNode<t> *curr = front;

  while (curr != NULL)
  {
    if(curr->data == d)
      break;
    curr = curr->next;
    idx++;
  }

  if(curr == NULL) //couldn't find value we were looking for
    idx = -1;

  return idx;
}

template<typename t>
unsigned int DoublyLinkedList<t>::getSize()
{
  return size;
}

template<typename t>
void DoublyLinkedList<t>::printList()
{
  ListNode<t> *curr = front;
  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template<typename t>
bool DoublyLinkedList<t>::isEmpty()
{
  if (size == 0){
    return true;
  }
  return false;
}

template<typename t>
t DoublyLinkedList<t>::peek(int pos)
{
  if (isEmpty())
  {
    cout << "Empty List" << endl;
  }
  else
  {
    int index = 0;
    ListNode<t> *curr = front;
    while(index != pos)
    {
      curr = curr->next;
      if(curr == NULL)
      {
        cout << "Index not found" << endl;
      }
      index++;
    }
    return curr->data;
  }
}
