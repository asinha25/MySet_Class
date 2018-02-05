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
    // The fourth set of tests focus on iterators:
    //
    TEST_METHOD(_grading_set4_T01)
    {
      myvector<int> V(40);

      Assert::IsTrue(V.size() == 0);

      auto i = V.begin();
      auto j = V.end();

      Assert::IsFalse(i != j);
    }

    TEST_METHOD(_grading_set4_T02)
    {
      myvector<string> V(10);

      V.push_back("apple");

      auto i = V.begin();
      auto j = V.end();

      Assert::IsTrue(i != j);
      Assert::IsTrue(*i == "apple");
    }

    TEST_METHOD(_grading_set4_T03)
    {
      myvector<string> V(10);

      V.push_back("apple");

      auto i = V.begin();
      auto j = V.end();

      Assert::IsTrue(i != j);
      Assert::IsTrue(*i == "apple");
      ++i;
      Assert::IsFalse(i != j);
    }

    TEST_METHOD(_grading_set4_T04)
    {
      myvector<int> V(20);
      const int N = 15;

      for (int i = 0; i < N; ++i)
        V.push_back(3 * i - 9);

      int count = 0;

      for (auto iter = V.begin();
        iter != V.end();
        ++iter)
      {
        Assert::IsTrue(*iter == (3 * count - 9));
        count++;
      }

      // did we touch all N elements?
      Assert::IsTrue(count == N);
    }

    TEST_METHOD(_grading_set4_T05)
    {
      myvector<int> V(20);
      const int N = 15;

      auto iter = V.begin();
      auto iter2 = V.end();

      while (iter != iter2)
      {
        // this should never happen:
        Assert::IsTrue(false);
      }

      for (int i = 0; i < N; ++i)
        V.push_back(3 * i - 9);

      int count = 0;

      iter = V.begin();
      iter2 = V.end();

      while (iter != iter2)
      {
        Assert::IsTrue(*iter == (3 * count - 9));
        count++;

        ++iter;
        iter2 = V.end();
      }

      // did we touch all N elements?
      Assert::IsTrue(count == N);
    }

    TEST_METHOD(_grading_set4_T06)
    {
      //
      // same as above, but fill node completely:
      //
      myvector<int> V(20);
      const int N = 20;

      auto iter = V.begin();
      auto iter2 = V.end();

      while (iter != iter2)
      {
        // this should never happen:
        Assert::IsTrue(false);
      }

      for (int i = 0; i < N; ++i)
        V.push_back(3 * i - 9);

      int count = 0;

      iter = V.begin();
      iter2 = V.end();

      while (iter != iter2)
      {
        Assert::IsTrue(*iter == (3 * count - 9));
        Assert::IsTrue(*iter == V[count]);
        count++;

        ++iter;
        iter2 = V.end();
      }

      // did we touch all N elements?
      Assert::IsTrue(count == N);
    }

    //
    // let's test having multiple iterators, over different vectors
    //
    TEST_METHOD(_grading_set4_T07)
    {
      myvector<int>  V(20);
      myvector<char> V2(10);

      const int N = 15;

      V2.push_back('a');

      for (int i = 0; i < N; ++i)
        V.push_back(3 * i - 9);

      V2.push_back('b');

      Assert::IsTrue(V.size() == N);
      Assert::IsTrue(V2.size() == 2);

      auto iter = V.begin();
      auto iter2 = V2.begin();

      Assert::IsTrue(iter != V.end());
      Assert::IsTrue(iter2 != V2.end());

      Assert::IsTrue(*iter2 == 'a');
      Assert::IsTrue(*iter == -9);
      ++iter;
      Assert::IsTrue(*iter == -6);
      Assert::IsTrue(*iter2 == 'a');

      ++iter2;
      Assert::IsTrue(*iter2 == 'b');
      Assert::IsTrue(*iter == -6);

      ++iter;
      ++iter2;
      Assert::IsFalse(iter2 != V2.end());
      Assert::IsTrue(*iter == -3);
      ++iter;
      Assert::IsTrue(*iter == 0);

      int count = 3;

      while (iter != V.end())
      {
        Assert::IsTrue(*iter == (3 * count - 9));
        Assert::IsTrue(*iter == V[count]);
        count++;

        ++iter;
      }

      // did we touch all N elements?
      Assert::IsTrue(count == N);
    }

    TEST_METHOD(_grading_set4_T08)
    {
      //
      // now we need to iterate across multiple nodes:
      //
      myvector<int> V(100);
      const int N = 450;

      for (int i = 0; i < N; ++i)
        V.push_back(-4 * i + 7);

      int count = 0;

      for (auto iter = V.begin();
        iter != V.end(); 
        ++iter)
      {
        Assert::IsTrue(*iter == (-4 * count + 7));
        Assert::IsTrue(*iter == V[count]);
        count++;
      }

      // did we touch all N elements?
      Assert::IsTrue(count == N);
    }

    TEST_METHOD(_grading_set4_T09)
    {
      //
      // now we need to iterate across multiple nodes,
      // such that fill all N nodes:
      //
      myvector<int> V(100);
      const int N = 1100;

      for (int i = 0; i < N; ++i)
        V.push_back(-4 * i + 7);

      int count = 0;

      for (auto iter = V.begin();
        iter != V.end();
        ++iter)
      {
        Assert::IsTrue(*iter == (-4 * count + 7));
        Assert::IsTrue(*iter == V[count]);
        count++;
      }

      // did we touch all N elements?
      Assert::IsTrue(count == N);
    }

    TEST_METHOD(_grading_set4_T10)
    {
      //
      // we tested multiple iterators to different vectors,
      // how about multiple iterators to the *same* vector?
      //
      myvector<int> V(100);
      const int N = 450;

      for (int i = 0; i < N; ++i)
        V.push_back(-4 * i + 7);

      auto iter1 = V.begin();
      auto iter2 = V.begin();

      ++iter1;
      ++iter1;
      int count = 2;

      while (iter1 != V.end())
      {
        Assert::IsTrue(*iter1 == (-4 * count + 7));
        Assert::IsTrue(*iter1 == V[count]);

        Assert::IsTrue(*iter2 == (-4 * (count - 2) + 7));
        Assert::IsTrue(*iter2 == V[count - 2]);

        count++;

        ++iter1;
        ++iter2;
      }

      Assert::IsTrue(count == N);

      //
      // iter2 should be 2 shy of .end():
      //
      Assert::IsFalse(iter1 != V.end());
      Assert::IsTrue(iter2 != V.end());

      Assert::IsTrue(*iter2 == (-4 * (N - 2) + 7));
      Assert::IsTrue(*iter2 == V[N - 2]);

      ++iter2;
      Assert::IsTrue(*iter2 == (-4 * (N - 1) + 7));
      Assert::IsTrue(*iter2 == V[N - 1]);

      ++iter2;
      Assert::IsFalse(iter2 != V.end());
    }

    // credit to manclls2:
    TEST_METHOD(_grading_set4_T11)
    {
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

    //
    // foreach:
    //
    TEST_METHOD(_grading_set4_T12)
    {
      myvector<std::string> V(3);
      std::vector<std::string> S = {
        "apples", "bananas", "oranges", "pizza"
      };

      V.push_back("apples");
      V.push_back("bananas");
      V.push_back("oranges");
      V.push_back("pizza");

      Assert::IsTrue(V.size() == 4);
      Assert::IsTrue(V.capacity() == 6);

      myvector<std::string> V2 = V;

      int i = 0;
      for (auto s : S)
      {
        Assert::IsTrue(s == V[i]);
        Assert::IsTrue(s == V2[i]);
        i++;
      }

      Assert::IsTrue(i == 4);
    }

    //
    // another foreach:
    //
    TEST_METHOD(_grading_set4_T13)
    {
      const int N = 1000;
      const int NodeSize = 17;

      myvector<int> V(NodeSize);

      //
      // initialize: N, N-1, N-2, ..., 3, 2, 1
      //
      for (int i = 0; i < N; ++i)
        V.push_back(N - i);

      V.push_back(0);

      //
      // range-for:
      //
      int i = 0;
      for (auto e : V)
      {
        Assert::IsTrue(e == (N - i));
        ++i;
      }

      Assert::IsTrue(i == N+1);
    }

    //
    // selection sort:
    //
    TEST_METHOD(_grading_set4_T14)
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

  };

}