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
#include "myvector.h"

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