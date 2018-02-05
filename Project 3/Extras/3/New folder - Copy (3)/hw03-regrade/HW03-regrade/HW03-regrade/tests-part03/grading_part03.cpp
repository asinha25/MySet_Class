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
    // The third set of tests focus on copy constructor:
    //
    void s3_F01(myvector<char> V)
    {
      Assert::IsTrue(V.size() == 0);
    }

    TEST_METHOD(_grading_set3_T01)
    {
      myvector<char> V(10);

      Assert::IsTrue(V.size() == 0);

      s3_F01(V);

      Assert::IsTrue(V.size() == 0);
    }

    void s3_F02(myvector<char> V)
    {
      Assert::IsTrue(V.size() == 0);
      V.push_back('a');
      Assert::IsTrue(V.size() == 1);
    }

    TEST_METHOD(_grading_set3_T02)
    {
      myvector<char> V(10);

      Assert::IsTrue(V.size() == 0);

      s3_F02(V);

      Assert::IsTrue(V.size() == 0);
    }

    void s3_F03(myvector<char> V)
    {
      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'z');

      V.push_back('a');

      Assert::IsTrue(V.size() == 2);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'a');
    }

    TEST_METHOD(_grading_set3_T03)
    {
      myvector<char> V(10);

      Assert::IsTrue(V.size() == 0);

      V.push_back('z');

      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'z');

      s3_F03(V);

      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'z');
    }

    void s3_F04(myvector<char> V, myvector<int> V2)
    {
      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'z');

      Assert::IsTrue(V2.size() == 1);
      Assert::IsTrue(V2.front() == 123);
      Assert::IsTrue(V2.back() == 123);

      V.push_back('a');
      V2.push_back(-1);

      Assert::IsTrue(V.size() == 2);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'a');

      Assert::IsTrue(V2.size() == 2);
      Assert::IsTrue(V2.front() == 123);
      Assert::IsTrue(V2.back() == -1);
    }

    TEST_METHOD(_grading_set3_T04)
    {
      myvector<char> V(10);
      myvector<int>  V2(10);

      Assert::IsTrue(V.size() == 0);
      Assert::IsTrue(V2.size() == 0);

      V.push_back('z');
      V2.push_back(123);

      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'z');

      Assert::IsTrue(V2.size() == 1);
      Assert::IsTrue(V2.front() == 123);
      Assert::IsTrue(V2.back() == 123);

      s3_F04(V, V2);

      Assert::IsTrue(V.size() == 1);
      Assert::IsTrue(V.front() == 'z');
      Assert::IsTrue(V.back() == 'z');

      Assert::IsTrue(V2.size() == 1);
      Assert::IsTrue(V2.front() == 123);
      Assert::IsTrue(V2.back() == 123);
    }


    void s3_F05_2(myvector<int> V, const int N)
    {
      Assert::IsTrue(V.size() == N);

      int count = 0;
      for (int i = 0; i < N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == N);

      // push another N elements:
      for (int i = N; i < 2 * N; ++i)
        V.push_back(-2 * i + 1);

      Assert::IsTrue(V.size() == 2 * N);

      count = 0;
      for (int i = 0; i < 2 * N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == 2 * N);
    }

    void s3_F05_1(myvector<int> V, const int N)
    {
      Assert::IsTrue(V.size() == N);

      int count = 0;
      for (int i = 0; i < N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == N);

      // push another N elements:
      for (int i = N; i < 2*N; ++i)
        V.push_back(-2 * i + 1);
      
      Assert::IsTrue(V.size() == 2*N);

      count = 0;
      for (int i = 0; i < 2*N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == 2*N);

      // now pass:
      s3_F05_2(V, 2 * N);

      Assert::IsTrue(V.size() == 2 * N);

      count = 0;
      for (int i = 0; i < 2 * N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == 2 * N);
    }

    TEST_METHOD(_grading_set3_T05)
    {
      myvector<int> V(40);
      const int N = 1000;

      Assert::IsTrue(V.size() == 0);

      for (int i = 0; i < N; ++i)
        V.push_back(-2 * i + 1);

      int count = 0;
      for (int i = 0; i < N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == N);
      Assert::IsTrue(V.size() == N);

      s3_F05_1(V, N);

      Assert::IsTrue(V.size() == N);

      count = 0;
      for (int i = 0; i < N; ++i)
      {
        Assert::IsTrue(V[i] == -2 * i + 1);
        count++;
      }

      Assert::IsTrue(count == N);
    }

    //
    // copy constructor with strings:
    //
    TEST_METHOD(_grading_set3_T06)
    {
      myvector<std::string> V(3);

      std::vector<std::string> S = {
        "apples", "bananas", "oranges", "pizza",
        "cat", "dog", "lion", "tiger", "bear",
        "house", "boat", "car", "plane", "uic",
        "uci", "michigan"
      };

      for (auto s : S)
        V.push_back(s);

      Assert::IsTrue(V.size() == S.size());
      Assert::IsTrue(V.capacity() == 18);

      //
      // copy constructor:
      //
      myvector<std::string> V2 = V;

      V.push_back("testing 123");

      Assert::IsTrue(V2.size() == S.size());
      Assert::IsTrue(V2.capacity() == 18);

      Assert::IsTrue(V2.front() == "apples");
      Assert::IsTrue(V2.back() == "michigan");

      int i = 0;
      for (auto s : S)
      {
        Assert::IsTrue(s == V[i]);
        Assert::IsTrue(s == V2[i]);
        i++;
      }
    }

  };

}