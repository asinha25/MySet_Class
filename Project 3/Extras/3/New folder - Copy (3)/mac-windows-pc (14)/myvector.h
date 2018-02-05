/*myvector.h*/

//
// myvector class --- a replacement for std::vector based on linked
// nodes of array "chunks".  The idea is to avoid the need to reallocate
// the underlying dynamic array (and copying elements) when the vector
// becomes full.
//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS341, Fall 2016
// HW #03
//

#pragma once

#include <iostream>
#include <iterator>
#include <exception>
#include <stdexcept>

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
    T           *elements;
    int          nodeSize;
    int          numElems;
    class Node  *next;

    Node(int nodesize)
      : elements{ new T[nodesize] }, nodeSize{ nodesize }, numElems{ 0 }, next{ nullptr }
    { }

    ~Node()
    {
      delete[] elements;
    }

    void push_back(const T& e)
    {
      if (numElems == nodeSize)
        throw std::exception("node is full!");

      elements[numElems] = e;
      numElems++;
    }
  };

  //
  // myvector:
  //
private:
  Node  *head;
  Node  *tail;
  int    nodeSize;
  int    numNodes;
  int    numElems;

public:
  myvector(int nodesize = 100)
    : head{ new Node(nodesize) }, tail{ head }, nodeSize{ nodesize }, numNodes{ 1 }, numElems{ 0 }
  { }

  myvector(const myvector& other)
  {
    throw std::exception("myvector::copy constructor() not yet implemented")
  }

  ~myvector()
  {
    //
    // needs to be generalized:
    //
    delete head;
  }

  int size()
  {
    throw std::exception("myvector::size() not yet implemented");
  }

  int capacity()
  {
    throw std::exception("myvector::capacity() not yet implemented");
  }

  void push_back(const T& e)
  {
    //
    // needs to be generalized:
    //
    tail->push_back(e);
    numElems++;
  }

  T& operator[](int i)
  {
    throw std::exception("myvector::operator[] not yet implemented");
  }

  T& front()
  {
    if (numElems == 0)
      throw std::exception("vector is empty!");

    return head->elements[0];
  }

  T& back()
  {
    if (numElems == 0)
      throw std::exception("vector is empty!");

    return tail->elements[tail->numElems - 1];
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
