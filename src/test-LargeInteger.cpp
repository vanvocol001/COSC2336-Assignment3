/** @file test-LargeInteger.cpp
 *
 * @brief Unit tests for Assignment Classes and Memory, practice with
 *   classes and dynamic memory allocation.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Classes and Memory
 * @date   June 1, 2021
 *
 * Practice with classes and dynamic memory allocation.  In this
 * assignment we build a class to represent a large integer.  We use
 * dynamic memory allocation to manage an array of digits for the
 * LargeInteger object.  This file is a set of unit tests of the
 * LargeInteger class using the catch2 unit test framework.
 */
#include "LargeInteger.hpp"
#include "catch.hpp"
#include <iostream>
using namespace std;

/** Task 1: test default constructor and tostring() implementation
 * Uncomment the following test case block and write your code to pass
 * the tests.  You were given a default and standard constructor for
 * the class.  You need to implement the tostring() method, which we
 * will use extensively in the tests to test your other member
 * functions.
 */
 //uncomment the tests cases 1 at a time.  This test case tests implementation
 //* of the tostring() member function which we use for further testing.
   TEST_CASE("<tostring()> member function tests using default and standard constructor",
             "[task1]")
   {
   LargeInteger li1;
   CHECK( li1.tostring() == "0" );

   LargeInteger li2(12345);
   CHECK( li2.tostring() == "12345" );

   // an even larger value
   LargeInteger li3(1234567890);
   CHECK( li3.tostring() == "1234567890" );
   }
 

/** Task 2: test array based constructor implementation
 * Uncomment the following test case block and write your code to pass
 * the tests.
 */
// uncomment this test case when ready to implement and test the
 //* array constructor you are to create
   TEST_CASE("<array constructor> constructor function tests",
             "[task2]")
   {
   // a kind of large integer
   int digits1[] = {8, 4, 6, 3, 8, 4, 7, 4, 1, 2};
   LargeInteger li1(10, digits1);
   CHECK( li1.tostring() == "2147483648" );

   // a really large integer
   int digits2[] = {2, 4, 7, 3, 6, 5, 4, 3, 5, 9,
                  2, 7, 3, 8, 4, 9, 6, 2, 1, 0,
                  7, 6, 1, 9, 3, 4, 2, 0, 2, 8};
   LargeInteger li2(30, digits2);
   CHECK( li2.tostring() == "820243916701269483729534563742" );
   }
 

/** Test fixture of some LargeInteger instances to be used in the following
 * tests.  Define a diverse set of large integer instances that we can
 * reuse in all of the following test cases.  Uncomment these for
 * Task 3 and subsequent tests.
 */
// uncomment this fixture before performing the following test cases
   struct LargeIntegerTestFixture
   {
   public:
   /// @brief Large Integer 1, 1 digits, 0 initially, uses default constructor
   LargeInteger li1;

   /// @brief Large Integer 2, 1 digit, non-zero initially, usest int parsing constructor
   LargeInteger li2 = LargeInteger(5);

   /// @brief Large Integer 3, 5 digits, non-zero
   LargeInteger li3 = LargeInteger(34567);

   /// @brief Large Integer 4, 5 digits, using task 2 array based constructor
   ///        Notice that the value of this is 56789
   int digits4[5] = {9, 8, 7, 6, 5};
   LargeInteger li4 = LargeInteger(5, digits4);

   /// @brief Large Integer 5, 9 digits
   LargeInteger li5 = LargeInteger(398298312);

   /// @brief Large Integer 6, 17 digits, uses task 2 array based constructor
   int digits6[17] = {3, 3, 1, 4, 2, 1, 5, 1, 2, 4, 7, 6, 9, 3, 9, 5, 6};
   LargeInteger li6 = LargeInteger(17, digits6);
   };
 

/** Task 3: test maxDigits() member function
 * Uncomment the following test case block and write your code to pass
 * the tests.
 */

   TEST_CASE_METHOD(LargeIntegerTestFixture,
     "<maxDigits()> member function tests", "[task3]")
   {
   SECTION("test of maxDigits() member function")
   {
    // when max digits are equal
    CHECK( li1.maxDigits(li2) == 1 );
    CHECK( li2.maxDigits(li1) == 1 );

    CHECK( li3.maxDigits(li4) == 5 );
    CHECK( li4.maxDigits(li3) == 5 );

    // not equal
    CHECK( li1.maxDigits(li3) == 5 );
    CHECK( li4.maxDigits(li2) == 5 );

    // some more checks
    CHECK( li5.maxDigits(li6) == 17 );
    CHECK( li6.maxDigits(li5) == 17 );

    CHECK( li5.maxDigits(li3) == 9 );
    CHECK( li3.maxDigits(li6) == 17 );

    CHECK( li5.maxDigits(li2) == 9 );
    CHECK( li1.maxDigits(li6) == 17 );
   }
   }
 

/** Task 4: test digitAtPosition() member function
 * Uncomment the following test case block and write your code to pass
 * the tests.
 */

   TEST_CASE_METHOD(LargeIntegerTestFixture,
     "<digitAtPosition()> member function tests (reading values)", "[task4]")
   {
   SECTION("test of digitAtPosition() member function")
   {
    // test single digit access working
    CHECK( li1.digitAtPosition(0) == 0 );
    CHECK( li2.digitAtPosition(0) == 5 );

    // check begin and end bounds
    CHECK( li3.digitAtPosition(0) == 7 );
    CHECK( li3.digitAtPosition(4) == 3 );
    CHECK( li5.digitAtPosition(0) == 2 );
    CHECK( li5.digitAtPosition(8) == 3 );
    CHECK( li6.digitAtPosition(0) == 3 );
    CHECK( li6.digitAtPosition(16) == 6 );

    // check some aribitrary values not at ends
    CHECK( li3.digitAtPosition(2) == 5 );
    CHECK( li4.digitAtPosition(1) == 8 );
    CHECK( li5.digitAtPosition(6) == 8 );
    CHECK( li5.digitAtPosition(2) == 3 );
    CHECK( li6.digitAtPosition(4) == 2 );
    CHECK( li6.digitAtPosition(14) == 9 );

    // according to specifications, illegal indexes should give a 0 as the digit at place
    CHECK( li1.digitAtPosition(-1) == 0 );
    CHECK( li2.digitAtPosition(-5) == 0 );
    CHECK( li4.digitAtPosition(-7) == 0 );
    CHECK( li1.digitAtPosition(1) == 0 );
    CHECK( li2.digitAtPosition(5) == 0 );
    CHECK( li3.digitAtPosition(6) == 0 );
    CHECK( li4.digitAtPosition(6) == 0 );
    CHECK( li5.digitAtPosition(15) == 0 );
    CHECK( li6.digitAtPosition(17) == 0 );
   }
   }
 

/** Task 5: test appendDigit() member function
 * Uncomment the following test case block and write your code to pass
 * the tests.
 */
// uncomment this test case to work on implementation of appendDigit()
 // member function
   TEST_CASE_METHOD(LargeIntegerTestFixture,
     "<appendDigit()> member function tests", "[task5]")
   {
   SECTION("test of appendDigit() member function")
   {
    li2.appendDigit(7);
    CHECK( li2.tostring() == "75" );
    li3.appendDigit(9);
    CHECK( li3.tostring() == "934567" );
    li5.appendDigit(1);
    CHECK( li5.tostring() == "1398298312" );
    li6.appendDigit(7);
    CHECK( li6.tostring() == "765939674215124133" );

    // append of 0 (as most significant digit) should be ignored
    li1.appendDigit(0);
    CHECK( li1.tostring() == "0" );
    li4.appendDigit(0);
    CHECK( li4.tostring() == "56789" );
    li5.appendDigit(0);
    CHECK( li5.tostring() == "1398298312" );
    li6.appendDigit(0);
    CHECK( li6.tostring() == "765939674215124133" );
   }
   }
 

/** Task 6: test add() member function
 * Uncomment the following test case block and write your code to pass
 * the tests.
 */

   TEST_CASE_METHOD(LargeIntegerTestFixture,
     "<add()> member function tests", "[task6]")
   {
   SECTION("")
   {
    // append the digits from previous test case again
    li2.appendDigit(7);
    li3.appendDigit(9);
    li5.appendDigit(1);
    li6.appendDigit(7);

    // now perform the tests of the add operator
    LargeInteger lires;

    lires = li1.add(li2);
    CHECK( lires.tostring() == "75" );

    lires = li2.add(li1);
    CHECK( lires.tostring() == "75" );

    lires = li3.add(li4);
    CHECK( lires.tostring() == "991356" );

    lires = li4.add(li3);
    CHECK( lires.tostring() == "991356" );

    lires = li5.add(li6);
    CHECK( lires.tostring() == "765939675613422445" );

    lires = li6.add(li5);
    CHECK( lires.tostring() == "765939675613422445" );

    // an explicit test of carry on last digit
    LargeInteger li7(999999999);
    int digits8[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    LargeInteger li8(9, digits8);

    lires = li7.add(li8);
    CHECK( lires.tostring() == "1999999998" );

    lires = li8.add(li7);
    CHECK( lires.tostring() == "1999999998" );
   }
   }
 
