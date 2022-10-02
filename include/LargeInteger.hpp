/** @file LargeInteger.hpp
 *
 * @brief Header file for Assignment Classes and Memory: practie with
 *   classes and dynamic memory allocation.
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Classes and Memory
 * @date   June 1, 2021
 *
 * LargeInteger class.  This is the class header file.  It contains the
 * declaration of the LargeInteger class.  It is included in other files that
 * want to use and create instances of LargeInteger objects.  The declaration of
 * a class is basically just a list of the prototypes of the member functions
 * for the class, as well as the private member variables/data that is
 * encapsulated in the class.
 */
#ifndef _LARGEINTEGER_H_
#define _LARGEINTEGER_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/** LargeInteger class.
 * Represent an arbitrarily large (signed) integer.  This class keeps the
 * digits of the integer in an array of integers internally.  The array of
 * integers is dynamically resized as necessary during LargeInteger operations.
 * This abstract data type supports addition of large integers.
 */
class LargeInteger
{
public:
  // class constructors and destructors
  LargeInteger();          // default constructor
  LargeInteger(int value); // standard constructor
  // your constructor from an array prototype should go here
  ~LargeInteger();
  LargeInteger(int numDigits, const int arr[]);

  // your member function declarations/prototypes should go here

string tostring() const;
int maxDigits(const LargeInteger& other) const;
int digitAtPosition(int position) const;
void appendDigit(int addition);
LargeInteger& add(const LargeInteger& other) const;


private:
  /// @brief id private member integer variable, this is not strictly needed
  ///   for this class, but we assign a unique id to each instance of
  ///   LargeInteger that is created, so that you can more easily see how
  ///   the destructor works and is being called.  You should set the
  ///   id and increment it in any constructors you create for this class.
  int id;
  /// @brief numDigits Private member integer variable, contains the number
  ///   of digits currently in the LargeInteger, or equivalently, the size
  ///   of the digits array of integers.
  int numDigits;
  /// @brief digit A dynamically allocated array of integers.  This array
  ///   holds the digits of the large integer this object represents.  The
  ///   digits in the array are orderd such that the 1's place (10^0) is in
  ///   index 0 of the array, the 10's place (10^1) is in the index 1, and so
  ///    on.
  int* digit;
};

#endif
