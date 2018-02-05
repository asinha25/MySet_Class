//
// Unit tests for grading of myvector<T> class.
//
// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS341, Fall 2016
// HW #03 -- Solution
//

#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>
#include "..\myvector\myvector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


//
// Grading tests for HW #3, myvector<T>
//

namespace myvectorUnitTest
{		
  TEST_CLASS(UnitTest2)
  {
  public:

    //
    // The second set of tests force multiple nodes
    // to be created:
    //
    TEST_METHOD(_grading_set2_T01)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');
      V.push_back('d');
      V.push_back('e');
      V.push_back('f');
      V.push_back('g');
      V.push_back('h');
      V.push_back('i');

      Assert::IsTrue(V.size() == 9);
    }

    TEST_METHOD(_grading_set2_T02)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');
      V.push_back('d');
      V.push_back('e');
      V.push_back('f');
      V.push_back('g');
      V.push_back('h');
      V.push_back('i');

      Assert::IsTrue(V.capacity() == 9);
    }

    TEST_METHOD(_grading_set2_T03)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');
      V.push_back('d');
      V.push_back('e');
      V.push_back('f');
      V.push_back('g');
      V.push_back('h');
      V.push_back('i');

      Assert::IsTrue(V.front() == 'a');
    }

    TEST_METHOD(_grading_set2_T04)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');
      V.push_back('d');
      V.push_back('e');
      V.push_back('f');
      V.push_back('g');
      V.push_back('h');
      V.push_back('i');

      Assert::IsTrue(V.back() == 'i');
    }

    TEST_METHOD(_grading_set2_T05)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');
      V.push_back('d');
      V.push_back('e');
      V.push_back('f');
      V.push_back('g');
      V.push_back('h');
      V.push_back('i');

      Assert::IsTrue(V[8] == 'i');
      Assert::IsTrue(V[7] == 'h');
      Assert::IsTrue(V[6] == 'g');
      Assert::IsTrue(V[3] == 'd');
      Assert::IsTrue(V[4] == 'e');
      Assert::IsTrue(V[5] == 'f');
      Assert::IsTrue(V[2] == 'c');
      Assert::IsTrue(V[1] == 'b');
      Assert::IsTrue(V[0] == 'a');
    }

    TEST_METHOD(_grading_set2_T06)
    {
      myvector<string>  V(3);

      V.push_back("a");
      V.push_back("b");
      V.push_back("c");
      V.push_back("d");
      V.push_back("e");
      V.push_back("f");
      V.push_back("g");
      V.push_back("h");
      V.push_back("i");
      V.push_back("x");

      Assert::IsTrue(V.size() == 10);
    }

    TEST_METHOD(_grading_set2_T07)
    {
      myvector<string>  V(3);

      V.push_back("a");
      V.push_back("b");
      V.push_back("c");
      V.push_back("d");
      V.push_back("e");
      V.push_back("f");
      V.push_back("g");
      V.push_back("h");
      V.push_back("i");
      V.push_back("x");

      Assert::IsTrue(V.capacity() == 12);
    }

    TEST_METHOD(_grading_set2_T08)
    {
      myvector<string>  V(3);

      V.push_back("a");
      V.push_back("b");
      V.push_back("c");
      V.push_back("d");
      V.push_back("e");
      V.push_back("f");
      V.push_back("g");
      V.push_back("h");
      V.push_back("i");
      V.push_back("x");

      Assert::IsTrue(V.front() == "a");
    }

    TEST_METHOD(_grading_set2_T09)
    {
      myvector<string>  V(3);

      V.push_back("a");
      V.push_back("b");
      V.push_back("c");
      V.push_back("d");
      V.push_back("e");
      V.push_back("f");
      V.push_back("g");
      V.push_back("h");
      V.push_back("i");
      V.push_back("x");

      Assert::IsTrue(V.back() == "x");
    }

    TEST_METHOD(_grading_set2_T10)
    {
      myvector<string>  V(3);

      V.push_back("a");
      V.push_back("b");
      V.push_back("c");
      V.push_back("d");
      V.push_back("e");
      V.push_back("f");
      V.push_back("g");
      V.push_back("h");
      V.push_back("i");
      V.push_back("x");

      Assert::IsTrue(V[8] == "i");
      Assert::IsTrue(V[7] == "h");
      Assert::IsTrue(V[6] == "g");
      Assert::IsTrue(V[3] == "d");
      Assert::IsTrue(V[4] == "e");
      Assert::IsTrue(V[9] == "x");
      Assert::IsTrue(V[5] == "f");
      Assert::IsTrue(V[2] == "c");
      Assert::IsTrue(V[1] == "b");
      Assert::IsTrue(V[0] == "a");
    }

    //
    // trigger some destructors...
    //
    TEST_METHOD(_grading_set2_T11)
    {
      myvector<char> V(9);

      V.push_back('a');

      {
        const int N = 100;
        myvector<int>  V(9);

        for (int i = 1; i <= N; ++i)
        {
          V.push_back(-2 * i + 9);

          myvector<int> V2(7);
          for (int j = 0; j < N; ++j)
            V2.push_back(j);

          V.push_back(-2 * i + 10);

          Assert::IsTrue(V2.size() == N);
          Assert::IsTrue(V.size() == 2 * i);
        }

        Assert::IsTrue(V.size() == 2 * N);
      }//block

      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V[0] == 'a');

      {
        const int N = 2000;
        myvector<int>  V(10);

        for (int i = 1; i <= N; ++i)
          V.push_back(-2 * i + 9);

        Assert::IsTrue(V.size() == N);
      }

      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V[0] == 'a');
    }

    //
    // lots of elements, lots of nodes, extensive
    // testing of push_back and []:
    //
    TEST_METHOD(_grading_set2_T12)
    {
      const int N = 17317;  // must be odd:
      myvector<int>  V(313);
      myvector<int>  V2(313);

      for (int i = 0; i < N; ++i)
      {
        V.push_back(i);
        V2.push_back(0);
      }

      for (int i = 1; i < N; ++i)
      {
        V2[i] = V[i - 1] + V[i];
      }

      int count = 0;
      int sum = 0;

      Assert::IsTrue(V2[0] == 0);
      count++;

      for (int i = 1; i < N; ++i)
      {
        Assert::IsTrue(V2[i] == i + i - 1);
        count++;
        sum += V2[i];
      }

      Assert::IsTrue(count == N);
      int sumShouldBe = (2 * (N - 1))*((N - 1) / 2);
      Assert::IsTrue(sum == sumShouldBe);
    }

    //
    // lots of elements, lots of nodes, extensive
    // testing of push_back and [].  Smaller node
    // size than before.
    //
    TEST_METHOD(_grading_set2_T13)
    {
      const int N = 17317;  // must be odd:
      myvector<int>  V(10);
      myvector<int>  V2(10);

      for (int i = 0; i < N; ++i)
      {
        V.push_back(i);
        V2.push_back(0);
      }

      for (int i = 1; i < N; ++i)
      {
        V2[i] = V[i - 1] + V[i];
      }

      int count = 0;
      int sum = 0;

      Assert::IsTrue(V2[0] == 0);
      count++;

      for (int i = 1; i < N; ++i)
      {
        Assert::IsTrue(V2[i] == i + i - 1);
        count++;
        sum += V2[i];
      }

      Assert::IsTrue(count == N);
      int sumShouldBe = (2 * (N - 1))*((N - 1) / 2);
      Assert::IsTrue(sum == sumShouldBe);
    }

    //
    // lots of elements, lots of nodes, extensive
    // testing of push_back and [].  Node size of 1
    // in this case.
    //
    TEST_METHOD(_grading_set2_T14)
    {
      const int N = 17317;  // must be odd:
      myvector<int>  V(1);
      myvector<int>  V2(1);

      for (int i = 0; i < N; ++i)
      {
        V.push_back(i);
        V2.push_back(0);
      }

      for (int i = 1; i < N; ++i)
      {
        V2[i] = V[i - 1] + V[i];
      }

      int count = 0;
      int sum = 0;

      Assert::IsTrue(V2[0] == 0);
      count++;

      for (int i = 1; i < N; ++i)
      {
        Assert::IsTrue(V2[i] == i + i - 1);
        count++;
        sum += V2[i];
      }

      Assert::IsTrue(count == N);
      int sumShouldBe = (2 * (N - 1))*((N - 1) / 2);
      Assert::IsTrue(sum == sumShouldBe);
    }

    // 
    // general test:
    //
    TEST_METHOD(_grading_set2_T15)
    {
      const int N = 1000;
      const int NodeSize = 100;

      myvector<int> V(NodeSize);

      //
      // initialize: N, N-1, N-2, ..., 3, 2, 1
      //
      for (int i = 0; i < N; ++i)
        V.push_back(N - i);

      Assert::IsTrue(V[0] == N);
      Assert::IsTrue(V[1] == N - 1);
      Assert::IsTrue(V[2] == N - 2);
      Assert::IsTrue(V[N - 3] == 3);
      Assert::IsTrue(V[N - 2] == 2);
      Assert::IsTrue(V[N - 1] == 1);

      Assert::IsTrue(V.front() == N);
      Assert::IsTrue(V.back() == 1);

      for (int i = 0; i < N; ++i)
      {
        Assert::IsTrue(V[i] == (N - i));
      }

      V.push_back(0);
      Assert::IsTrue(V[N] == 0);
      Assert::IsTrue(V.size() == N + 1);

      // overwrite:
      for (int i = 0; i <= N; ++i)
        V[i] = i*i;

      for (int i = 0; i <= N; ++i)
      {
        Assert::IsTrue(V[i] == i*i);
      }
    }

  };

}