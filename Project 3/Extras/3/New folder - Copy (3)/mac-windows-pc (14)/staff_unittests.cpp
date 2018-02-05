#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>
#include "myvector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace myvectorUnitTest
{		
  TEST_CLASS(UnitTest1)
  {
  public:

    TEST_METHOD(_jhummel2_1_simple)
    {
      myvector<int>  V(10);  // nodesize of 10:

      V.push_back(1);
      V.push_back(2);
      V.push_back(3);

      Assert::IsTrue(V.front() == 1);
      Assert::IsTrue(V.back() == 3);
    }

    TEST_METHOD(_jhummel2_2_simple)
    {
      myvector<int>  V(10);  // nodesize of 10:

      Assert::IsTrue(V.size() == 0);

      V.push_back(1);
      V.push_back(2);
      V.push_back(3);

      Assert::IsTrue(V.size() == 3);
    }

    TEST_METHOD(_jhummel2_3_strings)
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
    }

    TEST_METHOD(_jhummel2_4_medium)
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

    TEST_METHOD(_jhummel2_5_copy_constructor)
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

    TEST_METHOD(_jhummel2_6_foreach)
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
    }

    TEST_METHOD(_jhummel2_7_iterators)
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