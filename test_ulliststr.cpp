#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

using namespace std;
int main(int argc, char* argv[])
{
    //Create a new list
    ULListStr list;

    //Add some elements
    list.push_back("ello");
    list.push_back("world");
    list.push_back("!");
    list.push_front("H");

    //Test the front function
    cout << "front: " << list.front() << endl;

    //Test the back function
    cout << "back: " << list.back() << endl;

    //Test the pop_back function
    list.pop_back();

    //Test the pop_front function
    list.pop_front();
  
    return 0;
}
