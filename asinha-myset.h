/*myset.h*/
//
//
// myset data structure, i.e. a data structure modelled
// after std::set in modern C++.
//
// Aditya Sinha
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
	int set_size;
	int capacity;
	T* elements;

  //
  // Allows iteration through the set in element order.
  //
  class iterator
  { 
  private:
	  T* Elements;
	  int index;

  public:
    //
    // Constructor
    //

	 iterator(T* elements, int i) 
			: Elements(elements), index(i)
		{ }

    //
    // Destructor
    //
    ~iterator()
    {
		Elements = NULL;
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

		index++;

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

		//T* e = new T(*Elements);
		
      //
      // Note: this code is wrong, you cannot return a reference 
      // to a local variable -- the local is destroyed when 
      // function returns. Must return something with a longer 
      // lifetime, i.e. data in the heap.
      //
	
      return (Elements[index]);
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
		if (index != rhs.index) {
			return true;
		}
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
		if(Elements[index] == rhs.Elements[index])
			return true;
		return false;
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
	  set_size = 0;
	  elements = new T[64];
	  capacity = 64;
  }


  //
  // Copy constructor:
  //
  myset(const myset& other)
  {
    //
    // TODO:
    //
	  if (other.capacity > this->capacity) {
		  delete[] elements;
		  elements = new T[other.capacity];
		  capacity = other.capacity;
	  }
	  int index = 0;
	  while (index < other.set_size) {
		  elements[index] = other.elements[index++];
	  }
	  set_size = other.set_size;
  }


  //
  // Destructor: destroy all elements in set.
  //
  ~myset()
  {
    //
    // TODO:
    //
	  delete[] elements;
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
    return set_size;
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
	  if (set_size!=0)
		  return false;
	  else
		  return true;
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
	  delete[]elements;
	  set_size = 0;
	  capacity = 64;
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
	  //check to see if it alreay in set
	  int index = 0;
	  while (index < set_size) {
		  if (elements[index++] == e) {
			  return false;
		  }
	  }

	  //the capacity if full
	  if (set_size == capacity) {
		  index = 0;
		  T* newElements = new T[capacity * 2];
		  while (index < capacity) {
			  newElements[index] = elements[index++];
		  }
		  set_size++;
		  capacity *= 2;
		  delete[] elements;
		  elements = newElements;
		  return true;
	  }

	  //is the set is empty
	  if (set_size == 0) {
		  elements[0] = e;
		  set_size++;
		  return true;
	  }
    
	  //all above condition are not match
	  elements[set_size++] = e;
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
	  int i = 0;
	  while (i < set_size) {
		  if (elements[i++] == e)
			  break;
	}
	  return iterator(elements, i);
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
	  int index = 0;
	  while (index < set_size-1) {
		  if (elements[index++] == e) {
			  return true;
		  }
	  }
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
	  delete[] elements;
	  set_size = 0;
	  
	  if (rhs.capacity > this->capacity) {
		  delete[] elements;
		  elements = new T[rhs.capacity];
		  capacity = rhs.capacity;
	  }
	  int index = 0;
	  while (index < rhs.set_size) {
		  elements[index] = rhs.elements[index++];
	  }
	  set_size = rhs.set_size;

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
    return iterator(elements, 0);
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
    return iterator(elements, set_size+1);
  }

};
