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
			//Logger::WriteMessage("Node: constructor called");  // debug output:
		}

		~Node()
		{
			delete[] Elements;
		}

		void push_back(const T& e)
		{
			if (NumElems == NodeSize)
				return;

			// this function should not be called if the node is full

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

	}

	myvector(const myvector& other)

	{
		//
		// TODO: not yet implemented
		//
		//throw std::runtime_error("myvector::copy constructor() not yet implemented");
	}

	~myvector()
	{

		delete Head;
	}

	int size() const
	{
		return NumElems;

		//throw std::runtime_error("myvector::size() not yet implemented");
	}

	int capacity() const
	{
		Node *cur = Head;
		int count = 0;

		while (cur != nullptr)
		{
			count = count + cur->NodeSize;
			cur = cur->Next;
		}
		return count;


		//return NumNodes * 4;

		//throw std::runtime_error("myvector::capacity() not yet implemented");
	}



	int nodes() const

	{
		return NumNodes;
		//throw std::runtime_error("myvector::nodes() not yet implemented");
	}

	void push_back(const T& e)
	{


		if (NumNodes == capacity())
		{
			int size;
			if (Tail->NodeSize == 4)
				size = 11;
			else if (Tail->NodeSize == 11)
				size = 85;
			else if (Tail->NodeSize == 85)
				size = 156;
			else if (Tail->NodeSize == 156)
				size = 256;
			else
				size = (Tail->NodeSize) * 2;

			Node *newnode = new Node(size);
			NumNodes++;
			Tail->Next = newnode;
			Tail = newnode;
		}
		
			Tail->push_back(e);
			NumElems++;
	
	}

	T& operator[](int i)
	{

		Node *cur = Head;

		while (true)
		{
			if (i >= cur->NumElems)
			{
				i = i - cur->NumElems;
				cur = cur->Next;
			}
			else
			{
				return cur->Elements[i];
			}
		}


		//
		// TODO: not yet implemented, return ith element
		//
		//throw std::runtime_error("myvector::operator[] not yet implemented");
	}

	T& front()
	{
		if (NumElems == 0);
			//throw std::runtime_error("vector is empty!");

		return Head->Elements[0];
	}

	T& back()
	{
		if (NumElems == 0);
			//throw std::runtime_error("vector is empty!");

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
