/*myvector.h*/

//
// myvector class --- a replacement for std::vector based on linked
// nodes of varying-sized array "chunks".  The idea is to avoid the
// reallocation of the underlying dynamic array (and the copying of 
// elements) when the vector becomes full.
//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS341, Spring 2017
// Project #03
//

#pragma once

#include <iostream>
#include <iterator>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;


//
// myvector<T>
//
template<typename T>
class myvector
{
private:
  //
  // One node of the vector, i.e. an array "chunk" of size nodeSize.
  //
  class Node
  {
  public:
    T          *Elements;
    int         NumElems;
    int         NodeSize;
    class Node *Next;

    Node(int nodesize)
      : Elements{ new T[nodesize] }, NumElems{ 0 }, NodeSize{ nodesize }, Next{ nullptr }
    {
      Logger::WriteMessage("Node: constructor called");  // debug output:
    }

    ~Node()
    {
      delete[] Elements;
    }

    void push_back(const T& e)
    {
      // this function should not be called if the node is full:
      if (NumElems == NodeSize)
        throw std::exception("node is full!");

      Elements[NumElems] = e;
      NumElems++;
    }
  };

  //
  // myvector:
  //
private:
  Node  *Head;
  Node  *Tail;
  int    NumElems;
  int    NumNodes;

public:
  myvector()
    : Head{ new Node(4) }, Tail{ Head }, NumElems{ 0 }, NumNodes{ 1 }
  { 
    Logger::WriteMessage("myvector: constructor called");  // debug output:
    Logger::WriteMessage(to_string(NumElems).c_str());
  }

  myvector(const myvector& other)
  {
    //
    // TODO: not yet implemented
    //
    throw std::exception("myvector::copy constructor() not yet implemented")
  }

  ~myvector()
  {
    //
    // TODO: needs to be generalized to delete all the nodes...
    //
    delete Head;
  }

  int size() const
  {
    //
    // TODO: not yet implemented, return # of elements currently in vector
    //
    throw std::exception("myvector::size() not yet implemented");
  }

  int capacity() const
  {
    //
    // TODO: not yet implemented, return how many elements we can store given
    // the current # of nodes in the linked-list
    //
    throw std::exception("myvector::capacity() not yet implemented");
  }

  int nodes() const
  {
    //
    // TODO: not yet implemented, return # of nodes in the linked-list
    //
    throw std::exception("myvector::nodes() not yet implemented");
  }

  void push_back(const T& e)
  {
    //
    // TODO: needs to be generalized to link on a new node when
    // the current node becomes filled:
    //
    Tail->push_back(e);
    NumElems++;
  }

  T& operator[](int i)
  {
    //
    // TODO: not yet implemented, return ith element
    //
    throw std::exception("myvector::operator[] not yet implemented");
  }

  T& front()
  {
    if (NumElems == 0)
      throw std::exception("vector is empty!");

    return Head->Elements[0];
  }

  T& back()
  {
    if (NumElems == 0)
      throw std::exception("vector is empty!");

    return Tail->Elements[Tail->NumElems - 1];
  }

  //iterator begin()
  //{
  //  return iterator(???);
  //}

  //iterator end()
  //{
  //  return iterator(???);
  //}

};
