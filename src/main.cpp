/** @file main.cpp
 *
 * @brief main/debug executable for Assignment Classes and Memory,
 *   practice with classes and dynamic memory allocation.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Classes and Memory
 * @date   June 1, 2021
 *
 * Practice with classes and dynamic memory allocation.  In this assignment we
 * build a class to represent a large integer.  We use dynamic memory allocation
 * to manage an array of digits for the LargeInteger object.  This file is a
 * stub for a main() function so that we can build a version suitable for
 * running in the debugger.
 */
#include "LargeInteger.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/** @brief Main entry point
 *
 * Main entry point for debugging functions.
 *
 * @param argc The command line argument count, the number of arguments
 *   provided by user on the command line.
 * @param argv An array of char* old style c-strings.  Each argv[x]
 *   that is passed in holds one of the command line arguments provided
 *   by the user to the program when started.
 *
 * @returns int Returns 0 to indicate successfull completion of program,
 *   and a non-zero value to indicate an error code.
 */
int main(int argc, char** argv)
{
  // an example of invoking the tostring member function and the array based constructor
  /* uncomment the following to debug tostring() and the array based constructor
     int digits1[] = {8, 4, 6, 3, 8, 4, 7, 4, 1, 2};
     LargeInteger li1(10, digits1);
     string res;
     res = li1.tostring();
     cout << "Expected result 2147483648, got result: " << res << endl;
     assert(res == "2147483648"); // will fail assertion if we don't get what we expect
   */
  cout << "Assignment Classes and Memory hello world" << endl;

  // return 0 to indicate successful completion of program
  return 0;
}
