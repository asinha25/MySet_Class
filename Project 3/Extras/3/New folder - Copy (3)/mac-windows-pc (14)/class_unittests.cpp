#include "stdafx.h"
#include "CppUnitTest.h"

#include "myvector.h"
#include <vector>
#include <algorithm>
#include <numeric>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace myvectorUnitTest
{
	TEST_CLASS(UnitTest1)
	{

	public:

		//Block
		TEST_METHOD(jhummel2_Test1)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(jhummel2_Test2)
		{
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(jhummel2_Sort)
		{
			myvector<int>  V(10);  // nodesize of 10:

			const int N = 33;

			// 32, 31, 30, ..., 23
			for (int i = 1; i < 11; ++i)
				V.push_back(N - i);

			// 0, 1, 2, ..., 10
			for (int i = 0; i < 11; ++i)
				V.push_back(i);

			for (int i = 11; i <= 22; ++i)
				V.push_back(i);

			Assert::IsTrue(V.size() == N);

			// selection sort using iterators:
			for (auto i = V.begin(); i != V.end(); ++i)
			{
				auto smallest = i;
				for (auto j = i; j != V.end(); ++j)
				{
					if (*j < *smallest)
						smallest = j;
				}

				// swap:
				auto T = *i;
				*i = *smallest;
				*smallest = T;
			}

			// did sort work?
			// should be 0, 1, 2, 3, ..., 30, 31, 32:
			int val = 0;

			for (auto e : V)
			{
				Assert::IsTrue(e == val);
				val++;
			}

			Assert::IsTrue(V.size() == N);
			Assert::IsTrue(val == N);
		}









		TEST_METHOD(aander57_Test01) {
			//test default capacity

			myvector<int> V(10);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(aander57_Test02) {
			// test capacity when capacity has to be increased by push_back

			myvector<int> V(5);

			Assert::IsTrue(V.capacity() == 5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(aander57_Test03) {
			// test size when capacity is increased with push_back

			myvector<int> V(5);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);

			V.push_back(4);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.size() == 6);
		}

		TEST_METHOD(aander57_Test04) {
			// copy vector with one node, check size
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);

			Assert::IsTrue(V2.size() == 3);

		}

		TEST_METHOD(aander57_Test05) {
			// copy vector with one node, check capacity
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);

			Assert::IsTrue(V2.capacity() == 10);
		}

		TEST_METHOD(aander57_Test06) {
			// copy vector, push back to increase numNodes, check capacity

			myvector<int> V(5);

			Assert::IsTrue(V.capacity() == 5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			myvector<int> V2(V);

			V2.push_back(6);

			Assert::IsTrue(V.capacity() == 5);
			Assert::IsTrue(V2.capacity() == 10);

		}

		TEST_METHOD(aander57_Test07) {
			// copy vector with multiple nodes, check size
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

      myvector<int> V2 = V;

			Assert::IsTrue(V2.size() == 11);
      Assert::IsTrue(V2[0] == 1);
      Assert::IsTrue(V2[10] == 11);
      Assert::IsTrue(V2.front() == 1);
      Assert::IsTrue(V2.back() == 11);
		}

		TEST_METHOD(aander57_Test08) {
			// copy vector with multiple nodes, check capacity
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			myvector<int> V2(V);

			Assert::IsTrue(V2.capacity() == 15);
		}

		TEST_METHOD(aander57_Test09) {
			// test operator on first node
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(24);

			Assert::IsTrue(V[2] == 24);

		}

		TEST_METHOD(aander57_Test10) {
			// test operator on third node
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(24);

			Assert::IsTrue(V[10] == 24);

		}

		// FRONT AND BACK TESTS //
		// TEST 1: Tests if front = back
		TEST_METHOD(adankh2_test_front_equal_back)
		{
			myvector<string>V(10);
			V.push_back("Hello, my name is Ashour. How are you doing today? (:");
			Assert::IsTrue(V.front() == V.back());
		}

		// TEST 2: Tests to see if the back is pointing to last element after new Nodes have been created.
		TEST_METHOD(adankh2_test_back_value)
		{
			myvector<int> V(10);
			for (int i = 0; i < 54; ++i)
				V.push_back(i);
			Assert::IsTrue(V.back() == 53);	// 53 here since vector starts from 0.
		}


		// SIZE AND CAPCITY TESTS //
		// TEST 3: Tests size where size is the total number of elements in your vector and it exceeds 1 full node. Different from Hummel's Test(s)
		TEST_METHOD(adankh2_test_size)
		{
			myvector<int> V(10);
			for (int i = 0; i < 54; ++i)
				V.push_back(i);
			Assert::IsTrue(V.size() == 54);
		}

		// TEST 4: Test capcity if multiple nodes are full. 31 elements -> 4 nodes. 4 nodes x 10 = 40.
		TEST_METHOD(adankh2_test_capacity)
		{
			myvector<int> V(10); // Nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);
			for (int i = 0; i < 54; ++i)
				V.push_back(i);
			Assert::IsTrue(V.capacity() == 60);
		}

		// TEST 5:  WILL FAIL IF DEEPCOPY CONSTRUCTOR FAILS! TESTS SIZE OF BOTH VECTORS
		TEST_METHOD(adankh2_test_size_deepcopy)
		{

			myvector<int> V(10); // Nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			myvector<int>W(V);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3 && W.size() == 2);
		}


		// OPERATOR TESTS //
		// TEST 6: Tests operator. Since pushing back 0..n in indices 0..n
		TEST_METHOD(adankh2_test_operator)
		{
			myvector<int> V(10);
			for (int i = 0; i < 42; ++i)
				V.push_back(i);
			Assert::IsTrue(V.operator[](12) == 12);
			Assert::IsTrue(V.operator[](1) == V.front() + 1);
		}

		//TEST 7: Test operator that does some arthimetic.
		TEST_METHOD(adankh2_test_operator_add)
		{
			myvector<int> V(10);
			for (int i = 0; i < 42; ++i)
				V.push_back(i);

			V.operator[](5) += 6;
			Assert::IsTrue(V.operator[](5) == 11);
			V.operator[](5) /= 2;			// 11 divided by 2 = 5.5 -> 5.
			Assert::IsTrue(V.operator[](5) == 5);
		}


		// DEEP COPY CONSTRUCTOR TESTS //
		// TEST 8: Tests the deep copy constructor. First vector should have {1,2,3} second vector should have, {1,2}
		TEST_METHOD(adankh2_test_deepcopy)
		{
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			myvector<int>W(V);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1 && V.back() == 3 && W.front() == 1 && W.back() == 2);
		}


		// ITERATOR TESTS //
		// TEST 9: Tests begin iterator of vector V. Should be equal to the front.
		TEST_METHOD(adankh2_test_beginIter)
		{
			myvector<int> V(10); // Nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(*(V.begin()) == V.front());
		}

		////TEST 10: Tests end iterator of vector V. should be the end of the value.
		//TEST_METHOD(adankh2_test_endIter)
		//{
		//	myvector<int> V(10);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	Assert::IsTrue(*(V.end() - 1) == V.back());
		//}


		// Haven't fully tested, so I'll leave it commented. 10 test cases are above.
		// TEST 11: Tests Iterator of the deepcopy
		TEST_METHOD(adankh2_test_iter_deepcopy)
		{
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			myvector<int>W(V);
			V.push_back(3);
			Assert::IsTrue(*(W.begin()) == W.front());
			//Assert::IsTrue(*(W.end() - 1) == W.back());
		}


		TEST_METHOD(indexTest)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[1] == 2);
		}

		//TEST_METHOD(indexOutOfBoundsTest)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(V[2] == NULL);
		//}

		//TEST_METHOD(sizeOutOfRange)
		//{
		//	myvector<int> V(-1);

		//	Assert::IsFalse(V.size() != -1);
		//}

		TEST_METHOD(capcityTest)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
      Assert::IsTrue(V[5] == 3);
		}





		// Testing push_back past nodesize
		// Testing front & back over multiple nodes
		TEST_METHOD(alanfan1_Test1) {
			myvector<int> V(1);
			V.push_back(42);
			V.push_back(10);
			Assert::IsTrue(V.front() == 42);
			Assert::IsTrue(V.back() == 10);
		}

		// Testing default capacity
		TEST_METHOD(alanfan1_Test2) {
			myvector<int> V;
			Assert::IsTrue(V.capacity() == 100);
		}

		// Testing capacity over 1 node
		TEST_METHOD(alanfan1_Test3) {
			myvector<int> V(10);
			V.push_back(42);
			V.push_back(10);
			Assert::IsTrue(V.capacity() == 10);
		}

		// Testing capacity over mutliple nodes
		TEST_METHOD(alanfan1_Test4) {
			myvector<int> V(1);
			V.push_back(42);
			V.push_back(10);
			Assert::IsTrue(V.capacity() == 2);
		}

		// Testing overloaded []
		TEST_METHOD(alanfan1_Test5) {
			myvector<int> V(10);
			V.push_back(42);
			V.push_back(10);
			Assert::IsTrue(V[0] == 42);
		}

		// Testing copy constructor
		TEST_METHOD(alanfan1_Test6) {
			myvector<int> V(10);
			V.push_back(42);
			myvector<int> X = V;
			Assert::IsTrue(X.back() == 42);
		}

		// testing destructor explicit call
		TEST_METHOD(alanfan1_Test7) {
			int* x = nullptr;

			if (x == nullptr) {
				myvector<int> V(10);
				V.push_back(42);
				x = &(V.back());
				Assert::IsTrue(*x == 42);
			}// destructor called as V is out of scope

			//Assert::IsTrue(*x != 42);
      Assert::IsTrue(true);  // we got here!
		}

		// Testing destructor implicit call
		TEST_METHOD(alanfan1_Test8) {
			myvector<int>* V = new myvector<int>(1);
			V->push_back(42);
			V->push_back(128);
			int* x = &(V->back());
			Assert::IsTrue(*x == 128);
			delete V;
			//Assert::IsTrue(*x != 128);
      Assert::IsTrue(true);  // we got here!
		}

		//// Testing handling nodesize 0
		//TEST_METHOD(alanfan1_Test9) {
		//	myvector<int> V(0);
		//	V.push_back(42);
		//	Assert::IsTrue(V.front() != 42);
		//}

		//// Testing handling negative nodesize
		//TEST_METHOD(alanfan1_Test10) {
		//	myvector<int> V(-10);
		//	V.push_back(42);
		//	Assert::IsTrue(V.back() != 42);
		//}




		TEST_METHOD(alevin24_Test1)
		{
			myvector<int> V(10);	//nodesize of 10;

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.front() -= V.back();

			Assert::IsTrue(V.front() == -2);

		}

		TEST_METHOD(alevin24_test2)
		{
			myvector <int> V(3);	//nodesize of 10;

			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(8);
			Assert::IsTrue(V.size() == 4);
		}

		TEST_METHOD(alevin24_test3)
		{
			myvector <int> V(10);//nodesize of 10;

			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(alevin24_test4)
		{
			myvector <int> V(10); //nodesize of 10;

			V.push_back(10);
			V.push_back(20);
			V.push_back(1);
			V.push_back(5);
			Assert::IsTrue(V.operator[](3) == 5);
		}


		TEST_METHOD(alevin24_test5)
		{
			myvector <int> V(3); //nodesize of 3
			V.push_back(10);
			V.push_back(12);
			V.push_back(15);
			myvector<int> V2 = V;
			Assert::IsTrue(V2.front() == 10);
			Assert::IsTrue(V2.back() == 15);
		}


		TEST_METHOD(alevin24_test6)
		{
			myvector <std::string> V(5); //nodesize of 5
			V.push_back("14423");
			V.push_back("343");
			V.push_back("abba");

			Assert::IsTrue(V.front() == "14423");
			Assert::IsTrue(V.back() == "abba");
		}


		//TEST_METHOD(alevin24_test7)
		//{
		//	myvector <int> V(10);		//nodesize of 10
		//	V.push_back(10);
		//	V.push_back(12);
		//	V.push_back(15);
		//	V.~myvector();

		//	Assert::IsTrue(V.front() == 0);
		//	Assert::IsTrue(V.back() == 0);
		//}

		TEST_METHOD(alevin24_test8)
		{
			myvector <int> V(3);	//nodesize of 3
			V.push_back(10);
			V.push_back(12);
			V.push_back(15);
			V.push_back(1);
			V.push_back(4);
			Assert::IsTrue(V.front() == 10);
			Assert::IsTrue(V.back() == 4);
		}

		TEST_METHOD(alevin24_test9)
		{
			myvector <int> V(10);	//nodesize of 10
			V.push_back('a');
			V.push_back(12);
			V.push_back(15);
			V.push_back(1);
			V.push_back('c');
			Assert::IsTrue(V.front() == 'a');
			Assert::IsTrue(V.back() == 'c');
		}

		TEST_METHOD(alevin24_test10)
		{
			myvector <char> V(10);  //nodesize of 10
			V.push_back('a');
			V.push_back('c');
			V.push_back('d');
			V.push_back('e');
			Assert::IsTrue(V.front() == 'a');
			Assert::IsTrue(V.back() == 'e');
		}


		TEST_METHOD(amujta2_Test1)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(amujta2_Test2)
		{
			myvector<int> V(10);

			V.push_back(9);
			V.push_back(2);

			Assert::IsTrue(V.front() == 9);
		}

		TEST_METHOD(amujta2_Test3)
		{
			myvector<int> V(10);

			V.push_back(5);
			V.push_back(7);

			Assert::IsTrue(V.back() == 7);
		}

		TEST_METHOD(amujta2_Test4)
		{
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.operator[](0) == 1);

		}

		//TEST_METHOD(amujta2_Test5)
		//{
		//	myvector<int> V(10);
		//	V.push_back(11);
		//	V.~myvector();
		//	Assert::IsTrue(V.size() == 0);
		//}

		TEST_METHOD(amujta2_Test6)
		{
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(1);
			Assert::IsTrue((V.back() + V.front()) == 2);
		}

		TEST_METHOD(amujta2_Test7)
		{
			myvector<int> V(19);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsTrue(V.capacity() == 19);
		}

		TEST_METHOD(amujta2_Test8)
		{
			myvector<int> V(20);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsTrue(V.size() == 11);
		}

		TEST_METHOD(amujta2_Test9)
		{
			myvector<int> V(10);
			Assert::IsTrue(V.size() == 0);
		}

		TEST_METHOD(amujta2_Test10)
		{
			myvector<int> V(10);
			V.push_back(NULL);
			Assert::IsTrue(V.size() == 1);
		}





		//tests is the front is 1 and if the back is 3
		TEST_METHOD(apared5_Testp)
		{
			myvector<int> V(10); // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		//tests if the size is 0, then after 3 pushes tests if the size is 3
		TEST_METHOD(apared5_Testo)
		{
			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3);
		}

		//tests if the front is 80
		TEST_METHOD(apared5_Test1)
		{
			myvector<int> V(10);

			V.push_back(80);
			V.push_back(2);

			Assert::IsTrue(V.front() == 80);
		}

		//tests if the back is 3
		TEST_METHOD(apared5_Test2)
		{
			myvector<int> V(3);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		//tests is front = back after only 1 push
		TEST_METHOD(apared5_Test3)
		{
			myvector<int> V(1);
			V.push_back(1);
			Assert::IsTrue(V.front() == V.back());
		}

		//tests to see if the capacity works for 1 node
		TEST_METHOD(apared5_Test4)
		{
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.capacity() == 10);
		}

		//tests to see if the capacity works for more than 1 filled node
		TEST_METHOD(apared5_Test5)
		{
			myvector<int> V(10);
			for (int i = 1; i <= 22; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 30);
		}

		//tests copy constructor to see if it works
		TEST_METHOD(apared5_Test6)
		{
			myvector<int> V(1);
			V.push_back(1);

			myvector<int> V2(V);

			V.push_back(2);

			Assert::IsTrue(V.front() == 1 && V.back() == 2 && V2.front() == V.front() && V2.back() == V.front());
		}

		//tests iterator begin()
		TEST_METHOD(apared5_Test7)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(*(V.begin()) == V.front());
		}

		//tests iterator end()
		//TEST_METHOD(apared5_Test8)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);

		//	Assert::IsTrue(*(V.end() - 1) == V.back());
		//}

		//tests size
		TEST_METHOD(apared5_Test9)
		{
			myvector<int> V(10);
			V.push_back(40);
			V.push_back(23);
			Assert::IsTrue(V.size() == 2);
		}

		//tests size with more than one node
		TEST_METHOD(apared5_Test10)
		{
			myvector<int> V(10);

			for (int i = 0; i < 23; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 23);
		}



		TEST_METHOD(arashi6_CheckingInsert)
		{
			myvector<int> v(10);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			Assert::IsTrue(v.back() == 4);
			Assert::IsTrue(v.front() == 1);
		}

		TEST_METHOD(arashi6_CheckingSize)
		{
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			Assert::IsTrue(v.size() == 4);

		}

		TEST_METHOD(arashi6_checkingCapacity)
		{
			myvector<int> v(10);
			for (int k = 0; k < 46; k++)
				v.push_back(k);
			Assert::IsTrue(v.capacity() == 50);
		}

		TEST_METHOD(arashi6_CheckFrontBackEqual)
		{
			myvector<int> v;
			int x = v.capacity();
			for (int k = 0; k < x; k++)
				v.push_back(55);
			Assert::AreEqual(v.front(), v.back());
		}

		TEST_METHOD(arashid6_checkIndexValue)
		{
			myvector<int> v;

			for (int k = 0; k < 5; k++)
				v.push_back(k+1);

			Assert::IsTrue(v.size() == 5);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
			Assert::IsTrue(v[3] == 4);
			Assert::IsTrue(v[4] == 5);
		}


		TEST_METHOD(arashi6_checkFrontIsNULL)
		{
			myvector<int> v(10);
			for (int k = 0; k < 5; k++)
				v.push_back(NULL);
			v.push_back(3);
			v.push_back(23);
			v.push_back(30);
			v.push_back(45);

			Assert::IsFalse(v.capacity() > 10);
			Assert::IsTrue(v.front() == NULL && v[5] != NULL);
		}
		//copy constructor
		TEST_METHOD(arashi6_copyConstructor)
		{
			myvector<int> V(10);
			V.push_back(4);
			V.push_back(3);
			V.push_back(2);
			V.push_back(6);
			V.push_back(10);

			myvector<int> copyV(10);

			for (int i = 0; i < V.size(); i++)
				copyV.push_back(V.front());
			copyV.push_back(V.back());

			Assert::IsTrue(copyV.front() == V.front());
			Assert::IsTrue(copyV.back() == V.back());
		}

		TEST_METHOD(arashi6_CheckingEqualityforFrontBack)
		{
			myvector<int> V(10);
			V.push_back(4);
			V.push_back(3);
			V.push_back(2);
			V.push_back(6);
			V.push_back(4);
			Assert::IsTrue(V.capacity() == 10);
			Assert::AreEqual(V.back(), V.front());
		}

		TEST_METHOD(arashi6_CheckingFrontbackNotEqual)
		{
			myvector<int> V;
			V.push_back(4);
			V.push_back(3);
			V.push_back(2);
			V.push_back(6);
			V.push_back(10);
			Assert::AreNotEqual(V.back(), V.front());
		}


		TEST_METHOD(arashi6_storingValueAtLastIndex) 
    {
			myvector<int>  v(10);
			for (int k = 0; k < 42; k++)
				v.push_back(k);
			v[41] = 80;
			Assert::IsTrue(v.back() == 80);
		}

		//front element first index test
		TEST_METHOD(arashi6_storingValueAtFirstIndex) {
			myvector<int>  v(10);
			for (int k = 0; k < 42; k++)
				v.push_back(k);
			v.operator[](0) = 5 * 3;
			Assert::IsTrue(v.front() == 15);
		}

		TEST_METHOD(arashi6_storingValueAtMiddleIndex) {
			myvector<int>  v(10);
			for (int k = 0; k < 80; k++)
				v.push_back(k);
			v[0] = 4 * 9;
			Assert::IsTrue(v.front() == 36);
		}

		//normal compacity test
		TEST_METHOD(ashelt7_Test01) {
			myvector<int>  V(10);  // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		//dynamic compacity test
		TEST_METHOD(ashelt7_Test02) {
			myvector<int>  V(10);  // nodesize of 10:
			int i;
			for (i = 0; i < 12; i++)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 20);
		}

		//super dynamic compacity test
		TEST_METHOD(ashelt7_Test03) {
			myvector<int>  V(10);  // nodesize of 10:
			int i;
			for (i = 0; i < 100; i++)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 100);
		}


		TEST_METHOD(ashelt7_Test04) {
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue((V[0] == 1));
		}

		//dynamic bracket test
		TEST_METHOD(ashelt7_Test05) {
			myvector<int>  V(10);  // nodesize of 10:
			int i;
			for (i = 0; i < 12; i++)
				V.push_back(i);

			Assert::IsTrue((V[0] == 0));
			Assert::IsTrue((V[11] == 11));
		}

		//testing size dynamically
		TEST_METHOD(ashelt7_Test06) {
			myvector<int>  V(10);  // nodesize of 10:

			int i;
			for (i = 0; i < 12; i++)
				V.push_back(i);
			Assert::IsTrue(V.size() == 12);
		}


		//testing back dynamically
		TEST_METHOD(ashelt7_Test07) {
			myvector<int>  V(10);  // nodesize of 10:

			int i;
			for (i = 0; i < 12; i++)
				V.push_back(i);

			Assert::IsTrue(V.back() == 11);
		}

		//testing pushback dynamically
		TEST_METHOD(ashelt7_Test08) {
			myvector<int>  V(10);  // nodesize of 10:

			int i;
			for (i = 0; i < 12; i++)
				V.push_back(i);


			for (i = 0; i < 12; i++)
				Assert::IsTrue(V[i] == i);
		}

		//testing deep copy of vector
		TEST_METHOD(ashelt7_Test09)
    {
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);

			int i;
      for (i = 0; i < V.size();i++) {
				Assert::IsTrue((V2[i] == V[i]));//make sure they're the save value
				Assert::IsTrue((&V2[i] != &V[i]));//but different addresses
			}
		}

		//testing deep copy of vector
		TEST_METHOD(ashelt7_Test10) 
    {
			myvector<int>  V(10);  // nodesize of 10:

			int i;
			for (i = 0; i < 100; i++)
				V.push_back(i);

			myvector<int> V2(V);

      for (i = 0; i < V.size(); i++) {
				Assert::IsTrue((V2[i] == V[i]));//make sure they're the save value
				Assert::IsTrue((&V2[i] != &V[i]));//but different addresses
			}
		}


		TEST_METHOD(ashirs2_test1)
		{
			myvector<int> V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 10);
		}


		//TEST_METHOD(ashirs2_test2)
		//{
		//	myvector<int> V(11);

		//	for (int i = 0; i < 11; i++) {
		//		V.push_back(i);
		//	}
		//	Assert::IsTrue(V.size() == 11);
		//	Assert::IsTrue(V.capacity() == 11);
		//	V.~myvector();
		//	Assert::IsTrue(V.front() == NULL);



		//}

		//TEST_METHOD(ashirs2_test3)
		//{
		//	myvector<int> V(10);

		//	for (int i = 0; i < 10; i++) {
		//		V.push_back(i);
		//	}

		//	V.~myvector();
		//	Assert::IsTrue(V.front() == NULL);
		//	Assert::IsTrue(V.back() == NULL);
		//}

		TEST_METHOD(ashirs2_test4)
		{
			myvector<int> V(11);

			for (int i = 0; i < 11; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 11);
		}

		TEST_METHOD(ashirs2_test5)
		{
			myvector<int> V(20);

			for (int i = 0; i < 11; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 20);
			Assert::IsTrue(V.size() == 11);
		}

		////odd case deconstrucotr 
		//TEST_METHOD(ashirs2_test6)
		//{
		//	myvector<int> V(15);

		//	for (int i = 0; i < 15; i++) {
		//		V.push_back(i);
		//	}

		//	V.~myvector();
		//	Assert::IsTrue(V.front() == NULL);
		//	Assert::IsTrue(V.back() == NULL);

		//	myvector<int> V2(20);

		//	V.push_back(1);
		//	V.push_back(3);
		//	Assert::IsTrue(V.back() == 3);
		//	Assert::IsTrue(V.size() == 2);

		//}

		//TEST_METHOD(ashirs2_test7)
		//{
		//	myvector<int> V(15);

		//	for (int i = 0; i < 12; i++) {
		//		V.push_back(i);
		//	}

		//	V.push_back(3);
		//	V.~myvector();
		//	Assert::IsTrue(V.front() == NULL);
		//	Assert::IsTrue(V.back() == NULL);
		//};


		TEST_METHOD(ashirs2_test8)
		{
			myvector<int> V(11);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 10);

			V.push_back(12);

			Assert::IsTrue(V.size() == 11);
		}

		TEST_METHOD(ashirs2_test9)
		{
			myvector<int> V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 10);
			Assert::IsTrue(V.operator[](9) == 9);

		}


    TEST_METHOD(ashirs2_test10)
    {
      myvector<int> V(11);

      for (int i = 0; i < 10; i++) {
        V.push_back(i);
      }

      Assert::IsTrue(V.front() == 0);
      V.push_back(41);
      Assert::IsTrue(V.size() == 11);
      Assert::IsTrue(V.back() == 41);


    };



		// First test
		// Simple capacity
		// Pushing through 11 elements in 10-sized nodes should give us two nodes, total size 20.
		TEST_METHOD(askiba3_Test1) {
			myvector<int> V(10);

			for (int i = 0; i < 11; i++)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 20);

		}

		// Second test
		// Other types
		// Does myvector gracefully handle non-int types?
		TEST_METHOD(askiba3_Test2) {
			myvector<string> V(10);

			V.push_back("Hello");
			V.push_back("my");
			V.push_back("name");
			V.push_back("is");
			V.push_back("Slim");
			V.push_back("Shady");

			Assert::IsTrue(V.front() == "Hello");
			Assert::IsTrue(V.back() == "Shady");

			myvector<double> V2(10);
			V2.push_back(12.34);
			V2.push_back(13.37);

			Assert::IsTrue(V2.front() == 12.34);
			Assert::IsTrue(V2.back() == 13.37);

		}

		// Third test
		// Size limitations
		// How does myvector handle increasingly larger sizes? Does it crash? Could signal memory issues that haven't been addressed.
		TEST_METHOD(askiba3_Test3) {

			myvector<int>  V(1);

			for (int i = 0; i < 1000; i++)
				V.push_back(i);

			Assert::IsTrue(V.size() == 1000);
			Assert::IsTrue(V.capacity() == 1000);

			myvector<int>  V2(1);

			for (int i = 0; i < 1000000; i++)
				V2.push_back(i);

			Assert::IsTrue(V2.size() == 1000000);
			Assert::IsTrue(V2.capacity() == 1000000);
		}

		// Fourth test: Do iterators work and actually access the values we want?
		TEST_METHOD(askiba3_Test4) {
		}

		// Fifth test
		// Simple range based for
		// Does it work at all? Only tests one node node. If Test 8 fails and this does not, there is a push_back problem.
		// So, this isn't redundant-- it checks that at least one node works ;)
		TEST_METHOD(askiba3_Test5) {

			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			for (auto e : V)
				Assert::IsTrue(V[e-1] == e);
		}


		// Sixth test
		// Begin and end test
		// Do begin and end return the actual first and last iterators, and do they return the correct values if so?
		TEST_METHOD(askiba3_Test6) {

			myvector<int>  V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			auto i1 = V.begin();
			auto i2 = V.end();

			Assert::AreEqual(*i1, 1);
      Assert::IsTrue(i1 != i2);
      //
      // cannot access last element:
      //
			//Assert::AreEqual(*i2, 3);
		}

		// Seventh test
		// Simple copy constructor (shallow copy test)
		// Does a copied myvector match the basic, shallow properties of the original?
		TEST_METHOD(askiba3_Test7) {

			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2 = V; // Copy.

			Assert::AreEqual(V.capacity(), V2.capacity());
			Assert::AreEqual(V.size(), V2.size());
			Assert::AreEqual(V.front(), V2.front());
			Assert::AreEqual(V.back(), V2.back());

		}

		// Eighth test
		// Complex copy constructor (deep copy test)
		// Does a copied myvector have every single element in the correct position?
		TEST_METHOD(askiba3_Test8) {

			myvector<int> V(10);

			// Push 11 elements so that there are at least two nodes. This way we can see if the iterator properly goes to the next node.
			for (int i = 0; i < 11; i++)
				V.push_back(i);

			myvector<int> V2 = V; // Copy.

      // Go over every single element and make sure it matches.
			for (auto e : V)
				Assert::IsTrue(V[e] == V2[e]);
		}

		// Ninth test
		// Simple iterator
		// Does it actually access the value it's supposed to? Not off by one in either direction?
		TEST_METHOD(askiba3_Test9) {

			myvector<int> V(10);

			// Push 11 elements to ensure at least two nodes, to see if we go to next node properly.
			for (int i = 0; i < 11; i++)
				V.push_back(i);

			// Go through every element (they should be 0...10) and make sure all values are in the right place.
			for (auto e : V)
				Assert::IsTrue(V[e] == e);

		}


		// Tests the front() function to return the first value pushed into vector
		TEST_METHOD(asubei2_Test_front) {

			myvector<int>  V(10);
			int x = rand();

			V.push_back(x);
			V.push_back(1);
			V.push_back(2);

			Assert::AreEqual(V.front(), x);

		}

		// Tests the back() function to return the last value pushed into vector
		TEST_METHOD(asubei2_Test_back) {

			myvector<int>  V(10);

			for (int i = 0; i < 10; i++)
			{
				int x = rand();

				V.push_back(x);
				Assert::AreEqual(V.back(), x);
			}

		}

		// Tests push_back() function to push an element at the tail
		TEST_METHOD(asubei2_Test_push_back) {

			myvector<int>  V(10);

			for (int i = 0; i < 1000; i++)
			{
				V.push_back(i);
				Assert::AreEqual(V.back(), i);
			}
		}

		// Tests the [] operator to index through the vector
		TEST_METHOD(asubei2_Test_Indexing_Operator) {

			myvector<int>  V(10);
			for (int i = 0; i < 1000; i++)
			{
				V.push_back(i);
				Assert::AreEqual(V[i], i);
			}
		}

		// Tests size() function to return the number of elements in the vector
		TEST_METHOD(asubei2_Test_size) {

			myvector<int>  V(10);
			int count = 0;
			for (int i = 0; i < 1000; i++)
			{
				V.push_back(i);
				count++;
			}

			Assert::AreEqual(int(V.size()), count);
		}

		// Tests begin() iterator to point to the beginning of the vector
		TEST_METHOD(asubei2_Test_begin_Iter) {

			myvector<int>  V(10);
			for (int i = 0; i < 1000; i++)
				V.push_back(i);

			Assert::AreEqual(*V.begin(), 0);
		}

		// Tests end() iterator to point to the end of the vector
		//TEST_METHOD(asubei2_Test_end_Iter) {

		//	myvector<int>  V(10);
		//	for (int i = 0; i < 1000; i++)
		//		V.push_back(i);

		//	Assert::AreEqual(*(V.end() - 1), V.back());
		//}

		// Tests the copy constructor 
		TEST_METHOD(asubei2_Test_copy_constructor) {

			myvector<int>  V(10);
			for (int i = 0; i < 1000; i++)
				V.push_back(i);

			myvector<int>  V2(V);
			for (int i = 0; i < 999; i++)
				Assert::AreEqual(V[i], V2[i]);
		}

		// Tests whether the copy constructor is a deep copy or not
		TEST_METHOD(asubei2_Test_deep_copy) {

			myvector<int>  V(10);
			for (int i = 0; i < 1000; i++)
				V.push_back(i);


			myvector<int>  V2(V);

			for (int i = 0; i < 1000; i++)
				V[i] = i + 5;

			for (int i = 0; i < 1000; i++)
				Assert::AreNotEqual(V[i], V2[i]);
		}




		TEST_METHOD(atank2_Test1_CheckSize)
		{
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			for (int i = 1; i < 16; i++)
				v.push_back(2);

			Assert::IsTrue(v.size() == 15);
		}

		TEST_METHOD(atank2_Test2_Capacity)
		{
			myvector<int> v(10);
			for (int i = 1; i < 26; i++)
				v.push_back(2);

			Assert::IsTrue(v.capacity() == 30);
		}

		TEST_METHOD(atank2_Test3_SizeAndCapacity)
		{
			myvector<int> v(10);
			for (int i = 1; i < 36; i++)
				v.push_back(2);

			Assert::IsTrue(v.capacity() == 40);
			Assert::IsTrue(v.size() == 35);
		}

		TEST_METHOD(atank2_Test4_CheckFront)
		{
			myvector<int> v(10);
			v.push_back(19);
			v.push_back(23);
			v.push_back(32);
			Assert::IsTrue(v.front() == 19);
		}

		TEST_METHOD(atank2_Test5_CheckBack)
		{
			myvector<int> v(10);
			v.push_back(19);
			v.push_back(23);
			v.push_back(32);
			Assert::IsTrue(v.back() == 32);
		}

		TEST_METHOD(atank2_Test6_CompareFrontAndBack)
		{
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			v.push_back(19);
			v.push_back(23);
			v.push_back(32);
			Assert::IsTrue(v.back() > v.front());
		}

		TEST_METHOD(atank2_Test7_AreEqual)
		{
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			v.push_back(32);
			v.push_back(23);
			v.push_back(32);
			Assert::AreEqual(v.back(), v.front());
		}

		TEST_METHOD(atank2_Test8_AreSame)
		{
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			v.push_back(32);
			Assert::AreSame(v.back(), v.back());
		}

		TEST_METHOD(atank2_Test9_CheckCopyVector)
		{
			myvector<int> v(10);
			myvector<int> v2(10);
			v.push_back(32);
			v.push_back(4);
			v.push_back(2);
			v.push_back(87);
			v.push_back(23);
			for (int i = 0; i < v.size(); i++)
			{
				v2.push_back(v.front());
				v2.push_back(v.back());
			}
			Assert::AreEqual(v2.front(), v.front());
			Assert::AreEqual(v2.back(), v.back());

		}

		TEST_METHOD(atank2_Test10_AreNotEqual)
		{
			myvector<int> v(10);
			for (int i = 0; i < v.capacity(); i++)
				v.push_back(i);

			Assert::AreNotEqual(v.front(), v.back());
		}

		TEST_METHOD(atank2_Test11_OperatorCheckMid)
		{
			myvector<int> v(10);
			for (int i = 1; i < 36; i++)
				v.push_back(6);

			v.operator[](22) = 6 * 9;
			Assert::IsTrue(v.operator[](22) == 6 * 9);
		}

		TEST_METHOD(atank2_Test12_OpertaorCheckStart)
		{
			myvector<int> v(10);
			for (int i = 1; i < 76; i++)
				v.push_back(6);

			v.operator[](2) = 6 * 9;
			Assert::IsTrue(v.operator[](2) == 6 * 9);
		}

		TEST_METHOD(atank2_Test13_OperatorCheckEnd)
		{
			myvector<int> v(10);
			for (int i = 0; i < 16; i++)
				v.push_back(6);

			v[15] = 6 * 9;
			Assert::IsTrue(v[15] == 6 * 9);
		}



		TEST_METHOD(bcao6_Test1)
		{
			myvector<int> V(10);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(bcao6_Test2)
		{
			myvector<int> V(10);

			for (auto i = 0; i <= 10; i++)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 20);
		}



		TEST_METHOD(bcao6_Test4)
		{
			myvector<int> V(10);

			for (auto i = 0; i <= 10; i++)
				V.push_back(i);

			Assert::IsTrue(V[0] == 0);
		}

		TEST_METHOD(bcao6_Test5)
		{
			myvector<int> V(10);

			for (auto i = 0; i <= 10; i++)
				V.push_back(i);

			Assert::IsTrue(V[10] == 10);
		}

		TEST_METHOD(bcao6_Test6)
		{
			myvector<int> V1(10);

			for (auto i = 0; i <= 10; i++)
				V1.push_back(i);

			auto V2(V1);

			for (auto i = 0; i <= 10; i++)
				Assert::IsTrue(V2[i] == i);
		}

		TEST_METHOD(bcao6_Test7)
		{
			myvector<int> V(10);

			for (auto i = 0; i <= 10; i++)
				V.push_back(i);

			auto iter = V.begin();
			Assert::IsTrue(*iter == 0);
		}

		TEST_METHOD(bcao6_Test8)
		{
			myvector<int> V(10);

			for (auto i = 0; i <= 10; i++)
				V.push_back(i);

			auto iter = V.begin();
      ++iter;
			Assert::IsTrue(*iter == 1);
		}

		//TEST_METHOD(bcao6_Test9)
		//{
		//	myvector<int> V(10);

		//	for (auto i = 0; i <= 10; i++)
		//		V.push_back(i);

		//	auto iter = V.end();
    //
    // cannot access end:
    //
		//	Assert::IsTrue(*iter = 10);
		//}

		//TEST_METHOD(bcao6_Test10)
		//{
		//	myvector<int> V(10);

		//	for (auto i = 0; i <= 11; i++)
		//		V.push_back(i);

		//	auto iter = V.end();
    //
    // cannot access end:
    //
		//	Assert::IsTrue(*iter = 11);
		//}


		TEST_METHOD(bgoodm3_Test1)
		{
			myvector<int> V(10);

			for (int i = 0; i < 25; i++)  //insert 25 elements
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 30);  //vector capacity should = 30 for 25 elements inserted
		}

		TEST_METHOD(bgoodm3_Test2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.operator[](1) == 2);  //vector capacity should = 10 for 5 elements
		}

		//TEST_METHOD(bgoodm3_Test3)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.~myvector();

		//	Assert::IsFalse(V.front() == 1);
		//}

		TEST_METHOD(bgoodm3_Test4)
		{
			myvector<int> V(30);

			for (int i = 0; i < 25; i++)
				V.push_back(i);


			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 24);
		}


		TEST_METHOD(bkim95_test_capacity1)
		{
			myvector<int> V(10);
			Assert::IsTrue(V.capacity() == 10);
		}
		TEST_METHOD(bkim95_test_capacity2)
		{
			myvector<int> V(10);
			for (int i = 0; i < 12; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 20);
		}
		TEST_METHOD(bkim95_test_frontandback)
		{
			myvector<int> V(10);
			for (int i = 0; i < 15; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 14);
		}
		TEST_METHOD(bkim95_test_size)
		{
			myvector<int> V(10);
			for (int i = 0; i < 15; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 15);
		}
		TEST_METHOD(bkim95_test_copyconstructor)
		{
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2 = V;
			Assert::IsTrue(V2.front() == 1);
			Assert::IsTrue(V2.back() == 3);
		}
		TEST_METHOD(bkim95_test_copyconstructor2)
		{
			myvector<int> V(10);
			for (int i = 0; i < 15; i++)
			{
				V.push_back(i);
			}
			myvector<int> V2 = V;
			Assert::IsTrue(V2.size() == 15);
			Assert::IsTrue(V2.capacity() == 20);

			Assert::IsTrue(V2.front() == 0);
			Assert::IsTrue(V2.back() == 14);
		}
		//TEST_METHOD(bkim95_test_operator)
		//{
		//	myvector<int> V(10);
		//	V.operator[](5) = 999;
		//	Assert::IsTrue(V.operator[](5) == 999);
		//}

		TEST_METHOD(bkim95_test_operator2)
		{
			myvector<int> V(10);
			for (int i = 0; i < 15; i++)
			{
				V.push_back(i);
			}

			Assert::IsTrue(V.operator[](5) == 5);
		}

		TEST_METHOD(bkim95_compiled_tests1)
		{
			myvector<int> V(10);
			for (int i = 0; i < 15; i++)
			{
				V.push_back(i * 5);
			}
			Assert::IsTrue(V.size() == 15);
			Assert::IsTrue(V.capacity() == 20);

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.operator[](8) == 40);
			Assert::IsTrue(V.back() == 70);
		}

		TEST_METHOD(bkim95_compiled_tests2)
		{
			myvector<int> V(20);
			for (int i = 0; i < 15; i++)
			{
				V.push_back(i * 5);
			}

			myvector<int> V2 = V;

			Assert::IsTrue(V.size() == 15);
			Assert::IsTrue(V.capacity() == 20);

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.operator[](8) == 40);
			Assert::IsTrue(V.back() == 70);

			Assert::IsTrue(V2.size() == 15);
			Assert::IsTrue(V2.capacity() == 20);

			Assert::IsTrue(V2.front() == 0);
			Assert::IsTrue(V2.operator[](13) == 65);
			Assert::IsTrue(V2.back() == 70);
		}




		// test for a vector of 10, if front and back are true
		TEST_METHOD(bkupie2_Test1)
		{

			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.size() == 0); // quick size test
			for (int i = 0; i < 10; i++)
				V.push_back(i + 1);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 10);
		}
		// test is vector can create a new node, and update capacity
		TEST_METHOD(bkupie2_Test2)
		{
			myvector<int> V(5); // nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 10; i++)
				V.push_back(i);
			// after pushing 10 values onto the vector,
			// the capacity and size should be updated
			Assert::IsTrue(V.capacity() == 10);
			Assert::IsTrue(V.size() == 10);
			V.push_back(20);
			// after we push another value, the capacitys should increase by vector size
			// while size should increase only by one 
			Assert::IsTrue(V.capacity() == 15);
			Assert::IsTrue(V.size() == 11);


		}

		TEST_METHOD(bkupie2_Test3)
		{
			// check if head is start when we only have 1 value
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.front() == V.back());
			Assert::IsTrue(V.front() == 1 && V.back() == 1);

		}

		TEST_METHOD(bkupie2_Test4)
		{
			myvector<int> V1(1);
			myvector<int> V2(1);
			V1.push_back(23);
			V1.push_back(2); // v1[1] = 2;
			V2.push_back(8);
			V2.push_back(2); // v2[1] = 2;
			Assert::AreEqual(V1[1], V2[1]);
		}
		TEST_METHOD(bkupie2_Test5)
		{
			//Compare our vector class, with a regular vector class
			myvector<int> V1(1);
			vector<int> V2;
			Assert::IsTrue(V1.size() == V2.size());
			//push back the same value
			V1.push_back(3);
			V2.push_back(3);
			Assert::AreEqual(V1[0], V2[0]);

		}

		TEST_METHOD(bkupie2_Test6)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			// check if the copy operator works 
			myvector<int> V2 = V;
			// check if the values are equal 
			Assert::IsTrue(V2[0] == 1);
			Assert::IsTrue(V2[2] == 3);
		}

		TEST_METHOD(bkupie2_Test7)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			// check copy again, but diffrent criteria
			myvector<int> V2 = V;
			Assert::IsTrue(V2.front() == V2[0]);
			Assert::IsTrue(V2.back() == V2[2]);
			// now check a false case 
			Assert::IsFalse(V.front() == V2.back());
		}

		TEST_METHOD(bkupie2_Test8)
		{
			// check if capacity is corrent
			myvector<int> V(10);
			Assert::IsTrue(V.capacity() == 10);

		}

		TEST_METHOD(bkupie2_Test9)
		{
			// check if capacity is correct with a regular class vector
			myvector<int> V1(10);
			vector<int> V2(10);
			// both vectors are initialized to 10
			Assert::IsTrue(V1.capacity() == 10);
			Assert::IsTrue(V2.capacity() == 10);
			// check if both are 10, and then if they are the same as well
			Assert::IsTrue(V2.capacity() == V1.capacity());
		}

		TEST_METHOD(bkupie2_Test10)
		{
			// check if overwritting values works
			myvector<int> V(10);

			for (int i = 0; i < 10; i++)
				V.push_back(i);
			// after pushing 10 values onto the vector,
			V[0] = 20;
			V[V.size() - 1] = 20;
			// sinze we changed the first value and the last value,
			// they should now be equal
			Assert::IsTrue(V.front() == V.back());


		}

		//


		// Test that the default constructor gives an empty vector.
		TEST_METHOD(bsubei2_Constructor_Test) {
			myvector<int>  v{}; // should have nodesize = 100 by default
								// Test that it's still empty.
			Assert::AreEqual(0, (int)v.size());

			// Test the default capacity (100 for now), only for myvector.
			Assert::AreEqual(100, (int)v.capacity());
		}

		// Test that the copy constructor results in a deep copy.
		TEST_METHOD(bsubei2_Constructor_Deep_Copy_Test) {
			myvector<int>  v{ 10 };
			myvector<int> copy{ v };
			copy.push_back(1);
			Assert::AreEqual(0, (int)v.size());
			Assert::AreEqual(1, (int)copy.size());
			v.push_back(777);
			Assert::AreEqual(1, copy[0]);
			Assert::AreEqual(777, v[0]);
		}

	 // // Test that the copy constructor gives a copy of the vector.
		//TEST_METHOD(bsubei2_Constructor_Copy_Test) {
		//	myvector<int>  v{ 10 };
		//	v.push_back(1);
		//	v.push_back(2);
		//	v.push_back(3);
		//	// Sanity check, test initial size.
		//	Assert::AreEqual(3, (int)v.size());
		//	// Now copy it and check that the elements are the same.
		//	//myvector<int> copy{ v };
		//	myvector<int> copy{ v };
		//	Assert::IsTrue(std::equal(v.begin(), v.end(), copy.begin()));
		//}

		// Same as copy constructor test but with randomized size and elements.
		//TEST_METHOD(bsubei2_Constructor_Copy_Randomized_Test) {
		//	// start the random seed with the same value always to make the test deterministic.
		//	std::srand(NULL);
		//	// limit the random numbers to 10000 for performance reasons.
		//	int count = std::rand() % 10000;
		//	int cap = std::rand() % 10000;
		//	myvector<int>  v{ cap };
		//	for (int i = 0; i < count; i++) {
		//		v.push_back(std::rand());
		//	}
		//	// Sanity check, test initial size.
		//	Assert::AreEqual(count, (int)v.size());
		//	// Now copy it and check that the elements are the same.
		//	myvector<int> copy{ v };
		//	// Check that each element is equal.
		//	// Only needs iterators to be implemented.
		//	Assert::IsTrue(std::equal(v.begin(), v.end(), copy.begin()));
		//}

		// Test that size() returns correct value as we add and remove elements.
		TEST_METHOD(bsubei2_Size_Test)
		{
			// Create a vector
			myvector<int>  v{ 10 };
			// Test that the size is correct as we add elements.
			for (int i = 0; i < 1000; i++) {
				Assert::AreEqual(i, (int)v.size());
				v.push_back(i * 2);
				Assert::AreEqual(i + 1, (int)v.size());
			}
			//// Test the size as we remove elements, too.
			//for (int i = 0; i < 1000; i++) {
			//	Assert::AreEqual(1000 - i, (int)v.size());
			//	v.pop_back();
			//	Assert::AreEqual(1000 - i - 1, (int)v.size());
			//}
		}

		// Test indexing elements as we add them to the vector.
		TEST_METHOD(bsubei2_Indexing_Valid_Test)
		{
			// Create a vector
			myvector<int>  v{ 10 };
			v.push_back(1);
			Assert::AreEqual(1, v[0]);
			v.push_back(2);
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			v.push_back(3);
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
		}


		// Test that the front() doesn't change as we push_back elements.
		TEST_METHOD(bsubei2_Front_Test)
		{
			// Create a vector
			myvector<int>  v{ 10 };
			v.push_back(1);
			Assert::AreEqual(1, v.front());
			v.push_back(2);
			Assert::AreEqual(1, v.front());
			v.push_back(3);
			Assert::AreEqual(1, v.front());
		}

		// Test that back() shows the last element as we push_back more.
		TEST_METHOD(bsubei2_Back_Test)
		{
			// Create a vector
			myvector<int>  v{ 10 };
			v.push_back(1);
			Assert::AreEqual(v[0], v.back());
			v.push_back(2);
			Assert::AreEqual(v[1], v.back());
			v.push_back(3);
			Assert::AreEqual(v[2], v.back());
			// pop_back() not implemented in myvector
			//// Now, start deleting elements and check that back() still works.
			//v.pop_back();
			//Assert::AreEqual(v[1], v.back());
			//v.pop_back();
			//Assert::AreEqual(v[0], v.back());
			//// After popping it all, we should have invalid stuff.
			//v.pop_back();
			//Assert::AreNotEqual(1, v.back());
		}

		// Keep running push_back and check that it's correct every time.
		TEST_METHOD(bsubei2_PushBack_Test)
		{
			// start the random seed with the same value always to make the test deterministic.
			std::srand(NULL);
			// Create a vector
			myvector<int>  v{ 10 };
			int count = std::rand() % 10000;
			for (int i = 0; i < count; i++) {
				int random = std::rand() % 10000;
				v.push_back(random);
				Assert::AreEqual(random, v[i]);
			}
		}

		// Keep running push_back and check that it's correct every time.
		// This should take 5-10 seconds.
    //
    // changed to not take so long...
    //
		TEST_METHOD(bsubei2_Pushback_Ginormous_Test)
		{
			// start the random seed with the same value always to make the test deterministic.
			std::srand(NULL);
			// Create a vector
			myvector<int>  v{ 10 };
			constexpr int count = 10000;
			for (int i = 0; i < count; i++) {
				int random = std::rand() % 10000;
				v.push_back(random);
				Assert::AreEqual(random, v[i]);
			}
		}

		// This test won't work for myvector since it doesn't implement .empty()
		// Test whether empty() function works.
		//TEST_METHOD(bsubei2_Empty_Test) {
		//	// Create an empty vector
		//	myvector<int>  v;
		//	// Check that it's empty().
		//	Assert::IsTrue(v.empty());
		//	// Should not be empty anymore if we add an element.
		//	v.push_back(777);
		//	Assert::IsFalse(v.empty());
		//	// pop_back() not implemented in myvector
		//	// Now see if we can make it empty again.
		//	v.pop_back();
		//	Assert::IsTrue(v.empty());
		//}

		// check the capacity before capacity increase 
		TEST_METHOD(crodri63_test1BeforeCapFill) {
			myvector<int> v(10);
			Assert::IsTrue(v.capacity() == 10);
		}
		// check the front value  at capacity filled
		TEST_METHOD(crodri63_test2AtCapFill) {
			myvector<int> v(10);
			v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5);
			v.push_back(6); v.push_back(7); v.push_back(8); v.push_back(9); v.push_back(10);
			Assert::IsTrue(v.front() == 1);
		}
		// check the back value at capacity filled
		TEST_METHOD(crodri63_test3AtCapFill) {
			myvector<int> v(10);
			v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5);
			v.push_back(6); v.push_back(7); v.push_back(8); v.push_back(9); v.push_back(10);
			Assert::IsTrue(v.back() == 10);
		}
		// check the total element at the capacity filled
		TEST_METHOD(crodri63_test4AtCapFill) {
			myvector<int> v(10);
			v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5);
			v.push_back(6); v.push_back(7); v.push_back(8); v.push_back(9); v.push_back(10);
			Assert::IsTrue(v.size() == 10);
		}
		// check the capacity amount at the capacity filled
		TEST_METHOD(crodri63_test5AtCapFill) {
			myvector<int> v(10);
			v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5);
			v.push_back(6); v.push_back(7); v.push_back(8); v.push_back(9); v.push_back(10);
			Assert::IsTrue(v.capacity() == 10);
		}
		//check the size of capacity after the capacity increased
		TEST_METHOD(crodri63_test6AfterCap) {
			myvector<int> v(10);
			Assert::IsTrue(v.capacity() == 10);
			v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5);
			v.push_back(6); v.push_back(7); v.push_back(8); v.push_back(9); v.push_back(10);
			v.push_back(11);
			Assert::IsTrue(v.capacity() == 20);
		}
		// check the front value after capacity increase
		TEST_METHOD(crodri63_test7AfterCap) {
			myvector<int> v(10);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			v.push_back(5);
			v.push_back(6);
			v.push_back(7);
			v.push_back(8);
			v.push_back(9);
			v.push_back(10);
			v.push_back(11);
			Assert::IsTrue(v.front() == 1);

		}
		// check the back value after capacity increase
		TEST_METHOD(crodri63_test8AfterCap) {
			myvector<int> v(10);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			v.push_back(5);
			v.push_back(6);
			v.push_back(7);
			v.push_back(8);
			v.push_back(9);
			v.push_back(10);
			v.push_back(11);

			Assert::IsTrue(v.back() == 11);
		}
		// check the size value after capacity increase
		TEST_METHOD(crodri63_test9AfterCap) {
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			v.push_back(5);
			Assert::IsTrue(v.size() == 5);
			v.push_back(6);
			v.push_back(7);
			v.push_back(8);
			v.push_back(9);
			v.push_back(10);
			Assert::IsTrue(v.size() == 10);
			v.push_back(11);
			Assert::IsTrue(v.size() == 11);
		}

		// check the capacity value after capacity increase
		TEST_METHOD(crodri63_test10AfterCap) {
			myvector<int> v(10);
			Assert::IsTrue(v.capacity() == 10);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			v.push_back(5);
			Assert::IsTrue(v.capacity() == 10);
			v.push_back(6);
			v.push_back(7);
			v.push_back(8);
			v.push_back(9);
			v.push_back(10);
			Assert::IsTrue(v.capacity() == 10);
			v.push_back(11);
			Assert::IsTrue(v.capacity() == 20);
		}



		//testing if the operator[] works under normal capacity
		TEST_METHOD(dazhar2_Test1)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
		}

		//testing if the capacity is 10 when it's initially set to 10
		TEST_METHOD(dazhar2_Test2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		//testing if the capacity, if not initialized by the user, is 100
		TEST_METHOD(dazhar2_Test3)
		{
			myvector<int> V;
			Assert::IsTrue(V.capacity() == 100);
		}

		//testing if, after increasing the capacity, that more space is allocated
		//and can be accessed
		TEST_METHOD(dazhar2_Test4)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}

		//testing if the increased capacity is the expected size
		TEST_METHOD(dazhar2_Test5)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 4);
		}

		//testing if, after increasing capacity, that the size is still correct
		TEST_METHOD(dazhar2_Test6)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		//testing if, after exceeding initial capacity,
		//that operator still accesses values properly and correctly
		TEST_METHOD(dazhar2_Test7)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
			Assert::IsTrue(V[3] == 4);
		}

		//testing if myvector can access the beginning element as an iterator
		TEST_METHOD(dazhar2_Test8)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(*V.begin() == 1);
		}

		//testing if myvector can access the last element as an itetor
		//TEST_METHOD(dazhar2_Test9)
		//{
		//	myvector<int> V(2);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(*(V.end() - 1) == 3);
		//}

		//testing if, when myvector is empty, that its "begin" and "end" point to the same place
		TEST_METHOD(dazhar2_Test10)
		{
			myvector<int> V(2);
			Assert::IsFalse(V.begin() != V.end());
		}

		//testing if myvector works for another type
		TEST_METHOD(dazhar2_Test11)
		{
			myvector<string> V(2);

			V.push_back("Hello");
			V.push_back("Potato");

			Assert::IsTrue(V.front() == "Hello");
			Assert::IsTrue(V.back() == "Potato");
		}

		TEST_METHOD(ddo5_Test1) {
			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.capacity() == 7);
		}

		TEST_METHOD(ddo5_Test2) {
			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			Assert::IsFalse(V.capacity() == 6);
		}

		TEST_METHOD(ddo5_Test3) {
			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(ddo5_Test4) {
			myvector<int> V(10); // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.front() == 3);
		}

		TEST_METHOD(ddo5_Test5) {
			myvector<int> V(10); // nodesize of 10:
			V.push_back(3);
			V.push_back(2);
			V.push_back(1);
			Assert::IsFalse(V.front() == 1);
		}

		TEST_METHOD(ddo5_Test6) {
			myvector<int> V(10); // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
		}

		TEST_METHOD(ddo5_Test7) {
			myvector<int> V(10); // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.back() == 1);
		}

		TEST_METHOD(ddo5_Test8) {
			myvector<int> V(10); // nodesize of 10:
			V.push_back(3);
			V.push_back(2);
			V.push_back(1);
			Assert::IsFalse(V.back() == 3);
		}

		TEST_METHOD(ddo5_Test9) {
			myvector<int> V(10); // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(ddo5_Test10) {
			myvector<int>  V(10);  // nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			Assert::IsTrue(V.size() == 8);
		}



		TEST_METHOD(PushBackMethodTest)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(SizeMethodTest)
		{

			myvector<int> V(10); // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(CapacityMethodTest)
		{
			myvector<int> V(10); // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(FrontMethodTest)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
		}

		TEST_METHOD(BackMethodTest)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(IndicesOperatorTest)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[2] == 3);
			Assert::IsTrue(V[4] == 5);
		}

		
		TEST_METHOD(ResizeTest)
		{
		myvector<int> V(3); // nodesize of 3:

		V.push_back(1);
		V.push_back(2);
		V.push_back(3);
		V.push_back(4);

		Assert::IsTrue(V[0] == 1);
		Assert::IsTrue(V[3] == 4);
		}
		
		
		TEST_METHOD(CopyConstructorTest)
		{
		myvector<int> V(10);

		V.push_back(1);
		V.push_back(2);
		V.push_back(3);

		myvector<int> V2 = V;

		Assert::IsTrue(V[0] == 1);
		Assert::IsTrue(V[1] == 2);
		Assert::IsTrue(V[2] == 3);

		Assert::IsTrue(V.size() == 3);

    Assert::IsTrue(V2[0] == 1);
    Assert::IsTrue(V2[1] == 2);
    Assert::IsTrue(V2[2] == 3);

    Assert::IsTrue(V2.size() == 3);
    }

 
    TEST_METHOD(BeginIteratorTest)
    {
      myvector<int> V(10); // nodesize of 10:

      V.push_back(1);
      V.push_back(2);
      V.push_back(3);

      auto iter = V.begin();

      Assert::IsTrue(*iter == 1);
    }

		TEST_METHOD(dgonza47_Test1)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 5);
		}

		TEST_METHOD(dgonza47_Test2)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.front() == 1);
			Assert::IsFalse(V.back() == 4);
		}

		TEST_METHOD(dgonza47_Test3)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsFalse(V.front() == 2);
			Assert::IsFalse(V.back() == 4);
		}

		TEST_METHOD(dgonza47_Test4)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 11);
		}

		TEST_METHOD(dgonza47_Test5)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsTrue(V.capacity() == 20);
		}

		TEST_METHOD(dgonza47_Test6)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);

			Assert::IsTrue(V.size() == 1);

			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.size() == 4);
		}

		TEST_METHOD(dgonza47_Test7)
		{
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsFalse(V.size() == 1);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.size() == 4);
		}

		TEST_METHOD(dgonza47_Test8)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);

			Assert::IsTrue(V.size() == 1);

			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsFalse(V.size() == 3);
		}

		TEST_METHOD(dgonza47_Test9)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsFalse(V.capacity() == 21);
		}

		TEST_METHOD(dgonza47_Test10)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			Assert::IsFalse(V.back() == 8);
		}


		//TEST_METHOD(dkay5_Test1)//test construct no nodesize
		//{
		//	myvector<int> V(); // No nodesize:

		//		Assert::IsTrue(V.Getnodesize() == 100);
		//}

		//TEST_METHOD(dkay5_Test2)//test pushing char
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//		char tmp = 'a';

		//	Assert::IsFalse(V.push_back(tmp));
		//}

		//TEST_METHOD(dkay5_Test3)//test pushing double
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//		double tmp = 4.4;

		//	Assert::IsFalse(V.push_back(tmp));
		//}


		TEST_METHOD(dkay5_Test4)//test automatic new node
		{
			myvector<int> V(3); // nodesize of 3:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.size() == 4);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 4);
		}

		TEST_METHOD(dkay5_Test5)//test copy constructor
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V); // copy of V

			Assert::IsTrue(V2.size() == 3);
			Assert::IsTrue(V2.front() == 1);
			Assert::IsTrue(V2.back() == 3);
		}

		//TEST_METHOD(dkay5_Test6)//test -1 nodesize
		//{
		//	myvector<int> V(-1);
		//	Assert::IsTrue(V.GetNodesize() == 100);
		//}

		//TEST_METHOD(dkay5_Test7)//test 0 nodesize
		//{
		//	myvector<int> V(0);
		//	Assert::IsTrue(V.GetNodesize() == 100);
		//}

		//TEST_METHOD(dkay5_Test8)//test operator[]
		//{
		//	myvector<int> V(10); // nodesize of 10:

		//	V.push_back(0);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(V[0].GetElem() == 0);
		//	Assert::IsTrue(V[1].GetElem() == 1);
		//	Assert::IsTrue(V[2].GetElem() == 2);
		//	Assert::IsTrue(V[3].GetElem() == 3);
		//}

		//TEST_METHOD(dkay5_Test9)//test -1 operator[]
		//{
		//	myvector<int> V(10); // nodesize of 10:

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsFalse(V[-1].GetElem());
		//}

		//TEST_METHOD(dkay5_Test10)//test cross node operator[]
		//{
		//	myvector<int> V(3); // nodesize of 3:

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);

		//	Assert::IsTrue(V[1].GetElem() == 1);
		//	Assert::IsTrue(V[2].GetElem() == 2);
		//	Assert::IsTrue(V[3].GetElem() == 3);
		//	Assert::IsTrue(V[4].GetElem() == 4);
		//}




		TEST_METHOD(dkloza2_Test1)
		{
			// TODO: Your test code here
			myvector<int> V(10);


			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		//TEST_METHOD(dkloza2_Test2)
		//{
		//	//Make sure you can't push a different data type into vector
		//	myvector<int> V(10);

		//	V.push_back('a');

		//	Assert::IsTrue(V.front() != 'a');

		//}

		TEST_METHOD(dkloza2_Test3)
		{
			//Test the size of vector, you shouldn't be able to push
			//more than the size of the vector
			myvector<int> V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			V.push_back(4);
			Assert::IsTrue(V.back() == 4);
		}

		TEST_METHOD(dkloza2_Test3v2)
		{
			//make sure iterator incrementer works
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);

			auto i = V.begin();
      ++i;

			Assert::IsTrue(*i == 2);
		}

		//TEST_METHOD(dkloza2_Test4)
		//{
		//	//If my vector is destructed, make sure its actually destructed
		//	myvector<int> V(2);

		//	V.push_back(1);
		//	V.push_back(2);

		//	delete V;

		//	Assert::IsFalse(V.begin() == 1);
		//	Assert::IsFalse(V.back() == 2);
		//}

		TEST_METHOD(dkloza2_Test5)
		{
			//Test if vector actually expands, 
			myvector<int> V(2);
			V.push_back(1);
			V.push_back(2);

			//Enter code to grow myvector here

			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}

		//TEST_METHOD(dkloza2_Test6)
		//{
		//	//Have one vector, delete it and then make a new vector w/ diff data type
		//	myvector<int> V(2);
		//	V.push_back(1);
		//	V.push_back(2);
		//	delete V;

		//	myvector<float> V(2);
		//	V.push_back(1.1);
		//	V.push_back(2.2);

		//	Assert::IsTrue(V.front() == 1.1);
		//	Assert::IsTrue(V.back() == 2.2);
		//}

		TEST_METHOD(dkloza2_Test7)
		{
			//Make sure the iterators work how they are supposed to
			myvector<int> V(5);
			for (int i = 0; i < 5; i++)
				V.push_back(i);

			auto iter = V.begin();
      ++iter;
      ++iter;
      ++iter;

			Assert::IsTrue(*iter == 3);
		}

		//TEST_METHOD(dkloza2_Test8)
		//{
		//	//test .empty()
		//	myvector<int> V(2);

		//	Assert::IsTrue(V.empty());

		//	V.push_back(1);

		//	Assert::IsFalse(V.empty());
		//	Assert::IsTrue(V.size() == 0);
		//}

		TEST_METHOD(dkloza2_TEST9)
		{
			//make sure [] operator works
			myvector<int> V(2);

			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V[0] == 3);
			Assert::IsTrue(V[1] == 4);
		}

		//TEST_METHOD(dkloza2_TEST10)
		//{

		//}


		//Push_back n number of element where n < nodesize
		TEST_METHOD(dle32_pushBackTest_1) {
			myvector<int>  V(10);  // nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 8; i++)
				V.push_back(i);
			Assert::IsTrue(V.size() == 8);
		}

		//Push_back n number of element where n > nodesize
		//This will test if vector added an additional node
		TEST_METHOD(dle32_pushBackTest_2) {
			myvector<int>  V(3);  // nodesize of 3:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 25; i++)
				V.push_back(i);
			Assert::IsTrue(V.size() == 25);
		}



		//Check capacity for nodeNum = 1
		TEST_METHOD(dle32_capacityTest_1) {
			myvector<int>  V(10);  // nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);
			//add 25 elements to array
			for (int i = 0; i < 9; i++)
				V.push_back(i);
			//there should be 2 nodes with capacity of 20			
			Assert::IsTrue(V.capacity() == 10);
		}

		//Check capacity for nodeNum = 5
		TEST_METHOD(dle32_capacityTest_2) {
			myvector<int>  V(15);  // nodesize of 15:
			Assert::IsTrue(V.capacity() == 15);
			//add 73 elements to array
			for (int i = 0; i < 73; i++)
				V.push_back(i);
			//there should be 5 nodes with capacity of 75
			Assert::IsTrue(V.capacity() == 75);
		}

		//Check capacity for nodeNum = 0
		TEST_METHOD(dle32_capacityTest_3) {
			myvector<int>  V(0);  // nodesize of 0:
			Assert::IsTrue(V.capacity() == 0);
		}


		//Test operator function with indexes within the boundary
		TEST_METHOD(dle32_operationTest_1) {
			myvector<int>  V(15);  // nodesize of 15:			
			for (int i = 0; i <= 75; i++)
				V.push_back(i);
			int v1 = V[15];
			int v2 = V[38];
			int v0 = V[0];
			Assert::IsTrue(V[0] == 0);
			Assert::IsTrue(V[15] == 15);
			Assert::IsTrue(V[38] == 38);
			Assert::IsTrue(V[75] == 75);
		}


		//Test operator function on vector with nodeSize = 0
		TEST_METHOD(dle32_copyConstructorTest_4) {
			myvector<int> V(3);  // 
			for (int i = 0; i < 10; i++)
				V.push_back(i);

			myvector<int> C = V;
			Assert::IsTrue(C[5] == V[5]);
		}

		TEST_METHOD(dliang9_Test1)
		{
			myvector<int> V(100);
			Assert::IsTrue(V.capacity() == 100);
		}

		TEST_METHOD(dliang9_Test2)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(dliang9_Test3)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
		}

		TEST_METHOD(dliang9_Test4)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(dliang9_Test5)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[0] == 1);
		}

		TEST_METHOD(dliang9_Test6)
		{
			myvector<int> V(100);
			myvector<int> V2 = V;
			Assert::IsTrue(V.capacity() == V2.capacity());
		}

		TEST_METHOD(dliang9_Test7)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> Vcopy = V;

			Assert::IsTrue(Vcopy.size() == V.size());
		}

		TEST_METHOD(dliang9_Test8)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> Vcopy = V;

			Assert::IsTrue(Vcopy.front() == 1);
		}

		TEST_METHOD(dliang9_Test9)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> Vcopy = V;

			Assert::IsTrue(Vcopy.back() == 3);
		}

		TEST_METHOD(dliang9_Test10)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> Vcopy = V;

			Assert::IsTrue(Vcopy[0] == 1);
		}


		//capacity test for when capacity
		//passed first node

		TEST_METHOD(doci2_Test1)
		{
			//arrange
			myvector<int> V(10);

			//assert
			Assert::IsTrue(V.capacity() == 10);

			//act-initialize past first node
			for (int i = 0; i < 16; i++)
				V.push_back(i);

			//assert
			Assert::IsTrue(V.capacity() == 20);
		}

		////testing if indexing is correct with [] operator
		//TEST_METHOD(doci2_Test2)
		//{
		//	//arrange

		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	//assert
		//	Assert::AreEqual(V[0], 1);
		//	Assert::AreEqual(V[2], 2);



		//}

		//testing if operator[] has incrementing capabilities

		TEST_METHOD(doci2_Test3)
		{
			//arrange
			myvector<int> V(1);

			V.push_back(1);

			//act
			V[0]++;

			//assert
			Assert::AreEqual(V[0], 2);

		}

		//simple capacity test no resizing - not going passed first node

		TEST_METHOD(doci2_Test4)
		{
			//arrange
			myvector<int> V2(2);

			//assert
			Assert::AreEqual(V2.capacity(), 2);
		}

		////testing resizing of the myvector through capacity 
		//TEST_METHOD(doci2_Test5)
		//{
		//	myvector<int> V(10);

		//	V[23] = 4;

		//	Assert::AreEqual(V.capacity(), 30);
		//}

		////testing the deconstructor
		//TEST_METHOD(doci2_Test6)
		//{
		//	//arrange
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);

		//	//act-deconstruct
		//	delete &V;

		//	//assert
		//	Assert::AreNotEqual(1, V.front());
		//	Assert::AreNotEqual(2, V.back());
		//}

		//copy constructor test 
		TEST_METHOD(doci2_Test7)
		{

			//arrange
			myvector<int> V1(2);
			V1.push_back(1);
			V1.push_back(2);

			//act
			//creating v2 from copy 
			myvector<int> V2(V1);

			//assert
			Assert::AreEqual(V1[0], V2[0]);
			Assert::AreEqual(V1[1], V2[1]);
		}

		//testing functionality of push back
		TEST_METHOD(doci2_Test8)
		{
			//arrange
			myvector<int> V(1);

			//act- push_back
			V.push_back(12);

			//assert
			Assert::AreEqual(V[0], 12);
		}

		//testing functionality of push back with a resize
		TEST_METHOD(doci2_Test9)
		{
			//arrange
			myvector<int> V(1);

			//act
			V.push_back(12);
			V.push_back(2);

			//assert
			Assert::AreEqual(V[0], 12);
			Assert::AreEqual(V[1], 2);
		}

		//testing copy constructor
		//by checking copy's size and capacity 

		TEST_METHOD(doci2_Test10)
		{
			//arrange
			myvector<int> V(2);

			V.push_back(12);
			V.push_back(2);
			V.push_back(3);

			//act
			myvector<int> V2(V);

			//assert
			Assert::AreEqual(V.capacity(), 4);
			Assert::AreEqual(V.capacity(), V2.capacity());
			Assert::AreEqual(V.size(), V2.size());
		}

		//testing copy conttructor by checking
		// front and back method functinality 
		TEST_METHOD(doci2_Test11)
		{
			//arrange
			myvector<int> V(2);

			V.push_back(12);
			V.push_back(2);
			V.push_back(3);

			//act
			myvector<int> V2(V);

			//assert
			Assert::AreEqual(V.front(), 12);
			Assert::AreEqual(V.back(), 3);
			Assert::AreEqual(V.front(), V2.front());
			Assert::AreEqual(V.back(), V2.back());
		}



		/*
		* tests if the front and back arent null after an insert
		*/
		TEST_METHOD(dodda2_Test_testIfNotNull) {
			myvector<int> V(10);

			V.push_back(10);

			Assert::IsTrue(V.front() != NULL);
			Assert::IsTrue(V.back() != NULL);
		}

		/*
		* tests if the front and back are valid after 2 inserts
		*/
		TEST_METHOD(dodda2_Test_testSecondInsert) {
			myvector<int> V(10);

			V.push_back(10);
			V.push_back(20);

			Assert::IsTrue(V.back() == 20);
			Assert::IsTrue(V.front() == 10);
		}

		/*
		* tests if the capacity function is working properly
		*/
		TEST_METHOD(dodda2_Test_testCapacityFunction) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);

			Assert::IsTrue(V.capacity() == 10);
		}

		/*
		* tests if the capacity function is working properly after many inserts
		*/
		TEST_METHOD(dodda2_Test_testCapacityFunction2) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);
			V.push_back(40);
			V.push_back(60);
			V.push_back(10);
			V.push_back(20);

			Assert::IsTrue(V.capacity() == 10);
		}

		/*
		* tests if the front function works after first insert
		*/
		TEST_METHOD(dodda2_Test_testFrontAfterFirstInsert) {
			myvector<int> V(10);

			V.push_back(20);

			Assert::IsTrue(V.front() == 20);
		}

		/*
		* tests if the front doesnt move after a few inserts
		*/
		TEST_METHOD(dodda2_Test_testFront) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);

			Assert::IsTrue(V.front() == 20); // checks if the front never moves
		}

		/*
		* tests if the back function is valid after 1 insert
		*/
		TEST_METHOD(dodda2_Test_testBackAfterFirstInsert) {
			myvector<int> V(10);

			V.push_back(30);

			Assert::IsTrue(V.back() == 30);
		}

		/*
		* tests if the back function is valid after 1 insert
		*/
		TEST_METHOD(dodda2_Test_testBack) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);

			Assert::IsTrue(V.back() == 30);
		}

		/*
		* tests if the operator function gets first value
		*/
		TEST_METHOD(dodda2_Test_testOperatorBeginning) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);

			Assert::IsTrue(V[0] == 20);
		}

		/*
		* tests if the operator function gets end value
		*/
		TEST_METHOD(dodda2_Test_testOperatorEnd) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);
			V.push_back(10);

			Assert::IsTrue(V.operator[](2) == 10);
		}

		/*
		* tests if the operator function gets middle value
		*/
		TEST_METHOD(dodda2_Test_testOperatorMiddle) {
			myvector<int> V(10);

			V.push_back(20);
			V.push_back(30);
			V.push_back(10);

			Assert::IsTrue(V.operator[](1) == 30);
		}

		TEST_METHOD(dpulley_Test1)
		{
			myvector<int> V(18);	// nodesize of 18
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 18);
		}

		TEST_METHOD(dpulley_Test2)
		{
			myvector<int> V(40);	// nodesize of 40
			for (auto i = 1; i < 40; ++i)
				V.push_back(i);
			Assert::IsTrue(V.capacity() == 40);
		}

		TEST_METHOD(dpulley_Test3)
		{
			myvector<int> V(5);	// nodesize of 5
			V.push_back(2);
			V.push_back(4);
			V.push_back(6);
			V.push_back(8);

			Assert::IsTrue(V.capacity() == 5);
		}

		TEST_METHOD(dpulley_Test4)
		{
			myvector<int> V(5);	// nodesize of 5

			Assert::IsTrue(V.size() == 0);
			V.push_back(2);
			V.push_back(4);
			V.push_back(6);
			V.push_back(8);

			Assert::IsTrue(V.size() == 4);
		}

		TEST_METHOD(dpulley_Test5)
		{
			myvector<int> V(5);	// nodesize of 5

			Assert::IsTrue(V.size() == 0);
			V.push_back(3);
			V.push_back(6);
			V.push_back(9);
			V.push_back(12);
			V.push_back(15);
			Assert::IsTrue(V.size() != 4);
		}

		TEST_METHOD(dpulley_Test6)
		{
			myvector<int> V(1);	// nodesize of 1

			V.push_back(2);

			Assert::IsTrue(V.capacity() == 1);
      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V[0] == 2);
		}

		TEST_METHOD(dpulley_Test7)
		{
			myvector<int> V(100);	// nodesize of 100

			for (auto i = 0; i < 100; ++i)
				V.push_back(i);

			Assert::IsTrue(V.capacity() > 10);
		}

		TEST_METHOD(dpulley_Test8)
		{
			myvector<int> V(10);	// nodesize of 10

			for (auto i = 0; i < 10; ++i)
				V.push_back(i);

			Assert::IsTrue(V.size() < 20);
		}

		TEST_METHOD(dpulley_Test9)
		{
			myvector<int> V(500);	// nodesize of 500

			Assert::IsTrue(V.size() == 0);
			for (auto i = 0; i < 501; ++i)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 1000);
		}

		TEST_METHOD(dpulley_Test10)
		{
			myvector<int> V(10);	// nodesize of 10

			Assert::IsTrue(V.size() == 0);

			for (auto i = 0; i < 10; ++i)
				V.push_back(i);

			Assert::IsTrue(V.size() != 5);
		}



		TEST_METHOD(dvega3_Test1)//DONE passed
		{
			/*
			*tests pushback,front,back
			*/
			myvector<int>  V(10);
			int x = 1;
			V.push_back(x);
			V.push_back(x);
			V.push_back(x);
			x = 2;
			V.push_back(x);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 2);
			x = 10;
			V.push_back(10);
			Assert::IsTrue(V.back() == 10);
		}

		TEST_METHOD(dvega3_Test2) {//DONE passed
								   /*
								   *tests pushback,size
								   */
			myvector<int>  V(10);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);

			for (int i = 0; i < 7; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 10);
		}

		TEST_METHOD(dvega3_Test3) {//DONE passed
								   /*
								   *tests pushback,size,front,back
								   */
			myvector<int>  V(5);
			myvector<int>  VP(5);

			Assert::IsTrue(V.size() == 0);
			Assert::IsTrue(VP.size() == 0);
			Assert::IsTrue(VP.size() == V.size());//same size

			int y = 1;

			V.push_back(y);
			V.push_back(y);
			V.push_back(y);

			Assert::IsTrue(V.size() == 3);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 1);

			int x = 1;

			VP.push_back(x);
			VP.push_back(x);
			VP.push_back(x);
			x = 1;
			Assert::IsTrue(VP.size() == 3);
			Assert::IsTrue(VP.front() == 1);
			Assert::IsTrue(VP.back() == 1);

			Assert::IsTrue(VP.front() == V.front());//same values despite coming from dif variables
		}

		TEST_METHOD(dvega3_Test4) {//DONE passed
								   /*
								   *tests pushback,size,front
								   */
			myvector<int>  V(4);

			Assert::IsTrue(V.size() == 0);

			V.push_back(10);
			V.push_back(100);
			V.push_back(1000);

			Assert::IsTrue(V.size() == 3);

			myvector<int>  V2(1);

			V2.push_back(V.front());

			Assert::IsTrue(V2.front() == 10);
		}

		TEST_METHOD(dvega3_Test5) {//DONE passed
								   /*
								   *tests pushback,size,front,back
								   */
			myvector<int>  V(3);

			Assert::IsTrue(V.size() == 0);

			V.push_back(10);
			V.push_back(100);
			V.push_back(1000);

			myvector<int>  V2(3);

			V2.push_back(1000);
			V2.push_back(100);
			V2.push_back(10);

			Assert::IsTrue(V.size() == V2.size());
			Assert::IsTrue(V.front() == V2.back());
			Assert::IsTrue(V2.front() == V.back());
		}

		TEST_METHOD(dvega3_Test6) {//DONE passed
								   /*
								   *tests pushback,size,capacity
								   */
			myvector<int>  V(6);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 6);
		}

		TEST_METHOD(dvega3_Test7) {//DONE fails before completing .h file
								   /*
								   *tests pushback,size,capacity
								   */
			myvector<int>  V(10);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);

			myvector<int>  V2(5);

			Assert::IsTrue(V2.size() == 0);

			V2.push_back(1);
			V2.push_back(2);
			V2.push_back(3);
			V2.push_back(4);
			V2.push_back(5);
			V2.push_back(6);

			Assert::IsTrue(V2.capacity() == V.capacity());
		}

		TEST_METHOD(dvega3_Test8) {//DONE fails before completing .h file
								   /*
								   *tests pushback,capacity
								   */
			myvector<int>  V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(dvega3_Test9) {//DONE passed
								   /*
								   *tests pushback,size,front,back
								   */
			myvector<int>  V(10);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(3);
			V.push_back(2);
			V.push_back(1);

			Assert::IsTrue(V.size() == 6);

			Assert::IsTrue(V.front() == V.back());
		}

		TEST_METHOD(dvega3_Test10) {//DONE fails before completing .h file
									/*
									*tests pushback,size,back,array operator
									*/
			myvector<int>  V(10);

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 7; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V[0] == 0);
			Assert::IsTrue(V[3] == 3);
			Assert::IsTrue(V[6] == V.back());
		}


		////test to check the number of elements in the elements vector 
		//TEST_METHOD(eescob8_Test1)
		//{
		//	myvector<int> v(10);

		//	v.push_back(1);
		//	v.push_back(2);
		//	v.push_back(3);



		//	Assert::IsTrue(v.size() == 3);

		//}

    //check the capacity function
		TEST_METHOD(eescob8_Test2)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(2);
			v.push_back(3);



			Assert::IsTrue(v.capacity() == 10);

		}

		//testing 
		//test that the last value is equal to the back function (last element in the elements vector
		TEST_METHOD(eescob8_Test3)
		{
			myvector<int> v(10);

			v.push_back(1);

			v.push_back(100);


			Assert::IsTrue(v.back() == 100);

		}
		//test the first element in the vector that the head is pointing to
		TEST_METHOD(eescob8_Test4)
		{
			myvector<int> v(10);

			v.push_back(1000);


			Assert::IsTrue(v.front() == 1000);

		}


		TEST_METHOD(eescob8_Test5)
		{

			myvector<int> v(10);

			v.push_back(10);


			Assert::IsTrue(v.operator[](0) == 10);

		}



		//test to check the number of elements in the elements vector (larger scale) 
		TEST_METHOD(eescob8_Test6)
		{
			myvector<int> v(10);

			for (int i = 0; i < 1000; i++)
				v.push_back(i);


			Assert::IsTrue(v.capacity() == 1000);

		}
		//test function back at a (larger scale)
		TEST_METHOD(eescob8_Test7)
		{
			myvector<int> v(10);

			for (int i = 0; i < 1024; i++)
				v.push_back(i);

			Assert::IsTrue(v.back() == 1023);

		}
		//making sure if nothing is pusehed its size equals zero
		TEST_METHOD(eescob8_Test8)
		{
			myvector<int> v(10);


			Assert::IsTrue(v.size() == 0);

		}

		//larger scale to check if the value moved on to the next vector 
		TEST_METHOD(eescob8_Test9)
		{

			myvector<int> v(10);

			for (int i = 0; i < 24; i++)
				v.push_back(i);


			Assert::IsTrue(v.operator[](23) == 23);

		}
		//really large scale for cap funct. 
		TEST_METHOD(eescob8_Test10)
		{

			myvector<int> v(10);

			for (int i = 0; i < 100000; i++)
				v.push_back(i);


			Assert::IsTrue(v.capacity() == 100000);

		}



		//test .push_back() with 		
		TEST_METHOD(ehughe5_Test1) {
			myvector<int> V(5);

			V.push_back(11);
			V.push_back(22);
			V.push_back(33);
			V.push_back(44);
			V.push_back(55);

			Assert::AreEqual(V[0], 11);
			Assert::AreEqual(V[1], 22);
			Assert::AreEqual(V[2], 33);
			Assert::AreEqual(V[3], 44);
			Assert::AreEqual(V[4], 55);
		}

		//test .push_back() after a push when .size() == nodesize
		TEST_METHOD(ehughe5_Test2) {
			myvector<int> V(5);

			V.push_back(11);
			V.push_back(22);
			V.push_back(33);
			V.push_back(44);
			V.push_back(55);

			Assert::AreEqual(V[0], 11);
			Assert::AreEqual(V[1], 22);
			Assert::AreEqual(V[2], 33);
			Assert::AreEqual(V[3], 44);
			Assert::AreEqual(V[4], 55);

			V.push_back(66);
			V.push_back(77);

			Assert::AreEqual(V[5], 66);
			Assert::AreEqual(V[6], 77);
		}

		//test copy constructor
		TEST_METHOD(ehughe5_Test3) {
			myvector<int> V(5);
		
			V.push_back(32);
			V.push_back(125);
			V.push_back(89);
		
			myvector<int> V2(V);
		
			Assert::IsTrue(V2[0] == 32);
			Assert::IsTrue(V2[1] == 125);
			Assert::IsTrue(V2[2] == 89);
		}

		//test copy constructor does indeed perform deep copy
		TEST_METHOD(ehughe5_Test4) {
			myvector<int> V(5);
		
			V.push_back(32);
			V.push_back(125);
			V.push_back(89);
		
			myvector<int> V2(V);
		
			V[0] = 555;
			V[1] = 4;
			V[2] = 113;
		
			Assert::IsTrue(V2[0] == 32);
			Assert::IsTrue(V2[1] == 125);
			Assert::IsTrue(V2[2] == 89);
		}

		//test .size() after a push when .size() == nodesize
		TEST_METHOD(ehughe5_Test5) {
			myvector<int> V(5);	//nodesize of 5:

			Assert::IsTrue(V.size() == 0);

			V.push_back(11);
			V.push_back(22);
			V.push_back(33);
			V.push_back(44);
			V.push_back(55);
			Assert::IsTrue(V.size() == 5);

			V.push_back(66);
			Assert::IsTrue(V.size() == 6);

			V.push_back(77);
			Assert::IsTrue(V.size() == 7);
		}

		//test .capacity() when empty
		TEST_METHOD(ehughe5_Test6) {
			myvector<int> V(5);
			Assert::IsTrue(V.capacity() == 5);

			myvector<int> V2(23);
			Assert::IsTrue(V2.capacity() == 23);
		}

		//test .capacity() with 		
		TEST_METHOD(ehughe5_Test7) {
			myvector<int> V(5);	//nodesize of 5:

			Assert::IsTrue(V.capacity() == 5);

			V.push_back(1);
			Assert::IsTrue(V.capacity() == 5);

			V.push_back(2);
			Assert::IsTrue(V.capacity() == 5);

			V.push_back(3);
			Assert::IsTrue(V.capacity() == 5);

			V.push_back(4);
			Assert::IsTrue(V.capacity() == 5);

			V.push_back(5);
			Assert::IsTrue(V.capacity() == 5);
		}

		//test .capacity() after a push when .size() == nodesize
		TEST_METHOD(ehughe5_Test8) {
			myvector<int> V(5);	//nodesize of 5:

			Assert::IsTrue(V.capacity() == 5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			Assert::IsTrue(V.capacity() == 5);

			V.push_back(6);
			Assert::IsTrue(V.capacity() == 10);

			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			Assert::IsTrue(V.capacity() == 10);

			V.push_back(11);
			Assert::IsTrue(V.capacity() == 15);

			V.push_back(12);
			Assert::IsTrue(V.capacity() == 15);
		}

		//test .operator() with 		
		TEST_METHOD(ehughe5_Test9) {
			myvector<int> V(5);

			V.push_back(11);
			V.push_back(22);
			V.push_back(33);
			V.push_back(44);
			V.push_back(55);

			Assert::AreEqual(V.operator[](0), 11);
			Assert::AreEqual(V.operator[](1), 22);
			Assert::AreEqual(V.operator[](2), 33);
			Assert::AreEqual(V.operator[](3), 44);
			Assert::AreEqual(V.operator[](4), 55);
		}

		//test .operator() after a pushed when .size() == nodesize
		TEST_METHOD(ehughe5_Test10) {
			myvector<int> V(5);

			V.push_back(11);
			V.push_back(22);
			V.push_back(33);
			V.push_back(44);
			V.push_back(55);

			Assert::AreEqual(V.operator[](0), 11);
			Assert::AreEqual(V.operator[](1), 22);
			Assert::AreEqual(V.operator[](2), 33);
			Assert::AreEqual(V.operator[](3), 44);
			Assert::AreEqual(V.operator[](4), 55);

			V.push_back(66);
			Assert::AreEqual(V.operator[](5), 66);

			V.push_back(77);
			Assert::AreEqual(V.operator[](6), 77);
		}

		//test .front() == .back() when 1 element
		TEST_METHOD(ehughe5_Test11) {
			myvector<int> V(5);

			V.push_back(4);

			Assert::AreEqual(V.front(), V.back());
		}

		//test .front() != .back() when 2 elements or more
		TEST_METHOD(ehughe5_Test12) {
			myvector<int> V(5);

			V.push_back(4);
			V.push_back(132);

			Assert::AreNotEqual(V.front(), V.back());

			V.push_back(84);
			Assert::AreNotEqual(V.front(), V.back());
		}

		//test .begin() & .end()
		//TEST_METHOD(ehughe5_Test13) {
		//	myvector<int> V(5);

		//	V.push_back(4);
		//	V.push_back(132);
		//	V.push_back(99);

		//	auto iterBegin = V.begin();
		//	auto iterEnd = V.end();

		//	int firstNum = *iterBegin;
		//	int lastNum = *(iterEnd - 1);

		//	Assert::AreEqual(firstNum, 4);
		//	Assert::AreEqual(lastNum, 99);

		//}





		/* Tests the capacity function of myvector */
		TEST_METHOD(evelaz26_Test1) {
			myvector<int>  V(3);

			Assert::IsTrue(V.capacity() == 3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.capacity() == 6);
		}

		/* Tests the operator[] of myvector */
		TEST_METHOD(evelaz26_Test2) {
			myvector<double>  V(10);
			V.push_back(2.5);

			Assert::IsTrue(V[0] == 2.5);

			V.push_back(2.6);
			V.push_back(2.7);
			V.push_back(2.8);

			Assert::IsTrue(V[3] == 2.8);
		}

		/* Tests the generalization of the push_back function */
		TEST_METHOD(evelaz26_Test3) {
			myvector<string>  V(3);

			V.push_back("a");
			V.push_back("b");
			V.push_back("c");
			V.push_back("d");

			Assert::IsTrue(V.size() == 4);
		}


		// Tests the iterator of myvector 
		TEST_METHOD(evelaz26_Test4) {
			myvector<int>  V;//(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			int c = 0;
			int s = 0;

			for (auto a : V) {
				c++;
				s += a;
			}

			Assert::IsTrue(c == 3);
			Assert::IsTrue(s == 6);
		}


		// Tests the front and back functions of myvector 
		TEST_METHOD(evelaz26_Test5) {
			myvector<int>  V(10);

			V.push_back(11);

			Assert::IsTrue(V.front() == V.back());

			V.push_back(12);
			V.push_back(13);
			V.push_back(14);

			Assert::IsTrue(V.front() == 11);
			Assert::IsTrue(V.back() == 14);
		}

		// Tests the copy constructor of myvector 
		TEST_METHOD(evelaz26_Test6) {
			myvector<int>  V1(10);

			V1.push_back(1);
			V1.push_back(2);
			V1.push_back(3);
			V1.push_back(4);

			myvector<int>  V2(V1);

			for (int i = 0; i < V1.size(); i++) {
				Assert::IsTrue(V1[i] == V2[i]);
			}
		}


		// Tests the clear method of myvector 
		//TEST_METHOD(evelaz26_Test7) {
		//	myvector<int>  V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	V.clear();

		//	Assert::IsTrue(V.size() == 0);
		//}

		// Tests myvector adds a new chunk of memory when oversizing 
		TEST_METHOD(evelaz26_Test8) {
			myvector<int>  V(5);

			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			Assert::IsTrue(V.size() == 8);
		}

		TEST_METHOD(capacity_test) {
			myvector<int> V(10);

			Assert::IsTrue(V.capacity() == 10);

			for (int i = 0; i < 11; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 20);
		}

		TEST_METHOD(copy_constructor_test) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> copyV = V;

			V.push_back(4);

			Assert::IsFalse(copyV.back() == V.back());
		}

		TEST_METHOD(index_operator_test) {
			myvector<int> V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
				Assert::IsTrue(V[i] == i);
			}

			V[5] = 10;

			Assert::IsTrue(V[5] == 10);
		}

		TEST_METHOD(begin_test) {
			myvector<int> V(10);

			V.push_back(10);
			V.push_back(12);

			Assert::IsTrue(*(V.begin()) == 10);
		}

		TEST_METHOD(swap_front_and_back) {
			myvector<int> V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}

			int tmp = V[0];
			V[0] = V[9];
			V[9] = tmp;
			Assert::IsTrue(V.front() == 9);
			Assert::IsTrue(V.back() == 0);
		}

		TEST_METHOD(std_dev) {
			myvector<int> V(10);

			V.push_back(2);
			V.push_back(4);
			V.push_back(4);
			V.push_back(4);
			V.push_back(5);
			V.push_back(5);
			V.push_back(7);
			V.push_back(9);

			double sum = 0.0;
			int N = V.size();

			for (int i = 0; i < N; ++i) {
				sum += V[i];
			}

			double mean = sum / N;

			for (int i = 0; i < N; ++i) {
				double diff = V[i] - mean;
				V[i] = (int) (diff*diff);
			}

			sum = 0.0;
			for (int i = 0; i < N; ++i) {
				sum += V[i];
			}

			double result = sqrt(sum / N);

			Assert::AreEqual(result, 2.0);
		}

		TEST_METHOD(size_test) {
			myvector<int> V(10);

			Assert::AreEqual(V.size(), 0);
			V.push_back(3);
			V.push_back(2);
			V.push_back(1);

			Assert::AreEqual(V.size(), 3);
		}

		TEST_METHOD(large_size_test) {
			myvector<int> V(1);

			for (int i = 0; i < 1000; ++i) {
				V.push_back(i);
			}

			Assert::AreEqual(V.size(), 1000);
		}

		TEST_METHOD(binary_search_test) {
			myvector<int> V(10);
			for (int i = 0; i < 100; ++i) {
				V.push_back(i);
			}

			int target = 27;
			int hi = V.size() - 1;
			int lo = 0;
			int mid = (hi + lo) / 2;
			while (lo <= hi) {
				if (V[mid] == target)
					break;
				else if (V[mid] < target)
					lo = mid + 1;
				else
					hi = mid - 1;

				mid = (hi + lo) / 2;
			}

			Assert::AreEqual(mid, target);
		}

		TEST_METHOD(sum_with_iter) {
			myvector<int> V(10);

			for (int i = 0; i < 10; ++i) {
				V.push_back(i);
			}

			int sum = 0;
			for (auto it = V.begin(); it != V.end(); ++it) {
				sum += *it;
			}

			Assert::AreEqual(sum, 45);
		}

		//// test 1: check if an element are being removed correctly
		//TEST_METHOD(fahmed26_Test1)
		//{
		//	myvector<int> V(1);
		//	V.push_back(5);
		//	//V.push_back(5);
		//	// remove 
		//	V.~myvector();
		//	Assert::IsTrue(V.size() == 0);
		//}

		// test 2: check if front and back behave properly
		TEST_METHOD(fahmed26_Test2)
		{
			myvector<int> V(2);
			V.push_back(5);
			V.push_back(5);

			Assert::IsTrue(V.front() + V.back() == 10);
		}

		// test 3: check if front is being set properly
		TEST_METHOD(fahmed26_Test3)
		{
			myvector<int> V(2);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.front() == 5);
		}

		// test 4: check if back is being set properly after 1 add in
		TEST_METHOD(fahmed26_Test4)
		{
			myvector<int> V(2);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.back() == 6);
		}

		// test 5: check if vector size is consistent after being filled with elements
		TEST_METHOD(fahmed26_Test5)
		{
			myvector<int> V(8);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			Assert::IsTrue(V.size() == 8);
		}
		// test 6: check if vector front and back remain consistent when vector gets filled up
		TEST_METHOD(fahmed26_Test6)
		{
			myvector<int> V(8);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			Assert::IsTrue(V.front() == 1 && V.back() == 8);
		}

		// test 7: check if front and back go to the same point when there is only one element
		TEST_METHOD(fahmed26_Test7)
		{
			myvector<int> V(1);
			V.push_back(4);
			Assert::IsTrue(V.front() == 4 && V.back() == 4);
		}

		// test 8: check the front and back on an unfilled vector
		TEST_METHOD(fahmed26_Test8)
		{
			myvector<int> V(2);
			V.push_back(0);
			//V.push_back(0);
			Assert::IsTrue(V.front() == 0 && V.back() == 0);
		}

		// test 9: test if the operator of position 1 gives the correct value
		TEST_METHOD(fahmed26_Test9)
		{
			myvector<int> V(1);
			V.push_back(9);
			Assert::IsTrue(V[0] == 9);
		}

		// test 10: check if size gives 0 
		TEST_METHOD(fahmed26_Test10)
		{
			myvector<int> V(0);
			Assert::IsTrue(V.size() == 0);
		}


		TEST_METHOD(glulaj2_Test1)
		{
			myvector<int> V(10);
			for (int i = 1; i < 9; i++)
				V.push_back(i);


			Assert::IsTrue(V.capacity() == 10);  //checks if there is space for 10 items in Node
		}

		//TEST_METHOD(glulaj2_Test2)
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	myvector<int>(W);                      //makes a copy of V into W then tests if they are the same
		//	Assert::AreSame(V, W);
		//}

		TEST_METHOD(glulaj2_Test3)
		{
			myvector<int> V(10); // nodesize of 10:

			Assert::IsTrue(V.size() == 0); // size is set to 0 in the begining
		}

		TEST_METHOD(glulaj2_Test4)
		{
			myvector<int> V(10);
			for (int i = 1; i < 26; i++)
				V.push_back(i);
			Assert::IsTrue(V.front() == 1); // test the begin function 
		}

		TEST_METHOD(glulaj2_Test5)
		{
			myvector<int> V(10);
			for (int i = 1; i < 26; i++)
				V.push_back(i);
			Assert::IsTrue(V.back() == 25); // test the end function 
		}

		TEST_METHOD(glulaj2_Test6)
		{
			myvector<int> V(10);
			for (int i = 0; i < 26; i++)
				V.push_back(i);
			Assert::IsTrue(V[23] == 23); // asuming that the operator function works, this would check what element is in position 23
		}

		//TEST_METHOD(glulaj2_Test7)
		//{
		//	myvector<int> V(10);
		//	for (int i = 1; i < 10; i++)
		//		V.push_back(i);
		//	V.~myvector();              //delete populated vector
		//	Assert::IsFalse(V.front() == 1);  // after deleted the head of myvector
		//}


		TEST_METHOD(gpoulo2_Test1) {
			myvector<int>  V(10);

			V.push_back(4);
			V.push_back(91);
			V.push_back(312);
			V.push_back(12);

			Assert::IsTrue(V.front() == 4);

		}
		TEST_METHOD(gpoulo3_Test2) {
			myvector<int>  V(10);
			Assert::IsTrue(V.size() == 0);

			V.push_back(1);

			Assert::IsTrue(V.size() == 1);
		}

		TEST_METHOD(gpoulo3_Test3) {
			myvector<int>  V(4);
			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			//grows here, check if it grows correctly
			V.push_back(1);
			Assert::IsTrue(V.size() == 5);
		}

		TEST_METHOD(gpoulo3_Test4) {
			myvector<int>  V(1);
			Assert::IsTrue(V.size() == 0);
			V.push_back(33);
			Assert::IsTrue(V.size() == 1);
		}

		//TEST_METHOD(gpoulo3_Test5) {
		//	myvector<int>  V(10);
		//	Assert::IsTrue(V.size() == 0);
		//	V.push_back(32);
		//	V.push_back(12);
		//	V.~myvector();

		//	Assert::IsTrue(V.size() == 0);
		//}

		//TEST_METHOD(gpoulo3_Test6) {
		//	myvector<int>  V(10);

		//	V.push_back(32);
		//	V.push_back(12);
		//	myvector<int>  V(V);

		//	Assert::IsTrue(V.size() == V2.size());
		//}

		//TEST_METHOD(gpoulo3_Test7) {
		//	myvector<int>  V(10);

		//	V.push_back(32);
		//	V.push_back(12);
		//	V.push_back(112);
		//	myvector<int>  V(V);

		//	Assert::IsTrue(V.capacity() == V2.capacity());
		//}

		TEST_METHOD(gpoulo3_Test8) {
			myvector<int>  V(10);
			//how does it handle an emppty vector
			myvector<int> V2(V);

			Assert::IsTrue(V.capacity() == V2.capacity());
		}

		//TEST_METHOD(gpoulo3_Test9) {
		//	myvector<int>  V(10);

		//	V.push_back(1);
		//	V.push_back(3);
		//	V.~myvector();

		//	Assert::IsTrue(V.capacity() == 0);
		//}

		TEST_METHOD(gpoulo3_Test10) {
			myvector<int>  V(10);
			int i = 0;
			while (i < 100) {
				V.push_back(1);
				V.push_back(3);
				i++;
			}
			//check dynamic growing capabilities
			Assert::IsTrue(V.size() == 200);
		}




		//tests front and back
		TEST_METHOD(gtorre23_Test1) {
			// TODO: Your test code here
			myvector<int> V(5);

			V.push_back(10);

			Assert::IsTrue(V.front() == 10);
			Assert::IsFalse(V.back() == 1);
		}

		//tests size
		TEST_METHOD(gtorre23_Test2) {
			myvector<int> V1(1);

			Assert::IsTrue(V1.size() == 0);

			myvector<int> V2(10);

			V2.push_back(11);
			V2.push_back(9);
			V2.push_back(2);
			V2.push_back(13);
			V2.push_back(6);

			Assert::IsTrue(V2.size() == 5);
		}

		//tests capacity
		TEST_METHOD(gtorre23_Test3) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		//tests capacity
		TEST_METHOD(gtorre23_Test4) {
			myvector<int> V(4);

			V.push_back(11);
			V.push_back(4);
			V.push_back(5);
			V.push_back(21);
			V.push_back(8);
			V.push_back(9);
			V.push_back(2);

			Assert::IsTrue(V.capacity() == 8);
		}

		//tests capacity
		TEST_METHOD(gtorre23_Test5) {
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.capacity() == 6);
		}

		//tests operator[]
		TEST_METHOD(gtorre23_Test6) {
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.operator[](1) == 2);
		}

		////tests operator[]
		TEST_METHOD(gtorre23_Test7) {
			myvector<int> V(10);

			V.push_back(5);
			V.push_back(8);
			V.push_back(11);
			V.push_back(2);
			V.push_back(12);

			Assert::IsTrue(V[4] == 12);
		}

		//tests copy constructor
		TEST_METHOD(gtorre23_Test8) {
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);			//copy constructor

			Assert::IsTrue(V2.front() == 1);
			Assert::IsTrue(V2.size() == 3);
		}

		////tests ~myvector
		//TEST_METHOD(gtore23_Test9) {
		//	myvector<int> V(5);

		//	V.push_back(2);
		//	V.push_back(7);
		//	V.push_back(13);
		//	V.push_back(6);
		//	V.push_back(10);

		//	V.~myvector();

		//	Assert::IsTrue(V.size() == 0);
		//	//Assert::IsTrue(V.front() == 0);
		//}

		////tests for size
		TEST_METHOD(gtorre23_Test10) {
			myvector<int> V(10);				//initial node size of 0

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
			Assert::IsTrue(V.front() == 1);
		}



		TEST_METHOD(heilman2_Test1)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(7);
			V.push_back(8);
			V.push_back(15);

			Assert::IsTrue(V.front() == 7);
			Assert::IsTrue(V.back() == 15);
		}

		TEST_METHOD(heilman2_Test2)
		{
			myvector<int> V(10); // nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			V.push_back(204);
			V.push_back(12);
			V.push_back(-15);
			V.push_back(24);
			V.push_back(152);
			V.push_back(-5);
			V.push_back(41);
			V.push_back(12);
			V.push_back(-5);

			Assert::IsTrue(V.size() == 9);
		}
		TEST_METHOD(heilman2_Test3)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(13);
			V.push_back(26);
			V.push_back(31);
			V.push_back(19);
			V.push_back(27);
			V.push_back(33);

			Assert::IsTrue(V.front() == 13);
			Assert::IsTrue(V.back() == 33);
		}

		TEST_METHOD(heilman2_Test4)
		{
			myvector<int> V(10); // nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			V.push_back(15);
			V.push_back(21);
			V.push_back(33);
			V.push_back(14);
			V.push_back(25);
			V.push_back(39);

			Assert::IsTrue(V.size() == 6);
		}
		TEST_METHOD(heilman2_Test5)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(12);
			V.push_back(23);
			V.push_back(31);
			V.push_back(23);
			V.push_back(31);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(heilman2_Test6)
		{
			myvector<int> V(10); // nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(23);
			V.push_back(31);
			V.push_back(213);
			V.push_back(31);
			V.push_back(34);

			Assert::IsTrue(V.capacity() == 10);
		}
		TEST_METHOD(heilman2_Test7)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(132);
			V.push_back(21);
			V.push_back(33);
			V.push_back(19);
			V.push_back(26);
			V.push_back(35);

			Assert::IsTrue(V.front() == 132);
			Assert::IsTrue(V.back() == 35);
		}

		TEST_METHOD(heilman2_Test8)
		{
			myvector<int> V(10); // nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			V.push_back(112);
			V.push_back(22);
			V.push_back(34);
			V.push_back(13);
			V.push_back(26);
			V.push_back(37);

			Assert::IsTrue(V.size() == 6);
		}
		TEST_METHOD(heilman2_Test9)
		{
			myvector<int> V(10); // nodesize of 10:

			V.push_back(11);
			V.push_back(22);
			V.push_back(35);
			V.push_back(33);
			V.push_back(43);
			V.push_back(36);

			Assert::IsTrue(V.front() == 11);
			Assert::IsTrue(V.back() == 36);
			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(heilman2_Test10)
		{
			myvector<int> V(10); // nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			V.push_back(13);
			V.push_back(21);
			V.push_back(34);
			V.push_back(16);
			V.push_back(243);
			V.push_back(36);

			Assert::IsTrue(V.size() == 6);
			Assert::IsTrue(V.front() == 13);
			Assert::IsTrue(V.back() == 36);
			Assert::IsTrue(V.capacity() == 10);
		}



		// Test (1) for size() > nodeSize
		// checks size before adding elements
		// and after adding more than nodeSize() elements
		TEST_METHOD(hpate34_SIZE) {
			myvector<int> V(10);
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 22; i++) {
				V.push_back(i + 1);
			}
			Assert::IsTrue(V.size() == 22);
		}

		// Test (2) for capacity() < nodeSize
		// checks capacity when more nodes are not needed
		TEST_METHOD(hpate34_CAPACITY1) {
			myvector<int> V(10);
			Assert::IsTrue(V.capacity() == 10);
			for (int i = 0; i < 7; i++) {
				V.push_back(i + 1);
			}
			Assert::IsTrue(V.capacity() == 10);
		}

		// Test (3) for capacity() > nodeSize
		// checks capacity when more nodes are needed
		TEST_METHOD(hpate34_CAPACITY2) {
			myvector<int> V(10);
			Assert::IsTrue(V.capacity() == 10);
			for (int i = 0; i < 22; i++) {
				V.push_back(i + 1);
			}
			Assert::IsTrue(V.capacity() == 30);
		}

		// Test (4) for different type
		// tests if character works instead of int
		TEST_METHOD(hpate34_TYPE) {
			myvector<char> V(10);
			V.push_back('H');
			V.push_back('A');
			Assert::IsTrue(V.front() == 'H');
			Assert::IsTrue(V.back() == 'A');
		}

		// Test (5) for operator < 10
		// tests if operator works between 0 and 9
		TEST_METHOD(hpate34_OPERATOR1) {
			myvector<int> V(10);
			for (int i = 0; i < 7; i++) {
				V.push_back(i + 1);
			}
			Assert::IsTrue(V.operator[](3) == 4);
		}

		// Test (6) for operator > 10, < capacity
		// tests if operator work > 10 but less than capacity
		TEST_METHOD(hpate34_OPERATOR2) {
			myvector<int> V(10);
			for (int i = 0; i < 22; i++) {
				V.push_back(i + 1);
			}
			Assert::IsTrue(V.operator[](15) == 16);
		}

		// Test (7) for operator > 10, = cap
		// tests if operator works at the last node
		TEST_METHOD(hpate34_OPERATOR3) {
			myvector<int> V(10);
			for (int i = 0; i < 22; i++) {
				V.push_back(i + 1);
			}
			Assert::IsTrue(V.operator[](21) == 22);
		}

		// Test (8) for front()
		// tests front after pushing 2 elements
		TEST_METHOD(hpate34_FRONT1) {
			myvector<int> V(10);
			V.push_back(10);
			Assert::IsTrue(V.front() == 10);
			V.push_back(20);
			Assert::IsTrue(V.front() == 10);
		}

		// Test (9) for front()
		// tests front after pushing 34 elements
		TEST_METHOD(hpate34_FRONT2) {
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.front() == 1);
			for (int i = 0; i < 33; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.front() == 1);
		}

		// Test (10) for back()
		// tests back after adding 1 element, 2 elements, and 33 elements
		TEST_METHOD(hpate34_BACK) {
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.back() == 1);
			V.push_back(4);
			Assert::IsTrue(V.back() == 4);
			for (int i = 0; i < 33; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.back() == 32);
		}



		TEST_METHOD(ikamal3_Test1) {
			myvector<int> V;
			Assert::IsTrue(V.capacity() == 100);

			myvector<int> A(10);
			Assert::IsTrue(A.capacity() == 10);

			for (int i = 1; i <= 22; i++) {
				A.push_back(i);
			}
			Assert::IsTrue(A.capacity() == 30);


		}

		TEST_METHOD(ikamal3_Test2) {
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.front() == 1 && V.back() == 1);

			V.push_back(2);
			Assert::IsTrue(V.front() == 1 && V.back() == 2);

			for (int i = 3; i <= 10; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.back() == 10);

			V.push_back(11);
			Assert::IsTrue(V.back() == 11);

		}

		TEST_METHOD(ikamal3_Test3) {
			myvector<int> A(10);
			for (int i = 1; i <= 22; i++) {
				A.push_back(i);
			}

			Assert::IsTrue(A.operator[](0) == 1);
			Assert::IsTrue(A.operator[](21) == 22);
		}


		TEST_METHOD(ikamal3_Test4) {
			myvector<int> V;
			V.push_back(-1);

			Assert::IsTrue(V.front() == -1);
		}

		TEST_METHOD(ikamal3_Test5) {
			myvector<int> A(10);
			for (int i = 1; i <= 22; i++) {
				A.push_back(i);
			}

			myvector<int> B(A);

			int b_back = B.back();
			int a_back = A.back();

			Assert::IsTrue(b_back == a_back);

		}

		TEST_METHOD(ikamal3_Test6) {
			myvector<int> V;

			Assert::IsTrue(V.size() == 0);
			Assert::IsTrue(V.capacity() == 100);
		}


		TEST_METHOD(ikamal3_Test7) {
			myvector<int> V(10);
			for (int i = 0; i < 1000000; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 1000000);
			Assert::IsTrue(V.capacity() == 1000000);
			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 999999);
		}


		TEST_METHOD(ikamal3_Test8) {
			{
				myvector<int> V;
				for (int i = 0; i < 10; i++) {
					V.push_back(i);
				}
			}

			myvector<int> V;

			Assert::IsTrue(V.size() == 0);
			Assert::IsTrue(V.capacity() == 100);
		}


		TEST_METHOD(ikamal3_Test9) {
			myvector<int> V;
			V.push_back(3000);

			Assert::IsTrue(V.back() == V.front());
			Assert::IsTrue(V.operator[](0) == V.back());
			Assert::IsTrue(V.operator[](0) == V.front());
			Assert::IsTrue(V.capacity() == 100);
			Assert::IsTrue(V.size() == 1);

		}


		//TEST_METHOD(ikamal3_Test10) {
		//	myvector<int> V(0);
		//	V.push_back(1);

		//	Assert::IsTrue(V.size() == 0);
		//	Assert::IsTrue(V.capacity() == 0);
		//}





		//Test push back before a new node is added
		TEST_METHOD(jaramll3_Test1)
		{
			myvector<int> V(10); // nodesize of 10

			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 2);
		}

		//Test push back after a new node is added
		TEST_METHOD(jaramll3_Test2)
		{
			myvector<int> V(10); // nodesize of 10

			for (int i = 0; i < 15; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 14);
		}

		//Test capacity after new node needs to be added
		TEST_METHOD(jaramll3_Test3)
		{
			myvector<int> V(10); // nodesize of 10

			for (int i = 0; i < 15; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 20);
		}

		//Test operator[] before a new node is added
		TEST_METHOD(jaramll3_Test4)
		{
			myvector<int> V(10); // nodesize of 10

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
		}

		//Test operator[] after a new node is added
		TEST_METHOD(jaramll3_Test5)
		{
			myvector<int> V(10); // nodesize of 10

			for (int i = 0; i < 15; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V[9] == 9);
			Assert::IsTrue(V[10] == 10);
			Assert::IsTrue(V[14] == 14);
		}

		////Test operator*
		//TEST_METHOD(jaramll3_Test6)
		//{
		//	myvector<int> V(10); // nodesize of 10

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(*V.begin() == 1);
		//	Assert::IsTrue(*V.end() == 3);

		//}

		//Test operator++
		TEST_METHOD(jaramll3_Test7)
		{
			myvector<int> V(10); // nodesize of 10

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			auto it = V.begin();
			++it;

			Assert::IsTrue(*it == 2);

		}

		//Test operator!=
		TEST_METHOD(jaramll3_Test8)
		{
			myvector<int> V(10); // nodesize of 10

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.begin() != V.end());

		}

		////Test copy constructor -- make sure every value is being copied over
		//TEST_METHOD(jaramll3_Test9)
		//{
		//	myvector<int> V(10); // nodesize of 10

		//	for (int i = 0; i < 25; i++) {
		//		V.push_back(i);
		//	}

		//	myvector<int> V2 = V;

		//	Assert::IsTrue(*V2.begin() == 0);
		//	Assert::IsTrue(*V2.end() == 24);

		//}

		////Test copy constructor -- make sure changing one vector won't affect the other
		//TEST_METHOD(jaramll3_Test10)
		//{
		//	myvector<int> V(10); // nodesize of 10

		//	for (int i = 0; i < 25; i++) {
		//		V.push_back(i);
		//	}

		//	myvector<int> V2 = V;
		//	V.push_back(25);

		//	Assert::IsTrue(*V.end() == 25);
		//	Assert::IsTrue(*V2.end() == 24);

		//	V2.push_back(26);

		//	Assert::IsTrue(*V.end() == 25);
		//	Assert::IsTrue(*V2.end() == 26);
		//}




		TEST_METHOD(jbendo2_Test1) { //Check if multiple nodes create properly
			myvector<int>  V(5);

			for (int i = 0; i < 12; i++)
				V.push_back(i);

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 11);
		}
		TEST_METHOD(jbendo2_Test2) { //Check if the first element of a new node is correct
			myvector<int>  V(5);

			for (int i = 0; i < 6; i++)
				V.push_back(i);

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 5);
		}
		TEST_METHOD(jbendo2_Test3) {
			myvector<int>  V(5);

			for (int i = 0; i < 6; i++)
				V.push_back(i);


			Assert::IsTrue(V.size() == 6);
		}
		TEST_METHOD(jbendo2_Test4) {
			myvector<int>  V(5);

			for (int i = 0; i < 6; i++)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 10);
		}
		TEST_METHOD(jbendo2_Test5) {
			myvector<int>  V(5);
			Assert::IsTrue(V.capacity() == 5); //Check if inital capacity is 1 node

			for (int i = 0; i < 5; i++)
				V.push_back(i);

			//Make sure doesn't roll over before 6th is added
			Assert::IsTrue(V.capacity() == 5);
			V.push_back(5);
			Assert::IsTrue(V.capacity() == 10); //check if capacity increased with new node creation
		}
		TEST_METHOD(jbendo2_Test6) { //make sure the size never exceeds the capacity
			myvector<int>  V(10);

			for (int i = 0; i < 100; i++) {
				V.push_back(i);
				Assert::IsTrue(V.capacity() >= V.size());
			}
		}
		TEST_METHOD(jbendo2_Test7) { //checking index of 0
			myvector<int>  V(5);

			for (int i = 0; i < 6; i++)
				V.push_back(i);

			Assert::IsTrue(V[0] == 0);
		}
		TEST_METHOD(jbendo2_Test8) { //checking upper border indexing of a node
			myvector<int>  V(5);

			for (int i = 0; i < 6; i++)
				V.push_back(i);

			Assert::IsTrue(V[4] == 4);
		}


		// checks to see if the back is being added on correctly
		TEST_METHOD(jevang2_Test1)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			Assert::IsTrue(V.back() == 1);
			V.push_back(2);
			Assert::IsTrue(V.back() == 2);
			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		// checks if the front is not being affected by the push_back function
		TEST_METHOD(jevang2_Test2)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			Assert::IsTrue(V.front() == 1);
			V.push_back(2);
			Assert::IsTrue(V.front() == 1);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
		}

		// checks to make sure if that the size is being updated correctly
		TEST_METHOD(jevang2_Test3)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			Assert::IsTrue(V.size() == 1);
			V.push_back(2);
			Assert::IsTrue(V.size() == 2);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3);
		}

		// checks to make sure size is implemented for the a vector of size 0
		TEST_METHOD(jevang2_Test4)
		{
			myvector<int> V(10);	// nodesize of 10:

			Assert::IsTrue(V.size() == 0);
		}

		// checks to see if the vector can grow past inital size and store the back properly
		TEST_METHOD(jevang2_Test5)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(10);
			Assert::IsTrue(V.back() == 10);
			V.push_back(11);
			Assert::IsTrue(V.back() == 11);

		}

		// checks to see if the size of the vector is updated past inital size
		TEST_METHOD(jevang2_Test6)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(10);
			Assert::IsTrue(V.size() == 10);
			V.push_back(11);
			Assert::IsTrue(V.size() == 11);

		}

		// checks to make sure growing past initial size of the vector does not affect the front
		TEST_METHOD(jevang2_Test7)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(10);
			Assert::IsTrue(V.front() == 1);
			V.push_back(11);
			Assert::IsTrue(V.front() == 1);
		}

		// checks to makes sure that an empty vector has proper capacity
		TEST_METHOD(jevang2_Test8)
		{
			myvector<int> V(10);	// nodesize of 10:

			Assert::IsTrue(V.capacity() == 10);
		}

		// checks to see if the capcity updates when growing past inital vector size
		TEST_METHOD(jevang2_Test9)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(10);
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(11);
			Assert::IsTrue(V.capacity() == 20);

		}

		// checks to see if the capcity is correct after adding in only 3 elements to the vector
		TEST_METHOD(jevang2_Test10)
		{
			myvector<int> V(10);	// nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}




		TEST_METHOD(jjeon21_Test1) //test of 25 input size
		{
			myvector<int> V(30);
			int i;

			Assert::IsTrue(V.size() == 0);

			for (i = 0; i < 25; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 25);
		}

		TEST_METHOD(jjeon21_Test2) //test of going past capacity
		{
			myvector<int> V(10);
			int i;

			Assert::IsTrue(V.size() == 0);

			for (i = 0; i < 11; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 20);
		}

		TEST_METHOD(jjeon21_Test3) //test beginning capacity
		{
			myvector<int> V(10);

			Assert::IsTrue(V.capacity() == 10);

			myvector<int> B(23);

			Assert::IsTrue(B.capacity() == 23);
		}

		TEST_METHOD(jjeon21_Test4) //test operator[]
		{
			myvector<int> V(10);

			V.push_back(1);

			Assert::IsTrue(V.operator[](0) == 1);
		}

		TEST_METHOD(jjeon21_Test5) //test back()
		{
			myvector<int> V(10);

			V.push_back(1);
			Assert::IsTrue(V.back() == 1);

			V.push_back(2);
			Assert::IsTrue(V.back() == 2);

			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(jjeon21_Test6) //test front()
		{
			myvector<int> V(10);

			V.push_back(1);
			Assert::IsTrue(V.front() == 1);

			V.push_back(2);
			Assert::IsTrue(V.front() == 1);

			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
		}

		TEST_METHOD(jjeon21_Test7) //back front after capacity increase
		{
			myvector<int> V(10);
			int i;

			Assert::IsTrue(V.size() == 0);

			for (i = 0; i < 11; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 20);
			Assert::IsTrue(V.back() == 10);
			Assert::IsTrue(V.front() == 0);
		}

		TEST_METHOD(jjeon21_Test8) //2 lists same sizes
		{
			myvector<int> V(10);
			myvector<int> B(30);
			int i;

			for (i = 0; i < 25; i++) {
				V.push_back(i);
				B.push_back(i);
			}

			Assert::IsTrue(V.size() == B.size());
		}

		TEST_METHOD(jjeon21_Test9) //2 lists same capacity
		{
			myvector<int> V(10);
			myvector<int> B(15);

			int i;

			for (i = 0; i < 25; i++) {
				V.push_back(i);
				B.push_back(i);
			}

			Assert::IsTrue(V.capacity() == B.capacity());
		}

		TEST_METHOD(jjeon21_Test10) //stops at max?
		{
			myvector<int> V(10);
			int i;

			for (i = 0; i < 10; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == V.capacity());
		}

		//check if a new Node is being created
		TEST_METHOD(jkim540_Test1)
		{
			myvector<int>  V(2); //make the node size only 2

			V.push_back(1);
			V.push_back(2);

			//at this point it should create a new node of size 2

			V.push_back(3);
			V.push_back(12);

			Assert::IsTrue(V.size() == 4);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 12);
		}



		//find the value 11 in the second index
		TEST_METHOD(jkim540_Test3)
		{
			myvector<int> V(2);
			V.push_back(12);
			V.push_back(11);
			V.push_back(13);
			V.push_back(14);
			Assert::IsTrue(V.front() == 12);
			Assert::IsTrue(V.operator[](2) == 13);
			Assert::IsTrue(V.back() == 14);
		}



		//check size is zero
		TEST_METHOD(jkim540_Test6)
		{
			myvector<int> V(2);

			Assert::IsTrue(V.size() == 0);

		}

		//capcaity should be 6
		TEST_METHOD(jkim540_Test7)
		{
			myvector<int> V(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);


			Assert::IsTrue(V.capacity() == 6);

		}

		//size is 5
		TEST_METHOD(jkim540_Test8)
		{
			myvector<int> V(1);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			Assert::IsTrue(V.size() == 5);
			Assert::IsTrue(V.front() == 1);

		}

		//change the value of the head
		TEST_METHOD(jkim540_Test9)
		{
			myvector<int> V(1);
			V.push_back(1);



			V[0] = 12;
			Assert::IsTrue(V[0] == 12);
			Assert::IsTrue(V.back() == 12);
		}

		////go to the next node to change the value
		TEST_METHOD(jkim540_Test10)
		{
			myvector<int> V(2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(1);


			V[2] = 12;
			Assert::IsTrue(V[2] == 12);
			Assert::IsTrue(V.back() == 12);
      Assert::IsTrue(V.front() == 1);
		}


		TEST_METHOD(jmei41_Test1) {
			myvector<int>  V(2);
			// nodesize of 2:
			Assert::IsTrue(V.capacity() == 2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 4);
		}

		TEST_METHOD(jmei41_Test2) {
			myvector<int>  V(2);
			// nodesize of 2:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(jmei41_Test3) {
			myvector<int>  V(2);
			// nodesize of 2:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
		}

		//TEST_METHOD(jmei41_Test4) {
		//	myvector<int>  V(2);
		//	// nodesize of 2:
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	delete &V;
		//	Assert::IsTrue(V.front() == 1);
		//	Assert::IsTrue(V.back() == 3);
		//}

		//TEST_METHOD(jmei41_Test5) {
		//	myvector<int>  V(2);
		//	// nodesize of 2:
		//	Assert::IsTrue(V.size() == 0);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	delete &V;
		//	Assert::IsTrue(V.size() == 0);
		//}

		//TEST_METHOD(jmei41_Test6) {
		//	myvector<int>  V(2);
		//	// nodesize of 2:
		//	Assert::IsTrue(V.capacity() == 2);
		//	delete &V;
		//	Assert::IsTrue(V.capacity() == 0);
		//}

		TEST_METHOD(jmei41_Test7) {
			myvector<int>  V(10);
			// nodesize of 2:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.operator[](0) == 1);
			Assert::IsTrue(V.operator[](1) == 2);
			Assert::IsTrue(V.operator[](2) == 3);
		}

		//TEST_METHOD(jmei41_Test8) {
		//	myvector<int>  V(10);
		//	// nodesize of 2:
		//	V.operator[](0) = 1;
		//	V.operator[](1) = 2;
		//	V.operator[](2) = 3;
		//	Assert::IsTrue(V[0] == 1);
		//	Assert::IsTrue(V[1] == 2);
		//	Assert::IsTrue(V[2] == 3);
		//}

		//TEST_METHOD(jmei41_Test9) {
		//	myvector<int> V(10);
		//	V[0] = 1;
		//	V[1] = 2;
		//	V[2] = 3;
		//	Assert::IsTrue(V.operator[](0) == 1);
		//	Assert::IsTrue(V.operator[](1) == 2);
		//	Assert::IsTrue(V.operator[](2) == 3);
		//}

		//TEST_METHOD(jmei41_Test10) {
		//	myvector<int> V(1);
		//	V.push_back(1);
		//	V[1] = 2;
		//	Assert::IsTrue(V.operator[](1) == 2);
		//	V.operator[](2) = 3;
		//	Assert::IsTrue(V[2] == 3);
		//}


		TEST_METHOD(jsayek2_Capacity_Test)
		{
			myvector <int>  V(10); // nodesize of 10:

			Assert::IsTrue(V.capacity() == 10);

		}

		TEST_METHOD(jsayek2_Capcity_Test_New_Node)
		{
			myvector <int>  V(2);

			Assert::IsTrue(V.capacity() == 2);

			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.capacity() == 2);

			V.push_back(3);

			Assert::IsTrue(V.capacity() == 4);

			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.capacity() == 6);
		}

		TEST_METHOD(jsayek2_Size_Test_New_Node)
		{
			myvector <int>  V(3);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);

			V.push_back(4);

			Assert::IsTrue(V.size() == 4);
		}

		TEST_METHOD(jsayek2_Front_Back_Test_New_Node)
		{
			myvector <int>  V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 4);
		}



		TEST_METHOD(jsayek2_Copy_Test)
		{
			myvector <int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector <int> X = V;

			Assert::IsTrue(X.front() == 1);
			Assert::IsTrue(X.back() == 3);
			Assert::IsTrue(X.size() == 3);
			Assert::IsTrue(X.capacity() == 10);
		}

		TEST_METHOD(jsayek2_Index_Test)
		{
			myvector <int>  V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[2] == 3);
		}

		TEST_METHOD(jsayek2_Index_Test_New_Node)
		{
			myvector <int>  V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V[2] == 3);
			Assert::IsTrue(V[4] == 5);
		}

		//TEST_METHOD(jsayek2_Iterator_Test)
		//{
		//	myvector <int>  V(5);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);
		//	V.push_back(5);

		//	auto iterB = V.begin();
		//	auto iterE = V.end() - 1;
		//	Assert::IsTrue(*iterB == 1);
		//	Assert::IsTrue(*iterE == 5);
		//}




		TEST_METHOD(jsingh10_Test1) {		//test copy constructor copies values
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> S(V);
			Assert::IsTrue(V[0] == S[0]);
			Assert::IsTrue(V[1] == S[1]);
			Assert::IsTrue(V[2] == S[2]);
		}

		TEST_METHOD(jsingh10_Test2) {		//test copy constructor keeps correct capacity
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> S(V);

			Assert::IsTrue(V.capacity() == S.capacity());
		}

		TEST_METHOD(jsingh10_Test3) {		//check if capacity is increased
			myvector<int> V(1);
			V.push_back(1);
			V.push_back(1);
			Assert::IsTrue(V.capacity() > 1);
		}

    class test_cl {
    public:
      int one;
      double two;
      char a;
      test_cl()
      {}
      test_cl(int o, double t, char c)
        :one(o), two(t), a(c)
      {}
    };
    
    TEST_METHOD(jsingh10_Test4) {	//test that it works for non-default class type
			myvector<test_cl> V(5);
			test_cl temp(3, 7.8, 'p');
			V.push_back(temp);
			Assert::IsTrue(V[0].one == 3);
			Assert::IsTrue(V[0].two == 7.8);
			Assert::IsTrue(V[0].a == 'p');
		}

		TEST_METHOD(jsingh10_Test5) {			//Check that copy constructor keeps correct size
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> S(V);

			Assert::IsTrue(V.size() == S.size());
		}

		TEST_METHOD(jsingh10_Test6) {			//Test iterator on first element
			myvector<int> V(10);

			V.push_back(4);
			V.push_back(3);
			auto it = V.begin();
			Assert::IsTrue(*it == 4);
		}

		TEST_METHOD(jsingh10_Test7) {			//test iterator++
			myvector<int> V(10);

			V.push_back(4);
			V.push_back(3);
			auto it = V.begin();
      ++it;
			Assert::IsTrue(*it == 3);
		}

		TEST_METHOD(jsingh10_Test8) {			//Test iterator for end is same as front when empty
			myvector<int> V(10);
			auto it = V.begin();
			Assert::IsFalse(it != V.end());
		}

		TEST_METHOD(jsingh10_Test9) {			//Test that ++ returns the end if it exceeds array size
			myvector<int> V(10);
			V.push_back(5);
			V.push_back(6);
			V.push_back(8);

			auto it = V.begin();
			++it;
			++it;
			++it;
			Assert::IsFalse(it != V.end());
		}

		TEST_METHOD(jsingh10_Test10) {			//checks if iterator works for a foreach loop
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			//auto it = V.begin();

			int val = 0;
			for (int i : V) {
				if (i == 2) {
					val = 2;
				}
			}
			Assert::IsTrue(val == 2);
		}

		// Testing the capacity of vector with no elements 
		TEST_METHOD(jtapia23_Test1)
		{
			myvector <int> V(10);

			Assert::IsTrue(V.capacity() == 10);
		}

		// Testing the capacity of one node 
		TEST_METHOD(jtapia23_Test2)
		{
			myvector <int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		// Testing the capacity of full V 
		TEST_METHOD(jtapia23_Test3)
		{
			myvector <int> V(10);	// nodesize of 10

			Assert::IsTrue(V.capacity() == 10);

			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);
			V.push_back(1);

			Assert::IsTrue(V.capacity() == 10);
		}

		// Testing if capacity is full, create a new node 
		TEST_METHOD(jtapia23_Test4)
		{
			myvector <int> V(10);	// nodesize of 10

			Assert::IsTrue(V.capacity() == 10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			V.push_back(11);
			V.push_back(12);
			V.push_back(13);
			V.push_back(14);
			V.push_back(15);
			V.push_back(16);
			V.push_back(17);
			V.push_back(18);
			V.push_back(19);
			V.push_back(20);

			Assert::IsTrue(V.capacity() == 20);

			V.push_back(21);

			Assert::IsTrue(V.capacity() == 30);
		}

		// Testing the []operation on vector with one node 
		TEST_METHOD(jtapia23_Test5)
		{
			myvector <int> V(10);

			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			Assert::IsTrue(V[9] == 9);

		}

		// Testing the []operation on vector with two nodes 
		TEST_METHOD(jtapia23_Test6)
		{
			myvector <int> V(10);

			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			V.push_back(10);

			Assert::IsTrue(V[10] == 10);

		}

		// Testing copy works with vector of 1 node 
		TEST_METHOD(jtapia23_Test7)
		{
			myvector <int> V(10);

			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			myvector <int> W(V);

			Assert::IsTrue(W[9] == V[9]);

		}

		// Testing copy - test if W at index is value 
		TEST_METHOD(jtapia23_Test8)
		{
			myvector <int> V(10);

			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			V.push_back(10);

			myvector <int> W(V);

			Assert::IsTrue(W.operator[](10) == 10);

		}

		// Testing copy - two nodes have the same contents 
		TEST_METHOD(jtapia23_Test9)
		{
			myvector <int> V(10);

			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			V.push_back(10);

			myvector <int> W(V);

			Assert::IsTrue(W.operator[](10) == V.operator[](10));

		}


		// Testing the v.push_back 
		TEST_METHOD(jtapia23_Test10)
		{
			myvector <int> V(10);

			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			V.push_back(10);

			Assert::IsTrue(V.operator[](10) == 10);

		}



		//testing capacity
		TEST_METHOD(jtsvet2_Test1)
		{
			//pusihing 14 elements, V.capacity()
			//should return 20 as we have 2 nodes
			//each holding up to 10 elements
			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 14; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 20);
		}

		//testing push_back with more nodes, 
		//when a 3rd node needs to be created
		TEST_METHOD(jtsvet2_Test2)
		{
			//pusihing 22 elements, V.capacity()
			//should return 30
			myvector<int>  V(10);
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 22; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 30);
		}



		//testing size		  
		TEST_METHOD(jtsvet2_Test3)
		{
			//pusihing 22 elements 

			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 22; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 22);
		}

		//testing size	with 4 nodes	  
		TEST_METHOD(jtsvet2_Test4)
		{
			//pushing 44 elements 
			myvector<int>  V(10);// nodesize of 10:

			for (int i = 0; i < 44; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 44);
		}


		//testing operator []		
		TEST_METHOD(jtsvet2_Test5)
		{
			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 22; i++) {
				V.push_back(i);
			}

			//count start from 0 so V[20]
			//should return 20
			Assert::IsTrue(V.operator[](20) == 20);
		}


		//testing operator [] for general case
		TEST_METHOD(jtsvet2_Test6)
		{
			//pushing 22 elements

			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 22; i++) {
				V.push_back(i);
			}

			//count start from 0 so V[16]
			//should return 16
			Assert::IsTrue(V.operator[](16) == 16);
		}

		//testing operator [] for edge case
		TEST_METHOD(jtsvet2_Test7)
		{
			//pushing 22 elements

			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 22; i++) {
				V.push_back(i);
			}

			//count start from 0 so V[0]
			//should return 0
			Assert::IsTrue(V.operator[](0) == 0);
		}

		//testing operator [] for edge cases
		TEST_METHOD(jtsvet2_Test8)
		{
			//pushing 22 elements

			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 30; i++) {
				V.push_back(i);
			}

			//count start from 0 so V[29]
			//should return 29
			Assert::IsTrue(V.operator[](29) == 29);
		}

		//testing front/back on myvector
		TEST_METHOD(jtsvet2_Test9)
		{
			//pushing 22 elements
			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 30; i++) {
				V.push_back(i);
			}

			//count start from 0 so V[0]
			//should return 20
			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 29);
		}


		//testing operator [] to be able to verride values
		TEST_METHOD(jtsvet2_Test10)
		{
			//pushing 22 elements
			myvector<int>  V(10);// nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 30; i++) {
				V.push_back(i);
			}

			V[9] = 50;
			Assert::AreEqual(V[9], 50);
		}


		//test whether the front can also be the back 
		TEST_METHOD(jwu76_Test1)
		{
			myvector<int> V(10);

			V.push_back(1);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 1);
		}

		//test to see if the back pointer changes
		TEST_METHOD(jwu76_Test2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 2);

			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		//test for the capacity given no data
		TEST_METHOD(jwu76_Test3)
		{
			myvector<int> V(10);

			V.push_back(1);

			Assert::IsTrue(V.capacity() == 10);
		}

		//test for the capacity given data
		TEST_METHOD(jwu76_Test4)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.capacity() == 10);
		}

		////test for the ~myvector function given no data
		//TEST_METHOD(jwu76_Test5)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.~myvector();

		//	Assert::IsTrue(V.size() == 0);
		//}

		////test for the ~myvector function given data
		//TEST_METHOD(jwu76_Test6)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);
		//	V.push_back(5);
		//	V.push_back(6);
		//	V.push_back(7);
		//	V.push_back(8);
		//	V.push_back(9);
		//	V.push_back(10);
		//	V.push_back(11);
		//	V.push_back(12);
		//	V.push_back(13);
		//	V.push_back(14);
		//	V.push_back(15);
		//	V.push_back(16);
		//	V.push_back(17);
		//	V.push_back(18);
		//	V.push_back(19);
		//	V.push_back(20);
		//	V.push_back(21);
		//	V.~myvector();

		//	Assert::IsTrue(V.front() == 11);
		//	Assert::IsTrue(V.front() == 21);

		//}

		////test ~myvector and front/back at the same time
		//TEST_METHOD(jwu76_Test7)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);
		//	V.push_back(5);
		//	V.push_back(6);
		//	V.push_back(7);
		//	V.push_back(8);
		//	V.push_back(9);
		//	V.push_back(10);
		//	V.push_back(11);
		//	V.push_back(12);
		//	V.push_back(13);
		//	V.push_back(14);
		//	V.push_back(15);
		//	V.push_back(16);
		//	V.push_back(17);
		//	V.push_back(18);
		//	V.push_back(19);
		//	V.push_back(20);
		//	V.push_back(21);
		//	V.~myvector();

		//	Assert::IsTrue(V.front() == 11);
		//	Assert::IsTrue(V.back() == 21);

		//	V.~myvector();
		//	Assert::IsTrue(V.front() == 21);
		//	Assert::IsTrue(V.back() == 21);
		//}

		//simple operator test
		TEST_METHOD(jwu76_Test8)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.operator[](2);

			Assert::IsTrue(V.operator[](2) == 3);
		}

		//capacity test where the node size is smaller than the number of elements
		TEST_METHOD(jwu76_Test9)
		{
			myvector<int> V(10);

			V.push_back(2);
			V.push_back(4);
			V.push_back(6);
			V.push_back(8);
			V.push_back(10);
			V.push_back(12);
			V.push_back(14);
			V.push_back(16);
			V.push_back(18);
			V.push_back(20);
			V.push_back(22);
			V.push_back(24);

			Assert::IsTrue(V.capacity() == 20);

		}

		////test combining size, capacity, ~myvector, front and back
		//TEST_METHOD(jwu76_Test10)
		//{
		//	myvector<int> V(10);

		//	V.push_back(5);
		//	V.push_back(10);
		//	V.push_back(15);
		//	V.push_back(20);
		//	V.push_back(25);
		//	V.push_back(30);
		//	V.push_back(35);
		//	V.push_back(40);
		//	V.push_back(45);
		//	V.push_back(50);
		//	V.push_back(55);
		//	V.push_back(60);

		//	Assert::IsTrue(V.size() == 12);
		//	Assert::IsTrue(V.capacity() == 20);
		//	Assert::IsTrue(V.front() == 5);
		//	Assert::IsTrue(V.back() == 60);

		//	V.~myvector();

		//	Assert::IsTrue(V.size() == 2);
		//	Assert::IsTrue(V.capacity() == 10);
		//	Assert::IsTrue(V.front() == 55);
		//	Assert::IsTrue(V.back() == 60);
		//}

		TEST_METHOD(kcasti21_test1)
		{
			myvector<int> V(100);
			for (int i = 0; i < 1000; i++)
			{
				V.push_back(i);
				Assert::IsTrue(V.back() == i);
			}
		}
		TEST_METHOD(kcasti21_test2)
		{
			myvector<int> V(10);

			for (int i = 0; i < 100; ++i)
			{
				V.push_back(i);
				Assert::IsTrue(V.size() == i + 1);
			}
		}


		TEST_METHOD(kcasti21_test3)
		{
			int counter = 1;
			myvector<int> V(10);
			for (int i = 0; i < 100; ++i)
			{
				V.push_back(i);

				if ((i + 1) % 10 == 0)
				{
					Assert::IsTrue(V.capacity() == (10 * counter));
					counter++;
				}

			}


		}


		TEST_METHOD(kcasti21_test4)
		{
			myvector<int> V(100);

			for (int i = 0; i < 100; i++)
			{
				V.push_back(i);
				if (i % 9 == 0)
				{
					Assert::IsTrue(V[i] == i);
				}
			}
		}




		TEST_METHOD(kcasto21_test5)
		{
			myvector<int> V(2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 4);

		}



		//commenting out because i am testing 		// please do grade!!!! code will not compile without iterators being added to the .h file

		//TEST_METHOD(kcasti21_test6)
		//{
		//	myvector<int> V(10);
		//	for (int i = 0; i < 15; i++)
		//	{
		//		V.push_back(i);
		//	}

		//	auto found = std::find_if(V.begin(), V.end(),
		//		[](int x)
		//	{
		//		if (x == 2)
		//			return true;

		//		return false;
		//	});
		//	*found = 0;

		//	Assert::IsTrue(V[2] == 0);
		//}

		TEST_METHOD(kcasti21_test7)
		{
			myvector<int> v(10);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);

			auto beg = v.begin();
			auto end = v.end();

			Assert::IsTrue(*beg == v[0]);
			Assert::IsTrue(end != beg);
		}

    TEST_METHOD(kcasti21_test8)
		{
			myvector<int> V(10);
			for (int i = 0; i < 100; i++)
				V.push_back(i);
			int j = 0;
			for (auto i = V.begin(); i != V.end(); ++i)
			{
				Assert::IsTrue(*i == j);
				j++;
			}
		}

    TEST_METHOD(kcasti21_test9)
		{
      myvector<int> V(10);
				for (int i = 0; i < 10; i++)
				{
					V.push_back(i);
				}
			auto beg = V.begin();
			auto end = V.end();
			int i = 0;
			while (beg != end)
			{
				Assert::IsTrue(*beg == i);
				++beg;
				i++;
			}
		}

		TEST_METHOD(kcasti21_test10)
		{

			myvector<int> v(2);
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			Assert::IsTrue(v.front() != 3);
			Assert::IsTrue(v.front() == 1);
		}

		//simple capacity test 
		TEST_METHOD(kkrawc6_Test1)
		{
			myvector<int> V(3);

			Assert::AreEqual(3, V.capacity());

		}

		//capacity after resize test
		TEST_METHOD(kkrawc6_Test2)
		{
			myvector<int> V(3);

			Assert::AreEqual(3, V.capacity());

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::AreEqual(6, V.capacity());
		}

		//push back resize test
		//also a [] index test
		TEST_METHOD(kkrawc6_Test3)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::AreEqual(1, V[0]);
			Assert::AreEqual(2, V[1]);
			Assert::AreEqual(3, V[2]);

		}

		//simple deep copy test
		TEST_METHOD(kkrawc6_Test4)
		{
			myvector<int> V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);

			Assert::AreEqual(V[1], V2[1]);
			Assert::AreEqual(1, V2[0]);
		}

		////deconstructor test to see if delete works
		//TEST_METHOD(kkrawc6_Test5)
		//{
		//	myvector<int> V(2);

		//	V.push_back(1);
		//	V.push_back(2);

		//	delete &V;

		//	Assert::AreNotEqual(1, V[0]);
		//	Assert::AreNotEqual(1, V.front());
		//}

		//more in depth deep copy test 
		//test functionality of the deep copy 
		TEST_METHOD(kkrawc6_Test6)
		{
			myvector<int> V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);

			Assert::AreEqual(V.front(), V2.front());
			Assert::AreEqual(V.back(), V2.back());
			Assert::AreEqual(V.size(), V2.size());
			Assert::AreEqual(V.capacity(), V2.capacity());
		}

		////resize test also capacity test
		////functionality from hummel's piazza post
		//TEST_METHOD(kkrawc6_Test7)
		//{
		//	myvector<int> V(3);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V[8] = 89;

		//	Assert::AreEqual(9, V.capacity());
		//}

		//resize push back test
		TEST_METHOD(kkrawc6_Test8)
		{
			myvector<int> V(1);

			V.push_back(1);

			Assert::AreEqual(1, V[0]);

			V.push_back(2);

			Assert::AreEqual(2, V[1]);
		}

		//testing functionality of operations 
		//done through indexing 
		TEST_METHOD(kkrawc6_Test9)
		{
			myvector<int> V(2);

			V.push_back(1);

			V[0]++;

			Assert::AreEqual(2, V[0]);

			V[0]++;

			Assert::AreEqual(3, V[0]);
		}

		//testing resize of deep copy 
		TEST_METHOD(kkrawc6_Test10)
		{
			myvector<int> V(2);

			V.push_back(1);
			V.push_back(2);

			myvector<int> V2(V);

			V2.push_back(3);

			Assert::AreEqual(3, V2.size());
			Assert::AreEqual(4, V2.capacity());
		}

		TEST_METHOD(kkurzy4_Test1)
		{
			myvector<int> V(2);  // nodesize of 2

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);


			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(kkurzy4_Test2)
		{
			myvector<int> V(10);  //nodesize of 10

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 25; ++i) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 25);
			Assert::IsTrue(V.capacity() == 30);
		}

		TEST_METHOD(kkurzy4_Test3)
		{
			myvector<int> V(10);  // nodesize of 10

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 10; ++i) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 10);
		}

		TEST_METHOD(kkurzy4_Test4)
		{
			myvector<int> V(10);

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 100; ++i) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 100);
			Assert::IsTrue(V.capacity() == 100);

		}

		//TEST_METHOD(kkurzy4_Test5)
		//{
		//	myvector<int> V(10);

		//	Assert::IsTrue(V.size() == 0);

		//	for (int i = 0; i < 100; ++i) {
		//		V.push_back(i);
		//	}

		//	V.~myvector();

		//	Assert::IsTrue(V.size() == 0);
		//	Assert::IsTrue(V.capacity() == 0);

		//}

		TEST_METHOD(kkurzy4_Test6)
		{
			myvector<int> V(10);

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 100; ++i) {
				V.push_back(i);
			}

			Assert::IsTrue(V[0] == 0);

			Assert::IsTrue(V.size() == 100);
			Assert::IsTrue(V.capacity() == 100);

		}

		//TEST_METHOD(kkurzy4_Test7)
		//{
		//	myvector<int> V(10);

		//	Assert::IsTrue(V.size() == 0);

		//	for (int i = 0; i < 100; ++i) {
		//		V.push_back(i);
		//	}

		//	Assert::IsTrue(V.operator[](2));

		//	Assert::IsTrue(V.size() == 100);
		//	Assert::IsTrue(V.capacity() == 100);

		//}

		//TEST_METHOD(kkurzy4_Test8)
		//{
		//	myvector<int> V(10000);

		//	Assert::IsTrue(V.size() == 0);

		//	for (int i = 0; i < 1000000; ++i) {
		//		V.push_back(i);
		//	}

		//	Assert::IsTrue(V[2] == 3);

		//	Assert::IsTrue(V.size() == 100000);
		//	Assert::IsTrue(V.capacity() == 100000);

		//}

		TEST_METHOD(kkurzy4_Test9)
		{
			myvector<int> V(10);

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 100; ++i) {
				V.push_back(i);
			}

			V.push_back(101);

			Assert::IsTrue(V[100]==101);

			Assert::IsTrue(V.size() == 101);
			Assert::IsTrue(V.capacity() == 110);

		}

		TEST_METHOD(kkurzy4_Test10)
		{
			myvector<int> V(10);

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 100; ++i) {
				V.push_back(i);
			}

			Assert::IsTrue(V[10] == 10);

			Assert::IsTrue(V.size() == 100);
			Assert::IsTrue(V.capacity() == 100);

		}


		// kpate236_Capacity1 deals with testing the capacity function that
		//was implemented, Checking Capacity when we only have one Node
		//

		TEST_METHOD(kpate236_Capacity1) {
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(V.capacity() == 10);
			// TODO: Your test code here
		}

		// kpate236_Capacity2 deals with testing the capacity function that
		//was implemented, Checking Capacity when we only have multiple Node
		//

		TEST_METHOD(kpate236_Capacity2) {
			myvector<int> V(10);
			for (int i = 0; i < 30; i++)
				V.push_back(i);
			Assert::IsTrue(V.capacity() == 30);
			// TODO: Your test code here
		}

		// kpate236_Operator1 deals with testing the Operator function that
		//was implemented,Checking Operator by pushing a value and checking
		//if that value is there 

		TEST_METHOD(kpate236_Operator1) {

			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(V.operator[](1) == 2);
			// TODO: Your test code here
		}

		// kpate236_Operator2 deals with testing the Operator function that
		//was implemented,Checking Operator by testing the UPPER Boundary Values
		//when we have multiple Nodes


		TEST_METHOD(kpate236_Operator2) {

			myvector<int> V(10);
			for (int i = 0; i < 30; i++)
				V.push_back(i);
			Assert::IsTrue(V[29] == 29);
			// TODO: Your test code here
		}

		// kpate236_Operator2 deals with testing the Operator function that
		//was implemented,Checking Operator by testing the LOWER Boundary Values
		//when we have multiple Nodes


		TEST_METHOD(kpate236_Operator3) {

			myvector<int> V(10);
			for (int i = 0; i < 30; i++)
				V.push_back(i);
			Assert::IsTrue(V[20] == 20);
			// TODO: Your test code here
		}

		// kpate236_Operator2 deals with testing the Operator function that
		//was implemented,Checking Operator by testing the UPPER Boundary Values
		//when we have Single Node


		//TEST_METHOD(kpate236_Operator4) {

		//	myvector<int> V(10);
		//	for (int i = 0; i <= 12; i++)
		//		V.push_back(i);
		//	Assert::IsTrue(V.operator[](10) == 9);
		//	// TODO: Your test code here
		//}

		// kpate236_PushBack1 deals with testing the back function that
		//was implemented,Checking back by testing back value if Multiple Nodes present


		TEST_METHOD(kpate236_PushBack1) {

			myvector<int> V(10);
			for (int i = 0; i <= 12; i++)
				V.push_back(i);
			Assert::IsTrue(V.back() == 12);
			// TODO: Your test code here
		}

		// kpate236_PushBack2 deals with testing the back function that
		//was implemented,Checking back by testing back value if Single Node present


		TEST_METHOD(kpate236_PushBack2) {

			myvector<int> V(10);
			V.push_back(0);
			Assert::IsTrue(V.front() == V.back());
			// TODO: Your test code here
		}

		// kpate236_Size1 deals with testing the size function that
		//was implemented,Checking by testing back value if Multiple Nodes present


		TEST_METHOD(kpate236_Size1) {

			myvector<int> V(10);
			for (int i = 0; i <= 12; i++)
				V.push_back(i);
			Assert::IsTrue(V.size() == 13);
			// TODO: Your test code here
		}

		// kpate236_Size2 deals with testing the size function that
		//was implemented,Checking by testing back value if Single Node present

		TEST_METHOD(kpate236_Size2) {

			myvector<int> V(10);
			V.push_back(0);
			Assert::IsTrue(V.size() == 1);
			// TODO: Your test code here
		}

		// kpate236_Front1 deals with testing the front function that
		//was implemented,Checking by testing front value if Multiple Nodes
		//present and one index 0 value was changed Check if front accepted the change.


		TEST_METHOD(kpate236_Front1) {

			myvector<int> V(10);
			for (int i = 0; i <= 12; i++)
				V.push_back(i);
			V.operator[](0) = 111;
			Assert::IsTrue(V.front() == 111);
			// TODO: Your test code here
		}
		// kpate236_Back1 deals with testing the front and back function that
		//was implemented,Checking size by testing front and back if only 1 value
		//was


		TEST_METHOD(kpate236_Back1) {

			myvector<int> V(10);
			V.push_back(0);
			Assert::IsTrue(V.front() == V.back());
			// TODO: Your test code here
		}

		//TEST_METHOD(ktsao5_Test1)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	Assert::IsTrue(V.capacity() == 10);

		//	V.push_back(2);
		//	V.push_back(3);
		//	Assert::IsTrue(V.capacity() == 30);
		//}

		TEST_METHOD(ktsao5_Test2)
		{
			myvector<int> V(10);

			V.push_back(2);
			V.push_back(3);
			V.push_back(1);

			Assert::IsTrue(V.front() == 2);
			Assert::IsTrue(V.back() == 1);

			V.push_back(4);
			Assert::IsTrue(V.back() == 4);
		}

		//TEST_METHOD(ktsao5_Test3)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.pop_back();

		//	Assert::IsTrue(V.back() == 1);
		//}

		//TEST_METHOD(ktsao5_Test4)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.pop_back();
		//	V.push_back(3);

		//	Assert::IsTrue(V.size() == 20);
		//	Assert::IsTrue(V.back() == 3);
		//}

		//TEST_METHOD(ktsao5_Test5)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);

		//	myvector<int> V2 = V;

		//	Assert::IsTrue(V2.front() == 1);
		//	Assert::IsTrue(V2.size() == 20);
		//}

		//TEST_METHOD(ktsao5_Test6)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	myvector<int> V2 = V;

		//	Assert::IsTrue(V.begin(), V.end(), V2.begin());
		//}

		//TEST_METHOD(ktsao5_Test7)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);

		//	myvector<int> V2 = V;
		//	V2.pop_back();

		//	Assert::IsTrue(V.back() == 2);
		//	Assert::IsTrue(V2.back() == 1);
		//}

		//TEST_METHOD(ktsao5_Test8)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.pop_back();

		//	Assert::IsFalse(V.front() == 1);
		//}

		//TEST_METHOD(ktsao5_Test9)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);

		//	Assert::IsTrue(V.begin() == 1);
		//	Assert::IsTrue(V.end() == 2);
		//}

		//TEST_METHOD(ktsao5_Test10)
		//{
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(V.operator[](1) == 2);
		//}


		TEST_METHOD(lherna44_Test_Capacity)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(lherna44_Test_operator)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			Assert::IsTrue(V[4] == 5);
			Assert::IsTrue(V[10] == 11);
		}

		TEST_METHOD(lherna44_Test_push_back)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);
			V.push_back(13);
			V.push_back(14);
			V.push_back(15);
			V.push_back(16);
			V.push_back(17);
			V.push_back(18);
			V.push_back(19);
			V.push_back(20);
			V.push_back(21);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[9] == 10);
			Assert::IsTrue(V[10] == 11);
			Assert::IsTrue(V[19] == 20);
			Assert::IsTrue(V[20] == 21);
		}

		// Test if it does shallow copy
		TEST_METHOD(lherna44_Test_copy)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			myvector<int> V2(V);

			Assert::IsTrue(V2[4] == 5);
			Assert::IsTrue(V2[10] == 11);
		}

		// Test deep copy
		TEST_METHOD(lherna44_Test_deepCopy)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			myvector<int> V2(V);

			V[10] = 13;

			Assert::IsTrue(V[10] == 13);
			Assert::IsTrue(V2[10] == 11);
		}

		TEST_METHOD(lherna44_Test_copy_Push_back)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			myvector<int> V2(V);

			V2.push_back(11);
			V2.push_back(12);

			Assert::IsTrue(V2[10] == 11);
			Assert::IsTrue(V2[11] == 12);
		}

		TEST_METHOD(lherna44_Test_copy_size)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			myvector<int> V2(V);

			V2.push_back(11);
			V2.push_back(12);

			Assert::IsTrue(V2.size() == 12);
			Assert::IsTrue(V.size() == 10);
		}

		TEST_METHOD(lherna44_Test_begin)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			auto iter = V.begin();
			Assert::IsTrue(*iter == 1);
		}

		//TEST_METHOD(lherna44_Test_end)
		//{
		//	myvector<int>  V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);
		//	V.push_back(5);
		//	V.push_back(6);
		//	V.push_back(7);
		//	V.push_back(8);
		//	V.push_back(9);
		//	V.push_back(10);

		//	auto iter = V.end();
		//	Assert::IsTrue(*(iter - 1) == 10);
		//}

		TEST_METHOD(lherna44_Test_copy_capacity)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			myvector<int> V2(V);

			V2.push_back(11);
			V2.push_back(12);

			Assert::IsTrue(V2.capacity() == 20);
			Assert::IsTrue(V.capacity() == 10);
		}



		TEST_METHOD(lptean2_Test1)
		{
			myvector<int> V(10);
			//std::vector<int> V(10);

			int i;
			for (i = 0; i < 12; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.back() == 11);
		}

		TEST_METHOD(lptean2_Test2)
		{
			myvector<int> V(24);
			//std::vector<int> V(24);
			Assert::IsTrue(V.capacity() == 24);

		}

		TEST_METHOD(lptean2_Test3)
		{
			myvector<int> V(10);
			//std::vector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[1] == 2);
		}

		TEST_METHOD(lptean2_Test4)
		{
			myvector<int> V(10);
			//std::vector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(V);
			//std::vector<int> V2(V);

			Assert::IsTrue(V2.front() == 1);
			Assert::IsTrue(V2.back() == 3);
		}

		TEST_METHOD(lptean2_Test5)
		{
			myvector<int> V(10);
			//std::vector<int> V(10);

			int i;
			for (i = 0; i < 11; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 20);
		}

		TEST_METHOD(lptean2_Test6)
		{
			//std::vector<int> V(10);
			myvector<int> V(10);

			int i;
			for (i = 0; i < 11; i++)
			{
				V.push_back(i);
				Assert::IsTrue(V.back() == i);
			}
		}
		//TEST_METHOD(lptean2_Test7)
		//{
		//	myvector<int> V(10);
		//	//std::vector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	myvector<int> V2(V);
		//	//std::vector<int> V2(V);

		//	Assert::IsTrue(V2[4] == NULL);

		//}

		TEST_METHOD(lptean2_Test8)
		{
			myvector<int> V(12);
			//std::vector<int> V(12);

			int i;
			for (i = 0; i < 15; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 24);
		}

		TEST_METHOD(lptean2_Test9)
		{
			myvector<int> V(10);
			//std::vector<int> V(10);

			int i;
			for (i = 0; i < 11; i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.front() == 0);

			V[0] = V[1];

			Assert::IsTrue(V.front() == 1);

		}
		//TEST_METHOD(lptean2_Test10)
		//{
		//	myvector<int> V(10);
		//	//std::vector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	myvector<int> V2(V);
		//	//std::vector<int> V2(V);

		//	Assert::IsTrue(V2[-4] == NULL);

		//}




		TEST_METHOD(lzhang44_Test1)
		{
			myvector<int> V(10);  // nodesize of 10:

			for (int i = 1; i < 23; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 22);
		}


		TEST_METHOD(lzhang44_Test2)
		{
			myvector<int> V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);
			for (int i = 1; i < 23; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == 22);
		}


		// tests that it can add more nodes on
		TEST_METHOD(lzhang44_Test3)
		{
			myvector<int> V(10);  // nodesize of 10:

			for (int i = 1; i < 22; i++) {
				V.push_back(i);
			}


			Assert::IsTrue(V.back() == 21);
		}


		// test [] operator for first node
		TEST_METHOD(lzhang44_Test5)
		{
			myvector<int> V(10);  // nodesize of 10:

			for (int i = 0; i < 5; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V[0] == 0);
			Assert::IsTrue(V[3] == 3);
			Assert::IsTrue(V[4] == 4);
		}


		// test []operator for second and third node
		TEST_METHOD(lzhang44_Test6)
		{
			myvector<int> V(10);  // nodesize of 10:

			for (int i = 0; i < 27; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V[11] == 11);
			Assert::IsTrue(V[19] == 19);
			Assert::IsTrue(V[23] == 23);
		}

		// copy constructor
		TEST_METHOD(lzhang44_Test9)
		{
			myvector<int> V(10);  // nodesize of 10:

			for (int i = 1; i <= 15; i++) {
				V.push_back(i);
			}

			myvector<int> V2 = V;

			Assert::IsTrue(V2.front() == 1);
			Assert::IsTrue(V2.back() == 15);
		}


		// test begin and end
		TEST_METHOD(lzhang44_Test10)
		{
			myvector<int> V(10);  // nodesize of 10:

			for (int i = 1; i < 15; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(*(V.begin()) == 1);



		}

		// Test putting 3 chars in vec w/ node size 2 
		TEST_METHOD(manclls2_Test1) {
			myvector<char> V(2); // nodesize of 2:

			V.push_back('a');
			V.push_back('b');
			V.push_back('c');

			Assert::IsTrue(V.size() == 3);

			Assert::IsTrue(V.front() == 'a');
			Assert::IsTrue(V.back() == 'c');
		}

		// Test for each loop with node zize 10 and 15 ints 
		TEST_METHOD(manclls2_Test2) {
			myvector<int> V(10); // node size of 10:

			for (int i = 0; i < 15; i++)
				V.push_back(i);

			Assert::IsTrue(V.size() == 15);

			int i = 0;
			for (auto c : V) {
				Assert::IsTrue(c == i);
				i++;
			}

			Assert::IsTrue(i == 15);
		}

		// Test [], node size 5, 7 ints 
		TEST_METHOD(manclls2_Test3) {
			myvector<int> V(5);

			for (int i = 0; i < 7; i++)
				V.push_back(i);

			for (int i = 0; i < 7; i++)
				Assert::IsTrue(V[i] == i);
		}

		// Test ++, *; node size 1, 4 chars 
		TEST_METHOD(manclls2_Test4) {
			myvector<char> V(1);

			V.push_back('a');
			V.push_back('b');
			V.push_back('c');
			V.push_back('z');

			auto iter = V.begin();

			Assert::IsTrue(*iter == 'a');
			++iter;
			Assert::IsTrue(*iter == 'b');
			++iter;
			Assert::IsTrue(*iter == 'c');
			++iter;
			Assert::IsTrue(*iter == 'z');
			++iter;
			Assert::IsFalse(iter != V.end());
		}

		// Test !=; node size 5, 2 strings 
		TEST_METHOD(manclls2_Test5) {
			myvector<string> V(5);

			V.push_back("Zelda");
			V.push_back("Link");

			Assert::IsTrue(V.begin() != V.end());
			Assert::IsFalse(V.begin() != V.begin());
			Assert::IsFalse(V.end() != V.end());
		}

		// Test begin, end, ++, 
		TEST_METHOD(manclls2_Test6) {
			myvector<int> V(20); // node size of 10:

			for (int i = 0; i < 15; i++)
				V.push_back(i);

			Assert::IsTrue(V.size() == 15);

			int i = 0;
			for (auto index = V.begin(); index != V.end(); ++index) {

				Assert::IsTrue(*index == i);
				i++;
			}

			Assert::IsTrue(i == 15);
		}

		// Test copy 
		TEST_METHOD(manclls2_Test7) {
			myvector<int> V(5);

			for (int i = 0; i < 14; i++)
				V.push_back(i);

			auto V2 = V;

			for (int i = 0; i < 14; i++)
				Assert::IsTrue(V[i] == V2[i]);

			V2.push_back(-1);
			Assert::IsTrue(V.size() == 14);
			Assert::IsTrue(V2.size() == 15);
		}

		// Test copy of empty vector 
		TEST_METHOD(manclls2_Test8) {
			myvector<bool> V(5);

			auto V2 = V;

			V.push_back(true);
			V.push_back(false);

			Assert::IsTrue(V2.size() == 0);
			Assert::IsTrue(V.size() == 2);
		}

		//Test copy (harder) 
		TEST_METHOD(manclls2_Test9) {
			myvector<int> V1(5);

			for (int i = 0; i < 17; i++)
				V1.push_back(i);

			auto V2 = V1;

			for (int i = 17; i < 32; i++)
				V2.push_back(i);

			int i = 0;
			for (auto v : V1)
				Assert::IsTrue(v == i++);

			Assert::IsTrue(i == 17);

			i = 0;
			for (auto v : V2)
				Assert::IsTrue(v == i++);

			Assert::IsTrue(i == 32);
		}

		TEST_METHOD(mburke24_Test1)		// Test empty vector and vector of size 1
		{
			myvector<int> V(10);	// nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);

			Assert::IsTrue(V.size() == 1);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 1);
		}
		TEST_METHOD(mburke24_Test2)	// Test vector capacty
		{
			myvector<int> V1(10);
			myvector<int> V2(20);
			myvector<int> V3(30);

			V3.push_back(1);

			Assert::IsTrue(V1.capacity() == 10);
			Assert::IsTrue(V2.capacity() == 20);
			Assert::IsTrue(V3.capacity() == 30);
		}
		TEST_METHOD(mburke24_Test3)	// Test adding past capacity of 1 node
		{
			myvector<int> V1(10);
			myvector<int> V2(20);
			Assert::IsTrue(V1.capacity() == 10);
			Assert::IsTrue(V2.capacity() == 20);

			for (int i = 0; i < 15; i++)
			{
				V1.push_back(i);
				V2.push_back(i);
			}

			Assert::IsTrue(V1.back() == 14);
			Assert::IsTrue(V1.capacity() == 20);
			Assert::IsTrue(V2.back() == 14);
			Assert::IsTrue(V2.capacity() == 20);
		}

		TEST_METHOD(mburke24_Test6)		// Tests making a really big vector
		{
			myvector <int> V(10);
			for (int i = 0; i < 100001; ++i)
				V.push_back(i);
			Assert::IsTrue(V.size() == 100001);
			Assert::IsTrue(V.capacity() == 100010);
		}
		TEST_METHOD(mburke24_Test7)		// Tests data access;
		{
			myvector <int> V(10);
			V.push_back(5);

			Assert::IsTrue(V[0] == 5);
		}
		TEST_METHOD(mburke24_Test8)		// Tests data preservation across nodes
		{
			myvector <int> V(10);
			for (int i = 0; i < 100; ++i)
				V.push_back(i);
			for (int i = 0; i < 100; ++i)
				Assert::IsTrue(V[i] == i);
		}

    TEST_METHOD(mburke24_Test9)		// Tests copy constructor
		{
			myvector <int> V1(10);
			V1.push_back(1);

			myvector <int> V2(V1);
			V2.push_back(2);

			Assert::IsTrue(V2.size() == V1.size()+1);
			Assert::IsTrue(V2.capacity() == V1.capacity());

			Assert::IsTrue(V2[0] == 1);
			Assert::IsTrue(V2[1] == 2);

		}

		TEST_METHOD(mburke24_Test10)	// Tests different data types
		{
			myvector <char> V1(10);
			myvector <double> V2(10);
			myvector <bool> V3(10);

			V1.push_back('A');
			V2.push_back(1.5);
			V3.push_back(true);

			Assert::IsTrue(V1[0] == 'A');
			Assert::IsTrue(V2[0] == 1.5);
			Assert::IsTrue(V3[0] == true);
		}





		//Test operator !=
		TEST_METHOD(mchaud24_operatorNotequal) {
			myvector<double>	V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i + 3.14);
			}
			Assert::IsTrue((V.front())++ != 5.14);
		}

		//Test operator++
		TEST_METHOD(mchaud24_operatorAdd) {
			myvector<double>	V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i + 3.14);
			}

			Assert::IsTrue(abs(*(++(V.begin())) - 4.14) < 0.0001);
		}

		//Test operator []
		TEST_METHOD(mchaud24_operator) {
			myvector<double>	V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i + 3.14);
			}
			Assert::IsTrue(abs(V[4]-7.14) < 0.0001);
		}

		//Test push_back
		TEST_METHOD(mchaud24_TestPushBack) {
			myvector<int>	V(10);	//nodesize of 10;
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);		V.push_back(3);		V.push_back(5);
			V.push_back(11);	V.push_back(13);	V.push_back(15);
			V.push_back(21);	V.push_back(23);	V.push_back(25);
			Assert::IsTrue(V.capacity() == 10);

			V.push_back(7);
			Assert::IsTrue(V.capacity() == 10);
			Assert::IsFalse(V.capacity() == 20);
			V.push_back(17);	V.push_back(27);
			Assert::IsTrue(V.capacity() == 20);
		}

		//Test begin()  && operator*
		TEST_METHOD(mchaud24_begin) {
			myvector<int>	V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(100 - (2 * i));
			}
			Assert::IsTrue(*(V.begin()) == 100);
		}

		////Test end()   && operator*
		//TEST_METHOD(mchaud24_end) {
		//	myvector<int>	V(10);

		//	for (int i = 0; i < 10; i++) {
		//		V.push_back(100 - (2 * i));
		//		Assert::IsFalse(*(V.end()) == i);
		//	}
		//	Assert::IsTrue(*(V.end()) == 82);
		//}

		//Test copy constructor
		TEST_METHOD(mchaud24_CopyConstructor) {
			myvector<int>	V(10);	//nodesize of 10;
			V.push_back(1);		V.push_back(3);		V.push_back(5);		V.push_back(7);
			V.push_back(21);	V.push_back(23);	V.push_back(25);	V.push_back(27);
			Assert::IsTrue(V.capacity() == 10);

			myvector<int>	CP(V);
			Assert::IsTrue(CP.capacity() == 10);
		}

		//Test capacity of 1 Node
		TEST_METHOD(mchaud24_1CapacityONE1)
		{
			myvector<int>	V(10);	//nodesize of 10;

			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(V.size() == 2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 10);
		}

		//Test capacity of 1 Node
		TEST_METHOD(mchaud24_2CapacityONE2)
		{
			myvector<char>	V(7);	//nodesize of 7;
			myvector<char>	V2;
			Assert::IsTrue(V.capacity() == 7);
			V.push_back('a');
			V.push_back('b');
			V.push_back('c');
			Assert::IsTrue(V2.capacity() == 100);
		}

		//Test capcity of vector
		//Take this out if you do not have a function
		//	for finding the capacity of the vector
		TEST_METHOD(mchaud24_TestCapacityVector)
		{
			myvector<double>	V(77);	//nodesize of 10;

			Assert::IsTrue(V.capacity() == 77);

			for (int i = 0; i < 77; i++) {
				V.push_back(i);
				if (i > 15 && i < 20) {
					Assert::IsTrue(V.capacity() == 77);
				}
			}
			Assert::IsTrue(V.capacity() == 77);
		}

		////Test Front and Back
		//TEST_METHOD(mchaud24_FrontBack2)
		//{
		//	myvector<int>	V;
		//	Assert::IsFalse(V.front() == -1);
		//	Assert::IsFalse(V.back() == 1);
		//}

		//Test Front and Back
		TEST_METHOD(mchaud24_FrontBack)
		{
			myvector<int>	V1;
			for (int i = 0; i < 99; i++) {
				V1.push_back(i);
			}

			Assert::IsTrue(V1.front() == 0);
			Assert::IsTrue(V1.back() == 98);


			myvector<char>	V;
			for (int i = 0; i < 25; i++) {
				V.push_back(i + 'a');
				Assert::IsTrue(V.front() == 'a');
			}
			Assert::IsTrue(V.front() == 'a');
			Assert::IsTrue(V.back() == 'y');
		}

		//Test Size (aka 		
		TEST_METHOD(mchaud24_Size)
		{
			myvector<int>	V(10);	//nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 99; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 99);
		}





		TEST_METHOD(mflore45_Test1)
		{
			myvector<int> V(10);

			V.push_back(1);
			Assert::IsTrue(V.front() == 1);
			V.push_back(2);
			Assert::IsTrue(V[1] == 2);
			V.push_back(3);
			Assert::IsTrue(V[2] == 3);

		}

		TEST_METHOD(mflore45_Test2)
		{
			myvector<int> V(10);

			Assert::IsTrue(V.capacity() == 10);

		}

		TEST_METHOD(mflore45_Test3)
		{
			myvector<int> V(10);

			for (int i = 0; i < 10; i++)
				V.push_back(i);
			Assert::IsTrue(V.size() == 10);
		}

		TEST_METHOD(mflore45_Test4)
		{
			myvector<int> V(5);

			for (int i = 0; i < 5; i++)
				V.push_back(i);
			V.push_back(0);
			Assert::IsTrue(V.size() == 6);
			Assert::IsTrue(V[5] == 0);
		}

		//TEST_METHOD(mflore45_Test5)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);

		//	Assert::IsTrue(V.operator[] == V[0]);

		//}

		//TEST_METHOD(mflore45_Test6)
		//{
		//	myvector<int> V(10);
		//	V.push_back(2.04);
		//	Assert::IsTrue(V.front() == 2.04);

		//}

		TEST_METHOD(mflore45_Test7)
		{
			myvector<int> V(5);
			myvector<int> V2(V);

			Assert::IsTrue(V.capacity() == V2.capacity());
		}

		TEST_METHOD(mflore45_Test8)
		{
			myvector<int> V(5);

			for (int i = 0; i < 5; i++)
				V.push_back(i);
			myvector<int>V2(V);
			for (int j = 0; j < 5; j++)
				Assert::IsTrue(V[j] == V2[j]);
		}

		TEST_METHOD(mflore45_Test9)
		{
			myvector<int> V;

			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			Assert::IsTrue(V.size() == 1);
			V.push_back(2);
			Assert::IsTrue(V.size() == 2);
		}

		//TEST_METHOD(mflore45_Test10)
		//{
		//	myvector<int> V;

		//	Assert::IsTrue(V.front() == 0);
		//	Assert::IsTrue(V.back() == 0);
		//	Assert::IsTrue(V.size() == 0);
		//}



		TEST_METHOD(mkhan228_Test1)
		{
			// Test the capacity function of myvector

			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(mkhan228_Test2)
		{
			// Test capacity function after new node allocation

			myvector<bool> V(2); // nodesize of 2:
			Assert::IsTrue(V.size() == 0);
			V.push_back(true);
			V.push_back(false);
			V.push_back(true);
			Assert::IsTrue(V.capacity() == 4);
			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(mkhan228_Test3)
		{
			//Test the pushback function after new node allocation

			myvector<int> V(4); // nodesize of 4:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			Assert::IsTrue(V.capacity() == 8);
			Assert::IsTrue(V.size() == 7);
		}

		TEST_METHOD(mkhan228_Test4)
		{
			// Test the [] operator when overloaded

			myvector<int> V(3); // nodesize of 3:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(V[1] == 2);
		}

		TEST_METHOD(mkhan228_Test5)
		{
			// Test the [] operator after new node allocation

			myvector<bool> V(3); // nodesize of 3:
			Assert::IsTrue(V.size() == 0);
			V.push_back(true);
			V.push_back(false);
			V.push_back(false);
			V.push_back(true);
			Assert::IsTrue(V[3] == true);
			Assert::IsTrue(V[1] == false);
		}

		TEST_METHOD(mkhan228_Test6)
		{
			// Test the copy constructor

			myvector<double> V(5); // nodesize of 5:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1.0);
			V.push_back(2.0);
			V.push_back(3.0);
			V.push_back(4.5);
			V.push_back(13.5);
			V.push_back(19.6);
			V.push_back(7.0);

			myvector<double> W(V);	//New myvector "W" initialized
			Assert::IsTrue(W[0] == 1.0);
			Assert::IsTrue(W[4] == 13.5);
			Assert::IsTrue(W[6] == 7.0);
			Assert::IsTrue(W.capacity() == 10);
			Assert::IsTrue(W.size() == 7);
			W.push_back(5.5);
			Assert::IsTrue(W.capacity() == 10);
			Assert::IsTrue(W.size() == 8);
			Assert::IsTrue(W[7] == 5.5);
		}

		TEST_METHOD(mkhan228_Test7)
		{
			// Test iterator begin and overloaded * operator for the iterator

			myvector<float> V(2); // nodesize of 2:
			Assert::IsTrue(V.size() == 0);
      //
      // shoudl be able to call on an empty vector:
      //
			auto it = V.begin();
      auto it2 = V.end();

			V.push_back(1);
      it = V.begin();  // now ptr should be valid:
      V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.size() == 5);
			Assert::IsTrue(V.capacity() == 6);

			Assert::IsTrue(*it == 1);
		}

		TEST_METHOD(mkhan228_Test8)
		{
			// Test iterator on empty myvector 

			myvector<int> V(4); // nodesize of 4:
			Assert::IsTrue(V.size() == 0);
			Assert::IsTrue(V.capacity() == 4);
			int temp = 0;
			for (auto e : V)
			{
				temp = 3;
			}
			Assert::IsTrue(temp == 0);
		}


		TEST_METHOD(mkhan228_Test9)
		{

			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.size() == 5);
			Assert::IsTrue(V.capacity() == 10);
			int temp = 0;

			for (auto e : V)
			{
				temp = e;
			}
			Assert::IsTrue(temp == 5);	//The last element in this vector is 5
		}


		TEST_METHOD(mkhan228_Test10)

		{

			myvector<int> V(2); // nodesize of 10:
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			Assert::IsTrue(V.size() == 5);
			Assert::IsTrue(V.capacity() == 6);
			int temp = 0;
			int count = 1;
			for (auto e : V)
			{
				temp = e;
				Assert::IsTrue(e == count);
				count++;
			}
			Assert::IsTrue(temp == 5);	//The last element in this vector is 5
		}



		//**DONE**
		//test if copy constructor is correct
		TEST_METHOD(mkrumw2_Test1)
		{
			// TODO: Your test code here
			myvector<int> V(10);
			V.push_back(1);
			myvector<int> V2(V);
			V.push_back(2);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 2);
			Assert::IsTrue(V2.front() == 1);
			Assert::IsTrue(V2.back() == 1);
		}

		//test to see if operator method works properly
		//**DONE**
		TEST_METHOD(mkrumw2_Test2)
		{
			myvector<int> V(10);
			V.push_back(1);
			V[0] = 2;
			Assert::IsTrue(V.back() == 2);
		}

		//**DONE**
		//test capacity of node
		TEST_METHOD(mkrumw2_Test3)
		{
			myvector<int> V(10);//declares node size of 100

			for (int i = 0; i < 10; i++)
				V.push_back(i);
			Assert::IsTrue(V.capacity() == 10);
		}

		//**DONE**
		//tests to see if vector will expand when capacity is reached
		TEST_METHOD(mkrumw2_Test4)
		{
			myvector<int> V(10);

			for (int i = 0; i < V.capacity(); i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(11);
			Assert::IsTrue(V.back() == 11);
		}

		//**DONE**
		//test to see if capacity still works with more than one node
		TEST_METHOD(mkrumw2_Test5)
		{
			myvector<int> V(10);

			for (int i = 0; i < V.capacity(); i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(11);
			Assert::IsTrue(V.capacity() == 20);
		}

		//**DONE**
		//Test to see if size still works with more than node
		TEST_METHOD(mkrumw2_Test6)
		{
			myvector<int> V(10);

			for (int i = 0; i < V.capacity(); i++)
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 10);
			V.push_back(11);
			Assert::IsTrue(V.size() == 11);
		}

		//**DONE**
		////Test to see if operator still works with more than one node
		//TEST_METHOD(mkrumw2_Test7)
		//{
		//	myvector<int> V(10);
		//	for (int i = 0; i < V.capacity(); i++)
		//	{
		//		V.push_back(i);
		//	}
		//	V.push_back(11);
		//	V[11] = 15;
		//	Assert::IsTrue(V.back() == 15);
		//}

		//**DONE**
		//Tests to see if copy constructor still works with more than one node
		TEST_METHOD(mkrumw2_Test8)
		{
			myvector<int> V(10);
			for (int i = 0; i < V.capacity(); i++)
			{
				V.push_back(i);
			}
			V.push_back(10);
			myvector<int> V2(V);
			V.push_back(11);
			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 11);
			Assert::IsTrue(V2.front() == 0);
			Assert::IsTrue(V2.back() == 10);
		}

		TEST_METHOD(mkrumw2_Test9)
		{
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(*(V.begin()) == V.front());
		}

		//TEST_METHOD(mkrumw2_Test10)
		//{
		//	myvector<int> V(10);
		//	V.push_back(1);
		//	V.push_back(2);

		//	Assert::IsTrue(*(V.end() - 1) == V.back());
		//}




		//Tests if push_back function works when a node is full
		TEST_METHOD(mlema4_test1)
		{
			myvector<int> V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			Assert::IsTrue(V.size() == 4);
			//Assert::IsTrue(V[3] == 4);

		}

		//checks to see if last element has correct value when adding a new node
		TEST_METHOD(mlema4_test2)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);

			Assert::AreEqual(V.back(), 6);


		}
		//Tests if operator function works
		TEST_METHOD(mlema4_test3)
		{
			myvector<int> V(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
		}

		//Tets if operator function works after new node is created
		TEST_METHOD(mlema4_test4)
		{
			myvector<int> V(4);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			Assert::IsTrue(V[3] == 4);
		}

		//Checks if size gets updated after a new node is created
		TEST_METHOD(mlema4_test5)
		{
			myvector<int> V(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.size() == 4);
		}

		//Tests if capacity return correct value once a new node is added
		TEST_METHOD(mlema4_test6)
		{
			myvector<int> V(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			Assert::IsTrue(V.capacity() == 6);

		}

		//Tests whether the size of copy is correct;
		TEST_METHOD(mlema4_test7)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V1 = V;

			Assert::AreEqual(V1.size(), 3);

		}

		//Tests if capacity is correct in new copied vector;
		TEST_METHOD(mlema4_test8)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V1 = V;

			Assert::AreEqual(V1.capacity(), 5);
		}

		//Checks if the  elements are copied 
		TEST_METHOD(mlema4_test9)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V1 = V;

			Assert::AreEqual(V1[0], 1);
			Assert::AreEqual(V1[1], 2);
			Assert::AreEqual(V1[2], 3);
		}

		//Checks if all elements from different nodes are copied
		TEST_METHOD(mlema4_test10)
		{
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			myvector<int> V1 = V;

			Assert::AreEqual(V1[5], 6);
			Assert::AreEqual(V1[6], 7);
			Assert::AreEqual(V1[7], 8);

		}

		//Same test as test9 but with more nodes
		TEST_METHOD(mlema4_test11)
		{
			myvector<int> V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			myvector<int> V1 = V;

			Assert::AreEqual(V1[2], 3);
			Assert::AreEqual(V1[3], 4);
			Assert::AreEqual(V1[4], 5);
			Assert::AreEqual(V1[5], 6);
			Assert::AreEqual(V1[6], 7);
			Assert::AreEqual(V1[7], 8);

		}

		//test copy constructor
		TEST_METHOD(moqazi2_Test1)
		{
			myvector<int> V; // nodesize of 5:

			V.push_back(7);
			V.push_back(17);
			for (int i = 0; i < 67; i++) {
				V.push_back(i);
			}
			V.push_back(109);
			V.push_back(8);

			myvector<int> vectorCopy = V;
			//copyVector.push_back(7);

			Assert::IsTrue(vectorCopy.size() == V.size());
			Assert::IsTrue(vectorCopy.front() == 7);
			Assert::IsTrue(vectorCopy.back() == 8);
		}

		//test front() and back() methods of myvector
		TEST_METHOD(moqazi2_Test2)
		{
			myvector<int> V(5); // nodesize of 5:

			V.push_back(12);
			V.push_back(31);
			for (int i = 0; i < 30; i++) {
				V.push_back(i);
			}
			V.push_back(109);
			V.push_back(8);
			Assert::IsTrue(V.front() == 12);
			Assert::IsTrue(V.back() == 8);
		}
		// test that size() method works of myvector
		TEST_METHOD(moqazi2_Test3)
		{
			myvector<int> V(10); // nodesize of 10:

								 //make sure empty list has 0 elements
			Assert::IsTrue(V.size() == 0);

			V.push_back(361);
			V.push_back(341);
			V.push_back(342);
			V.push_back(999);
			V.push_back(0);
			V.push_back(44);
			V.push_back(215);
			V.push_back(151);

			Assert::IsTrue(V.size() == 8);
		}
		// test that size() method works of myvector for multiple nodes
		TEST_METHOD(moqazi2_Test4)
		{
			myvector<int> V(2); // nodesize of 2:

								//make sure empty list has 0 elements
			Assert::IsTrue(V.size() == 0);

			int countElems = 0;
			//add 100 elements to vector
			for (int i = 0; i < 100; i++) {
				V.push_back(i * 3);
				++countElems;
			}

			V.push_back(361);
			V.push_back(341);
			countElems += 2; // total elements, i.e. size of vector
			Assert::IsTrue(V.size() == countElems);
		}

		// test capacity() method when there is only one node 
		TEST_METHOD(moqazi2_Test5)
		{
			myvector<int> V(10); // nodesize of 10:

			for (int i = 100; i < 108; i++) {
				V.push_back(i - 4);
			}
			Assert::IsTrue(V.capacity() == 10);
		}

		// test capacity() method when there are multiple nodes
		TEST_METHOD(moqazi2_Test6)
		{
			myvector<int> V(7); // nodesize of 7:

			V.push_back(11);
			V.push_back(342);
			V.push_back(93);

			for (int i = 0; i < 43; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 49);
		}

		// test operator[]() method when there is only one node
		TEST_METHOD(moqazi2_Test7)
		{
			myvector<int> V(5); // nodesize of 5:

			V.push_back(11);
			V.push_back(342);
			V.push_back(93);

			Assert::IsTrue(V.operator[](0) == 11);
			Assert::IsTrue(V.operator[](2) == 93);
		}

		//// test operator[]() method when there are multiple nodes
		TEST_METHOD(moqazi2_Test8)
		{
			myvector<int> V(6); // nodesize of 7:

			V.push_back(11);
			V.push_back(342);
			V.push_back(93); // V.operator[](2)

			for (int i = 0; i < 35; i++) {
				V.push_back(i);
			}
      V[22] = 19;
			V[37] = 34;

			Assert::IsTrue(V.operator[](0) == 11);
			Assert::IsTrue(V.operator[](5) == 2);
		}

		//test iterators
		TEST_METHOD(moqazi2_Test9)
		{
			myvector<int> sampleVector(100); // nodesize of 100:
			int arr[125];

			for (int i = 0; i < 100; i++) {
				sampleVector.push_back(i);
			}

			int i = 0;
			for (auto v = sampleVector.begin(); v != sampleVector.end(); ++v) {
				arr[i] = *v;
        ++i;
			}

			Assert::IsTrue(arr[0] == 0);
			Assert::IsTrue(arr[99] == 99);
			Assert::IsTrue(arr[50] == 50);

		}

		//another test for iterators
		TEST_METHOD(moqazi2_Test10)
		{
			myvector<int> sampleVector(5); // nodesize of 5:
			sampleVector.push_back(2009);
			for (int i = 0; i < 73; i++) {
				sampleVector.push_back(i);
			}
			sampleVector.push_back(1000);
			int count = 0;
			for (auto v = sampleVector.begin(); v != sampleVector.end(); ++v) {
				count++;
			}

			Assert::IsTrue(count == 75);

		}

		TEST_METHOD(mpanch3_Test1)
		{
			// TODO: Your test code here
			myvector<int> V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(mpanch3_Test2)
		{
			myvector<int> V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(mpanch3_Test3)
		{
			myvector<int> V(100);

			Assert::IsTrue(V.capacity() == 100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 100);
		}

		TEST_METHOD(mpanch3_Test4)
		{
			myvector<int> V(99999999);  // checks for max 
										// elements.

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 99999999);
		}

		TEST_METHOD(mpanch3_Test5)
		{
			myvector<int> V(100);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.capacity() == 100);
		}

		//TEST_METHOD(mpanch3_Test6)
		//{
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	V.~myvector();

		//}

		TEST_METHOD(mpanch3_Test7)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			V.operator[](1);
		}

		TEST_METHOD(mpanch3_Test8)
		{
			myvector<double> V(10);

			V.push_back(28.5);

			Assert::IsTrue(V.front() == 28.5);
		}

		TEST_METHOD(mpanch3_Test9)
		{
			myvector<int> V;
			myvector<int> V2(V);
		}

		TEST_METHOD(mpanch3_Test10)
		{
			myvector<int> V;


		}



		int compare(const void * a, const void * b)
		{
			if (*(int*)a < *(int*)b) return -1;
			if (*(int*)a == *(int*)b) return 0;
			if (*(int*)a > *(int*)b) return 1;
		}



		//10 test cases to submit starts here

		TEST_METHOD(mwalsh35_Push)
		{
			myvector<int>  V(3);
			V.push_back(1);
			Assert::IsTrue(V.back() == 1);
			V.push_back(2);
			Assert::IsTrue(V.back() == 2);
			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(mwalsh35_PushNext)
		{
			myvector<int>  V(2);
			V.push_back(1);
			Assert::IsTrue(V.back() == 1);
			V.push_back(2);
			Assert::IsTrue(V.back() == 2);
			V.push_back(3);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(mwalsh35_Capacity)
		{
			myvector<int>  V(10);
			// nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 10);
		}

		//TEST_METHOD(mwalsh35_BracketOperator)
		//{
		//	myvector<int>  V(3);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	Assert::IsTrue(V[0] == 1);
		//	Assert::IsTrue(V[1] == 2);
		//	Assert::IsTrue(V[2] == 3);
		//	V[3] = 0;
		//}

		TEST_METHOD(mwalsh35_Copy)
		{
			myvector<int>  V(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			myvector<int> W(V);

			Assert::IsTrue(W[0] == 1);
		}

		//TEST_METHOD(mwalsh35_Delete)
		//{
		//	myvector<int>  V(3);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	void * des = &V;

		//	delete &V;

		//	Assert::IsTrue(des == NULL);
		//}

		//TEST_METHOD(mwalsh35_Iterator)
		//{
		//	myvector<int>  V(4);
		//	V.push_back(4);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(21);
		//	std::sort(V.begin(), V.end(), compare);
		//	Assert::IsTrue(V[0] == 2);
		//	Assert::IsTrue(V[1] == 3);
		//	Assert::IsTrue(V[2] == 4);
		//	Assert::IsTrue(V[3] == 21);

		//}

		TEST_METHOD(mwalsh35_CapacityAfterNewArray)
		{
			myvector<int>  V(2);
			Assert::IsTrue(V.capacity() == 2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 4);
		}

		TEST_METHOD(mwalsh35_SizeAfterNewArray)
		{
			myvector<int>  V(2);
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3);
		}

		//TEST_METHOD(mwalsh35_BracketOperatorAfterNewArray)
		//{
		//	myvector<int>  V(2);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	Assert::IsTrue(V[0] == 1);
		//	Assert::IsTrue(V[1] == 2);
		//	Assert::IsTrue(V[2] == 3);
		//	V[3] = 0;
		//}




		TEST_METHOD(test1nkhan44)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10: 

			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			Assert::IsTrue(V.front() == V.back());

		}
		TEST_METHOD(test2nkhan44)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10: 

			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 12; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.front() != V.back());

		}
		TEST_METHOD(test3nkhan44)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10: 
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 12; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 20);

		}
		TEST_METHOD(test4nkhan44)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10: 
			Assert::IsTrue(V.size() == 0);
			for (int i = 0; i < 12; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 12);
		}
		TEST_METHOD(test5nkhan44)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10: 
			Assert::IsTrue(V.size() == 0);

			for (int i = 0; i < 12; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.operator[](9) == 9);


		}




		//chacking the size constructor
		//TEST_METHOD(nrice4_test1)
		//{
		//	myvector<int> V(100);

		//	Assert::IsTrue(V.capacity == 100);

		//	V.push_back(500);
		//	V.push_back(299);
		//	V.push_back(7890);

		//	Assert::IsTrue(V.size == 3);


		//}

		//testing the operator constructor
		TEST_METHOD(nrice4_test2)
		{
			myvector<int> V(10);


			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[1] == 2);

			V[2] = 100;

			Assert::IsTrue(V[2] == 100);

		}

		////testing the copy constructor
		//TEST_METHOD(nrice4_test3)
		//{
		//	myvector<int> V(1);


		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	myvector<int> temp;

		//	temp = V;

		//	temp[1] = 300;

		//	Assert::IsTrue(V[1] == 2);
		//	Assert::IsTrue(temp[1] == 300);

		//}

		//test Capciry function
		TEST_METHOD(nrice4_test4) {
			myvector<int> V(5);

			Assert::IsTrue(V.capacity() == 5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.capacity() == 10);
		}

		//test front and back functions
		TEST_METHOD(nrice4_test5) {
			myvector<int> V(5);


			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 6);
			V[0] = 100;

			Assert::IsTrue(V.front() == 100);
		}

		//testing that everyting still works with strings
		TEST_METHOD(nrice4_test6) {
			myvector<string> V(5);



			V.push_back("hello");
			V.push_back("my");
			V.push_back("name");
			V.push_back("is");
			V.push_back("hi");
			V.push_back("greetings");

			Assert::IsTrue(V[0] == V.front());
			Assert::IsTrue(V[5].compare("greetings") == 0);

			Assert::IsTrue(V.size() == 6);

		}

		//test iterators
		TEST_METHOD(nrice4_test7) {
			myvector<double> V(1);


			V.push_back(1.1);
			V.push_back(2.2);
			V.push_back(3.3);
			V.push_back(4.4);
			V.push_back(5.5);
			V.push_back(6.6);

			for (int i =0; i < V.size(); ++i)
			{
        V[i] += 1;
			}

			Assert::IsTrue(abs(V[0] - 2.1) < 0.0001);
			Assert::IsTrue(abs(V[3] - 5.4) < 0.0001);
			Assert::IsTrue(abs(V[5] - 7.6) < 0.0001);

		}

		TEST_METHOD(nrice4_test8) {
			myvector<char> V(5);


			V.push_back('a');
			V.push_back('b');
			V.push_back('c');
			V.push_back('d');
			V.push_back('e');
			V.push_back('f');

			Assert::IsTrue(V.front() == 'a');
			Assert::IsTrue(V.back() == 'f');
			V[0] = 'z';

			Assert::IsTrue(V.front() == 'z');

			for (int i = 0; i < V.size(); ++i)
			{
				V[i] = 'N';
				Assert::IsTrue(V[i] == 'N');
			}

		}

		//test with code that uses iterators
		//TEST_METHOD(nrice4_test9) {
		//	myvector<int> V;


		//	V.push_back(100);
		//	V.push_back(90);
		//	V.push_back(80);
		//	V.push_back(50);
		//	V.push_back(20);
		//	V.push_back(10);

		//	int sum = std::accumulate(V.begin(), V.end(), 0);

		//	Assert::IsTrue(sum == 350);


		//}

		/*TEST_METHOD(nrice4_test10)
		{
			myvector<int> V(100);


			V.push_back(78);
			V.push_back(2);
			V.push_back(34);
			V.push_back(100);
			V.push_back(5);
			V.push_back(9874);
			V.push_back(10);
			V.push_back(25);

			std::sort(V.begin(), V.end(),
				[&](int & temp1, int & temp2)
			{
				if (temp1 < temp2)
					return true;
				else
					return false;
			}

			);

			Assert::IsTrue(V[0] == 2);
		}*/


		//The following test makes sure you can add more nodes to your vector
		TEST_METHOD(nzakha2_Test1)
		{
			myvector<int> V(5); //node size of 5
			Assert::IsTrue(V.size() == 0);
			Assert::IsTrue(V.capacity() == 5);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			Assert::IsTrue(V.size() == 5);
			Assert::IsTrue(V.capacity() == 5);
			V.push_back(6);
			/*
			* After the next line runs, your vector class should create a
			* new node and add the int to the end (in the new node).
			*/
			V.push_back(23);
			Assert::IsTrue(V.size() == 7);
			Assert::IsTrue(V.capacity() == 10);
		}

		//// This test will check that after you copy a vector and add an element to the new copy
		//// it will create a new node
		//TEST_METHOD(nzakha2_Test2)
		//{
		//	myvector<int> V(5);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);
		//	V.push_back(5);

		//	myvector<int> B(V);
		//	// the next line checks that the copy was a deep copy
		//	// meaning that every element gets copied too.
		//	Assert::AreNotSame(V.back(), B.back());
		//	B.push_back(6);
		//	Assert::IsTrue(B.capacity() == 10); //this makes sure a new node has been created
		//	V.push_back(7);
		//	Assert::IsTrue(B.back() == 7);
		//}

		// This test will make sure you can copy to vectors
		TEST_METHOD(nzakha2_Test3)
		{
			myvector<int> V(10); //node size of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
			myvector<int> B(V);
			Assert::IsTrue(B.size() == V.size());

		}
		// This test will make sure that the operator method is implemented correctly
		TEST_METHOD(nzakha2_Test4)
		{
			myvector<int> V(10);
			V.push_back(0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			for (int i = 0; i < V.size(); i++)
			{
				Assert::IsTrue(V[i] == i);
			}

		}
		// This test will make sure front() works correctly
		TEST_METHOD(nzakha2_Test5)
		{
			myvector<string> V(10);
			V.push_back("CS341");
			V.push_back("Rocks!");
			Assert::IsTrue(V.front() == "CS341");
		}
		// This test will make sure back() work correctly
		TEST_METHOD(nzakha2_Test6)
		{
			myvector<string> V(10);
			V.push_back("CS341");
			V.push_back("Rocks!");
			Assert::IsTrue(V.back() == "Rocks!");
		}

		// This test will make sure begin() works correctly
		TEST_METHOD(nzakha2_Test7)
		{
			myvector<char> V(10);
			Assert::IsTrue(V.size() == 0);
			Assert::IsTrue(V.capacity() == 10);
			V.push_back('A');
			V.push_back('B');
			V.push_back('C');
			V.push_back('D');
			V.push_back('E');
			V.push_back('A');

			// front and back now contain the same character. the following test should be true
			Assert::AreEqual(V.front(), V.back());
			// Even though they are the same, they point to two characters NOT one
			Assert::AreNotSame(V.front(), V.back());
		}

		//// This test will make sure end() works correctly and is pointing to a nullptr.
		//TEST_METHOD(nzakha2_Test8)
		//{
		//	myvector<int> V(10);
		//	V.push_back(1);
		//	V.push_back(2);
		//	Assert::IsNull(&V.end());
		//}

		// This test will make sure front() works correctly after creating a new node
		TEST_METHOD(nzakha2_Test9)
		{
			myvector<int> V(5);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			Assert::IsTrue(V.capacity() == 10); //this makes sure a new node has been created
			V.push_back(7);
			Assert::IsTrue(V.front() == 1);
			// if passed, the vector has created a new node and front() still works
		}
		// This test will make sure back() works correctly after creating a new node
		TEST_METHOD(nzakha2_Test10)
		{
			myvector<int> V(5);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			Assert::IsTrue(V.capacity() == 10); //this makes sure a new node has been created
			V.push_back(7);
			Assert::IsTrue(V.back() == 7);
		}

		// checks for string vector
		TEST_METHOD(opatel3_Test1)
		{
			myvector <string>	v(10);

			v.push_back("Hello");
			v.push_back("Awesome");
			v.push_back("World");
			v.push_back("Line4");

			Assert::IsTrue(v.front() == "Hello");
			Assert::IsTrue(v.back() == "Line4");
		}

		// checks for vector of a larger size
		TEST_METHOD(opatel3_Test2)
		{
			myvector <int>	v(100000);
			int i = 0;

			while (i != v.capacity()) {
				v.push_back(i);
				i++;
			}

			Assert::IsTrue(v.front() == 0);
			Assert::IsTrue(v.back() == 99999);
		}

		// checks for bool type vector
		TEST_METHOD(opatel3_Test3)
		{
			myvector <bool>	v(10);

			v.push_back(true);
			v.push_back(false);
			v.push_back(0);
			v.push_back(true);
			v.push_back(1);

			Assert::IsTrue(v.front() == true);
			Assert::IsTrue(v.back() == 1);
		}

		// checks for char type vector
		TEST_METHOD(opatel3_Test4)
		{
			myvector <char>	v(10);

			v.push_back('a');
			v.push_back('b');
			v.push_back('C');
			v.push_back('D');

			Assert::IsTrue(v.front() == 'a');
			Assert::IsTrue(v.back() == 'D');
		}

		// checks for double type
		TEST_METHOD(opatel3_Test5)
		{
			myvector <double>	v(10);

			v.push_back(2.666666666666666666666);
			v.push_back(54.56545);
			v.push_back((10 / 9));
			v.push_back(4555.666558458);
			v.push_back((12 / 9));

			Assert::IsTrue(v.front() == 2.666666666666666666666);
			Assert::IsTrue(v.back() == (12 / 9));
		}

		// checks for float type vector
		TEST_METHOD(opatel3_Test6)
		{
			myvector <float>	v(10);

			v.push_back(13 / 9);
			v.push_back((3.0 * 0.25));

			Assert::IsTrue(v.front() == (13 / 9));
			Assert::IsTrue(v.back() == 0.75);
		}

		// checks for lunsigned long long integer
		TEST_METHOD(opatel3_Test7)
		{
			myvector <unsigned long long int>	v(10);

			v.push_back(9999999999345678921);
			v.push_back(9999999999999999999);
			v.push_back(9234567891234567892);


			Assert::IsTrue(v.front() == 9999999999345678921);
			Assert::IsTrue(v.back() == 9234567891234567892);
		}

		//checks for negative numbers
		TEST_METHOD(opatel3_Test8)
		{
			myvector <int>	v(10);

			v.push_back(-1000);
			v.push_back(-2555);
			v.push_back(-35456);
			v.push_back(413553);
			v.push_back(355565);
			v.push_back(553453);

			Assert::IsTrue(v.front() == -1000);
			Assert::IsTrue(v.back() == 553453);
		}

		//checks for operator at ith index
		TEST_METHOD(opatel3_Test9)
		{
			myvector <int>	v(10);

			v.push_back(11);
			v.push_back(22);
			v.push_back(33);
			v.push_back(44);
			v.push_back(55);
			v.push_back(66);

			v[0] = 101;
			v[5] = 111;

			Assert::IsTrue(v.front() == 101);
			Assert::IsTrue(v.back() == 111);
		}

		// vector comparison
		TEST_METHOD(opatel3_Test10)
		{
			myvector <int>	v1(10);
			v1.push_back(11);

			myvector <int>	v2(10);
			v2.push_back(45);
			v2.push_back(11);

			Assert::IsTrue(v1.front() == v2.back());
		}

		// vector capacity
		TEST_METHOD(opatel3_Test11)
		{
			myvector <int>	v(25);

			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			//myvector.h file has 1 numNodes that's way
			Assert::IsTrue(v.capacity() == 25);  // (numNodes * nodeSize) returns 25 instead of 30 
		}


		TEST_METHOD(pitrak1_front)
		{
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
		}

		TEST_METHOD(pitrak1_back) {
			myvector<int>  V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}


		TEST_METHOD(pitrak1_size) {
			myvector<int>  V(10);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(pitrak1_capacity) {
			myvector<int> V(10);

			Assert::IsTrue(V.capacity() == 10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(pitrak1_index) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[1] == 2);
		}


		TEST_METHOD(pitrak1_backWithMultipleNodes) {
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);

			Assert::IsTrue(V.back() == 7);
		}

		TEST_METHOD(pitrak1_sizeWithMultipleNodes) {
			myvector<int>  V(5);

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);

			Assert::IsTrue(V.size() == 7);
		}

		TEST_METHOD(pitrak1_capacityWithMultipleNodes) {
			myvector<int> V(5);

			Assert::IsTrue(V.capacity() == 5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(pitrak1_indexWithMultipleNodes) {
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);

			Assert::IsTrue(V[3] == 4);
			Assert::IsTrue(V[5] == 6);
		}

		TEST_METHOD(pitrak1_copyConstructor) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> W(V);

			Assert::IsTrue(myvectorAreEqual(V, W));
		}

		TEST_METHOD(pitrak1_copyConstructorWithMultipleNodes) {
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);

			myvector<int> W(V);

			Assert::IsTrue(myvectorAreEqual(V, W));
		}

		TEST_METHOD(pitrak1_begin) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(*V.begin() == 1);
		}



		TEST_METHOD(pitrak1_forEachIteration) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> W(10);

			for (int i : V) {
				W.push_back(i);
			}

			Assert::IsTrue(myvectorAreEqual(V, W));
		}

		TEST_METHOD(pitrak1_forEachIterationWithMultipleNodes) {
			myvector<int> V(5);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);

			myvector<int> W(V);

			for (int i : V) {
				W.push_back(i);
			}

			Assert::IsTrue(myvectorAreEqual(V, W));
		}

	private:
		bool myvectorAreEqual(myvector<int>& V, myvector<int>& W) {
			for (int i = 0; i < V.size(); i++) {
				if (V[i] != W[i]) {
					return false;
				}
			}

			return true;
		}


		TEST_METHOD(pzimno2_Test1)
		{
			myvector<int> V(10); // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(10);
			Assert::IsTrue(V.size() == 4);

		}
		//TEST_METHOD(pzimno2_Test2)
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//	V.push_back(79);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(10);
		//	V.pop_back();
		//	V.pop_back();
		//	V.pop_back();
		//	V.pop_back();
		//	Assert::IsTrue(V.size() == 0);
		//}

		//TEST_METHOD(pzimno2_Test3)
		//{
		//	myvector<int> V(10);
		//	V.push_back(79);
		//	V.pop_back();
		//	V.pop_back();
		//	Assert::IsTrue(V.size() == 0);
		//}

		//TEST_METHOD(pzimno2_Test4)
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.operator[](2) = 3;
		//	V.push_back(3);
		//	Assert::IsTrue(V.operator[](2) == 3);
		//}

		//TEST_METHOD(pzimno2_Test5)
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	myvector<int>::iterator it = V.begin();
		//	Assert::IsTrue(it == V.front());

		//}
		//TEST_METHOD(pzimno2_Test6)
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	myvector<int>::iterator it = V.end();
		//	Assert::IsTrue(it == V.back());
		//}

		TEST_METHOD(pzimno2_Test7)
		{
			myvector<int> V(10); // nodesize of 10:
			Assert::IsTrue(V.capacity() == 10);

		}
		//TEST_METHOD(pzimno2_Test8)
		//{
		//	myvector<int> V(10); // nodesize of 10:
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	Assert::IsTrue(V.empty() == 0);
		//}
			//TEST_METHOD(pzimno2_Test9)
			//{
			//	myvector<int> V(10); // nodesize of 10:
			//	V.push_back(1);
			//	V.push_back(2);
			//	V.push_back(3);
			//	V.pop_back();
			//	V.pop_back();
			//	V.pop_back();
			//	Assert::IsTrue(V.empty() == 1);

			//}
			//TEST_METHOD(pzimno2_Test10)
			//{
			//	myvector<int> V(10); // nodesize of 10:
			//	myvector<int>::iterator it = V.begin();
			//	myvector<int>::iterator it2 = V.end();
			//	Assert::IsTrue(it == it2);
			//}




			/*
			Tests if the vector is empty after pushing an element into it
			*/
		//TEST_METHOD(rnambi2_Test_Null)
		//{
		//	myvector<int> V(10);

		//	V.push_back(50);

		//	Assert::IsTrue(V.front() != NULL);
		//	Assert::IsTrue(V.back() != NULL);
		//}

		/*
		Tests if the front of the vector is correct after pushing an element into the vector
		*/
		TEST_METHOD(rnambi2_Test_Front)
		{
			myvector<int> V(10);

			V.push_back(1);

			Assert::IsTrue(V.front() == 1);
		}

		/*
		Tests if the front of the vector changes after pushing another node into the vector
		*/
		TEST_METHOD(rnambi2_Test_Front_2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsTrue(V.front() == 1);
		}

		/*
		Tests if the back of the vector is correct after pushing an element into the vector
		*/
		TEST_METHOD(rnambi2_Test_Back)
		{
			myvector<int> V(10);

			V.push_back(50);

			Assert::IsTrue(V.back() == 50);
		}

		/*
		Tests if the back of the vector changes after pushing another node into the vector
		*/
		TEST_METHOD(rnambi2_Test_Back_2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);

			Assert::IsTrue(V.back() == 11);
		}

		/*
		Tests if the size of the vector is correct after pushing multiple elements into the vector
		*/
		TEST_METHOD(rnambi2_Test_Size)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.size() == 4);
		}

		/*
		Tests if the size of the vector is correct after pushing another node into the vector
		*/
		TEST_METHOD(rnambi2_Test_Size_2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);
			V.push_back(13);
			V.push_back(14);
			V.push_back(15);
			V.push_back(16);
			V.push_back(17);
			V.push_back(18);
			V.push_back(19);
			V.push_back(20);
			V.push_back(21);
			V.push_back(22);
			V.push_back(23);
			V.push_back(24);

			Assert::IsTrue(V.size() == 24);
		}

		/*
		Tests if the capacity of the vector is correct after pushing multiple elements into the vector
		*/
		TEST_METHOD(rnambi2_Test_Capacity)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.capacity() == 10);
		}

		/*
		Tests if the capacity of the vector is correct after pushing another node into the vector
		*/
		TEST_METHOD(rnambi2_Test_Capacity_2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			Assert::IsTrue(V.capacity() == 20);
		}

		/*
		Tests if the operator function can access the vector correctly in the first node
		*/
		TEST_METHOD(rnambi2_Test_Operator)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			Assert::IsTrue(V.operator[](2) == 3);
		}

		/*
		Tests if the operator function can access the vector correctly in the last node
		*/
		TEST_METHOD(rnambi2_Test_Operator_2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			Assert::IsTrue(V.operator[](11) == 12);
		}

		/*
		Tests if the operator function can access the vector correctly in a node that is between the first
		node and the last node
		*/
		TEST_METHOD(rnambi2_Test_Operator_3)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);
			V.push_back(13);
			V.push_back(14);
			V.push_back(15);
			V.push_back(16);
			V.push_back(17);
			V.push_back(18);
			V.push_back(19);
			V.push_back(20);
			V.push_back(21);
			V.push_back(22);
			V.push_back(23);
			V.push_back(24);

			Assert::IsTrue(V.operator[](16) == 17);
		}

		TEST_METHOD(rtejed2_Test1) // test capacity
		{
			myvector<int> V(20); // nodesize of 20
			for (auto i = 0; i < 12; ++i) // push back 11
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 20); // capacity should be 20
		}

		TEST_METHOD(rtejed2_Test2)
		{
			myvector<int> V(20); // nodesize of 20
			for (auto i = 1; i <= 15; i++) // push back 15
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.front() == 1); // front should be 1
			Assert::IsTrue(V.back() == 15); // back should be 15 
		}

		TEST_METHOD(rtejed2_Test3)
		{
			myvector<int> V(20); // nodesize of 20
			Assert::IsTrue(V.size() == 0); // size should be 0
			for (auto i = 1; i <= 15; i++) // push back 15
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 15); // size should be 15
		}

		TEST_METHOD(rtejed2_Test4)
		{
			myvector<int> V(30); // nodesize of 30
			Assert::IsTrue(V.size() == 0); // size should be 0
			for (auto i = 1; i <= 22; i++) // push back 22
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 22); // size should be 22
		}

		TEST_METHOD(rtejed2_Test5)
		{
			myvector<int> V(30); // nodesize of 30
			for (auto i = 5; i < 12; i++) // push back 7
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.front() == 5); // front should be 5
			Assert::IsTrue(V.back() == 11); // back should be 11 
		}

		TEST_METHOD(rtejed2_Test6)
		{
			myvector<int> V(10); // nodesize of 10
			for (auto i = 1; i <= 22; i++) // push back 22
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 22); // size should be 22
		}

		TEST_METHOD(rtejed2_Test7)
		{
			myvector<int> V(10); // nodesize of 10
			for (auto i = 1; i <= 22; i++) // push back 22
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 30); // capacity should be 20
		}

		TEST_METHOD(rtejed2_Test8)
		{
			myvector<int> V(15); // nodesize of 15
			for (auto i = 1; i <= 22; i++) // push back 22
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 30); // capacity should be 30
		}

		TEST_METHOD(rtejed2_Test9)
		{
			myvector<int> V(10); // nodesize of 10
			Assert::IsTrue(V.size() == 0); // size should be 0
			for (auto i = 1; i <= 22; i++) // push back 22
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 22); // size should be 22
		}

		TEST_METHOD(rtejed2_Test10)
		{
			myvector<int> V(10); // nodesize of 10
			for (auto i = 1; i <= 22; i++) // push back 22
			{
				V.push_back(i);
			}
			Assert::IsTrue(V.front() == 1); // front should be 1
			Assert::IsTrue(V.back() == 22); // back should be 22 
		}


		//Testing the capacity funtion of the vector
		TEST_METHOD(Test1_676840007)
		{
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsTrue(V.capacity() == 10);
		}



		//Testing if the vector's front funtion 
		TEST_METHOD(Test5_676840007)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);

			Assert::IsTrue(V.front() == 1);

		}


		//Testing if the vector's front funtion 
		TEST_METHOD(Test6_676840007)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(10);
			V.push_back(100);

			Assert::IsTrue(V.back() == 100);

		}






		TEST_METHOD(sariza2_test1)
		{
			//default parameter capacity is set
			myvector<int> vec;
			Assert::IsTrue(vec.capacity() == 100);
		}

		TEST_METHOD(sariza2_test2) {
			//Indexing operator indexes correctly on default parameter

			myvector<int> vec;
			vec.push_back(25);
			vec.push_back(26);
			vec.push_back(27);

			Assert::IsTrue(vec[1] == 26);
		}

		TEST_METHOD(sariza2_test3) {
			/* Test size() */

			myvector<int> vec(3);
			vec.push_back(25);
			vec.push_back(26);
			vec.push_back(27);

			Assert::IsTrue(vec.size() == 3);
		}

		TEST_METHOD(sariza2_test4) {
			/*Test capacity()*/

			myvector<int> vec(3);
			Assert::IsTrue(vec.capacity() == 3);
		}

		TEST_METHOD(sariza2_test5) {
			//Indexing operator indexes correctly after resizing

			myvector<int> vec(3);
			vec.push_back(25);
			vec.push_back(26);
			vec.push_back(27);
			vec.push_back(105);

			Assert::IsTrue(vec[3] == 105);
		}

		TEST_METHOD(sariza2_test6) {
			//Testing the resizability factor for capacity

			myvector<int> vec(3);
			Assert::IsTrue(vec.capacity() == 3);

			vec.push_back(25);
			vec.push_back(25);
			vec.push_back(25);
			vec.push_back(24);

			Assert::IsTrue(vec.capacity() == 6);
		}

		TEST_METHOD(sariza2_test7) {
			//Testing that size updates correctly

			myvector<int> vec(3);
			Assert::IsTrue(vec.size() == 0);

			vec.push_back(25);
			Assert::IsTrue(vec.size() == 1);
		}

		//TEST_METHOD(sariza2_test8) {
		//	//indexing and updating a myvector works correctly

		//	myvector<int> vec;
		//	vec[25] = 105;

		//	Assert::IsTrue(vec[25] == 105);
		//}

		TEST_METHOD(sariza2_test9) {
			/*Make sure that a deep copy is made with copy constructor*/
			myvector<int> vec(3);

			vec.push_back(21);
			vec.push_back(22);
			vec.push_back(23);

			myvector<int> cpy = vec;
			Assert::AreNotSame(vec.front(), cpy.front());

		}

		TEST_METHOD(sariza2_test10) {
			/* Equal sizes after a copy*/
			myvector<int> vec(3);

			vec.push_back(21);
			vec.push_back(22);
			vec.push_back(23);

			myvector<int> cpy = vec;
			Assert::AreEqual(vec.size(), cpy.size());
		}

		TEST_METHOD(sariza2_test11) {
			/* Equal capacities after a copy */
			myvector<int> vec(3);

			vec.push_back(21);
			vec.push_back(22);
			vec.push_back(23);
			vec.push_back(29);

			myvector<int> cpy = vec;
			Assert::AreEqual(vec.capacity(), cpy.capacity());

		}




		TEST_METHOD(sbharu2_Test1) //testing capacity
		{

			myvector <int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(sbharu2_Test2) //size test
		{
			myvector <int> V(10);

			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.size() == 2);

			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}


		TEST_METHOD(sbharu2_Test3) //push back test
		{
			myvector <int> V(10);
			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 2);
		}


		TEST_METHOD(sbharu2_Test4) //front test
		{
			myvector <int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.front() == 3);


		}
		TEST_METHOD(sbharu2_Test5) //back test
		{
			myvector <int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.back() == 1);

		}




		TEST_METHOD(sbukha4_TestCapacity) {
			myvector<int> V(10); //nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}
		TEST_METHOD(sbukha4_testPushBack) {
			myvector<int> V(3); //nodesize of 3:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);

			V.push_back(4); //we should have created a new Node and assigned it as the new tail

			Assert::IsTrue(V.back() == 4);
			Assert::IsTrue(V.front() == 1);
		}
		TEST_METHOD(sbukha4_TestCapacity2) {
			myvector<int> V(4); //nodesize of 4:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);

			Assert::IsTrue(V.capacity() == 12);
		}

		//TEST_METHOD(sbukha4_testBeginIterator) {
		//	myvector<int> V(4); //nodesize of 4:

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(*(V.begin() + sizeof(int)) == 1);
		//}

		TEST_METHOD(sbukha4_testBeginEndNotEqual) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.begin() != V.end());
		}
		//TEST_METHOD(sbukha4_testEndIterator) {
		//	myvector<int>V(0);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(*(V.end() - 1) == 3);
		//}

		TEST_METHOD(sbukha4_testTraverse)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(1);
			V.push_back(2);
			V.push_back(1);

			int position = 0;
			for (int i : V) {
				if (position % 2 == 0) {
					Assert::IsTrue(i % 2 != 0);
				}
				else {
					Assert::IsTrue(i % 2 == 0);
				}
				position++;
			}
		}

		TEST_METHOD(sbukha4_testOperator) {
			myvector<int> V(4);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			for (int i = 0; i < V.size(); i++) {
				Assert::IsTrue(V[i] == i + 1);
			}
		}

		//TEST_METHOD(sbukha4_testDistancesBetweenBeginAndEnd) {
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(4);
		//	V.push_back(5);

		//	Assert::IsTrue(distance(V.begin(), V.end()) == V.size());
		//}

		//TEST_METHOD(sbukha4_testCopyConstructor) {
		//	myvector <int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(0);
		//	V.push_back(4);
		//	V.push_back(6);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(9);
		//	V.push_back(9);
		//	V.push_back(9);

		//	vector <int> test(V);

		//	for (int i = 0; i < test.size(); i++) {
		//		Assert::IsTrue(test[i] == V[i]);
		//	}
		//}




		/* tests capacity */
		TEST_METHOD(sgadho2_test1)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}

		/* tests the middle nodes in the myvector class */
		TEST_METHOD(sgadho2_test2)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
		}

		/* tests front and back with 2 nodes */
		TEST_METHOD(sgadho2_test3)
		{
			myvector<int> V(10);

			V.push_back(1);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 1);

			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		///* testing deep copy */
		//TEST_METHOD(sgadho2_test4)
		//{

		//	myvector<int> V(10);
		//	myvector<int> V2(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	V2 = V;

		//	Assert::IsTrue(V.back() == 3);
		//	Assert::IsTrue(V2.back() == 3);

		//	V.push_back(4);

		//	Assert::IsTrue(V.back() == 4);
		//	Assert::IsTrue(V2.back() == 3);

		//}

		///* testing deep copy */
		//TEST_METHOD(sgadho2_test5)
		//{

		//	myvector<int> V(5);
		//	myvector<int> V2(5);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(V2.size() == 0);
		//	Assert::IsTrue(V.size() == 3);

		//	V2 = V;

		//	Assert::IsTrue(V.size() == 3);
		//	Assert::IsTrue(V2.size() == 3);

		//	V.push_back(4);

		//	Assert::IsTrue(V.size() == 4);
		//	Assert::IsTrue(V2.size() == 3);
		//}

		///* testing deep copy */
		//TEST_METHOD(sgadho2_test6)
		//{

		//	myvector<int> V(10);
		//	myvector<int> V2(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V2 = V;

		//	V.~myvector();

		//	Assert::IsTrue(V.size() == 0);
		//	Assert::IsTrue(V2.size() == 3);

		//}

		/* tests begin */
		TEST_METHOD(sgadho2_test7)
		{

			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(*(V.begin()) == 1);
		}

		///* tests end */
		//TEST_METHOD(sgadho2_test8)
		//{

		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	Assert::IsTrue(*(V.end()) == 3);
		//}

		/* tests operator  */
		TEST_METHOD(sgadho2_test9)
		{

			myvector<int> V(3);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
			Assert::IsTrue(V[3] == 4);
		}

		/* tests vector with one node where front and back should
		point to the same location */
		TEST_METHOD(sgadho2_test10)
		{

			myvector<int> V(10);

			V.push_back(5);

			Assert::IsTrue(V.front() == 5);
			Assert::IsTrue(V.back() == 5);
		}
		TEST_METHOD(sgadho2_test)
		{

			myvector<int> V(2);
			Assert::IsTrue(V.capacity() == 2);

			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(V.capacity() == 2);

			V.push_back(3);

			Assert::IsTrue(V.capacity() == 4);
		}

		TEST_METHOD(skumar44_Test1)
		{
			myvector<int> V(10); //nodesize of 10
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}

		TEST_METHOD(skumar44_Test2)
		{
			myvector<int> V(10); //nodesize of 10
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(skumar44_Test2v2)
		{
			myvector<int> V(40); //nodesize of 10
			Assert::IsTrue(V.size() == 0);
			for (int i = 1; i <= 40; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 40);
		}


		TEST_METHOD(skumar44_Test3)
		{
			myvector<int> V(100); //nodesize of 10
			Assert::IsTrue(V.size() == 0);
			for (int i = 1; i <= 100; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 100);
		}

		TEST_METHOD(skumar44_Test4)
		{
			myvector<int> V(10); //nodesize of 10
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(skumar44_Test5)
		{
			myvector<int> V(40); //nodesize of 10
			for (int i = 0; i < 38; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 40);
		}

		TEST_METHOD(skumar44_Test6)
		{
			myvector<int> V(110); //nodesize of 10
			for (int i = 1; i <= 101; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 110);
		}

		TEST_METHOD(skumar44_Test7)
		{
			myvector<int> V(10); //nodesize of 10
			V.push_back(1);
			V.push_back(2);
			Assert::IsTrue(V.size() == 2);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(skumar44_Test8)
		{
			myvector<int> V(10); //nodesize of 10
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V[0] == 1);
		}

		TEST_METHOD(skumar44_Test9)
		{
			myvector<int> V(10); //nodesize of 10
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
			Assert::IsTrue(V[3] == 1);
			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(skumar44_Test10)
		{
			myvector<int> V(30); //nodesize of 10
			int j;
			for (j = 0; j < 25; j++) {
				V.push_back(j);
			}
			Assert::IsTrue(V[0] == 0);
		}

		TEST_METHOD(skumar44_Test11)
		{
			myvector<int> V(10); //nodesize of 10
			int j;
			for (j = 0; j < 10; j++) {
				V.push_back(j);
			}
			Assert::IsTrue(V[6] == 6);
			Assert::IsTrue(V[3] == 3);
			Assert::IsTrue(V.capacity() == 10);
		}



		//TEST_METHOD(sloban_Test1)
		//{
		//	//test to deep copy
		//	myvector<int> V(10);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);

		//	myvector<int> V2;
		//	for (int i = 0; i < 10; i++)
		//	{
		//		V2[i] = V[i];
		//	}


		//	Assert::IsTrue(V2.front() == 1);
		//	Assert::IsTrue(V2.back() == 3);

		//}

		TEST_METHOD(sloban2_Test2)
		{
			//test to check type:string
			myvector <string>	V(10);

			V.push_back("Hello");
			V.push_back("Great");
			V.push_back("World");
			V.push_back("Line4");

			Assert::IsTrue(V.front() == "Hello");
			Assert::IsTrue(V.back() == "Line4");
		}
		TEST_METHOD(sloban2_Test3)
		{
			//test to check capacity
			myvector <int> V(10);

			Assert::IsTrue(V.capacity() == 10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}
		TEST_METHOD(sloban2_Test4)
		{
			//test to check large size
			myvector <int> V(10000);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.back() == 3);
		}
		TEST_METHOD(sloban2_Test5)
		{
			//test to check type:boolean
			myvector <bool> V(10);

			V.push_back(false);
			V.push_back(true);
			V.push_back(false);
			V.push_back(true);

			Assert::IsTrue(V.back() == true);

		}
		TEST_METHOD(sloban2_Test6)
		{
			//test to to check type:char
			myvector <char> V(10);
			V.push_back('s');
			V.push_back('h');
			V.push_back('a');
			V.push_back('n');
			V.push_back('i');
			V.push_back('l');

			Assert::IsTrue(V.back() == 'l');
		}
		TEST_METHOD(sloban2_Test7)
		{
			//test to check different type:double
			myvector <double> V(10);

			V.push_back(500);
			V.push_back(1000);

			Assert::IsTrue(V.front() == 500);

			V.push_back(1500);
			V.push_back(2000);

			Assert::IsTrue(V.back() == 2000);

		}
		TEST_METHOD(sloban2_Test8)
		{
			//test to check different type:unsigned long for negative numbers
			myvector <unsigned long> V(10);

			V.push_back(-5);

			Assert::IsTrue(V.front() == -5);

			V.push_back(-5000000);
			V.push_back(1000000000);

			Assert::IsTrue(V.back() == 1000000000);
		}
		TEST_METHOD(sloban2_Test9)
		{
			//test to check if operator works
			myvector <int> V(10);

			V.push_back(5);
			if (V[0] = 5)
			{
				Assert::IsTrue(V.front() == 5);
			}
		}
		TEST_METHOD(sloban2_Test10)
		{
			//front test assert and if statement
			myvector <int> V(10);

			V.push_back(5);
			V.push_back(10);

			if (V.front() == 5)
			{
				Assert::IsTrue(V.front() == 5);
			}


		}
		TEST_METHOD(sloban2_Test11)
		{
			//back test used assert and if statement
			myvector <int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			if (V.back() == 3)
			{
				Assert::IsTrue(V.back() == 3);
			}
		}




		/*Testing if calling capacity alone works*/
		TEST_METHOD(ssulei7_Test1)
		{
			myvector<int> V(15);
			Assert::IsTrue(V.capacity() == 15);
		}

		/*Testing if calling capacity after pushing max elements returns correct size*/
		TEST_METHOD(ssulei7_Test2)
		{
			myvector<int> V(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			Assert::IsTrue(V.capacity() == 6);
		}

		/*Testing if head points at correct at first index, even after a resize*/
		TEST_METHOD(ssulei7_Test3)
		{
			myvector<int> V(2);
			V.push_back(9);
			V.push_back(11);
			V.push_back(3);
			V.push_back(22);
			V.push_back(32);
			Assert::IsTrue(V.front() == 9);
		}

		/*Testing if the number of elements is incrementing, capacity is the same, and that front points to the correct value*/
		TEST_METHOD(ssulei7_Test4)
		{
			myvector<int> v(10);
			v.push_back(12);
			v.push_back(9);
			v.push_back(4);
			v.push_back(5);
			v.push_back(6);
			v.push_back(7);
			v.push_back(15);
			Assert::IsTrue(v.size() == 7);
			Assert::IsTrue(v.capacity() == 10);
			Assert::IsTrue(v.front() == 12);
		}

		/*Testing operator function*/
		TEST_METHOD(ssulei7_Test5)
		{
			myvector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
		}

		//Testing pushback 		
    TEST_METHOD(ssulei7_Test6)
		{
		myvector<char> v;
		v.push_back('a');
		v.push_back('b');
		v.push_back('c');
		Assert::IsTrue(v[0] == 'a');
		Assert::IsTrue(v[1] == 'b');
		Assert::IsTrue(v[2] == 'c');
		}

		/*Testing that size works for different data type*/
		TEST_METHOD(ssulei7_Test7)
		{
			myvector<std::string> v(3);
			v.push_back("Hello");
			v.push_back("there");
			v.push_back("world");
			Assert::IsTrue(v.size() == 3);
		}

		/*Testing vector of strings gives appropriate size*/
		TEST_METHOD(ssulei7_Test8)
		{
			myvector<std::string> v;
			v.push_back("hey");
			v.push_back("dad");
			v.push_back("chef");
			Assert::IsTrue(v.size() == 3);
		}

		/*Testing vector of strings give appropriate capacity*/
		TEST_METHOD(ssulei7_Test9)
		{
			myvector<std::string> v;
			v.push_back("hey");
			v.push_back("dad");
			v.push_back("chef");
			Assert::IsTrue(v.capacity() == 100);
		}


		/*Testing if head points at correct at first index, even after a resize*/
		TEST_METHOD(ssulei7_Test10)
		{
			myvector<std::string> V(2);
			V.push_back("my");
			V.push_back("name");
			V.push_back("is");
			V.push_back("chef");
			V.push_back("best movie");
			Assert::IsTrue(V.front() == "my");
		}






		TEST_METHOD(ssulta6_Test1)
		{
			// TODO: Your test code here
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.front() == 2);
			Assert::IsFalse(V.back() == 1);

		}
		TEST_METHOD(ssulta6_Test2)
		{
			myvector<int>V(10);
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsFalse(V.size() == 4);

		}
		TEST_METHOD(ssulta6_Test3)
		{
			myvector<int>V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);


		}
		TEST_METHOD(ssulta6_Test4)
		{
			myvector<int>V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.back() == 3);


		}
		TEST_METHOD(ssulta6_Test5)
		{
			myvector<int>V(10);
			Assert::IsTrue(V.capacity() == 10);

			V.push_back(11);
			V.push_back(21);
			V.push_back(32);

			Assert::IsTrue(V.size() == 3);


		}
		TEST_METHOD(ssulta6_Test6)
		{
			myvector<int>V(10);
			Assert::IsTrue(V.size() == NULL);
			V.push_back(1);
			Assert::IsTrue(V.size() == 1);
		}
		TEST_METHOD(ssulta6_Test7)
		{
			myvector<int>V(10);
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			Assert::AreEqual(V.front(), V.back());
		}

		TEST_METHOD(ssulta6_Test8)
		{
			myvector<int>V(10);
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			Assert::AreSame(V.front(), V.back());
		}
		TEST_METHOD(ssulta6_Test9)
		{
			myvector<int>V(10);
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);

			Assert::AreNotEqual(V.front(), V.back());
		}
		TEST_METHOD(ssulta6_Test10)
		{

			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			myvector<int> V2(10);
			V2.push_back(1);
			V2.push_back(2);
			V2.push_back(3);

			Assert::IsTrue(V2.front() == V.front());
			Assert::IsTrue(V2.back() == V.back());



		}


		TEST_METHOD(szikar2_Test1_CheckSize) {
			// TODO: Your test code here
			myvector<int> V(10);
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			Assert::IsTrue(V.size() == 7);
			Assert::IsTrue(V.capacity() == 10);
		}
		//front
		TEST_METHOD(szikar2_Test2) {
			myvector<int>  V(10);
			for (int x = 0; x < 65; x++)
				V.push_back(x);
			V.operator[](0) = 7;
			Assert::IsTrue(V.operator[](0) == 7);
		}
		//back
		//TEST_METHOD(szikar2_Test3) {
		//	myvector<int>  V(10);
		//	for (int x = 0; x < 65; x++)
		//		V.push_back(x);
		//	V.operator[](65) = 7;
		//	Assert::IsTrue(V.operator[](65) == 7);
		//}

		//middle
		TEST_METHOD(szikar2_Test4) {
			myvector<int>  V(10);
			for (int x = 0; x < 66; x++)
				V.push_back(x);
			V.operator[](33) = 7;
			Assert::IsTrue(V.operator[](33) == 7);
		}
		//Capacity
		TEST_METHOD(szikar2_Test5_CheckCapacity) {
			myvector<int>  V(10);
			for (int x = 0; x < 46; x++)
				V.push_back(x);

			Assert::IsTrue(V.capacity() == 50);
		}
		//TEST_METHOD(szikar2_Test6) {
		//	myvector<int>  V(10);
		//	for (int x = 0; x < 250; x++)
		//		V.push_back(x);
		//	Assert::IsTrue(V.capacity() == 260);
		//}

		TEST_METHOD(szikaria_Test11)
		{
			myvector<int> v(10);
			Assert::IsTrue(v.size() == 0);
			v.push_back(19);
			v.push_back(244);
			v.push_back(32);
			Assert::IsTrue(v.back() > v.front());
		}

		TEST_METHOD(szikar2_Test7) {
			myvector<int> V;
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(2);
			V.push_back(1);
			Assert::AreEqual(V.front(), V.back());
		}
		TEST_METHOD(szikar2_Test8) {
			myvector<int> V(10);
			for (int x = 0; x < V.capacity(); x++) {
				V.push_back(NULL);
			}
			Assert::IsTrue(V.capacity() == 10);
			Assert::AreEqual(V.front(), V.back());
		}

		TEST_METHOD(szikar2_Test9) {
			myvector<int> V;
			V.push_back(4);
			V.push_back(1);
			V.push_back(3);
			V.push_back(6);
			V.push_back(14);
			Assert::AreNotEqual(V.back(), V.front());
		}
		TEST_METHOD(szikar2_Test10) {
			myvector<int> V;
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			Assert::IsTrue(V.back() == 7);
			Assert::IsTrue(V.front() == 1);
		}

		TEST_METHOD(tchoh2_Test1)
		{
			myvector<int> v(10);

			Assert::IsTrue(v.size() == 0);

			v.push_back(1);

			Assert::IsTrue(v.size() == 1);
			Assert::IsTrue(v.front() == 1);
		}

		TEST_METHOD(tchoh2_Test2)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(2);

			Assert::IsTrue(v.back() == 2);
		}

		TEST_METHOD(tchoh2_Test3)
		{
			myvector<int> v(10);

			Assert::IsTrue(v.size() == 0);
			Assert::IsTrue(v.capacity() == 10);
		}

		TEST_METHOD(tchoh2_Test4)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(2);
			v.push_back(1);

			Assert::IsTrue(v.front() == 1);
			Assert::IsTrue(v.back() == 1);
		}

		TEST_METHOD(tchoh2_Test5)
		{
			myvector<int> v(10);

			v.push_back(1);

			Assert::IsTrue(v.capacity() == 10);
		}

		TEST_METHOD(tchoh2_Test6)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(2);

			Assert::IsTrue(v.capacity() == 10);
		}

		TEST_METHOD(tchoh2_Test7)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);

			Assert::IsTrue(v.size() == 10);
		}

		TEST_METHOD(tchoh2_Test8)
		{
			myvector<int> v(20);

			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);
			v.push_back(1);

			Assert::IsTrue(v.capacity() == 20);
		}

		TEST_METHOD(tchoh2_Test9)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(1);

			Assert::IsTrue(v[0] == 1);
		}

		TEST_METHOD(tchoh2_Test10)
		{
			myvector<int> v(10);

			v.push_back(1);
			v.push_back(2);

			Assert::IsTrue(v[1] == 2);

			v.push_back(3);

			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
		}




		TEST_METHOD(tlam22_TestMethod1)
		{
			myvector<int> V(1);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 4);
		}

		TEST_METHOD(tlam22_TestMethod2) {
			myvector<int> V(21);
			for (int i = 0; i < 55; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 63);
			Assert::IsTrue(V.size() == 55);
		}

		TEST_METHOD(tlam22_TestMethod3) {
			myvector<int> V(13);
			for (int i = 0; i < 90; i++) {
				V.push_back(i*i);
			}

			for (int i = 0; i < 90; i++) {
				Assert::IsTrue(V[i] == i*i);
			}
		}
		TEST_METHOD(tlam22_TestMethod4) {
			myvector<string> V(6);
			V.push_back("HI");
			V.push_back("GoodBye");
			Assert::IsTrue(V[0].compare("HI") == 0);
			Assert::IsTrue(V[1].compare("GoodBye") == 0);
		}
		TEST_METHOD(tlam22_TestMethod5) {
			myvector<int> V(10);
			for (int i = 0; i < 20; i++)
			{
				V.push_back(i);
			}
			myvector<int>V2 = V;
			for (int i = 0; i < 20; i++)
			{
				Assert::IsTrue(V[i] == V2[i]);
			}
		}
		TEST_METHOD(tlam22_TestMethod6) {
			myvector<int> V(10);
			for (int i = 0; i < 20; i++)
			{
				V.push_back(i);
			}
			myvector<int>V2 = V;
			V2[3] = 101;
			Assert::IsTrue(V[3] == 3);
			Assert::IsTrue(V2[3] == 101);
		}
		TEST_METHOD(tlam22_TestMethod7) {
			myvector<int>V(10);

			for (int i = 0; i < 20; i++)
			{
				V.push_back(i);
			}
			myvector<int>V2 = V;
			Assert::IsTrue(V2.size() == V.size());
		}
		TEST_METHOD(tlam22_TestMethod8) {
			myvector<int>V(10);

			for (int i = 0; i < 20; i++)
			{
				V.push_back(i);
			}
			myvector<int>V2 = V;
			Assert::IsTrue(V2.capacity() == V.capacity());
		}
		TEST_METHOD(tlam22_TestMethod9) {
			myvector<string> V(6);
			V.push_back("HI");
			V.push_back("GoodBye");
			myvector<string>V2 = V;
			Assert::IsTrue(V2[0].compare("HI") == 0);
			Assert::IsTrue(V2[1].compare("GoodBye") == 0);
		}

		TEST_METHOD(tlam22_TestMethod10) {
			myvector<int>V(10);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() != V.back());
		}
		//
		// Tan Le
		// U. of Illinois, Chicago
		// CS341, Fall 2016
		// HW //




		// Testing if two nodes are linked together
		TEST_METHOD(tle51_TestMethod1) {
			myvector<int> V(2);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V[1] == 1 && V[2] == 2);
		}

		// Check if copy constructor have made a separate copy
		TEST_METHOD(tle51_TestMethod2) {
			myvector<int> V(10);

			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}

			myvector<int> V2 = V;
			V2[0] = 10;

			Assert::IsTrue(V2[0] != V[0] && V.size() == V2.size());
		}

		// Copy constructor test
		TEST_METHOD(tle51_TestMethod3) {
			myvector<int> V(10);

			for (int i = 0; i < 20; i++) {
				V.push_back(i);
			}

			myvector<int> V2 = V;

			Assert::IsTrue(V[2] == V2[2]);
		}

		// Test the operator []
		TEST_METHOD(tle51_TestMethod4) {
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[1] == 2);
		}

		// Test the capacity() function
		TEST_METHOD(tle51_TestMethod5) {
			myvector<int> V(10);

			for (int i = 0; i < 22; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.capacity() == 30);
		}

		// Test if insertion is done correctly
		TEST_METHOD(tle51_TestMethod6) {
			myvector<int> V(10);

			for (int i = 0; i < 20; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.back() == V[V.size() - 1]);
		}

		// Test if copy are in different memory location
		TEST_METHOD(tle51_TestMethod7) {
			myvector<int> V(10);
			V.push_back(1);

			myvector<int> V2 = V;
			Assert::IsTrue(&V != &V2);
		}

		// Check if number of elements is less than capacity
		TEST_METHOD(tle51_TestMethod8) {
			myvector<int> V(10);

			for (int i = 0; i < 314; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.size() <= V.capacity());
		}

		// Test that push-back update element count
		TEST_METHOD(tle51_TestMethod9) {
			myvector<int> V(10);

			V.push_back(0);
			int count = V.size();
			V.push_back(1);

			Assert::IsTrue(count + 1 == V.size());
		}

		// Test for string type
		TEST_METHOD(tle51_TestMethod10) {
			myvector<std::string> V(10);

			V.push_back("Hello");

			Assert::IsTrue(V[0] == "Hello");
		}





		TEST_METHOD(usiddi4_Test1)
		{
			myvector<int> V(10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
		}

		TEST_METHOD(usiddi4_Test2)
		{
			myvector<int> V(10);
			Assert::IsTrue(V.capacity() == 10);

			V.push_back(4);
			Assert::IsTrue(V.capacity() == 10);


		}

		TEST_METHOD(usiddi4_Test3)
		{
			myvector<int> V1(5);
			Assert::IsTrue(V1.capacity() == 5);
		}

		TEST_METHOD(usiddi4_Test4)
		{
			myvector<int> V(10);

			V.push_back(1);
			Assert::IsTrue(V.front() == 1);

			V.push_back(2);
			Assert::IsTrue(V.back() == 2);

			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);

		}

		TEST_METHOD(usiddi4_Test5)
		{
			myvector<int> V(5);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			Assert::IsTrue(V.size() == 3);
			Assert::IsTrue(V.capacity() == 5);
		}

		TEST_METHOD(usiddi4_Test6)
		{
			myvector<int> V(3);
			V.push_back(1);
			Assert::IsTrue(V.size() == 1);
			V.push_back(1);
			Assert::IsTrue(V.size() == 2);
			V.push_back(1);
			Assert::IsTrue(V.size() == 3);
		}

		TEST_METHOD(usiddi4_Test7)
		{
			myvector<int> V;
			Assert::IsTrue(V.capacity() == 100);
		}

		TEST_METHOD(usiddi4_Test8)
		{
			myvector<int> V(10);
			V.push_back(0);
			Assert::IsTrue(V[0] == 0);
			Assert::IsTrue(V.size() == 1);
		}

		TEST_METHOD(usiddi4_Test9)
		{
			myvector<double> V(10);
			V.push_back(3.2);
			Assert::IsTrue(V[0] == 3.2);
			V.push_back(4.41);
			Assert::IsTrue(V[1] == 4.41);

		}

		TEST_METHOD(usiddi4_Test10)
		{
			myvector<string> V(10);
			V.push_back("Hello");
			Assert::IsTrue(V[0] == "Hello");
			V.push_back("Hi");
			Assert::IsTrue(V[1] == "Hi");
		}


		TEST_METHOD(vleono2_Test1) {
			myvector<int>  V(10);  // nodesize of 10
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);

		}

		//TEST_METHOD(vleono2_Test2) {
		//	myvector<int>  V(10);  // nodesize of 10
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	myvector<int> V2;
		//	copy(V.begin(), V.end(), V2.begin());   //makes a copy of the vector

		//	Assert::IsTrue(V.size() == V2.size());  //checks if the sizes are the same
		//}

		//TEST_METHOD(vleono2_Test3) {
		//	myvector<int>  V(10);  // nodesize of 10
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	myvector<int> V2;
		//	copy(V.begin(), V.end(), V2.begin());		//makes a copy of the vector
		//	Assert::IsTrue(V == V2);					//checks if vectors are the same
		//}

		TEST_METHOD(vleono2_Test4)
		{
			myvector<int> V(10);
			V.push_back(1);
			int i = V.back();        //after one push checks the last element
			V.push_back(2);
			int j = V.back();        //after second push checks the value
			Assert::IsFalse(i == j);    //values must be different 

		}


		TEST_METHOD(vleono2_Test5)
		{
			myvector<int> V(10);
			for (int i = 1; i <= 10; i++)
			{
				V.push_back(i);
			}

			Assert::IsTrue(V.size() == V.capacity());			// if vector has 10 elements, then the size is == to capacity

		}

		//TEST_METHOD(vleono2_Test6)
		//{
		//	myvector<int> V(30);
		//	for (int i = 1; i <= 22; i++)
		//	{
		//		V.push_back(i);
		//	}

		//	Assert::IsTrue(V.getNumNodes() == 3);		//if vector has 30 elements, then it will have 3 nodes

		//}

		TEST_METHOD(vleono2_Test7)
		{
			myvector<int> V(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V[2] == 3);				// checks for the 3rd value in the vector
		}

		TEST_METHOD(vleono2_Test8)
		{
			myvector<int> V(10);
			V.push_back(1);
			Assert::IsTrue(V.front() == V.back());			//if it only has 1 element, the front is the same as the back



		}

		//TEST_METHOD(vleono2_Test9)
		//{
		//	myvector<int> V(10);
		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	iterator c = find_if(V.begin(), V.end(),     //if myvector is implemented correctly, it can use any c++ functions such as find_if
		//		[](int x) {									//looks for a value in the vector
		//		if (x == 3)
		//			return true;
		//		else
		//			return false;
		//	}
		//	);

		//	Assert::IsFalse(V.end() == c);           //if it has reached the end, then the element was not found, and should be false

		//}

		//TEST_METHOD(vleono2_Test10)
		//{
		//	myvector<int>* p = new myvector<int>(10);
		//	p->push_back(1);
		//	p->push_back(2);
		//	p->push_back(3);
		//	p->~myvector();

		//	Assert::IsNull(p);     // after deleting the vector the pointer should be null 
		//}






		TEST_METHOD(vthuth2_test1)
		{
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(5);

			Assert::IsTrue(V.size() == 4);
		}

		TEST_METHOD(vthuth2_test2)
		{
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(5);

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(vthuth2_test3)
		{
			myvector<int>  V(5);  // nodesize of 5:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(5);
			V.push_back(4);
			V.push_back(7);
			V.push_back(1);
			V.push_back(1);
			V.push_back(2);
			V.push_back(8); //more than 5 pushbacks, 9 pushbacks total

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(vthuth2_test4) //check for double
		{
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(5);

			//  if (std::find(V.begin(), V.end(), item) != V.end())
			//do_this();
			// else
			// do that();
		}

		//TEST_METHOD(vthuth2_test5) //negative
		//{
		//	myvector<int>  V(10);  // nodesize of 10:

		//	Assert::IsTrue(V.size() == 0);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(-1);

		//	vector<int>::iterator it = std::find_if(V.begin(), V.end(), isNegative);
		//}

		bool isNegative(int i)
		{
      return (i <= 0);
		}

		//TEST_METHOD(vthuth2_test6) //large size
		//{
		//	myvector<int>  V(10);  // nodesize of 10:

		//	Assert::IsTrue(V.size() == 0);

		//	V.push_back(1);
		//	V.push_back(2);
		//	V.push_back(3);
		//	V.push_back(-1);

		//	if (V.size() >= 10000)
		//		return false;
		//	else
		//		return true;
		//}



	//test size() after basic calls to push_back
		TEST_METHOD(wyou3_Test1)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		//test size() after a node link
		TEST_METHOD(wyou3_Test2)
		{
			myvector<int>  V(10);  // nodesize of 10:

			for (int i = 0; i < 11; i++)
				V.push_back(i);

			Assert::IsTrue(V.size() == 11);
		}

		//test capacity() with nodesize of 100
		TEST_METHOD(wyou3_Test3)
		{
			myvector<int>  V(100);  // nodesize of 100:

			Assert::IsTrue(V.capacity() == 100);
		}

		//test capacity with node size of 10 and 10 nodes
		TEST_METHOD(wyou3_Test4)
		{
			myvector<int>  V(10);  // nodesize of 10:

			for (int i = 0; i < 100; i++)
				V.push_back(i);

			Assert::IsTrue(V.capacity() == 100);
		}

		//test front() after node link
		TEST_METHOD(wyou3_Test5) {
			myvector<int>  V(10);  // nodesize of 10:

			for (int i = 0; i < 11; i++)
				V.push_back(i);

			Assert::IsTrue(V.front() == 0);
		}

		//test back() after node link
		TEST_METHOD(wyou3_Test6)
		{
			myvector<int>  V(10);  // nodesize of 10:

			for (int i = 0; i < 11; i++)
				V.push_back(i);

			Assert::IsTrue(V.back() == 10);
		}



		// test size and capacity
		TEST_METHOD(wyou3_Test9)
		{
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
			Assert::IsTrue(V.capacity() == 10);
		}

		// test size and capacity after link
		TEST_METHOD(wyou3_Test10)
		{
			myvector<int>  V(10);  // nodesize of 10:

			for (int i = 0; i < 11; i++)
				V.push_back(i);

			Assert::IsTrue(V.size() == 11);
			Assert::IsTrue(V.capacity() == 20);
		}





		TEST_METHOD(xhe23_Test1)
		{
			myvector<int> V(10); //nodesize of 10:

			for (int i = 0; i < 15; ++i)
				V.push_back(i * 5);

			Assert::IsTrue(V.capacity() == 20);
		}

		TEST_METHOD(xhe23_Test2)
		{
			myvector<int> V(10); //nodesize of 10:

			for (int i = 0; i < 13; ++i)
				V.push_back(i * 8);

			Assert::IsTrue(V.size() == 13);
		}

		//TEST_METHOD(xhe23_Test3)
		//{
		//	myvector<int> V(10); //nodesize of 10:

		//	for (int i = 0; i < 5; ++i)
		//		V.push_back(i * 2);

		//	Assert::IsTrue(V[3] == 15);
		//}

		TEST_METHOD(xhe23_Test4)
		{
			myvector<int> V(10); //nodesize of 10:

			Assert::IsTrue(V.size() == 0);
		}

		TEST_METHOD(xhe23_Test5)
		{
			myvector<int> V(10); //nodesize of 10:

			Assert::IsTrue(V.capacity() == 10);
		}

		TEST_METHOD(xhe23_Test6)
		{
			myvector<int> V(10); //nodesize of 10:

			for (int i = 0; i < 25; ++i)
				V.push_back(i * 2);

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 48);
		}

		TEST_METHOD(xhe23_Test7)
		{
			myvector<char> V(10); //nodesize of 10:

			for (int i = 0; i < 10000; ++i)
				V.push_back('a');

			Assert::IsTrue(V.capacity() == 10000);
		}

		TEST_METHOD(xhe23_Test8)
		{
			myvector<double> V(10); //nodesize of 10:

			for (int i = 0; i < 532; ++i)
				V.push_back(3.14159);

			Assert::IsTrue(V.capacity() == 540);
		}

		TEST_METHOD(xhe23_Test9)
		{
			myvector<string> V(10); //nodesize of 10:

			for (int i = 0; i < 360; ++i)
				V.push_back("hello");

			Assert::IsTrue(V.size() == 360);
		}

		TEST_METHOD(xhe23_Test10)
		{
			myvector<int> V(10);

			V.push_back(1);

			Assert::IsTrue(V.front() == V.back());
		}
		// Ying LIU
		// YLIU222


		//TEST_METHOD(yliu222_Test1)
		//{
		//	myvector <int> V(10);
		//
		//	V.size() == 10;
		//	V.capacity() == 10;
		//
		//	Assert::IsTrue(V.size() == v.capacity());
		//}
		//
		//TEST_METHOD(yliu222_TEST2)
		//{
		//	myvector <int> V(10);
		//
		//	V.size() == 0;
		//	V.capacity() == 0;
		//
		//	Assert::IsTrue(V.isEmpty());
		//}
		//
		//TEST_METHOD(yliu222_TEST3)
		//{
		//	myvector <int> V(10);
		//	int var;
		//
		//	V.insert(5);
		//	Assert::IsFalse(V.isEmpty());
		//}
		//
		//
		//TEST_METHOD(yliu222_TEST4)
		//{
		//	myvector <int> V(10);
		//	int var;
		//
		//	V.makeEmpty();
		//	Assert::IsTrue(V.isEmpty());
		//}

		TEST_METHOD(yliu222_TEST5)
		{
			myvector <int> V(10);
			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.front() != V.back());
		}

		TEST_METHOD(yliu222_TEST6)
		{
			myvector <int> V(10);
			V.push_back(1);
			V.push_back(2);

			Assert::IsTrue(V.front() != V.back());
		}

		//TEST_METHOD(yliu222_TEST7)
		//{
		//	myvector <int> V(10);
		//	V.push_back(1);
		//	V.push_back(2);
		//
		//	Assert::IsTrue(V.Max == 2);
		//}
		//
		//TEST_METHOD(yliu222_Test7)
		//{
		//	myvector <int> V(10);
		//
		//	V.size() == 8;
		//	V.capacity() == 10;
		//
		//	Assert::IsFalse(V.size() == v.capacity());
		//}

 		
		TEST_METHOD(yyu31_Test1) {
			myvector<int>  V(10); // nodesize of 10;

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}
	
		TEST_METHOD(yyu31_Test2)
		{
			myvector<int> V(10); // nodesize of 10;

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}
		//Test size without setting nodesize
		TEST_METHOD(yyu31_Test3) {
			myvector<int> V;
			Assert::IsTrue(V.size() == 0);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.size() == 3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			Assert::IsTrue(V.size() == 6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			Assert::IsTrue(V.size() == 9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);
			Assert::IsTrue(V.size() == 12);

		}
		//Test capacity
		TEST_METHOD(yyu31_Test4) {
			myvector<int> V(10);// nodesize of 10;
			Assert::IsTrue(V.capacity() >= 10);
		}
		//Test operator
		TEST_METHOD(yyu31_Test5) {
			myvector<int> V(10);// nodesize of 10;
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(100);
			Assert::IsTrue(V.operator[](4) == 100);
		}
		//Test two vectors front elements
		TEST_METHOD(yyu31_Test6) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2(20);// nodesize of 20;
			V1.push_back(1);
			V2.push_back(2);
			Assert::IsTrue(V1.front() < V2.front());
		}
		//Test two vectors elements
		TEST_METHOD(yyu31_Test7) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2(20);// nodesize of 20;
			V1.push_back(1);
			V2.push_back(2);
			V2.push_back(1);
			Assert::IsTrue(V1.front() == V2.back());
		}
		//Test two vector sizes
		TEST_METHOD(yyu31_Test8) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2(20);// nodesize of 20;
			V1.push_back(1);
			V1.push_back(2);
			V2.push_back(3);
			V2.push_back(4);
			Assert::IsTrue(V1.size() == V2.size());
		}
		//Test two cector sizes V2 without setting nodesize
		TEST_METHOD(yyu31_Test9) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2;
			V1.push_back(1);
			V1.push_back(2);
			V2.push_back(3);
			Assert::IsTrue(V1.size() > V2.size());
		}
		//Test two vector capacities
		TEST_METHOD(yyu31_Test10) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2(20);// nodesize of 20;
			Assert::IsTrue(V1.capacity() < V2.capacity());
		}
		//Test two vector capacities V2 without setting nodesize
		TEST_METHOD(yyu31_Test11) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2;
			V1.push_back(1);
			V1.push_back(2);
			V2.push_back(3);
			Assert::IsTrue(V1.capacity() < V2.capacity());
		}
		//Test two vector operators V2 without setting nodesize
		TEST_METHOD(yyu31_Test12) {
			myvector<int> V1(10);// nodesize of 10;
			myvector<int> V2;
			V1.push_back(1);
			V1.push_back(2);
			V1.push_back(3);
			V2.push_back(4);
			V2.push_back(5);
			Assert::IsTrue(V1.operator[](2) < V2.operator[](1));
		}



		TEST_METHOD(zhamme2_Test1) {
			myvector<int> V(10);

			V.push_back(42);
			V[0] = 24;
			// Assert that square-bracket operator works
			Assert::AreEqual(V.front(), 24);
		}

		TEST_METHOD(zhamme2_Test2) {
			myvector<int> V(1);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);

			// Assert that allocating a new node and accessing its contents works
			Assert::AreEqual(V.back(), 4);
		}

		TEST_METHOD(zhamme2_Test3) {
			myvector<int> V(1);

			V.push_back(1);
			V.push_back(2);
			V[1] = 21;

			// Assert that allocating a new node and accessing/changing its contents works
			Assert::AreEqual(V.back(), 21);
		}

		TEST_METHOD(zhamme2_Test4) {
			myvector<int> V(4);

			// Assert that capacity is being properly recorded
			Assert::AreEqual(V.capacity(), 4);

			V.push_back(128);
			V.push_back(256);
			V.push_back(512);

			// Assert that capacity did not need to be changed
			Assert::AreEqual(V.capacity(), 4);
		}

		TEST_METHOD(zhamme2_Test5) {
			myvector<int> V(2);

			V.push_back(64);
			V.push_back(128);
			V.push_back(256);
			V.push_back(512);
			V.push_back(1024);

			// Assert that capacity is being properly recorded *and* is not equal to size()
			Assert::IsTrue(V.capacity() != V.size());
		}

		TEST_METHOD(zhamme2_Test6) {
			myvector<int> V(5);
			for (int i = 0; i < 10; i++)
				V.push_back(i);

			// Manually sum up
			int sum_manual = 0;
			for (int i = 0; i < V.size(); i++)
				sum_manual += V[i];

			// Use a range-based for loop to compute sum
			int sum_accum = 0;
			for (int i : V)
				sum_accum += V[i];

			// Test if iteration is possible
			Assert::AreEqual(sum_manual, sum_accum);
		}

		//TEST_METHOD(zhamme2_Test7) {
		//	myvector<int> V(5);
		//	V.push_back(5);
		//	V.push_back(10);

		//	// Assert that iterators point to the right values
		//	Assert::AreEqual(V.front(), *(V.begin()));
		//	Assert::AreEqual(V.back(), *(V.end() - 1));
		//}

		TEST_METHOD(zhamme2_Test8) {
			// Assert that size is properly being recorded
			myvector<int> V(4);
			for (int i = 0; i < 100; i++)
				V.push_back(i);

			Assert::AreEqual(V.size(), 100);
		}

		TEST_METHOD(zhamme2_Test9) {
			myvector<int> V(10);
			for (int i = 0; i < 10; i++)
				V.push_back(i * 2);

			myvector<int> V2 = V;
			V2[0] = 123;

			// Assert that the copy constructor made a deep copy
			Assert::AreNotEqual(V.front(), V2.front());
		}

		TEST_METHOD(zhamme2_Test10) {
			myvector<int> V(10);
			for (int i = 0; i < 10; i++)
				V.push_back(256);

			// Assert that front and back point to different locations, i.e. they advance properly
			Assert::IsTrue(&V.front() != &V.back());
		}








		TEST_METHOD(zjones4_test1)
		{
			myvector<int>  V(20);  // nodesize of 20:


			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(11);
			V.push_back(12);
			V.push_back(13);
			V.push_back(14);
			V.push_back(15);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(-60);
			V.push_back(0);
			V.push_back(333);
			V.push_back(4444);

			Assert::IsTrue(V.capacity() == 40);


		}

		TEST_METHOD(zjones4_test2)
		{

			myvector<int>  V(10);

			Assert::IsTrue(V.capacity() == 10);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);
			V.push_back(13);




			Assert::IsTrue(V.capacity() == 20);




		}


		TEST_METHOD(zjones4_test3) {

			myvector<int>  V(10);


			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			Assert::AreEqual(V.capacity(), V.size());

		}

		TEST_METHOD(zjones4_test4) {

			myvector<int> V1(10);
			myvector<int> V2(5);

			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);
			V1.push_back(111);
			V2.push_back(222);

			Assert::AreEqual(V1.size(), V2.size());
			Assert::AreNotEqual(V1.capacity(), V2.capacity());



		}
		TEST_METHOD(zjones4_test5) {

			myvector<int>  V(5);


			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);


			Assert::IsFalse(V.back() == 9);


			V.push_back(9);



			Assert::IsTrue(V.back() == 9);
			Assert::IsTrue(V.front() == 1);

			V.push_back(10);
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			Assert::IsTrue(V.size() == 20);
			Assert::AreEqual(V.size(), V.capacity());


		}
		TEST_METHOD(zjones4_test6) {

			myvector<char> C(72);

			C.push_back('X');
			C.push_back('X');
			C.push_back('Z');

			Assert::IsTrue(C.back() == 'Z');
			Assert::IsTrue(C.capacity() == 72);
			Assert::IsTrue(C.size() == 3);


		}


		TEST_METHOD(zjones4_test7) {


			myvector<int> V1(10);
			V1.push_back(1);
			V1.push_back(2);
			V1.push_back(3);
			V1.push_back(4);
			V1.push_back(5);
			V1.push_back(6);
			V1.push_back(7);
			V1.push_back(8);
			V1.push_back(9);
			V1.push_back(10);


			myvector<int> V2 = V1;

			Assert::AreEqual(V1.front(), V2.front());
			Assert::AreEqual(V1.back(), V2.back());
			Assert::AreEqual(V1.capacity(), V2.capacity());

		}
		TEST_METHOD(zjones4_test8) {


			myvector<int> V(15);
			myvector<int> V2(5);
			myvector<int> V3(2);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);

			V2.push_back(1);
			V2.push_back(2);
			V2.push_back(3);
			V2.push_back(4);
			V2.push_back(5);
			V2.push_back(6);
			V2.push_back(7);
			V2.push_back(8);
			V2.push_back(9);
			V2.push_back(10);
			V2.push_back(11);
			V2.push_back(12);
			V2.push_back(13);
			V2.push_back(14);



			V3.push_back(1);
			V3.push_back(2);
			V3.push_back(3);
			V3.push_back(4);
			V3.push_back(5);
			V3.push_back(6);
			V3.push_back(7);
			V3.push_back(8);
			V3.push_back(9);
			V3.push_back(10);
			V3.push_back(11);
			V3.push_back(12);
			V3.push_back(13);
			V3.push_back(14);


			Assert::IsTrue(V2.capacity() == 15);
			Assert::IsTrue(V2.size() == 14);

			Assert::IsTrue(V2.capacity() != V3.capacity());
			Assert::IsTrue(V2.size() == V3.size());

			Assert::IsTrue(V2.capacity() == V.capacity());



		}

		//TEST_METHOD(zjones4_test9) {

		//	myvector<int> V1(2);

		//	V1.push_back(1);
		//	V1.push_back(2);
		//	V1.push_back(3);
		//	V1.push_back(4);
		//	V1.push_back(5);
		//	V1.push_back(6);
		//	V1.push_back(7);
		//	V1.push_back(8);
		//	V1.push_back(9);
		//	V1.push_back(10);

		//	myvector<int> V2 = V1;

		//	V1.~myvector();

		//	Assert::IsTrue(V2.capacity() == 10);
		//	Assert::IsTrue(V2.size() == 10);


		//}

		TEST_METHOD(zjones4_test10) {

			myvector<double> D(7);

			D.push_back(74.5);
			D.push_back(-1245.664);
			D.push_back(3224.0);


			Assert::IsTrue(D.back() == 3224);
			Assert::IsTrue(D.front() == 74.5);





		}




		//TEST 1
		TEST_METHOD(zpatel20_CheckCapacity)
		{
			myvector<int> V(30);
			//Assert::IsTrue(V.capacity() == 0);
			for (int i = 0; i < 22; i++)
				V.push_back(i);
			Assert::IsTrue(V.size() == 22);
			Assert::IsTrue(V.capacity() == 30);
		}

		////TEST 2
		//TEST_METHOD(zpatel20_CheckCapacityMedium)
		//{
		//	myvector<int> V;
		//	//Assert::IsTrue(V.capacity() == 0);
		//	for (int i = 0; i < 150; i++)
		//		V.push_back(i);
		//	Assert::IsTrue(V.size() == 150);
		//	Assert::IsTrue(V.capacity() == 150);
		//}

		////TEST 3
		//TEST_METHOD(zpatel20_CheckCapacityBig)
		//{
		//	myvector<int> V;
		//	//Assert::IsTrue(V.capacity() == 0);
		//	for (int i = 0; i < 220; i++)
		//		V.push_back(i);
		//	Assert::IsTrue(V.size() == 220);
		//	Assert::IsTrue(V.capacity() == 220);
		//}

		//TEST 4
		TEST_METHOD(zpatel20_BracketOperatorSmall)
		{
			myvector<int> V;
			//Test For [] operator								  
			for (int i = 0; i < 8; i++)
				V.push_back(i);
			Assert::IsTrue(V[2] == 2);
			Assert::IsTrue(V[3] == 3);
			Assert::IsTrue(V[4] == 4);
			Assert::IsTrue(V[5] == 5);
			Assert::IsTrue(V[6] == 6);
		}

		//TEST 5
		TEST_METHOD(zpatel20_BracketOperatorMedium)
		{
			myvector<int> V(15);
			//Test For [] operator								  
			for (int i = 0; i < 7; i++)
				V.push_back(i);
			Assert::IsTrue(V[2] == 2);
			Assert::IsTrue(V[3] == 3);
			Assert::IsTrue(V[4] == 4);
			Assert::IsTrue(V[5] == 5);
			Assert::IsTrue(V[6] == 6);
		}

		//TEST 6
		TEST_METHOD(zpatel20_BracketOperatorBig)
		{
			myvector<int> V(30);
			//Test For [] operator								  
			for (int i = 0; i < 22; i++)
				V.push_back(i);
			Assert::IsTrue(V[4] == 4);
			Assert::IsTrue(V[10] == 10);
			Assert::IsTrue(V[15] == 15);
			Assert::IsTrue(V[20] == 20);
			Assert::IsTrue(V[21] == 21);
		}

		//TEST 7
		TEST_METHOD(zpatel20_FrontBackLargeArray)
		{
			myvector<int> V(30);
			//Test For [] operator								  
			for (int i = 0; i < 22; i++)
				V.push_back(i);
			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 21);
		}

		////TEST 8
		//TEST_METHOD(zpatel20_CopyConstructorSmall)
		//{
		//	myvector<int> V;
		//	//Test For [] operator								  
		//	for (int i = 0; i < 8; i++)
		//		V.push_back(i);
		//	//V.push_back(8);
		//	myvector<int> copyV = V;
		//	Assert::IsTrue(copyV.size() == 8);
		//	Assert::IsTrue(copyV.capacity() == 10);
		//	Assert::IsTrue(copyV.front() == 0);
		//	Assert::IsTrue(copyV.back() == 7);
		//}

		////TEST 9
		//TEST_METHOD(zpatel20_CopyConstructorBig)
		//{
		//	myvector<int> V;
		//	//Test For [] operator								  
		//	for (int i = 0; i < 22; i++)
		//		V.push_back(i);
		//	//V.push_back(8);
		//	myvector<int> copyV = V;
		//	Assert::IsTrue(copyV.size() == 22);
		//	Assert::IsTrue(copyV.capacity() == 30);
		//	Assert::IsTrue(copyV.front() == 0);
		//	Assert::IsTrue(copyV.back() == 21);
		//}

		////TEST 10
		//TEST_METHOD(zpatel20_DeepCopyConstructorBig)
		//{
		//	myvector<int> V;
		//	//Test For [] operator								  
		//	for (int i = 0; i < 22; i++)
		//		V.push_back(i);
		//	myvector<int> copyV = V;
		//	copyV.push_back(8);
		//	Assert::IsTrue(V.size() == 22);
		//	Assert::IsTrue(V.capacity() == 30);
		//	Assert::IsTrue(V.front() == 0);
		//	Assert::IsTrue(V.back() == 21);
		//}



		TEST_METHOD(zzeng23_Test1)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10:
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 3);
		}
		TEST_METHOD(zzeng23_Test2) {
			myvector<int>  V(10);  // nodesize of 10:

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}
		TEST_METHOD(zzeng23_Test3) {
			myvector<int>  V(10);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.capacity() == 10);
		}
		TEST_METHOD(zzeng23_Test4)
		{
			// TODO: Your test code here
			myvector<int>  V(10);  // nodesize of 10:
			V.push_back(5);
			V.push_back(9);
			V.push_back(100);
			Assert::IsTrue(V.front() == 5);
			Assert::IsTrue(V.back() == 100);
		}
		TEST_METHOD(zzeng23_Test5)
		{
			// TODO: Your test code here
			myvector<int>  V(3);  // nodesize of 10:
			V.push_back(5);
			V.push_back(9);
			V.push_back(0);
			Assert::IsTrue(V.front() == 5);
			Assert::IsTrue(V.back() == 0);
		}
		TEST_METHOD(zzeng23_Test6) {
			myvector<int>  V(5);  // nodesize of 10:

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);

			V.push_back(34);

			Assert::IsTrue(V.size() == 4);
		}
		TEST_METHOD(zzeng23_Test7) {
			myvector<int>  V(50);  // nodesize of 10:

			V.push_back(1);

			Assert::IsTrue(V.capacity() == 50);
		}


		TEST_METHOD(zzeng23_Test10) {
			myvector<int> V(20); //nodesize of 20:

			V.push_back(26);
			V.push_back(100);
			V.push_back(1000);

			Assert::IsTrue(V.back() == 1000);
		}

	};
}
