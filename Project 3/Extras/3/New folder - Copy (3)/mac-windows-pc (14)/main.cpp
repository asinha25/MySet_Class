//
// Implementing and testing a std::vector replacement class.
//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS341, Fall 2016
// HW #03
//

#include <iostream>
#include <string>
#include <vector>

#include "myvector.h"

using namespace std;

//#define STDVECTOR
#define MYVECTOR


//
// main: 
//
int main()
{
  std::cout << "** Starting **" << endl << endl;

#ifdef STDVECTOR
  std::cout << "** Using std::vector **" << std::endl << std::endl;
  std::vector<int> V;
#else
  std::cout << "** Using myvector **" << std::endl << std::endl;
  myvector<int> V;
#endif

  std::cout << ">> Inserting 1, 2, 3..." << endl;

  V.push_back(1);
  V.push_back(2);
  V.push_back(3);

  std::cout << ">> front: " << V.front() << endl;
  std::cout << ">> back:  " << V.back() << endl;

  //
  // done:
  //
  std::cout << endl << "** Done **" << endl << endl;

  return 0;
}