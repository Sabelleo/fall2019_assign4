#include "ListNode.h"
#include <iostream>

using namespace std;

template <typename t>
ListNode<t>::ListNode()
{

}

template <typename t>
ListNode<t>::ListNode(t d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename t>
ListNode<t>::~ListNode()
{
  next = NULL;
  prev = NULL;
}
