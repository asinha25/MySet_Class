/*myset.h*/

//
// myset data structure, i.e. a data structure modelled
// after std::set in modern C++.
//
// YOUR NAME
// U. of Illinois, Chicago
// CS 341, Fall 2017
// Project #03
//

#pragma once

using namespace std;


template<typename T>
class myset
{
private:
  //
  // Allows iteration through the set in element order.
  //
  class iterator
  { 
  private:

  public:
    //
    // Constructor
    //
    iterator()
    {
      //
      // TODO:
      //
    }

    //
    // Destructor
    //
    ~iterator()
    {
      //
      // TODO:
      //
    }

    //
    // ++iter
    //
    // Advances to the next element in the set; elements are
    // visited in element order.  Operation is undefined if
    // iterator == end().
    //
    iterator& operator++()
    {
      //
      // TODO: advance "this" iterator
      //



      //
      // return "this" updated iterator:
      //
      return *this;
    }

    //
    // *iter
    //
    // Returns the element denoted by this iterator; the 
    // operation is undefined if iterator == end().
    //
    T& operator*()
    {
      //
      // TODO:
      //
      T  defaultValue;
      
      //
      // Note: this code is wrong, you cannot return a reference 
      // to a local variable -- the local is destroyed when 
      // function returns. Must return something with a longer 
      // lifetime, i.e. data in the heap.
      //

      return defaultValue;
    }

    //
    // lhs != rhs
    //
    // Returns true if "this" iterator != rhs iterator.
    //
    bool operator!=(const iterator& rhs)
    {
      //
      // TODO:
      //
      return false;
    }

    //
    // lhs == rhs
    //
    // Returns true if "this" iterator == rhs iterator.
    //
    bool operator==(const iterator& rhs)
    {
      //
      // TODO:
      //
      return true;
    }
  };

  //
  // Data members for myset:
  //
  //
  // TODO:
  //


public:
  //
  // Default constructor: constructs a new, empty set
  //
  myset()
  {
    //
    // TODO:
    //
  }


  //
  // Copy constructor:
  //
  myset(const myset& other)
  {
    //
    // TODO:
    //
  }


  //
  // Destructor: destroy all elements in set.
  //
  ~myset()
  {
    //
    // TODO:
    //
  }


  //
  // size()
  //
  // Returns # of elements in the set.
  //
  int size() const
  {
    //
    // TODO:
    //
    return -1;
  }


  // 
  // empty()
  //
  // Returns true if set is empty, false if not.
  //
  bool empty() const
  {
    //
    // TODO:
    //
    return false;
  }


  //
  // clear()
  //
  // Empties the set, destroying all the elements.  Afterwards, 
  // the size of the set is 0.
  //
  void clear()
  {
    //
    // TODO:
    //
  }


  //
  // insert(e)
  //
  // Inserts the element e into the set.  Returns true if e
  // was inserted, false if e was already in the set (and thus
  // not inserted again).  Elements are inserted in element 
  // order as defined by the < operator; this enables in order 
  // iteration.
  //
  // Requirements:
  //   1. Insert time must be <= O(N).
  //   2. Set grows as needed to accommodate new elements.
  //   3. Assumes only < operator; two elements x and y are
  //      equal if (!(x<y)) && (!(y<x)).
  //
  bool insert(const T& e)
  {
    //
    // TODO:
    //
    return false;
  }


  // 
  // += e
  //
  // Inserts e into the set; see insert(e).
  //
  myset& operator+=(const T& e)
  {
    //
    // insert e into "this" set:
    //
    this->insert(e);

    //
    // return "this" updated set:
    //
    return *this;
  }


  //
  // find(e)
  //
  // Searches the set for the element e, returning an iterator
  // to e if found.  If e is not found, end() is returned, i.e.
  // an iterator denoting one past the last element.
  //
  // Requirements:
  //   1. Find time must be <= O(lgN).
  //   2. Assumes only < operator; two elements x and y are
  //      equal if (!(x<y)) && (!(y<x)).
  //
  iterator find(const T& e)
  {
    //
    // TODO:
    //
    return iterator();
  }


  //
  // [e]
  //
  // Returns true if set contains e, false if not.
  //
  // Requirements:
  //   1. operation time must be <= O(lgN).
  //   2. Assumes only < operator; two elements x and y are
  //      equal if (!(x<y)) && (!(y<x)).
  //
  bool operator[](const T& e)
  {
    //
    // TODO:
    //
    return false;
  }


  //
  // lhs = rhs;
  //
  // Makes a deep copy of rhs (right-hand-side) and assigns into
  // lhs (left-hand-side).  Any existing elements in the lhs
  // are destroyed.
  //
  // Notes:
  //   1. this is essentially a clear() followed by a copy().
  //   2. the lhs operand is hidden --- it's "this" object.
  //
  myset& operator=(const myset& rhs)
  {
    //
    // TODO:
    //



    //
    // return "this" updated set:
    //
    return *this;
  }


  //
  // begin()
  //
  // Returns an iterator denoting the first element in the
  // set; iteration is performed in element order (as defined
  // by the < operator).
  //
  iterator begin()
  {
    //
    // TODO:
    //
    return iterator();
  }


  //
  // end()
  //
  // Returns an iterator denoting one past the last element
  // in the iteration.
  //
  iterator end()
  {
    //
    // TODO:
    //
    return iterator();
  }

};
