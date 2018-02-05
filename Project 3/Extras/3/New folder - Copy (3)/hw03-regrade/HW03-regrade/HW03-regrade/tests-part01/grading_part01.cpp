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
    // The first set of tests are basic functionality, where we just need 1 node,
    // and no iterators.
    //
    TEST_METHOD(_grading_set1_T01)
    {
      myvector<int>  V;  // default nodesize:

      Assert::IsTrue(V.size() == 0);
    }

    TEST_METHOD(_grading_set1_T02)
    {
      myvector<int>  V;  // default nodesize:

      Assert::IsTrue(V.capacity() == 100);  // should be 100 from handout
    }

    TEST_METHOD(_grading_set1_T03)
    {
      myvector<int>  V(25);  // nodesize = 25:

      Assert::IsTrue(V.size() == 0);
    }

    TEST_METHOD(_grading_set1_T04)
    {
      myvector<int>  V(25);  // nodesize = 25:

      Assert::IsTrue(V.capacity() == 25);  
    }

    TEST_METHOD(_grading_set1_T05)
    {
      myvector<int>  V(32);

      V.push_back(1);

      Assert::IsTrue(V.size() == 1);
    }

    TEST_METHOD(_grading_set1_T06)
    {
      myvector<int>  V(32);

      V.push_back(1);

      Assert::IsTrue(V.capacity() == 32);
    }

    TEST_METHOD(_grading_set1_T07)
    {
      myvector<int>  V(32);

      V.push_back(1);

      Assert::IsTrue(V.front() == 1);
    }

    TEST_METHOD(_grading_set1_T08)
    {
      myvector<int>  V(32);

      V.push_back(1);

      Assert::IsTrue(V.back() == 1);
    }

    TEST_METHOD(_grading_set1_T09)
    {
      myvector<int>  V(32);

      V.push_back(1);

      Assert::IsTrue(V[0] == 1);
    }

    TEST_METHOD(_grading_set1_T10)
    {
      myvector<char>  V(50);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.size() == 3);
    }

    TEST_METHOD(_grading_set1_T11)
    {
      myvector<char>  V(50);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.capacity() == 50);
    }

    TEST_METHOD(_grading_set1_T12)
    {
      myvector<char>  V(50);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.front() == 'a');
    }

    TEST_METHOD(_grading_set1_T13)
    {
      myvector<char>  V(50);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.back() == 'c');
    }

    TEST_METHOD(_grading_set1_T14)
    {
      myvector<char>  V(50);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V[2] == 'c');
      Assert::IsTrue(V[0] == 'a');
      Assert::IsTrue(V[1] == 'b');
    }

    TEST_METHOD(_grading_set1_T15)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.size() == 3);
    }

    TEST_METHOD(_grading_set1_T16)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.capacity() == 3);
    }

    TEST_METHOD(_grading_set1_T17)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.front() == 'a');
    }

    TEST_METHOD(_grading_set1_T18)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V.back() == 'c');
    }

    TEST_METHOD(_grading_set1_T19)
    {
      myvector<char>  V(3);

      V.push_back('a');
      V.push_back('b');
      V.push_back('c');

      Assert::IsTrue(V[0] == 'a');
      Assert::IsTrue(V[2] == 'c');
      Assert::IsTrue(V[1] == 'b');
    }

    TEST_METHOD(_grading_set1_T20)
    {
      const int N = 17317;  // must be odd:
      myvector<int>  V(N);
      myvector<int>  V2(N);

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

    TEST_METHOD(_grading_set1_T21)
    {
      myvector<int>      VI(1);
      myvector<string>   VS(2);
      myvector<double>   VF(3);
      myvector<char>     VC(4);

      VI.push_back(999);
      VS.push_back("apple");
      VF.push_back(1.0);
      VF.push_back(3.14159);

      Assert::IsTrue(VI.size() == 1);
      Assert::IsTrue(VS.size() == 1);
      Assert::IsTrue(VF.size() == 2);
      Assert::IsTrue(VC.size() == 0);
    }

    TEST_METHOD(_grading_set1_T22)
    {
      myvector<int>      VI(1);
      myvector<string>   VS(2);
      myvector<double>   VF(3);
      myvector<char>     VC(4);

      VI.push_back(999);
      VS.push_back("apple");
      VF.push_back(1.0);
      VF.push_back(3.14159);

      Assert::IsTrue(VI.capacity() == 1);
      Assert::IsTrue(VS.capacity() == 2);
      Assert::IsTrue(VF.capacity() == 3);
      Assert::IsTrue(VC.capacity() == 4);
    }

    TEST_METHOD(_grading_set1_T23)
    {
      myvector<int>      VI(1);
      myvector<string>   VS(2);
      myvector<double>   VF(3);
      myvector<char>     VC(4);

      VI.push_back(999);
      VS.push_back("apple");
      VS.push_back("orange");
      VF.push_back(1.0);
      VF.push_back(2.0);
      VF.push_back(3.14159);

      Assert::IsTrue(VI.front() == 999);
      Assert::IsTrue(VS.front() == "apple");
      Assert::IsTrue(abs(VF.front() - 1.0) < 0.0001);
    }

    TEST_METHOD(_grading_set1_T24)
    {
      myvector<int>      VI(1);
      myvector<string>   VS(2);
      myvector<double>   VF(3);
      myvector<char>     VC(4);

      VI.push_back(999);
      VS.push_back("apple");
      VS.push_back("orange");
      VF.push_back(1.0);
      VF.push_back(2.0);
      VF.push_back(3.14159);

      Assert::IsTrue(VI.back() == 999);
      Assert::IsTrue(VS.back() == "orange");
      Assert::IsTrue(abs(VF.back() - 3.14159) < 0.0001);
    }

    TEST_METHOD(_grading_set1_T25)
    {
      myvector<int>      VI(1);
      myvector<string>   VS(2);
      myvector<double>   VF(3);
      myvector<char>     VC(4);

      VI.push_back(999);
      VS.push_back("apple");
      VS.push_back("orange");
      VF.push_back(1.0);
      VF.push_back(2.0);
      VF.push_back(3.14159);

      Assert::IsTrue(VI[0] == 999);
      Assert::IsTrue(VS[1] == "orange");
      Assert::IsTrue(VS[0] == "apple");
      Assert::IsTrue(abs(VF[2] - 3.14159) < 0.0001);
      Assert::IsTrue(abs(VF[1] - 2.0) < 0.0001);
      Assert::IsTrue(abs(VF[0] - 1.0) < 0.0001);
    }

  };

}