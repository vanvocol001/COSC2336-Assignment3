/** @file LargeInteger.cpp
 *
 * @brief Implementation file for Assignment Classes and Memory,
 *   practice with classes and dynamic memory allocation.
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Classes and Memory
 * @date   June 1, 2021
 *
 * LargeInteger class.  This is the class implementation file. It
 * contains the implementation of all of the member functions declared
 * in the header file.  Since implementation is separated from the
 * declaration of each member function, you must indicate each
 * function is a member of the LargeIneger class by prepending member
 * function name with LargeInteger::
 */
#include "LargeInteger.hpp"

using namespace std;

// integer to create unique id for new LargeInteger instances
// please set and use this in the same way in the constructor you
// create for this assignment
static int nextLargeIntegerId = 1;

/** @brief LargeInteger default constructor
 *
 * Default constructor for LargeInteger class. By default we construct
 * with a value of 0 being represented.
 */
LargeInteger::LargeInteger()
{
  // set this instance id
  id = nextLargeIntegerId++;

  // only a single digit
  numDigits = 1;

  // allocate an array of the right size
  digit = new int[numDigits];

  // initialize the digit to 0
  digit[0] = 0;
}

/** @brief LargeInteger from int constructor
 *
 * Constructor for LargeInteger class that takes a simple built-in
 * integer to be used as the initial value of the large integer.
 *
 * @param value A regular (32-bit) integer that we will use as the
 *    initial value of this LargeInteger data type.
 */
LargeInteger::LargeInteger(int value)
{
  // set this instance id
  id = nextLargeIntegerId++;

  // first determine number of digits, so we know what size of array
  // to construct dynamically
  // https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
  numDigits = (int)log10((double)value) + 1;

  // allocate an array of the right size
  digit = new int[numDigits];

  // iterate through the digits in value, putting them into our
  // array of digits.
  int nextDigit;
  for (int digitIndex = 0; digitIndex < numDigits; digitIndex++)
  {
    // least significant digit
    nextDigit = value % 10;
    digit[digitIndex] = nextDigit;

    // integer division to chop off least significant digit
    value = value / 10;
  }
}

/** @brief LargeInteger array based constructor
 *
 * Constructor for LargeInteger class that takes an array of digits
 * and initializes this large integers digits to the given values.
 *
 * @param numDigits The number of digits being passed in to be
 *   initialized.
 * @param digit An array of integers representing digits of a
 *   large integer to be constructed.
 */

LargeInteger::LargeInteger(int numbers, const int arr[])
{
  id = nextLargeIntegerId++;
  numDigits = numbers;
  digit = new int[numDigits];
  for (int index = numDigits - 1; index >= 0; index--)
  {
    digit[index] = arr[index];
  }
  
}

/** @brief LargeInteger destructor
 *
 * Destructor for the LargeInteger class.  Make sure we are good
 * managers of memory by freeing up our digits when this object
 * goes out of scope.
 */

LargeInteger::~LargeInteger()
{
  // uncomment following output statement to debug/follow destruction of
   //LargeInteger instances
   cout << "<LargeInteger::~LargeInteger> destructor entered, freeing my digits" << endl
       << "     id = " << id << endl
       << "     value=" << tostring() << endl;
  delete[] this->digit;
}

/** @brief LargeInteger tostring
 *
 * Represent this large integer as a string value
 *
 * @returns string The large integer as a string
 */

string LargeInteger::tostring() const
{
  ostringstream output;
  for (int index = numDigits - 1; index >= 0; index--)
  {
    output << digit[index];
  }
  return output.str();
}

/** @brief Maximum number of digits
 *
 * Return the larger of the number of digits (numDigits) between
 * this object and the other LargeInteger object.  This might
 * not be so useful to users of this data type, but the first
 * step in addition and subtraction is to determine the size
 * we need for the new result array, which will either be the
 * larger numDigits of the two objects being added, or that value
 * plus 1 if there is cary from the addition.
 *
 * @param other Another LargeInteger object that we are to compare
 *   this object numDigits to
 *
 * @returns int The larger (max) of the numDigits of the two
 *   referenced objects.
 */

int LargeInteger::maxDigits(const LargeInteger& other) const
{
  if (numDigits > other.numDigits)
  {
    return numDigits;
  }
  else
  {
    return other.numDigits;
  }
  return 0;
}

/** @brief Digit at position
 *
 * Given a position, return the digit at the given index of
 * this LargeInteger.  The digitIndex passed in refers to
 * the place or power of the digit needed.  For example
 * 0 means we want the 10^0 or the 1's place, 1 means we
 * need the 10^1 or the 10s place digit, etc.  If the
 * requested digit index is bigger than the number of places
 * in the LargeInteger then 0 is returned.  For example, if this
 * LargeInteger represents the number 123, and we ask for the
 * 4th place (10^4 or the 1000s place), this function will
 * return 0.
 *
 * @param position The index, interpreted as the place or power,
 *   of the specific digit to be accessed and returned.
 *
 * @returns int The digit in the 10^position place of this
 *   LargeInteger object.
 */

int LargeInteger::digitAtPosition(int position) const
{
   if (position >= 0 and position <= numDigits - 1)
   { 
    return digit[position];
   }
   return 0;
}

/** @brief Append digit
 *
 * Append the indicated digit to the most significant place of this
 * digit.  This function is not so useful to users of LargeInteger.
 * However, for arithemetic operations, if there is carry over from
 * the last operations (like carry from adding the most significant
 * place of two integers), then the LargeInteger has to grow in size.
 *
 * @param digit The digit to append to the most significant place
 *   of this object.
 */

void LargeInteger::appendDigit(int addition)
{
  if (addition == 0)
  {

  }
  else
  {
    int newNumDigits = numDigits + 1;
    int* ray;
    ray = new int[newNumDigits];
    for (int index = 0; index < numDigits; index++)
    {
      ray[index] = digit[index];
    }

    if (digit != NULL)
    {
      delete[] digit;
    }

    digit = ray;
    digit[numDigits] = addition;
    numDigits = newNumDigits;
  }
}

/** @brief Add large integers
 *
 * Add this LargeInteger to the other LargeInteger passed in as
 * a parameter.
 *
 * @param other Another LargeInteger data type.
 *
 * @returns LargeInteger& Returns a reference to a newly created
 *   LargeInteger which contains the value of the this added
 *   with other.
 */

LargeInteger& LargeInteger::add(const LargeInteger& other) const
{ 
  int size = maxDigits(other);
  int* ray;
  ray = new int[size];
  int carry = 0;
  for (int index = 0; index < size ; index++)
  {
    int sum = (digitAtPosition(index) + other.digitAtPosition(index) + carry);
    int addition = sum % 10;
    ray[index] = addition;
    if (sum > 9)
    {
      carry = 1;
    }
    else
    {
      carry = 0; 
    }
  }
  LargeInteger* newNumber = new LargeInteger(size, ray);
  newNumber -> appendDigit(carry);
  delete[] ray;
  return *newNumber;
}