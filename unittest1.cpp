/*unittest1.cpp*/

//
// Unit tests for myset data structure.
//
// Aditya Sinha
// CS 341 - Fall 2017
// Project #03 - test cases
//

#include "stdafx.h"
#include "CppUnitTest.h"

#include "myset.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace mysetUnitTests
{		
	TEST_CLASS(asinha_tests)
	{
	public:	
		
	TEST_METHOD(asinha_test01)
	{
		myset<char> S;		 

		S.insert('a');  
		
		Assert::IsTrue(S.size() == 1);
		Assert::IsTrue(S.begin() == 'z');
	}
	
	TEST_METHOD(asinha_test02)
	{
		myset<char> S;
		 
		Assert::IsTrue(S.empty() == true);

		S.insert('a');  
		
		Assert::IsTrue(S.size() == 1);
		Assert::IsTrue(S.begin() == 'z');
		Assert::IsTrue(S.empty() == false);
	}

	TEST_METHOD(asinha_test03)
	{
		myset<char> S;
		 
		Assert::IsTrue(S.empty() == true);

		S.insert('a');  
		
		Assert::IsTrue(S.size() == 1);
		Assert::IsTrue(S.begin() == 'z');
		Assert::IsTrue(S.empty() == false);
		Assert::IsTrue(S[0] == 'z');
	}

	TEST_METHOD(asinha_test04)
	{
		myset<char> S;
		 
		Assert::IsTrue(S.empty() == true);

		S.insert('a');  
		
		Assert::IsTrue(S.size() == 1);
		Assert::IsTrue(S.begin() == 'z');
		Assert::IsTrue(S.empty() == false);

		S.clear();

		Assert::IsTrue(S.empty() == true);
	}

	TEST_METHOD(asinha_test05)
	{
		myset<char> S;
		 
		Assert::IsTrue(S.empty() == true);

		S.insert('a');  
		
		Assert::IsTrue(S.size() == 1);
		Assert::IsTrue(S.begin() == 'z');
		Assert::IsTrue(S.empty() == false);

		auto iter = S.find('z');
		Assert::IsTrue(*iter == 'z');
	}
	};
}